/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:13:36 by bberkrou          #+#    #+#             */
/*   Updated: 2024/06/04 08:50:09 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc [filename]" << std::endl;
        return 1;
    }

    std::cout << "data with potential for improvement (Bad Format)" << std::endl;
    BitcoinExchange exchange;
    std::cout << "-----------------------------------------------" << std::endl << std::endl;
    exchange.setMapWallets(argv[1]);

    exchange.displayWalletsValues();

    return 0;
}
