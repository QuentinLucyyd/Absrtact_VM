/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:59:40 by qmanamel          #+#    #+#             */
/*   Updated: 2018/07/08 14:40:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/OperandFactory.hpp"
#include "../headers/AbstractVM.hpp"

int main(int argc, char **argv){
    try { 
        AbstractVm _mainProgram;

        if (argc < 2) {
            _mainProgram.readFromStdin();
        } else if (argc == 2) {
            _mainProgram.readFromFile(argv[1]);
        }
        _mainProgram.start();
    } catch (std::exception & e) {
        std::cout << "AbstractVM: " << e.what() << std::endl;
    }
}