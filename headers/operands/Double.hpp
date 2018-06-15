/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:31:49 by qmanamel          #+#    #+#             */
/*   Updated: 2018/06/15 14:32:30 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DOUBLE_HPP
# define DOUBLE_HPP

# include <cstdint>

# include "../IOperand.hpp"

class Double : public IOperand {
    public:
        Double(int n);
        ~Double(void);
    private:
        double              _value;
        eOperandType        _type;
        eOperandPrecision   _precision;
};

#endif