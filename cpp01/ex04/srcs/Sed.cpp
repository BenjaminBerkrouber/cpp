/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:33:54 by bberkrou          #+#    #+#             */
/*   Updated: 2024/04/10 21:36:28 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils.h"
# include "Sed.hpp"

// ------------- Constructors -------------

Sed::Sed(std::string filename, std::string s1, std::string s2)
    : _filename(filename), _s1(s1), _s2(s2) {
		
}

// ------------- Destructors -------------

Sed::~Sed() {
	
}

// ------------- Methods -------------

void Sed::readFile() {
    std::ifstream file(_filename.c_str());
    std::string outputFilename;

    if (!file.is_open()) {
        std::cout << "Error: Unable to open file " << _filename << std::endl;
        return;
    }

    outputFilename = _filename + "_replace";
    std::ofstream outputFile(outputFilename.c_str());

    if (file.is_open() && outputFile.is_open()) {
        while (getline(file, _line)) {
            size_t pos = 0;
            while ((pos = _line.find(_s1, pos)) != std::string::npos) {
                if (_s1.length() == 0)
                    break;
                _line.replace(pos, _s1.length(), _s2);
                pos += _s2.length();
            }
            outputFile << _line << std::endl;
        }
        file.close();
        outputFile.close();
    } else {
        if (!file.is_open()) {
            std::cout << "Error: Unable to open file " << _filename << std::endl;
        }
        if (!outputFile.is_open()) {
            std::cout << "Error: Unable to create file " << outputFilename << std::endl;
        }
    }
}
