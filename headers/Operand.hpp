/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:08:38 by qmanamel          #+#    #+#             */
/*   Updated: 2018/07/09 13:59:24 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
#define OPERAND_HPP

# include "IOperand.hpp"

template <typename T> class Operand: public IOperand {
    public:
        Operand();
        Operand( Operand const &src );
        Operand( T value, eOperandType type , long double valueMax, long double valueMin);
        ~Operand();

        long double      valueMax( void );
        long double      valueMin( void );

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

        long double     _valueMax;
        long double     _valueMin;
};

template <typename T>Operand<T>::Operand( void ) {return ;}
template <typename T>Operand<T>::~Operand( void ) {return ;}

template <typename T>Operand<T>::Operand(Operand const &src) {
    this->_value = src->_value;
    this->_type = src->_type;
    this->_string = src->_string;
}

template <typename T>Operand<T>::Operand( T value, eOperandType type , long double valueMax, long double valueMin ) {
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
    if (this->getPrecision() < rhs.getPrecision()) {
        std::cout << "Precision Checking" << std::endl;
    }
    std::cout << "NO CHecking" << std::endl;
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

template <typename T> long double Operand<T>::valueMax( void ) { return (this->_valueMax);}

template <typename T> long double Operand<T>::valueMin( void ) { return (this->_valueMin);}

void             checkFlows(IOperand const &rhs, std::string op) {
}
#endif // !OPERAND_HPP