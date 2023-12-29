/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:47:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 15:00:30 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"
#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {};

Fwoosh::~Fwoosh() {
}

ASpell *Fwoosh::clone() const {
    return new Fwoosh();
}