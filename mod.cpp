//Defines a modulus operator

#include "wet.h"

template<typename V>
V wet::mod(V a, V b)
{
    return (a % b + b) % b;
}