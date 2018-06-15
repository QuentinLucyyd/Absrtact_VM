/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:12:25 by qmanamel          #+#    #+#             */
/*   Updated: 2018/06/15 13:39:15 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INT32_HPP
# define INT32_HPP

# include <cstdint>

# include "../IOperand.hpp"

class Int32 : public IOperand {
    public:
        Int32(int n);
        ~Int32(void);
    private:
        int32_t             _value;
        eOperandType        _type;
        eOperandPrecision   _precision;
};

#endif