/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:13:09 by qmanamel          #+#    #+#             */
/*   Updated: 2018/06/15 13:38:39 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FLOAT_HPP
# define FLOAT_HPP

# include <cstdint>

# include "../IOperand.hpp"

class Float : public IOperand {
    public:
        Float(int n);
        ~Float(void);
    private:
        float               _value;
        eOperandType        _type;
        eOperandPrecision   _precision;
};

#endif