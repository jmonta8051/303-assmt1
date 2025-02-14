#include "functions.h"

void read_file(std::ifstream &inputFile, int *data, int &dataSize)
{
    std::string line, number;
    
    while (std::getline(inputFile, line))
    {
        std::stringstream ss(line);
        
        while (std::getline(ss, number, ' '))
        {
            //Writes all data straight into the array, uses dataSize as the index.
            data[dataSize] = std::stoi(number);
            dataSize++;
        }
    }
}

void find_index(int *data, int dataSize)
{
    //Getting userInput
    std::cout << "Enter a value to search for: ";
    std::string userInput;
    std::getline(std::cin, userInput);

    //Validating userInput
    while (userInput.find_first_not_of("1234567890") != std::string::npos
        || userInput == "")
    {
        std::cout << "Please enter a numeric value: ";
        std::getline(std::cin, userInput);
    }

    int value = stoi(userInput);

    std::string temp;

    //Loops through until it finds the value
    for (int i = 0; i < dataSize; ++i)
    {
        if (data[i] == value)
        {
            std::cout 
                << "Item found at index: " << i << "!\n\n"
                << "Press enter to continue...";
            std::getline(std::cin, temp);
            return;
        }
    }

    //Only activates if item isn't found.
    std::cout 
        << "Item not found in array.\n\n"
        << "Press enter to continue...";
    std::getline(std::cin, temp);
}

void modify_index(int *&data, int dataSize)
{
    //Gets userInput
    std::cout << "Enter an index to modify: ";
    std::string userInput;
    std::getline(std::cin, userInput);
    
    //Validates user input.
    try
    {
        while (
            userInput.find_first_not_of("1234567890") != std::string::npos
            || userInput == ""
            || std::stoi(userInput) < 0 
            || std::stoi(userInput) >= dataSize
            
            )
        {
            std::cout << "Please enter a valid index (0-" << dataSize - 1 << "): ";
            std::getline(std::cin, userInput);
        }
    }
    //Catches all things not found by if-statements
    catch (...)
    {
        std::cout 
            << "ERROR: User input fatal error!\n\n"
            << "Press enter to continue...";
        std::getline(std::cin, userInput);
        return;
    }

    int index = stoi(userInput);

    //Gets user input
    std::cout << "Enter a value: ";
    std::getline(std::cin, userInput);

    //Validates user input
    while (userInput.find_first_not_of("1234567890") != std::string::npos
        || userInput == "")
    {
        std::cout << "Please enter a valid number: ";
        std::getline(std::cin, userInput);
    }

    int value = stoi(userInput);

    //Lets the handsome users know what value has been modified.
    std::cout 
        << "The value " << data[index] << " has been replaced with " << value << "!\n\n"
        << "Press enter to continue...";
    std::getline(std::cin, userInput);

    data[index] = value;
}

void add_value_to_end(int *&data, int &dataSize, int &arrayCapacity)
{
    //Gets user input
    std::cout << "Enter a value to add: ";
    std::string userInput;
    std::getline(std::cin, userInput);

    //Validates user input
    try
    {
        while (userInput.find_first_not_of("1234567890") != std::string::npos
            || userInput == "")
        {
            std::cout << "Please enter a numeric value: ";
            std::getline(std::cin, userInput);
        }
    }
    //Catches whatever previous validation missed.
    catch (...)
    {
        std::cout 
            << "ERROR: User input fatal error!\n\n"
            << "Press enter to continue...";
        std::getline(std::cin, userInput);
        return;
    }

    int value = stoi(userInput);

    dataSize++;     

    //Checks if there's room in the array
    if (!(dataSize > arrayCapacity))
    {
        data[dataSize - 1] = value;
        return;
    }

    //If not, writes all values to a new array with *2 size.
    arrayCapacity *= 2;
    int *temp = new int[arrayCapacity];

    for (int i = 0; i < dataSize - 1; ++i)
    {
        temp[i] = data[i];
    }

    temp[dataSize - 1] = value;

    //Saves new array data to original pointer.
    delete data;
    data = temp;
}

void remove_index(int *&data, int &dataSize)
{
    //Gets user input
    std::cout << "Enter an index to remove: ";
    std::string userInput;
    std::getline(std::cin, userInput);

    //Validates user input
    while (
        userInput.find_first_not_of("1234567890") != std::string::npos
        || userInput == ""
        || std::stoi(userInput) < 0 
        || std::stoi(userInput) >= dataSize
        )
    {
        std::cout << "Please enter a valid index (0-" << dataSize - 1 << "): ";
        std::getline(std::cin, userInput);
    }

    int index = stoi(userInput);

    //Lies and says that the thing has already been removed even though that happens after this chunk
    std::cout
        << "The value " << data[index] << " has been removed!\n\n"
        << "Press enter to continue...";
    std::getline(std::cin, userInput);

    //Shifts all items past the index of deletion down, then cuts off the tip.
    while (index != dataSize)
    {
        data[index] = data[index + 1];
        ++index;
    }

    --dataSize;
}

bool user_menu(int *&data, int &dataSize, int &arrayCapacity)
{
    //I don't think this works on windows so I'm sorry if it looks like a mess over there.
    system("clear");

    //Prints the array
    for (int i = 0; i < dataSize; ++i)
    {
        if (i % 20 == 0) { std::cout << std::endl; }

        std::cout << std::left << " " << std::setw(5) << data[i];
    }

    std::cout 
        << "\n\n  Array manager"
        << "\n 1. Find Index"
        << "\n 2. Modify Index"
        << "\n 3. Add Value to End"
        << "\n 4. Remove Index"
        << "\n 5. Exit"
        << "\nEnter your choice: ";
    
    std::string userInput;
    std::getline(std::cin, userInput);

    //Validating user input
    while (
        userInput.find_first_not_of("12345") != std::string::npos
        || userInput.size() != 1
        || userInput == ""
        )
    {
        std::cout << "Please enter a value (1-5): ";
        std::getline(std::cin, userInput);
    }

    //Switchity switch switch
    switch (userInput[0])
    {
    case '1':
        find_index(data, dataSize);
        return true;
    
    case '2':
        modify_index(data, dataSize);
        return true;
    
    case '3':
        add_value_to_end(data, dataSize, arrayCapacity);
        return true;
    
    case '4':
        remove_index(data, dataSize); 
        return true;
    
    case '5':
        return false;
    }
    
    //Because my compiler kept giving me warnings.. Ugh!
    return false;
}
