/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:47:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 15:01:17 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell() {};

ASpell::ASpell(const std::string &name, const std::string &effects) : name(name), effects(effects) {
}

ASpell::ASpell(const ASpell &src) {
    *this = src;
}

ASpell &ASpell::operator=(const ASpell &rhs) {
    if (this == &rhs)
        return *this;
    this->name = rhs.name;
    this->effects = rhs.effects;
    return *this;
}

ASpell::~ASpell() {
}

const std::string &ASpell::getName() const {
    return this->name;
}

const std::string &ASpell::getEffects() const {
    return this->effects;
}

void ASpell::launch(const ATarget &target) const {
    target.getHitBySpell(*this);
}