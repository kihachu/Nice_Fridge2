//
// Created by Kihachu on 12/20/2023.
//

#include "Product.h"
#include <stdexcept>

const std::string Product::WRONG_DATE_FORMAT = "Invalid date format. Required: DD-MM-YYYY!";
const std::string Product::BELOW_ZERO_QUANTITY = "Quantity must be greater than 0!";

Product::Product(const std::string &productName, int productQuantity, const std::string &productExpiryDate)
: name(productName), quantity(productQuantity), expiryDate(productExpiryDate) {
    if (quantity <= 0){
        throw std::invalid_argument(BELOW_ZERO_QUANTITY);
    }
    if (!isValidDate(expiryDate)){
        throw std::invalid_argument(WRONG_DATE_FORMAT);
    }
}

const std::string& Product::getName() const {
    return name;
}

int Product::getQuantity() const {
    return quantity;
}

const std::string& Product::getExpiryDate() const {
    return expiryDate;
}

void Product::setQuantity(int newQuantity) {
    if (newQuantity <= 0){
        throw std::invalid_argument(BELOW_ZERO_QUANTITY);
    }
    quantity = newQuantity;
}

void Product::setExpiryDate(const std::string &newExpiryDate) {
    if (!isValidDate(newExpiryDate)){
        throw std::invalid_argument(WRONG_DATE_FORMAT);
    }
    expiryDate = newExpiryDate;
}

bool Product::isValidDate(const std::string &date){
    std::regex datePattern(R"(^(\d{2})-(\d{2})-(\d{4})$)");
    return std::regex_match(date, datePattern);
}