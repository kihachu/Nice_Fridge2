//
// Created by Kihachu on 12/20/2023.
//

#ifndef NICE_FRIDGE_PRODUCT_H
#define NICE_FRIDGE_PRODUCT_H
#include <string>
#include <regex>

class Product {
public:
    static const std::string BELOW_ZERO_QUANTITY;
    static const std::string WRONG_DATE_FORMAT;
    Product() : name(""), quantity(0), expiryDate("") {};
    Product(const std::string& name, int quantity, const std::string& expiryDate);

    const std::string& getName() const;
    int getQuantity() const;
    const std::string& getExpiryDate() const;

    void setQuantity(int newQuantity);
    void setExpiryDate(const std::string& newExpiryDate);
private:
    std::string name;
    int quantity;
    std::string expiryDate;

    bool isValidDate(const std::string &date);
};


#endif //NICE_FRIDGE_PRODUCT_H
