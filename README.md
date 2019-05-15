<h3>Sales Tax Problem solution using C++</h3>



<br>

#### Structure
- `main.cpp` contains main entrypoint driver code and deals with input and output.
- `Item.cpp` contains implementations of funtions declared in `Item` class in `Item.hpp` header file.
- `ItemCategory.hpp` header contains `enum class` to store item categories.
-  `Tax.cpp` contains implementations of funtions declared in `Tax` class in `Tax.hpp` header file.


#### Running
```sh
$ cd to the src folder
$ g++ -o main main.cpp Item.cpp Tax.cpp
$ ./main
```
#### Providing Input
 Enter each item order on new line.
 When orders are finished ,enter 'stop' to console on new line.
