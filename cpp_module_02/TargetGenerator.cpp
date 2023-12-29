/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:47:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 15:03:29 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
}

void TargetGenerator::learnTargetType(ATarget *target) {
    if (target) {
        if (this->targets.find(target->getType()) == this->targets.end())
            this->targets.insert(make_pair(target->getType(), target->clone()));
    }
}

void TargetGenerator::forgetTargetType(const std::string &targetName) {
    if (this->targets.find(targetName) != this->targets.end())
        this->targets.erase(this->targets.find(targetName));
}

ATarget *TargetGenerator::createTarget(const std::string &targetName) {
    ATarget *target = NULL;
    if (this->targets.find(targetName) != this->targets.end())
        target = this->targets[targetName];
    return target;
}
