/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:47:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 15:02:16 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"
#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {};

Dummy::~Dummy() {
}

ATarget *Dummy::clone() const {
    return new Dummy();
}