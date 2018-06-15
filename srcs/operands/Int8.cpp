/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:45:42 by qmanamel          #+#    #+#             */
/*   Updated: 2018/06/15 15:09:15 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../headers/operands/Int8.hpp"

Int8::Int8(int n):_type(_Int8),_precision(eOint8_t) {
    this->_value = static_cast<int8_t>(n);
    return ;
}

Int8::~Int8(void){return ;}

int Int8::getPrecision( void ) const {
    return this->_precision;
}

eOperandType Int8::getType( void ) const {
    return this->_type;
}