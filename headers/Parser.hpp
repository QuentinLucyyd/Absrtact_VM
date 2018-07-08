/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 19:19:54 by root              #+#    #+#             */
/*   Updated: 2018/07/08 19:23:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "OperandFactory.hpp"

class Parser {
public:
    Parser();
    ~Parser();

    void    runParser(std::list<string> operations);
private:
    std::list<IOperand const *> _stack;
};

#endif //!PARSER_HPP
