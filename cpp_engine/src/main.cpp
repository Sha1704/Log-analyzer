#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // read from sample.log and print out num lines
    std::ifstream file ("../tests/sample.log");
    int line_count = 0;
    std::string line;
    

    if (!file.is_open())
    {
        std::cerr<<"Log file could not be opened." << std::endl;
        return 1;
    }

    while (std::getline(file, line))
    {
        line_count++;
    }

    std::cout<< "Line count: " << line_count << std::endl;

    return 0;
}