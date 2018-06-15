/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:12:18 by qmanamel          #+#    #+#             */
/*   Updated: 2018/06/15 14:42:22 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../headers/operands/Float.hpp"

Float::Float(int n):_type(_Float),_precision(eOfloat) {
    this->_value = static_cast<float>(n);
    return ;
}

Float::~Float(void){return ;}