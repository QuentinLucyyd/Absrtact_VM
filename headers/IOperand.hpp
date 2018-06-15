/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:42:06 by qmanamel          #+#    #+#             */
/*   Updated: 2018/06/15 15:08:29 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IOPERAND_HPP
# define IOPERAND_HPP

# include <iostream>
# include <cstdint>


enum eOperandType {_Int8, _Int16, _Int32, _Float, _Double};
enum eOperandPrecision {eOint8_t,eOint16_t,eOint32_t,eOfloat,eOdouble};

class IOperand {
    public:
        virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
        virtual eOperandType getType( void ) const = 0; // Type of the instance
        // virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
        // virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
        // virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
        // virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
        // virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
        // virtual std::string const & toString( void ) const = 0; // String representation of the instance
        virtual ~IOperand( void ) {}
};

#endif // !IOPERAND_HPP
