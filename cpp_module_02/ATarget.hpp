/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:47:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 15:01:57 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
    protected:
        std::string type;

    public:
        ATarget();
        ATarget(const std::string &type);
        virtual ~ATarget();

        ATarget(const ATarget &src);
        ATarget &operator=(const ATarget &rhs);

        const std::string &getType() const;

        virtual ATarget *clone() const = 0;
        void getHitBySpell(const ASpell &spell) const;
};
