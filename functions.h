#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

//PRE: Takes an input .txt file, a pointer to an array of integers, and a reference to the integer size of that array.
//POST: Reads and writes the files contents, seperated by spaces, onto the array.
void read_file(std::ifstream &inputFile, int *data, int &dataSize);

//PRE: Takes a pointer to an array and its integer size.
//POST: Gets a user index to dereference from the array.
void find_index(int *data, int dataSize);

//PRE: Takes a reference to a pointer to an array and its integer size.
//POST: Gets user index and a value to modify that index in the array with.
void modify_index(int *&data, int dataSize);

//PRE: Takes a reference to a pointer to an array, a reference to its integer size, and a reference to the arrays integer capacity.
//POST: Gets a user value to add to the end of the array. If capacity is full, doubles capacity.
void add_value_to_end(int *&data, int &dataSize, int &arrayCapacity);

//PRE: Takes a reference to a pointer to an array and a reference to its integer size.
//POST: Gets a user index to remove from the array.
void remove_index(int *&data, int &dataSize);

//PRE: Takes a reference to a pointer to an array, a reference to its integer size, and a reference to the arrays integer capacity.
//POST: A menu which can perform array functions. Only returns false when user chooses to exit the menu.
bool user_menu(int *&data, int &dataSize, int &arrayCapacity);