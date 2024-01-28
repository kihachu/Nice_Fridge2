#include <iostream>
#include "ui/ConsoleUI.h"
#include "data/Inventory.h"
#include "file_io/FileManager.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << std::endl;
    Inventory inventory;
    FileManager fileManager;
    int command;

    while (true){
        ConsoleUI::displayMenu();
        std::cin >> command;
        ConsoleUI::handleCommand(command, inventory, fileManager);
        std::cout << "====================\n";
    }
}
