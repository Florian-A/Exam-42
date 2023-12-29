/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:47:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 14:59:51 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <string>
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {
    protected:
        std::string name;
        std::string effects;

    public:
        ASpell();
        ASpell(const std::string &name, const std::string &effects);
        virtual ~ASpell();

        ASpell(const ASpell &src);
        ASpell &operator=(const ASpell &rhs);

        const std::string &getName() const;
        const std::string &getEffects() const;

        virtual ASpell *clone() const = 0;
        void launch(const ATarget &target) const;
};
