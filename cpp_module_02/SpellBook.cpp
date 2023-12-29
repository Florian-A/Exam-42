/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:47:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 15:03:17 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
}

void SpellBook::learnSpell(ASpell *spell) {
    if (spell) {
        if (this->spells.find(spell->getName()) == this->spells.end())
            this->spells.insert(make_pair(spell->getName(), spell->clone()));
    }
}

void SpellBook::forgetSpell(const std::string &spellName) {
    if (this->spells.find(spellName) != this->spells.end())
        this->spells.erase(this->spells.find(spellName));
}

ASpell *SpellBook::createSpell(const std::string &spellName) {
    ASpell *spell = NULL;
    if (this->spells.find(spellName) != this->spells.end())
        spell = this->spells[spellName];
    return spell;
}
