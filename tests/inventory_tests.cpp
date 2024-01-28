//
// Created by Kihachu on 12/25/2023.
//
#include "gtest/gtest.h"
#include "../src/data/Inventory.h"
#include "../src/data/Product.h"
#include <sstream>

const std::string InventoryTests;
TEST(InventoryTests, AddProduct){
    Inventory inventory;
    inventory.addProduct(Product("Milk", 2, "12-31-2023"));

    Product *retrieved = inventory.getProduct("Milk");

    ASSERT_NE(retrieved, nullptr);
    EXPECT_EQ(retrieved->getName(), "Milk");
    EXPECT_EQ(retrieved->getQuantity(), 2);
    EXPECT_EQ(retrieved->getExpiryDate(), "12-31-2023");

}

TEST(InventoryTests, AddTwoProducts){
    Inventory inventory;
    inventory.addProduct(Product("Milk", 2, "12-31-2023"));
    inventory.addProduct(Product("Cola", 60, "12-31-2022"));

    Product *retrieved = inventory.getProduct("Milk");
    Product *retrieved_second = inventory.getProduct("Cola");

    ASSERT_NE(retrieved, nullptr);
    EXPECT_EQ(retrieved->getName(), "Milk");
    EXPECT_EQ(retrieved->getQuantity(), 2);
    EXPECT_EQ(retrieved->getExpiryDate(), "12-31-2023");
    ASSERT_NE(retrieved_second, nullptr);
    EXPECT_EQ(retrieved_second->getName(), "Cola");
    EXPECT_EQ(retrieved_second->getQuantity(), 60);
    EXPECT_EQ(retrieved_second->getExpiryDate(), "12-31-2022");
}

TEST(InventoryTests, AddMultupleProducts){
    Inventory inventory;
    inventory.addProduct(Product("Milk", 2, "12-31-2023"));
    inventory.addProduct(Product("Cola", 60, "12-31-2022"));
    inventory.addProduct(Product("idviodfnviodfnbviofdnbiofdniobfdiobjdiobjdfiogjdoigjio", 2000032320, "12-31-3001"));

    Product *retrieved = inventory.getProduct("Milk");
    Product *retrieved_second = inventory.getProduct("Cola");
    Product *retrieved3 = inventory.getProduct("idviodfnviodfnbviofdnbiofdniobfdiobjdiobjdfiogjdoigjio");


    ASSERT_NE(retrieved, nullptr);
    EXPECT_EQ(retrieved->getName(), "Milk");
    EXPECT_EQ(retrieved->getQuantity(), 2);
    EXPECT_EQ(retrieved->getExpiryDate(), "12-31-2023");
    ASSERT_NE(retrieved_second, nullptr);
    EXPECT_EQ(retrieved_second->getName(), "Cola");
    EXPECT_EQ(retrieved_second->getQuantity(), 60);
    EXPECT_EQ(retrieved_second->getExpiryDate(), "12-31-2022");
    ASSERT_NE(retrieved3, nullptr);
    EXPECT_EQ(retrieved3->getName(), "idviodfnviodfnbviofdnbiofdniobfdiobjdiobjdfiogjdoigjio");
    EXPECT_EQ(retrieved3->getQuantity(), 2000032320);
    EXPECT_EQ(retrieved3->getExpiryDate(), "12-31-3001");
}

TEST(InventoryTests, AddThousandProducts) {
    Inventory inventory;

    for (int i = 0; i < 1000; ++i) {
        std::string name = "Product" + std::to_string(i);
        Product newProduct(name, i + 1, "01-01-2024");
        inventory.addProduct(newProduct);
    }

    for (int i = 0; i < 1000; ++i) {
        std::string name = "Product" + std::to_string(i);
        Product* retrieved = inventory.getProduct(name);
        EXPECT_NE(retrieved, nullptr);
        EXPECT_EQ(retrieved->getName(), name);
        EXPECT_EQ(retrieved->getQuantity(), i + 1);
        EXPECT_EQ(retrieved->getExpiryDate(), "01-01-2024");
    }
}


TEST(InventoryTests, AddBelowZeroQuantity){
    Inventory inventory;

    EXPECT_THROW({
                     inventory.addProduct(Product("Milk", -1, "12-31-2023"));
                 }, std::invalid_argument);
}

TEST(InventoryTests, AddBelowZeroQuantityMultiple){
    Inventory inventory;
    EXPECT_THROW({
                     inventory.addProduct(Product("Milk", -1, "12-31-2023"));
                 }, std::invalid_argument);

    EXPECT_THROW({
                     inventory.addProduct(Product("Eggs", -5, "11-30-2023"));
                 }, std::invalid_argument);

    EXPECT_THROW({
                     inventory.addProduct(Product("Cheese", -10, "10-15-2023"));
                 }, std::invalid_argument);
}

TEST(InventoryTests, AddBelowZeroWithWrongDate){
    Inventory inventory;
    EXPECT_THROW({
                     inventory.addProduct(Product("Milk", -1, "12-341-2023"));
                 }, std::invalid_argument);

    EXPECT_THROW({
                     inventory.addProduct(Product("Eggs", -5, "45-30-2023"));
                 }, std::invalid_argument);

    EXPECT_THROW({
                     inventory.addProduct(Product("Cheese", -10, "10-15-223"));
                 }, std::invalid_argument);
}

TEST(InventoryTests, RemoveProduct){
    Inventory inventory;
    inventory.addProduct(Product("Milk", 2, "12-31-2023"));
    EXPECT_NE(inventory.getProduct("Milk"), nullptr);
    inventory.removeProduct("Milk");
    EXPECT_EQ(inventory.getProduct("Milk"), nullptr);
}

TEST(InventoryTests, RemoveTwoProducts){
    Inventory inventory;
    inventory.addProduct(Product("Milk", 2, "12-31-2023"));
    inventory.addProduct(Product("Cola", 2, "12-31-2023"));
    EXPECT_NE(inventory.getProduct("Milk"), nullptr);
    EXPECT_NE(inventory.getProduct("Cola"), nullptr);
    inventory.removeProduct("Milk");
    inventory.removeProduct("Cola");
    EXPECT_EQ(inventory.getProduct("Milk"), nullptr);
    EXPECT_EQ(inventory.getProduct("Cola"), nullptr);
}

TEST(InventoryTests, RemoveThousandProducts) {
    Inventory inventory;

    for (int i = 0; i < 1000; ++i) {
        std::string name = "Product" + std::to_string(i);
        inventory.addProduct(Product(name, i + 1, "01-01-2024"));
    }

    for (int i = 0; i < 1000; ++i) {
        std::string name = "Product" + std::to_string(i);
        inventory.removeProduct(name);

        EXPECT_EQ(inventory.getProduct(name), nullptr);
    }
}

TEST(InventoryTests, Remove10000Products) {
    Inventory inventory;

    for (int i = 0; i < 10000; ++i) {
        std::string name = "Product" + std::to_string(i);
        inventory.addProduct(Product(name, i + 1, "01-01-2024"));
    }

    for (int i = 0; i < 10000; ++i) {
        std::string name = "Product" + std::to_string(i);
        inventory.removeProduct(name);

        EXPECT_EQ(inventory.getProduct(name), nullptr);
    }
}