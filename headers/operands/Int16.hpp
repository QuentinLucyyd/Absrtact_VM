/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:11:18 by qmanamel          #+#    #+#             */
/*   Updated: 2018/06/15 13:38:59 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INT16_HPP
# define INT16_HPP

# include <cstdint>

# include "../IOperand.hpp"

class Int16 : public IOperand {
    public:
        Int16(int n);
        ~Int16(void);
    private:
        int16_t             _value;
        eOperandType        _type;
        eOperandPrecision   _precision;
};

#endif