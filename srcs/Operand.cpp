/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:13:18 by qmanamel          #+#    #+#             */
/*   Updated: 2018/07/06 16:32:06 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Operand.hpp"

template <typename T>Operand<T>::Operand( void ) {return ;}
template <typename T>Operand<T>::~Operand( void ) {return ;}

template <typename T>Operand<T>::Operand(const & Operand _rhs) {
    this = _rhs;
    return (*this);
}

template <typename T>Operand<T>::Operand(std::string const & value, eOperandType type, int precision) {
    this->_value = value;
    this->_type = type;
    this->_precision = precision;
}

template <typename T> Operand& Operand<T>::operator=(const & Operand _new) {
    this->_value = _new._value;
    this->_type = _new._type;
    this->_precision = _new._precision;
    this->_string = _new._string;
    return (*this);
}

template <typename T> int Operand<T>::getPrecision( void ) const {
    return this->_precision;
}