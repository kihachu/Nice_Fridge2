FridgeManager by Bohdan Pasichnyk (aka Kihachu).

How to use?
The refrigerator json files are saved in the /cmake-build-debug folder.
The files are also saved there.

UI: I will create a console interface that will allow me to enter and display information about the products in the refrigerator. This includes functions to add a new product, remove a product, and view the current product list.

Working with files: I will use the file system to store product data. I plan to create a structured file, for example in JSON format, which will store product data such as name, expiration date, quantity, etc.

Non-trivial algorithm: I'll look at a few options:

An expiration date optimization algorithm: it will automatically calculate and optimize the expiration date of products and suggest recipes based on products that are about to expire.

Inventory algorithm: it will analyze the current stock of products and suggest a shopping list based on previous consumption patterns.

Modularity: I will divide the project into several modules including a file processing module, a data processing module and a user interface module.

Extensibility: I will design the architecture in such a way that new features can be easily added in the future.

Error handling: I will make sure that my application can correctly handle various errors, such as incorrect input format or problems reading a file.

TODO: connect the program to some API, through which you could get recipes from available products.

TODO: list output of available files

TODO: product search

TODO: improve user experience

TODO: improvе error output, no idea how to do it better yet