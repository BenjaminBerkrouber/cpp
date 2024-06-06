/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:13:36 by bberkrou          #+#    #+#             */
/*   Updated: 2024/06/05 18:28:15 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

static void printData(const Data* data)
{
    if (data) {
        std::cout << "  Data Adress =>  [" << data << "]" << std::endl;
        std::cout << "  Data Values =>  "
                << "s1: {" << std::left << std::setw(15) << data->s1 << "} "
                << "n: {" << std::left << std::setw(15) << data->n << "} "
                << "s2: {" << std::left << std::setw(15) << data->s2 << "}"
                << std::endl;
    } else
        std::cout << RED << "Data is null" << RESET << std::endl;
}

static void updateData(Data* data, const std::string& s1, int n, const std::string& s2)
{
    data->s1 = s1;
    data->n = n;
    data->s2 = s2;
}

int main(void)
{
    // The next line will not compile because the constructor is private
    // Serializer serializer;

	Data data1 = {"Hello", 42, "World"};
    Data data2 = {"Edge", 2147483647, "Case"};
    Data data3 = {"Baz", 123, ""};
    Data data4 = {"Test", -1, "Negative"};


    std::vector<Data*> dataset;
    dataset.push_back(&data1);
    dataset.push_back(&data2);
    dataset.push_back(&data3);
    dataset.push_back(&data4);

    std::vector<uintptr_t> rawPointers;
    std::vector<Data*> deserializedData;

    for (size_t i = 0; i < dataset.size(); ++i) {
        uintptr_t raw = Serializer::serialize(dataset[i]);
        rawPointers.push_back(raw);
    }

    for (size_t i = 0; i < rawPointers.size(); ++i) {
        Data* data = Serializer::deserialize(rawPointers[i]);
        deserializedData.push_back(data);
    }

    std::cout << std::endl << BLUE << "═════════════════════════╗    Orignial DATA    ╔═══════════════════════════" << RESET << std::endl << std::endl;
    std::cout << PURPLE << "-----  Original Data  -----" << RESET << std::endl;
    for (size_t i = 0; i < dataset.size(); ++i) {
        printData(dataset[i]);
    }

    std::cout << std::endl << PURPLE << "-----  Deserialized Data  -----" << RESET << std::endl;
    for (size_t i = 0; i < deserializedData.size(); ++i) {
        printData(deserializedData[i]);
    }

    updateData(&data1, "Bonjour", 21, "Monde");
    updateData(&data2, "Bord", 0, "Cote");
    updateData(&data3, "Foo", 456, "Bar");
    updateData(&data4, "Test", 0, "Zero");

    std::cout << std::endl << BLUE << "═════════════════════════╗    Update DATA    ╔═══════════════════════════" << RESET << std::endl << std::endl;
    std::cout << PURPLE << "-----  Original Update Data  -----" << RESET << std::endl;
    for (size_t i = 0; i < dataset.size(); ++i) {
        printData(dataset[i]);
    }

    std::cout << std::endl << PURPLE << "-----  Deserialized Data  -----" << RESET << std::endl;
    for (size_t i = 0; i < deserializedData.size(); ++i) {
        printData(deserializedData[i]);
    }

    std::cout << std::endl << BLUE << "═════════════════════════╗    NULL DATA    ╔═══════════════════════════" << RESET << std::endl << std::endl;
    Data* nullData = NULL;
    uintptr_t nullRaw = Serializer::serialize(nullData);
    Data* deserializedNullData = Serializer::deserialize(nullRaw);

    std::cout << PURPLE << "-----  Testing  -----" << RESET << std::endl;
    printData(deserializedNullData);

    return 0;
}