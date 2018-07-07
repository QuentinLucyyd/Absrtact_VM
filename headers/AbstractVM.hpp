/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:16:39 by root              #+#    #+#             */
/*   Updated: 2018/07/07 20:48:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP

#include "OperandFactory.hpp"

class AbstractVm {
public:
    AbstractVm();
    AbstractVm(AbstractVm const &rhs);
    ~AbstractVm();

    class FilenotfoundException : public std::exception {
        virtual const char* what() const throw();
    };
    class FileemptyException : public std::exception {
        virtual const char* what() const throw();
    };

    void readFromStdin( void );
    void readFromFile( std::string file);
private:
    std::list<std::string> _operations;
};

#endif