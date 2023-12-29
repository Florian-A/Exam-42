/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:47:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 15:06:42 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

// define constants
#define E_ARGS "Wrong number of arguments\n"
#define E_FATAL "Fatal error\n"
#define BUFFER_SIZE 650000
#define MAX_CLIENTS 65000

// define globales
int max_fd, server_fd, client_id = 0;
int client_fds[MAX_CLIENTS];
char msg_buff[BUFFER_SIZE];
fd_set array_set, read_set, write_set;

// error fnc
void error(char *msg)
{
    if (server_fd > 2)
        close(server_fd);
    write(2, msg, strlen(msg));
    exit(1);
}

// send message to all fd exept sender fd
void send_msg(int client_fd)
{
    for (int fd = 2; fd <= max_fd; fd++)
        if (fd != client_fd && FD_ISSET(fd, &write_set))
            if (send(fd, msg_buff, strlen(msg_buff), 0) < 0)
                error(E_FATAL);
}

int main(int argc, char *argv[])
{
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    // check nb args
    if (argc != 2)
        error(E_ARGS);

    // create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
        error(E_FATAL);

    // create server struct
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
    server_addr.sin_port = htons(atoi(argv[1]));

    // link server struct and server socket
    if (bind(server_fd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) != 0)
        error(E_FATAL);

    // listen incoming connections
    if (listen(server_fd, 4096) != 0)
        error(E_FATAL);

    // starting array set
    client_len = sizeof(client_addr);
    max_fd = server_fd;
    FD_ZERO(&array_set);
    FD_SET(server_fd, &array_set);

    while (1)
    {
        // prepare fd read, fd write for select fnc
        read_set = write_set = array_set;
        if (select(max_fd + 1, &read_set, &write_set, 0, 0) < 0)
            continue;

        // check if new incoming connection
        if (FD_ISSET(server_fd, &read_set))
        {
            // accept new connection
            int fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
            if (fd < 0)
                error(E_FATAL);

            // push message in buffer
            sprintf(msg_buff, "server: client %d just arrived\n", client_id);

            // update array of fd
            client_fds[fd] = client_id++;
            FD_SET(fd, &array_set);

            // send welcome msg to another clients
            send_msg(fd);
            max_fd = (fd > max_fd) ? fd : max_fd;
            continue;
        }

        // loop on all connected client for verify incoming msg
        for (int fd = 2; fd <= max_fd; fd++)
        {
            if (FD_ISSET(fd, &read_set))
            {
                int recv_return = 1;
                char msg[BUFFER_SIZE];
                memset(msg, 0, BUFFER_SIZE);

                // read client msg until new line
                while (recv_return == 1 && msg[strlen(msg) - 1] != '\n')
                    recv_return = recv(fd, msg + strlen(msg), 1, 0);
                if (recv_return <= 0)
                {
                    // update msg if client discounected
                    sprintf(msg_buff, "server: client %d just left\n", client_fds[fd]);
                    FD_CLR(fd, &array_set);
                    close(fd);
                }
                else
                {
                    // update msg if data recev
                    sprintf(msg_buff, "client %d: %s", client_fds[fd], msg);
                }
                // send msg to another clients
                send_msg(fd);
            }
        }
    }
    return (0);
}
