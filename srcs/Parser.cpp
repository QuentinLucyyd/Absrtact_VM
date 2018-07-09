/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 19:43:16 by root              #+#    #+#             */
/*   Updated: 2018/07/09 10:28:08 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Parser.hpp"

Parser::Parser():_lineCount(0) {
    return ;
}
Parser::~Parser() {
    return ;
}

void               Parser::runParser(std::list<std::string>& operations) {
    for(std::list<std::string>::iterator i = operations.begin(); i != operations.end(); ++i) {
        this->_lineCount++;
        std::string line =  *i;

        if (line.substr(0, line.find(" ")) == "push") { this->push(line); }
        if (line.substr(0, line.find(" ")) == "pop") {this->pop();}
        if (line.substr(0, line.find(" ")) == "dump") {this->dump();}
    }
    std::cout << "Stack Size: " << this->_stack.size() << std::endl;
}

eOperandType        Parser::getOperandValue(std::string operandType) {
    if (operandType == "int8") {return _Int8;}
    if (operandType == "int16") {return _Int16;}
    if (operandType == "int32") {return _Int32;}
    if (operandType == "float") {return _Float;}
    return _Double;
}

void              Parser::push( std::string line ) {
    std::string instruction = line.substr(line.find(" ") + 1, line.find(")"));
    std::string operandType = instruction.substr(0, instruction.find("("));
    std::string value = instruction.substr(instruction.find("(") + 1, instruction.size());
    value.resize(value.size() - 1);
    this->_stack.push_front(this->_factory.createOperand(getOperandValue(operandType), value));
}

void              Parser::pop( void ) {
    if (!this->_stack.size()) {
        throw Parser::PopOnEmptyStack(std::to_string(this->_lineCount));
    } else { this->_stack.pop_front(); }
}

void              Parser::dump( void ) {
    for (std::list<IOperand const *>::iterator i = this->_stack.begin(); i != this->_stack.end(); ++i) {
        std::cout << (*i)->toString() << std::endl;
    }
}

// !EXCEPTIONS

Parser::PopOnEmptyStack::PopOnEmptyStack( std::string line ) { _errLine = line; }

Parser::PopOnEmptyStack::~PopOnEmptyStack() throw() { return ;}

const char*Parser::PopOnEmptyStack::what() const throw() { 
    std::string errMsg = "[Parser (line: " + _errLine + ")] Illegal instruction: Pop on empty stack";
    return errMsg.c_str();
}