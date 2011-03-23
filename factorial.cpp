#include "Integer.h"
#include "UInteger.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int main2(int argc, char *argv[])
{
    long l1;
    cin >> l1;

    UInteger  j((long)1,10);
    // test factorial using operator*=(UInteger const&)
    for (long i =1; i<l1; ++i)
    {
        j = j * i;
        std::cout << i << "! =" << j << "\n";
    }
    j = j * l1;
    std::cout << l1<< "! =" << j << "\n";
    return EXIT_SUCCESS;
}


