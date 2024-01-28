//
// Created by Kihachu on 12/20/2023.
//

#include "Inventory.h"
#include <iostream>
void Inventory::addProduct(const Product &product) {
    products[product.getName()] = product;
}

void Inventory::removeProduct(const std::string &name) {
    products.erase(name);
}

Product* Inventory::getProduct(const std::string &name) {
    auto it = products.find(name);
    if (it != products.end()){
        return &(it->second);
    }
    return nullptr;
}

void Inventory::displayContents() {
    if (products.empty()){
        std::cout << "Fridge is empty. =(" << std::endl;
        return;
    }

    std::cout << "Contents of the fridge:" << std::endl;
    for (const auto& item : products){
        const auto& product = item.second;
        std::cout << "Name: " << product.getName()
                  << ", Quantity: " << product.getQuantity()
                  << ", Expiry date: " << product.getExpiryDate() << std::endl;
    }
}

std::vector<Product> Inventory::getAllProducts() const {
    std::vector<Product> allProducts;
    for (const auto &pair : products){
        allProducts.push_back(pair.second);
    }
    return allProducts;
}

void Inventory::fridgeClear() {
    products.clear();
}