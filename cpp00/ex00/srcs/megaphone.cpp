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

        for (std::string::iterator it = word.begin(); it != word.end(); ++it)
        {
            if (std::islower(*it))
                *it = std::toupper(*it);
            std::cout << *it;
        }
        std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}