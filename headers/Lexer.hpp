/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:29:01 by root              #+#    #+#             */
/*   Updated: 2018/07/18 10:50:26 by qmanamel         ###   ########.fr       */
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
            ~LexerError() _NOEXCEPT;
        private:
            virtual const char *what() const throw();
            std::string _exceptions;
    };

    void    checkValue(std::string line, int lineCount);
    void    runLexer(std::list<std::string>& operations);
    void    createExceptions();
private:
    std::list<std::string>  _errList;
    std::list<std::string>  _allowedInstructions;
};

#endif //!LEXER_HPP