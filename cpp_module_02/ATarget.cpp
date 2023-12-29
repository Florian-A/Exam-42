/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:47:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 15:01:52 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget() {};

ATarget::ATarget(const std::string &type) : type(type) {
}

ATarget::ATarget(const ATarget &src) {
    *this = src;
}

ATarget &ATarget::operator=(const ATarget &rhs) {
    if (this == &rhs)
        return *this;
    this->type = rhs.type;
    return *this;
}

ATarget::~ATarget() {
}

const std::string &ATarget::getType() const {
    return this->type;
}

void ATarget::getHitBySpell(const ASpell &spell) const {
    std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}