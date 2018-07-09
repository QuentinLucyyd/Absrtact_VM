/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:08:38 by qmanamel          #+#    #+#             */
/*   Updated: 2018/07/09 10:40:45 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
#define OPERAND_HPP

# include "IOperand.hpp"

template <typename T> class Operand: public IOperand {
    public:
        Operand();
        Operand( Operand const &src );
        Operand( T value, eOperandType type );
        ~Operand();

        int getPrecision( void ) const;
        std::string const & toString( void ) const;
        eOperandType getType( void ) const;

        IOperand const * operator+( IOperand const & rhs ) const;
        IOperand const * operator-( IOperand const & rhs ) const;
        IOperand const * operator*( IOperand const & rhs ) const;
        IOperand const * operator/( IOperand const & rhs ) const;
        IOperand const * operator%( IOperand const & rhs ) const;
    private:
        std::string     _value;
        eOperandType    _type;
        std::string     _string;
};

template <typename T>Operand<T>::Operand( void ) {return ;}
template <typename T>Operand<T>::~Operand( void ) {return ;}

template <typename T>Operand<T>::Operand(Operand const &src) {
    this->_value = src->_value;
    this->_type = src->_type;
    this->_string = src->_string;
}

template <typename T>Operand<T>::Operand(T value, eOperandType type) {
    this->_value = std::to_string(value);
    this->_type = type;
    this->_string = _value;
}

template <typename T> int Operand<T>::getPrecision( void ) const {
    return (static_cast<int>(this->_type));
}

template <typename T> std::string const & Operand<T>::toString( void ) const {
    return (this->_string);
}

template <typename T> eOperandType Operand<T>::getType( void ) const {
    return (this->_type);
}

template <typename T> IOperand const * Operand<T>::operator+( IOperand const & rhs ) const {
    return (this);
}

template <typename T> IOperand const *  Operand<T>::operator-( IOperand const & rhs ) const {
    return (this);
}
template <typename T> IOperand const *  Operand<T>::operator*( IOperand const & rhs ) const {
    return (this);
}
template <typename T> IOperand const *  Operand<T>::operator/( IOperand const & rhs ) const {
    return (this);
}
template <typename T> IOperand const *  Operand<T>::operator%( IOperand const & rhs ) const {
    return (this);
}

#endif // !OPERAND_HPP