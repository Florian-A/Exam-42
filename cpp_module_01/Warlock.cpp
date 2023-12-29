/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:47:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 15:00:43 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock() {};

Warlock::Warlock(const std::string &name, const std::string &title) : name(name), title(title) {
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock &src) {
    *this = src;
}

Warlock &Warlock::operator=(const Warlock &rhs) {
    if (this == &rhs)
        return *this;
    this->name = rhs.name;
    this->title = rhs.title;
    return *this;
}

Warlock::~Warlock() {
    std::cout << this->name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const {
    return this->name;
}

const std::string &Warlock::getTitle() const {
    return this->title;
}

void Warlock::setTitle(const std::string &title) {
    this->title = title;
}

void Warlock::introduce() const {
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell) {
    if (spell) {
        this->spells.insert(make_pair(spell->getName(), spell->clone()));
    }
}

void Warlock::forgetSpell(std::string spellName) {
    std::map<std::string, ASpell*>::iterator it = this->spells.find(spellName);
    this->spells.erase(it);
}

void Warlock::launchSpell(std::string spellName, const ATarget &target) {
    if (this->spells[spellName]) {
        this->spells[spellName]->launch(target);
    }
}