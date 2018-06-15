/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:53:29 by qmanamel          #+#    #+#             */
/*   Updated: 2018/06/15 15:08:55 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INT8_HPP
# define INT8_HPP

# include <cstdint>

# include "../IOperand.hpp"

class Int8 : public IOperand {
    public:
        Int8(int n);
        ~Int8(void);
        int getPrecision( void ) const;
        eOperandType getType( void ) const;
    private:
        int8_t              _value;
        eOperandType        _type;
        eOperandPrecision   _precision;
};

#endif