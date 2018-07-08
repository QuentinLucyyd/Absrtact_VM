/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:29:01 by root              #+#    #+#             */
/*   Updated: 2018/07/08 17:44:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
#define LEXER_HPP

#include "OperandFactory.hpp"

class Lexer{
public:
    Lexer();
    ~Lexer();

    class LexerError : public std::exception {
        public:
            LexerError(std::list<std::string> errList);
            ~LexerError();
        private:
            virtual const char *what() const throw();
            std::string _exceptions;
    };

    void    runLexer(std::list<std::string> operations);
    void    createExceptions();
private:
    std::list<std::string>  _errList;
    std::list<std::string>  _allowedInstructions;
};

#endif //!LEXER_HPP