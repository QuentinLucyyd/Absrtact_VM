/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:42:06 by qmanamel          #+#    #+#             */
/*   Updated: 2018/07/07 20:15:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IOPERAND_HPP
# define IOPERAND_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <cstdint>
# include <list>

enum eOperandType {_Int8, _Int16, _Int32, _Float, _Double};

class IOperand {
    public:
        virtual int getPrecision( void ) const = 0;
        virtual eOperandType getType( void ) const = 0;
        virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
        virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
        virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
        virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
        virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
        virtual std::string const & toString( void ) const = 0;
        virtual ~IOperand( void ) {}
};

#endif // !IOPERAND_HPP
