/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 19:43:16 by root              #+#    #+#             */
/*   Updated: 2018/07/08 19:50:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Parser.hpp"

Parser::Parser() {
    return ;
}
Parser::~Parser() {
    return ;
}

void    Parser::runParser(std::list<std::string> operations) {
    OperandFactory factory;

    for(std::list<std::string>::iterator i = operations.begin(); i != operations.end(); ++i) {
        std::string line =  *i;
        std::cout << line << std::endl;
    }
}