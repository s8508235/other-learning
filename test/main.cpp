#include <iostream>
#include "function.h"

int main()
{
    Block b{4, "@OO@" "OOOO" "OOOO" "@OO@"}; // create a 4x4 pattern, which is rotation invariant
    /*std::cout << b << std::endl;*/

    if (invariant(b)) // checking if two patterns are equivalent under rotation
        std::cout << "INVARIANT" << std::endl;
    else
        std::cout << "VARIANT" << std::endl;

    Block c{4, "@XX@" "OOOO" "OOOO" "@OO@"}; // create a 4x4 pattern, which is rotation variant
    /*std::cout << c << std::endl;*/

    if (invariant(c)) // checking if two patterns are equivalent under rotation
        std::cout << "INVARIANT" << std::endl;
    else
        std::cout << "VARIANT" << std::endl;

}
