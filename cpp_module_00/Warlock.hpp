/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:47:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 14:59:40 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Warlock {
    private:
        std::string name;
        std::string title;

        Warlock();
        Warlock(const Warlock &src);
        Warlock &operator=(const Warlock &rhs);

    public:
        Warlock(const std::string &name, const std::string &title);
        ~Warlock();

        const std::string &getName() const;
        const std::string &getTitle() const;
        void setTitle(const std::string &title);
        void introduce() const;
};
