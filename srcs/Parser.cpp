#include "../headers/Parser.hpp"

Parser::Parser():_lineCount(0) {
    return ;
}

Parser::~Parser() {
    return ;
}

static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
}

void               Parser::runParser(std::list<std::string>& operations) {
    for(std::list<std::string>::iterator i = operations.begin(); i != operations.end(); ++i) {
        this->_lineCount++;
        std::string line =  *i;

        if (line.substr(0, line.find(" ")) == "push") { this->push(line); }
        if (line.substr(0, line.find(" ")) == "pop") {this->pop();}
        if (line.substr(0, line.find(" ")) == "dump") {this->dump();}
        if (line.substr(0, line.find(" ")) == "add") {this->add();}
        if (line.substr(0, line.find(" ")) == "sub") {this->sub();}
        if (line.substr(0, line.find(" ")) == "mul") {this->mul();}
        if (line.substr(0, line.find(" ")) == "div") {this->div();}
        if (line.substr(0, line.find(" ")) == "mod") {this->mod();}
        if (line.substr(0, line.find(" ")) == "print") {this->print();}
        if (line.substr(0, line.find(" ")) == "assert") {this->assert(line);}
    }
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
    rtrim(operandType);
    ltrim(operandType);
    std::string value = instruction.substr(instruction.find("(") + 1, instruction.size());
    value.resize(value.size() - 1);
    this->_stack.push_front(this->_factory.createOperand(getOperandValue(operandType), value));
}

void              Parser::pop( void ) {
    if (!this->_stack.size()) {
        std::string errMsg = "[Parser (line: " + std::to_string(this->_lineCount) + " ) Illegal instruction: 'pop' on empty stack";
        throw Parser::PopOnEmptyStack(errMsg);
    } else { this->_stack.pop_front(); }
}

void              Parser::dump( void ) {
    if (!this->_stack.size()) {
        std::string errMsg = "[Parser (line: " + std::to_string(this->_lineCount) + " ) Illegal instruction: 'dump' on an empty stack";
        throw Parser::PopOnEmptyStack(errMsg);
    }
    for (std::list<IOperand const *>::iterator i = this->_stack.begin(); i != this->_stack.end(); ++i) {
        if ((*i)->getType() == _Float || (*i)->getType() == _Double) {
            std::cout << std::stold((*i)->toString()) << std::endl;
        } else {
           std::cout << std::stold((*i)->toString()) << std::endl;
        }
    }
}

void                Parser::print( void ) {
    if (!this->_stack.size()) {
        std::string errMsg = "[Parser (line: " + std::to_string(this->_lineCount) + " ) Illegal instruction: Stack not large enough for 'print'";
        throw Parser::PopOnEmptyStack(errMsg);
    }
    IOperand const * printVal = (*this->_stack.begin());
    if (printVal->getType() != _Int8) {
        std::string errMsg = "[Parser (line: " + std::to_string(this->_lineCount) + " ) Illegal instruction: top stack val is not an 8-bit integer";
        throw Parser::PopOnEmptyStack(errMsg);
    } else {
        int val =  std::stoi(printVal->toString());
        std::cout << static_cast<char>(val) << std::endl;
    }
}

void                Parser::add( void ) {
    if (this->_stack.size() < 2) {
        std::string errMsg = "[Parser (line: " + std::to_string(this->_lineCount) + " ) Illegal instruction: Stack not large enough for 'add'";
        throw Parser::PopOnEmptyStack(errMsg);
    }
    IOperand const * _addVal1 = (*this->_stack.begin());
    this->_stack.pop_front();
    IOperand const * _addVal2 = (*this->_stack.begin());
    this->_stack.pop_front();
    //std::cout << "Adding: " << _addVal1->toString() + " Of Type " << _addVal1->getType() << " To: " <<  _addVal2->toString() << " Of Type " << _addVal2->getType() << " In Line " << this->_lineCount << std::endl;
    IOperand const *retVal = *_addVal2 + *_addVal1;
    this->_stack.push_front(retVal);
}

void                Parser::mul( void ) {
    if (this->_stack.size() < 2) {
        std::string errMsg = "[Parser (line: " + std::to_string(this->_lineCount) + " ) Illegal instruction: Stack not large enough for 'mul'";
        throw Parser::PopOnEmptyStack(errMsg);
    }
    IOperand const * _addVal1 = (*this->_stack.begin());
    this->_stack.pop_front();
    IOperand const * _addVal2 = (*this->_stack.begin());
    this->_stack.pop_front();
    IOperand const *retVal = *_addVal2 * *_addVal1;
    this->_stack.push_front(retVal);
}

