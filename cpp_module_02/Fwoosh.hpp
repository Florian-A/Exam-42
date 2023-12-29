/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:47:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 15:02:47 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class Fwoosh : public ASpell {
    
    public:
        Fwoosh();
        ~Fwoosh();

        virtual ASpell *clone() const;
};
