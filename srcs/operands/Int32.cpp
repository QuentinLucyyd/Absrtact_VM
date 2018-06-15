/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:11:48 by qmanamel          #+#    #+#             */
/*   Updated: 2018/06/15 14:43:15 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../headers/operands/Int32.hpp"

Int32::Int32(int n):_type(_Int32), _precision(eOint32_t) {
    this->_value = static_cast<int32_t>(n);
    return ;
}

Int32::~Int32(void){return ;}