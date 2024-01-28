cmake_minimum_required(VERSION 3.26)
project(Nice_Fridge)

set(CMAKE_CXX_STANDARD 23)

add_compile_options(-Wall -Wextra -Wshadow -Wconversion -Wnon-virtual-dtor -Wpedantic -pedantic)

add_subdirectory(external/googletest)

include_directories(external/googletest/googletest/include)

set(SOURCE_FILES
        src/ui/ConsoleUI.cpp
        src/data/Product.cpp
        src/data/Inventory.cpp
        src/file_io/FileManager.cpp
        lib/json/json.hpp
)

add_executable(Nice_Fridge src/main.cpp ${SOURCE_FILES})

add_executable(InventoryTest tests/inventory_tests.cpp ${SOURCE_FILES})
target_link_libraries(InventoryTest gtest gtest_main)

