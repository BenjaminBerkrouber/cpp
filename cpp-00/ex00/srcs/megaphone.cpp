#include <iostream>

/*
 ** Program to display a string of characters by changing all lowercase letters to uppercase.
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
        std::string word(argv[i]);

        for (char &c : word)
        {
            if (std::islower(c))
                c = std::toupper(c);
            std::cout << c;
        }
        std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}