/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:08:38 by qmanamel          #+#    #+#             */
/*   Updated: 2018/07/06 14:42:18 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IOperand.hpp"

#ifndef OPERAND_HPP
#define OPERAND_HPP

class Operand: public IOperand {
    public:
        Operand();
        Operand(const Operand&);
        Operand(std::string const & value, eOperandType type, int precision);
        const Operand& operator=(const Operand&);
        ~Operand();

    private:
        Operand         _value();
        eOperandType    _type;
        int             _precision;
        std::string     _string;
};

#endif // !OPERAND_HPP