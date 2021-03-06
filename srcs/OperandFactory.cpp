/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:34:23 by qmanamel          #+#    #+#             */
/*   Updated: 2018/07/09 15:29:31 by qmanamel         ###   ########.fr       */
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
    return new Operand<int8_t>(value, _Int8);
}

IOperand const * OperandFactory::createInt16( std::string const & value ) const {
    return new Operand<int16_t>(value, _Int16);
}

IOperand const * OperandFactory::createInt32( std::string const & value ) const {
    return new Operand<int32_t>(value, _Int32);
}

IOperand const * OperandFactory::createFloat( std::string const & value ) const {
    return new Operand<float>(value, _Float);
}

IOperand const * OperandFactory::createDouble( std::string const & value ) const {
    return new Operand<double>(value, _Double);
}