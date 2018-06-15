/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:32:53 by qmanamel          #+#    #+#             */
/*   Updated: 2018/06/15 14:42:38 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../headers/operands/Double.hpp"

Double::Double(int n):_type(_Double), _precision(eOdouble) {
    this->_value = static_cast<double>(n);
    return ;
}

Double::~Double(void){return ;}