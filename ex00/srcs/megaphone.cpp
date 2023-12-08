#include <iostream>

/*
** 1. Write a program that takes a string and displays it, replacing each of its
*/
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                argv[i][j] = toupper(argv[i][j]);
            std::cout << argv[i][j];
        }
        std::cout << " ";
    }
    std::cout << std::endl;
    return (EXIT_SUCCESS);
}