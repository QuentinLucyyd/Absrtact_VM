/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:34:16 by root              #+#    #+#             */
/*   Updated: 2018/07/09 10:03:15 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Lexer.hpp"

Lexer::Lexer(){
    this->_allowedInstructions.push_back("pop");
    this->_allowedInstructions.push_back("push");
    this->_allowedInstructions.push_back("assert");
    this->_allowedInstructions.push_back("add");
    this->_allowedInstructions.push_back("sub");
    this->_allowedInstructions.push_back("mul");
    this->_allowedInstructions.push_back("div");
    this->_allowedInstructions.push_back("mod");
    this->_allowedInstructions.push_back("print");
    this->_allowedInstructions.push_back("exit");
    this->_allowedInstructions.push_back("dump");
    return ;
};

Lexer::~Lexer(){
    return ;
};

static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
}

void    Lexer::runLexer(std::list<std::string>& operations) {

    int lineCount = 0;
    for(std::list<std::string>::iterator i = operations.begin(); i != operations.end(); ++i) {
        lineCount++;
        ltrim(*i);
        rtrim(*i);

        std::string line = *i;
        if (line.substr(0, 1) != ";") {
            if (!(std::find(this->_allowedInstructions.begin(), this->_allowedInstructions.end(),
            line.substr(0, line.find(" "))) != this->_allowedInstructions.end())) {
                this->_errList.push_back("[Lexer (line: " + std::to_string(lineCount) +
                ")] '" + line.substr(0, line.find(" ")) + "' Unknown instruction.");
            } else if (line.substr(0,line.find(" ")) == "push") {
                if ((std::count(line.begin(), line.end(), '(')) > 1 || (std::count(line.begin(), line.end(), ')')) > 1) {
                    this->_errList.push_back("[Lexer (line: " + std::to_string(lineCount) +
                    ")] '" + line + "' Too many parantheses.");
                } else if ((std::count(line.begin(), line.end(), '(')) < 1 || (std::count(line.begin(), line.end(), ')')) < 1) {
                    this->_errList.push_back("[Lexer (line: " + std::to_string(lineCount) +
                    ")] '" + line + "' Missing parantheses.");
                }
            }
        }
    }

    if(!this->_errList.empty()) {
        throw Lexer::LexerError(this->_errList);
    }
}

/* Exceptions */

Lexer::LexerError::LexerError(std::list<std::string> errList) {
    for(std::list<std::string>::iterator i = errList.begin(); i != errList.end(); ++i) {
        _exceptions += (*i + '\n');
    }
}

Lexer::LexerError::~LexerError() throw(){ return ; }

const char *Lexer::LexerError::what() const throw() {
    return this->_exceptions.c_str();
}