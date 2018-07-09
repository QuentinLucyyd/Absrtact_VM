/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:34:23 by qmanamel          #+#    #+#             */
/*   Updated: 2018/07/09 13:17:53 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/OperandFactory.hpp"
#include "../headers/Operand.hpp"

OperandFactory::OperandFactory(){
    operand[_Int8] = &OperandFactory::createInt8;
    operand[_Int16] = &OperandFactory::createInt16;
    operand[_Int32] = &OperandFactory::createInt32;
    operand[_Float] = &OperandFactory::createFloat;
    operand[_Double] = &OperandFactory::createDouble;
}

OperandFactory::~OperandFactory(){};

IOperand const * OperandFactory::createOperand( eOperandType type, std::string const & value ) const {
    IOperand const * (OperandFactory::*newOperand)(std::string const &value) const;

    newOperand = operand.at(type);
    return ((*this.*newOperand)(value));
}

IOperand const * OperandFactory::createInt8( std::string const & value ) const {
    return new Operand<int8_t>(std::stoi(value), _Int8, CHAR_MAX, CHAR_MIN);
}

IOperand const * OperandFactory::createInt16( std::string const & value ) const {
    return new Operand<int16_t>(std::stoi(value), _Int16, SHRT_MAX, SHRT_MIN);
}

IOperand const * OperandFactory::createInt32( std::string const & value ) const {
    return new Operand<int32_t>(std::stoi(value), _Int32, INT_MAX, INT_MIN);
}

IOperand const * OperandFactory::createFloat( std::string const & value ) const {
    return new Operand<float>(std::stof(value), _Float, std::numeric_limits<float>::max(), std::numeric_limits<float>::min());
}

IOperand const * OperandFactory::createDouble( std::string const & value ) const {
    return new Operand<double>(std::stod(value), _Double, std::numeric_limits<double>::max(), std::numeric_limits<double>::min());
}