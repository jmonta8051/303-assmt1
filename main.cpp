#include "functions.h"
#include "functions.cpp"

int main()
{
    //Opening the file
    std::ifstream inputFile;

    inputFile.open("data.txt");
    if (!inputFile.is_open()) { return -1; }

    //Creating the main pointer to an array
    int *data = new int[100], arrayCapacity = 100, dataSize = 0;

    //Reading file, closing file.
    read_file(inputFile, data, dataSize);
    inputFile.close();

    //Breaks when user chooses to exit program.
    while (true)
    {
        if (!user_menu(data, arrayCapacity, dataSize))
            break;
    }
}