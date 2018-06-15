/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:59:40 by qmanamel          #+#    #+#             */
/*   Updated: 2018/06/15 15:13:15 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/IOperand.hpp"
#include "../headers/operands/Int8.hpp"
#include "../headers/operands/Int16.hpp"
#include "../headers/operands/Int32.hpp"
#include "../headers/operands/Float.hpp"
#include "../headers/operands/Double.hpp"

int main(){
    Int8    _int16(10);
    std::cout << _int16.getType();
    std::cout << _int16.getPrecision();
}