//
// Created by Kihachu on 12/14/2023.
//
// TODO: improve user experience
// TODO: improvе error output, no idea how to do it better yet
#include "ConsoleUI.h"
#include <iostream>
#include <limits>
void ConsoleUI::displayMenu() {
    std::cout << "Select action:\n";
    std::cout << "=================================\n";
    std::cout << "1. Add a product\n";
    std::cout << "2. Remove a product\n";
    std::cout << "3. Show refrigerator contents\n";
    std::cout << "4. Find a product(Work in progress)2\n";
    std::cout << "5. Load a fridge\n";
    std::cout << "6. Save a current fridge\n";
    std::cout << "7. Exit\n";
    std::cout << "=================================\n";
    std::cout << "Your choice is: ";
}

void ConsoleUI::handleCommand(int command, Inventory &inventory, FileManager &fileManager) {
    try {
        switch (command) {
            case 1: {
                Product product = promptForProduct();
                inventory.addProduct(product);
                break;
            }
            case 2: {
                displayProductsAndRemove(inventory);
                break;
            }
            case 3:
                inventory.displayContents();
                break;
            case 4:
                break;
            case 5:
                loadInventory(inventory, fileManager);
                break;
            case 6:
                saveInventory(inventory, fileManager);
                break;
            case 7:
                std::cout << "Quitting the program.\n";
                exit(0);
            default:
                //clearScreen(); doesnt work at the moment
                std::cout << "Unknown command.\n";
    }

    } catch (const std::exception &e){
        std::cerr << "Error: " << e.what() << '\n';
        std::cerr << "================\n";
    }
}

Product ConsoleUI::promptForProduct() {
    std::string  name, expiryDate;
    int quantity;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Type a name of the product: ";
    std::getline(std::cin, name);

    std::cout << "Type a quantity: ";
    std::cin >> quantity;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Type an expiry date in format (DD-MM-YYYY): ";
    std::getline(std::cin, expiryDate);
    return {name, quantity, expiryDate};

}

void ConsoleUI::displayProductsAndRemove(Inventory &inventory) {
    inventory.displayContents();

    std::string name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Type a name of the product for removing: ";
    std::getline(std::cin, name);

    if (inventory.getProduct(name) != nullptr) {
        inventory.removeProduct(name);
        std::cout << "Product '" << name << "' removed." << std::endl;
    } else{
        std::cout << "Product not found." << std::endl;
    }
}
void ConsoleUI::saveInventory(Inventory &inventory, FileManager &fileManager) {
    std::string filename;
    std::cout << "Type a file name: ";
    std::cin >> filename;
    fileManager.saveInventory(inventory, filename);
    std::cout << "Inventory successfully saved." << '\n';
}

void ConsoleUI::loadInventory(Inventory &inventory, FileManager &fileManager) {
    std::string filename;
    std::cout << "Type a file name: ";
    std::cin >> filename;
    if (fileManager.loadInventory(inventory, filename)){
        std::cout << "Inventory successfully loaded." << '\n';
    }
}

// Experimental function
void ConsoleUI::clearScreen() {
    system("cls");
}