/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:08:38 by qmanamel          #+#    #+#             */
/*   Updated: 2018/07/06 16:29:17 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IOperand.hpp"

#ifndef OPERAND_HPP
#define OPERAND_HPP

template <typename T> class Operand: public IOperand {
    public:
        Operand();
        Operand( const & Operand _rhs );
        Operand( std::string const & value, eOperandType type, int precision );
        const Operand& operator=( const & Operand _new );
        ~Operand();

        int getPrecision( void ) const = 0;
        std::string const & toString( void ) const = 0;
        eOperandType getType( void ) const = 0;

        IOperand const * operator+( IOperand const & rhs ) const = 0;
        IOperand const * operator-( IOperand const & rhs ) const = 0;
        IOperand const * operator*( IOperand const & rhs ) const = 0;
        IOperand const * operator/( IOperand const & rhs ) const = 0;
        IOperand const * operator%( IOperand const & rhs ) const = 0;
    private:
        std::string     _value;
        eOperandType    _type;
        int             _precision;
        std::string     _string;
};

#endif // !OPERAND_HPP