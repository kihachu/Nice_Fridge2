//
// Created by Kihachu on 12/21/2023.
//

#ifndef NICE_FRIDGE_FILEMANAGER_H
#define NICE_FRIDGE_FILEMANAGER_H
#include <iostream>
#include <string>
#include "../data/Inventory.h"
class FileManager {
public:
    FileManager();
    void saveInventory(const Inventory &inventory, const std::string &filename);
    bool loadInventory(Inventory &inventory, std::string &filename);
    std::vector<std::string> listFilesInDirectory(const std::string &directoryPath);
private:
    std::string filepath;
};


#endif //NICE_FRIDGE_FILEMANAGER_H
