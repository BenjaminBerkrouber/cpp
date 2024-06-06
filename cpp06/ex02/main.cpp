/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:13:36 by bberkrou          #+#    #+#             */
/*   Updated: 2024/06/06 13:36:04 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    int random = rand() % 3;

    std::cout << "Random Base created" << std::endl;
    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else
        return new C;
}

void identify(Base *p)
{
    std::cout << "  Ptr => [";
    if (dynamic_cast<A *>(p))
        std::cout << "A]" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B]" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C]" << std::endl;
    else
        std::cout << "Unknown]" << std::endl;
}

void    identify(Base &p)
{
    std::cout << "  Ref => [";
    try {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A]" << std::endl;
    } catch (std::exception &bc) {
        try {
            B &b = dynamic_cast<B &>(p);
            (void)b;
            std::cout << "B]" << std::endl;
        } catch (std::exception &bc) {
            try {
                C &c = dynamic_cast<C &>(p);
                (void)c;
                std::cout << "C]" << std::endl;
            } catch (std::exception &bc) {
                std::cout << "Unknown]" << std::endl;
            }
        }
    }
}

void    processBase() {
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
}

int main()
{
    srand(time(NULL));
    std::cout << std::endl << BLUE << "═════════════════════════╗    Standard Testing    ╔═══════════════════════════" << RESET << std::endl << std::endl;
    for (int i = 0; i < 10; i++)
        processBase();

    std::cout << std::endl << BLUE << "═════════════════════════╗    Wrong Testing    ╔═══════════════════════════" << RESET << std::endl << std::endl;
    Base *base = new Base;
    std::cout << "Base created" << std::endl;
    identify(base);
    identify(*base);
    delete base;

    std::cout << std::endl << BLUE << "═════════════════════════╗    Null Testing    ╔═══════════════════════════" << RESET << std::endl << std::endl;

    Base *null = NULL;
    std::cout << "Null Base created" << std::endl;
    identify(null);
    identify(*null);

    return 0;
}