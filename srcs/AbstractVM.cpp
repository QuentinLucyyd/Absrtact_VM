/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:23:55 by root              #+#    #+#             */
/*   Updated: 2018/07/08 15:38:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/AbstractVM.hpp"

AbstractVm::AbstractVm(){
    return ;
};

AbstractVm::AbstractVm(AbstractVm const &rhs) {
    this->_operations = rhs._operations;
};

AbstractVm::~AbstractVm() {
    return ;
}

void AbstractVm::readFromStdin( void ) {
    for (std::string line; std::getline(std::cin, line);) {
        this->_operations.push_back(line);
        if (line == ";;") {
            break;
        }
    }
}

void AbstractVm::readFromFile( std::string file) {
    std::ifstream progFile;

    progFile.open(file);
    if (!progFile) {
        throw AbstractVm::FilenotfoundException();
    } else if (progFile.peek() == std::ifstream::traits_type::eof()) {
        throw AbstractVm::FileemptyException();
    } else {
        for (std::string line; std::getline(progFile, line);) {
            this->_operations.push_back(line);
        }
        progFile.close();
    }
}

void AbstractVm::start( void ) {
    this->_lexer.runLexer(this->_operations);
}

/* Exceptions */

const char *AbstractVm::FilenotfoundException::what() const throw() {
    const char *err = "[Error (Code: 01)] Can't open file at the given path";
    return (err);
}

const char *AbstractVm::FileemptyException::what() const throw() {
    const char *err = "[Error (Code: 02)] File at given path is empty";
    return (err);
}