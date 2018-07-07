/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:29:18 by qmanamel          #+#    #+#             */
/*   Updated: 2018/07/07 13:45:28 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDFACTORY_HPP
#define OPERANDFACTORY_HPP

#include "Operand.hpp"

class OperandFactory {
    public:
        OperandFactory();
        OperandFactory(const OperandFactory&);
        const OperandFactory& operator=(const OperandFactory&);
        IOperand const * createOperand( eOperandType type, std::string const & value ) const;
        ~OperandFactory();

    private:
        std::map<eOperandType, IOperand const *(OperandFactory::*)(std::string const & value) const> operand;

        IOperand const * createInt8( std::string const & value ) const;
        IOperand const * createInt16( std::string const & value ) const;
        IOperand const * createInt32( std::string const & value ) const;
        IOperand const * createFloat( std::string const & value ) const;
        IOperand const * createDouble( std::string const & value ) const;
};

#endif // !OPERANDFACTORY_HPP