void                Parser::sub( void ) {
    if (this->_stack.size() < 2) {
        std::string errMsg = "[Parser (line: " + std::to_string(this->_lineCount) + " ) Illegal instruction: Stack not large enough for 'mul'";
        throw Parser::PopOnEmptyStack(errMsg);
    }
    IOperand const * _addVal1 = (*this->_stack.begin());
    this->_stack.pop_front();
    IOperand const * _addVal2 = (*this->_stack.begin());
    this->_stack.pop_front();
    IOperand const *retVal = *_addVal2 - *_addVal1;
    this->_stack.push_front(retVal);
}
void                Parser::div( void ) {
    if (this->_stack.size() < 2) {
        std::string errMsg = "[Parser (line: " + std::to_string(this->_lineCount) + " ) Illegal instruction: Stack not large enough for 'div'";
        throw Parser::PopOnEmptyStack(errMsg);
    }
    IOperand const * _addVal1 = (*this->_stack.begin());
    this->_stack.pop_front();
    IOperand const * _addVal2 = (*this->_stack.begin());
    this->_stack.pop_front();
    if (!std::stold(_addVal1->toString())) {
        std::string errMsg = "[Parser (line: " + std::to_string(this->_lineCount) + " ) Illegal Operation: divisor is equal to 0";
        throw Parser::PopOnEmptyStack(errMsg);
    }
    IOperand const *retVal = *_addVal2 / *_addVal1;
    //std::cout << "Divisor : " << std::stold(_addVal2->toString()) << std::endl;
    this->_stack.push_front(retVal);
}

void                Parser::mod( void ) {
    if (this->_stack.size() < 2) {
        std::string errMsg = "[Parser (line: " + std::to_string(this->_lineCount) + " ) Illegal instruction: Stack not large enough for 'div'";
        throw Parser::PopOnEmptyStack(errMsg);
    }
    IOperand const * _addVal1 = (*this->_stack.begin());
    this->_stack.pop_front();
    IOperand const * _addVal2 = (*this->_stack.begin());
    this->_stack.pop_front();
    if (!std::stold(_addVal1->toString())) {
        std::string errMsg = "[Parser (line: " + std::to_string(this->_lineCount) + " ) Illegal Operation: divisor is equal to 0";
        throw Parser::PopOnEmptyStack(errMsg);
    }
    IOperand const *retVal = *_addVal2 % *_addVal1;
    this->_stack.push_front(retVal);
}

void                Parser::assert( std::string line ) {
    if (!this->_stack.size()) {
        std::string errMsg = "[Parser (line: " + std::to_string(this->_lineCount) + " ) Illegal instruction: 'assert' on an empty stack";
        throw Parser::PopOnEmptyStack(errMsg);
    }
    IOperand const * assertVal = (*this->_stack.begin());
    eOperandType assertCheckType;

    std::string instruction = line.substr(line.find(" ") + 1, line.find(")"));
    std::string operandType = instruction.substr(0, instruction.find("("));
    std::string value = instruction.substr(instruction.find("(") + 1, instruction.size());
    value.resize(value.size() - 1);

    if (operandType == "int8") { assertCheckType = _Int8; }
    else if (operandType == "int16") { assertCheckType = _Int16; }
    else if (operandType == "int32") { assertCheckType = _Int32; }
    else if (operandType == "float") { assertCheckType = _Float; }
    else { assertCheckType = _Double; }

    if(assertCheckType != assertVal->getType()) {
        std::string errMsg = "[Parser (line: " + std::to_string(this->_lineCount) + " ) 'assert' Operand types don't match";
        throw Parser::PopOnEmptyStack(errMsg);
    }
    if (std::stold(value) != std::stold(assertVal->toString())) {
        std::string errMsg = "[Parser (line: " + std::to_string(this->_lineCount) + " ) 'assert' value does not match top value in stack";
        throw Parser::PopOnEmptyStack(errMsg);
    }
}

template <typename U>bool checkFlows(U value, eOperandType type) {
    switch (type) {
        case (_Int8):
            //std::cout << "CHAR" << std::endl;
            return (value > CHAR_MAX || value < CHAR_MIN);
        case (_Int16):
            //std::cout << "SHRT" << std::endl;
            return (value > SHRT_MAX || value < SHRT_MIN);
        case (_Int32):
            //std::cout << "INT" << std::endl;
            return (value > INT_MAX || value < INT_MIN);
        case (_Float):
            //std::cout << "FLOAT" << std::endl;
            return (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min());
        case (_Double):
            //std::cout << "DOUBLE" << std::endl;
            return (value > std::numeric_limits<double>::max() || value < std::numeric_limits<double>::min());
    }
    return (true);
}

// !EXCEPTIONS

Parser::PopOnEmptyStack::PopOnEmptyStack( std::string errMsg ) {
    _errMsg = errMsg;
}

Parser::PopOnEmptyStack::~PopOnEmptyStack() throw() { return ;}

const char*Parser::PopOnEmptyStack::what() const throw() { 
    return _errMsg.c_str();
}