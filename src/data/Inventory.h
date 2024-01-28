//
// Created by Kihachu on 12/20/2023.
//

#ifndef NICE_FRIDGE_INVENTORY_H
#define NICE_FRIDGE_INVENTORY_H
#include "Product.h"
#include <unordered_map>
#include <string>
#include <vector>

class Inventory {
public:
    void addProduct(const Product& product);
    void removeProduct(const std::string& name);
    Product& getProduct(const std::string& name);
    void displayContents();
    std::vector<Product> getAllProducts() const;
    void fridgeClear();

private:
    std::unordered_map<std::string, Product> products;
};


#endif //NICE_FRIDGE_INVENTORY_H
