
#include <iostream>
#include <locale>


extern bool impar(long numero);


int main()
{
    std::locale::global(std::locale("pt_BR.UTF-8"));
    std::cout.imbue(std::locale());

    int numbers[] = { 5, 7, 8, 3, 10 };

    for(int index = 0; index < sizeof(numbers) / sizeof(int); index++)
    { 
        std::cout << numbers[index];
        std::cout << " é ";
        std::cout << (impar((long)numbers[index]) ? "ímpar" : "par");
        std::cout << std::endl;
    }
 
    return 0;
}

