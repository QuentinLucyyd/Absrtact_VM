/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:08:38 by qmanamel          #+#    #+#             */
/*   Updated: 2018/07/09 16:19:59 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
#define OPERAND_HPP

# include "IOperand.hpp"

template <typename T> class Operand: public IOperand {
    public:
        Operand();
        Operand( Operand const &src );
        Operand( T value, eOperandType type);
        ~Operand();

        int                         getPrecision( void ) const;
        std::string const &         toString( void ) const;
        eOperandType                getType( void ) const;

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

template <typename T>Operand<T>::Operand( T value, eOperandType type ) {
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
    if (this->getPrecision() > rhs.getPrecision()) {
        std::cout << "Return This" << std::endl;
    }

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

template <typename T>bool checkFlows(T value, eOperandType type) {
    switch (type) {
        case (_Int8):
            return (value > CHAR_MAX || value < CHAR_MIN);
        case (_Int16):
            return (value > SHRT_MAX || value < SHRT_MIN);
        case (_Int32):
            return (value > INT_MAX || value < INT_MIN);
        case (_Float):
            return (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min());
        case (_Double):
            return (value > std::numeric_limits<double>::max() || value < std::numeric_limits)
    }
    return (true);
}

#endif // !OPERAND_HPP