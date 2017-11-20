#ifndef HELPFUL_HPP_INCLUDED
#define HELPFUL_HPP_INCLUDED
#include "System/LibrariesIncluding.hpp"
#include <sstream>

namespace RhA{
    template<typename T>
    std::string toString(T var){
        std::stringstream stream;
        stream << var;

        return stream.str();
    }
}

#endif // HELPFUL_HPP_INCLUDED
