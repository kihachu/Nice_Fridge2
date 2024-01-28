//
// Created by Kihachu on 12/14/2023.
//

#ifndef NICE_FRIDGE_CONSOLEUI_H
#define NICE_FRIDGE_CONSOLEUI_H
#include "../data/Inventory.h"
#include "../file_io/FileManager.h"
class ConsoleUI {
public:
    static void displayMenu();
    static void handleCommand(int command, Inventory &inventory, FileManager &fileManager);
    static void clearScreen();
    static void displayProductsAndRemove(Inventory &inventory);
    static void saveInventory(Inventory &inventory, FileManager &fileManager);
    static void loadInventory(Inventory &inventory, FileManager &fileManager);
    static Product promptForProduct();
};
#endif //NICE_FRIDGE_CONSOLEUI_H
