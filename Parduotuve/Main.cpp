#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Product.h"

void showProducts(const std::vector<Product>& products)
{
    for (size_t i = 0; i < products.size(); i++) {
        std::cout << i + 1 << ". "
            << std::left << std::setw(10) << products[i].name
            << std::fixed << std::setprecision(2) << products[i].price << " EUR"
            << "   quantity: " << products[i].quantity << "\n";
    }
}

int main() {
	std::ofstream outputFile("products.txt");

    std::vector<Product> products =
    {
        { "Pienas", 1.20, 30 },
        { "Duona", 0.95, 15 },
        { "Suris", 4.50, 8 }
    };

    if (outputFile.is_open())
    {
        for (size_t i = 0; i < products.size(); i++)
        {
            outputFile << products[i].name << " " << products[i].price << " " << products[i].quantity << "\n";
        }
        outputFile << "Issaugota prekiu " << products.size() << "\n";
        outputFile.close();
        std::cout << "Duomenys sekmingai issaugoti i products.txt\n";
    }
    else
    {
		std::cout << "Nepavyko atidaryti failo products.txt\n";
    }

    int choice = -1;
    while (choice != 0)
    {
        std::cout << "\n=== Parduotuve ===\n";
        std::cout << "1. Show products\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            showProducts(products);
            break;
        case 0:
            std::cout << "Bye!\n";
            break;
        default:
            std::cout << "Unknown option.\n";
        }
    }
    return 0;
}