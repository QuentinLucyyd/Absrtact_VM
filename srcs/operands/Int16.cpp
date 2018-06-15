/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:10:40 by qmanamel          #+#    #+#             */
/*   Updated: 2018/06/15 14:43:02 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../headers/operands/Int16.hpp"

Int16::Int16(int n):_type(_Int16), _precision(eOint16_t) {
    this->_value = static_cast<int16_t>(n);
    return ;
}

Int16::~Int16(void){return ;}