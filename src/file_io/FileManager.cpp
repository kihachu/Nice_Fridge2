//
// Created by Kihachu on 12/21/2023.
//
// TODO: list output of available files
// TODO: product search
#include "FileManager.h"
#include <fstream>
#include <iostream>
#include "../ui/ConsoleUI.h" // displayMenu()
#include "../data/Inventory.h"
#include "../data/Product.h"
#include <filesystem>
#include "../../lib/json/json.hpp"

FileManager::FileManager(){
    std::string baseDirectory = "../test_data/";
    std::vector<std::string> fileNames = listFilesInDirectory(baseDirectory);
    for (const auto &name : fileNames){
        std::cout << name << '\n';
    }
}

std::vector<std::string> FileManager::listFilesInDirectory(const std::string &directoryPath) {
    std::vector<std::string> files;
    try {
        for (const auto &entry : std::filesystem::directory_iterator(directoryPath)){
            if (entry.is_regular_file()){
                files.push_back(entry.path().filename().string());
            }
        }
    } catch (const std::filesystem::filesystem_error &e){
        std::cerr << "Filesystem error: " << e.what() << '\n';
    }
    return files;
}

void FileManager::saveInventory(const Inventory &inventory, const std::string &filename) {

    std::ofstream file(filename);
    if (file.is_open() == false){
        std::cerr << "Could not open the file for write: " << filename << '\n';
        return;
    }
    nlohmann::json json;

    auto  allProducts = inventory.getAllProducts();
    for (const auto &product : allProducts){
        nlohmann::json productJson = {
                {"name",       product.getName()},
                {"quantity",   product.getQuantity()},
                {"expiryDate", product.getExpiryDate()}
        };
        json.push_back(productJson);
    }

    file << json.dump(4);
    std::cout << "The inventory is saved to a file: " << filename << '\n';
}

bool FileManager::loadInventory(Inventory &inventory, std::string &filename) {
    std::ifstream file(filename);
    if (file.is_open() == false){
        std::cerr << "Could not open file: " << filename << '\n';
        return false;
    }

    nlohmann::json json;
    try {
        inventory.fridgeClear();
        file >> json;

        for (const auto &item : json){
            std::string  name = item.at("name").get<std::string>();
            int quantity = item.at("quantity").get<int>();
            std::string expiryDate = item.at("expiryDate").get<std::string>();

            Product product(name, quantity, expiryDate);
            inventory.addProduct(product);
        }
    } catch (nlohmann::json::parse_error &e){
        std::cerr << "\n=====================\n";
        std::cerr << "JSON parsing error: " << e.what() << '\n';
        std::cerr << "=====================\n";
        std::cerr << "Your choice is: ";
        return false;
    } catch (nlohmann::json::out_of_range &e){
        std::cerr << "\n=====================\n";
        std::cerr << "Error accessing JSON data: " << e.what() << '\n';
        std::cerr << "=====================\n";
        std::cerr << "Your choice is: ";
        return false;
    } catch (nlohmann::json::type_error &e){
        std::cerr << "\n=====================\n";
        std::cerr << "JSON data type error: " << e.what() << '\n';
        std::cerr << "=====================\n";
        std::cerr << "Your choice is: ";
        return false;
    } catch (std::exception &e){
        std::cerr << "\n=====================\n";
        std::cerr << "Error: " << e.what() << '\n';
        std::cerr << "=====================\n";
        std::cerr << "Your choice is: ";
        return false;
    }
    return true;
}
