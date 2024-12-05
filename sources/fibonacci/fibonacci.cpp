// fibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <climits>


#define FIBONACCI_MAX_INPUT    95


unsigned long long fibonacci(int n, bool reuse = true) 
{ 
    if (n > 47 && sizeof(unsigned long long) == 4)
        throw std::overflow_error("O maior Fibonnaci calculável para 32 bits é o 47");

    if (n > 93 && sizeof(unsigned long long) == 8)
        throw std::overflow_error("O maior Fibonnaci calculável para 32 bits é o 93");

    if (reuse)
    {
        static unsigned long long previous[FIBONACCI_MAX_INPUT + 1];
        static bool initialized = false;
        
        if (!initialized)
        {
            previous[0] = 0;
            previous[1] = 1;
            for (int index = 2; index < FIBONACCI_MAX_INPUT; index++)
            {
                previous[index] = ULLONG_MAX;
            }

            initialized = true;
        }

        if (n < 2)
            return previous[n];

        previous[n - 1] = (previous[n - 1] == ULLONG_MAX) ? fibonacci(n - 1, true) : previous[n - 1];
        previous[n - 2] = (previous[n - 2] == ULLONG_MAX) ? fibonacci(n - 2, true) : previous[n - 2];

        return previous[n - 1] + previous[n - 2];
    }

    if (n == 0)
        return 0;

    return (n < 1) ? 1 : fibonacci(n - 1, false) + fibonacci(n - 2, false);
}

int main()
{
    std::cout << "Fibonacci" << std::endl << std::endl;

    std::cout << "sizeof(unsinged long long) = " << sizeof(unsigned long long) << std::endl << std::endl;
/*
    for (int n = 0; n < 95; n++)
    {
        std::cout << n << " : " << fibonacci(n, false) << std::endl;
        //unsigned long long result = fibonacci(n);
        //printf("%d : %llu\n", n, result);
    }
*/
    //std::cout << fibonacci(15) << std::endl;
    std::cout << fibonacci(42, false) << std::endl;
    std::cout << fibonacci(42, true ) << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
