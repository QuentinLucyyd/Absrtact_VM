
#ifndef OPERAND_HPP
#define OPERAND_HPP

# include "OperandFactory.hpp"

template <typename T> class Operand: public IOperand {
    public:
        Operand( void ) {return ;}
        ~Operand( void ) {return ;}

        Operand(Operand const &src) {
            this->_value = src->_value;
            this->_type = src->_type;
            this->_string = src->_string;
        }

        Operand( T value, eOperandType type ) {
            this->_value = std::to_string(value);
            this->_type = type;
            this->_string = _value;
        }

        int getPrecision( void ) const {
            return (static_cast<int>(this->_type));
        }

        std::string const & toString( void ) const {
            return (this->_string);
        }

        eOperandType getType( void ) const {
            return (this->_type);
        }

        IOperand const * operator+( IOperand const & rhs ) const {
            OperandFactory  factory;
            IOperand const * retVal;
            if (this->getPrecision() < rhs.getPrecision()) {
                retVal = factory.createOperand(rhs.getType(), std::to_string(std::stold(this->toString()) + std::stold(rhs.toString())));
                long double v = std::stold(retVal->toString());
                if (checkFlows<long double>(v, this->getType())) {throw OperandError("[Operand] Overflow / Underflow detected");}
            } else {
                retVal = factory.createOperand(this->getType(), std::to_string(std::stold(this->toString()) + std::stold(rhs.toString())));
                long double v = std::stold(retVal->toString());
                if (checkFlows<long double>(v, this->getType())) { throw OperandError("[Operand] Overflow / Underflow detected"); }
            }
            return (retVal);
        }

        IOperand const *  operator-( IOperand const & rhs ) const {
            OperandFactory  factory;
            IOperand const * retVal;
            if (this->getPrecision() < rhs.getPrecision()) {
                retVal = factory.createOperand(rhs.getType(), std::to_string(std::stold(this->toString()) - std::stold(rhs.toString())));
                long double v = std::stold(retVal->toString());
                if (checkFlows<long double>(v, this->getType())) {throw OperandError("[Operand] Overflow / Underflow detected");}
            } else {
                retVal = factory.createOperand(this->getType(), std::to_string(std::stold(this->toString()) - std::stold(rhs.toString())));
                long double v = std::stold(retVal->toString());
                if (checkFlows<long double>(v, this->getType())) { throw OperandError("[Operand] Overflow / Underflow detected"); }
            }
            return (retVal);
        }

        IOperand const *  operator*( IOperand const & rhs ) const {
            OperandFactory  factory;
            IOperand const * retVal;
            if (this->getPrecision() < rhs.getPrecision()) {
                retVal = factory.createOperand(rhs.getType(), std::to_string(std::stold(this->toString()) * std::stold(rhs.toString())));
                long double v = std::stold(retVal->toString());
                if (checkFlows<long double>(v, this->getType())) {throw OperandError("[Operand] Overflow / Underflow detected");}
            } else {
                retVal = factory.createOperand(this->getType(), std::to_string(std::stold(this->toString()) * std::stold(rhs.toString())));
                long double v = std::stold(retVal->toString());
                if (checkFlows<long double>(v, this->getType())) { throw OperandError("[Operand] Overflow / Underflow detected"); }
            }
            return (retVal);
        }

        IOperand const *  operator/( IOperand const & rhs ) const {
            OperandFactory  factory;
            IOperand const * retVal;
            if (this->getPrecision() < rhs.getPrecision()) {
                retVal = factory.createOperand(rhs.getType(), std::to_string(std::stold(this->toString()) / std::stold(rhs.toString())));
                long double v = std::stold(retVal->toString());
                if (checkFlows<long double>(v, this->getType())) {throw OperandError("[Operand] Overflow / Underflow detected");}
            } else {
                retVal = factory.createOperand(this->getType(), std::to_string(std::stold(this->toString()) / std::stold(rhs.toString())));
                long double v = std::stold(retVal->toString());
                if (checkFlows<long double>(v, this->getType())) { throw OperandError("[Operand] Overflow / Underflow detected"); }
            }
            return (retVal);
        }

        IOperand const *  operator%( IOperand const & rhs ) const {
            return (this);
        }

        template <typename U>bool checkFlows(U value, eOperandType type) const {
            switch (type) {
                case (_Int8):
                    return (value > CHAR_MAX || value < CHAR_MIN);
                case (_Int16):
                    return (value > SHRT_MAX || value < SHRT_MIN);
                case (_Int32):
                    return (value > INT_MAX || value < INT_MIN);
                case (_Float):
                    return (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min());
                case (_Double):
                    return (value > std::numeric_limits<double>::max() || value < std::numeric_limits<double>::min());
            }
            return (true);
        }

    // !EXCEPTIONS
    class   OperandError : public std::exception {
        public:
            OperandError( std::string errMsg ): _errMsg(errMsg) { return ; }
            ~OperandError( void ) _NOEXCEPT { return ; }
        private:
            std::string _errMsg;
            virtual const char *what() const throw () {
                return _errMsg.c_str();
            }
    };
    private:
        std::string     _value;
        eOperandType    _type;
        std::string     _string;

};

#endif // !OPERAND_HPP