#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr<<"Need 3 command line arguments (input file location (as directory), config file name and output file location (as directory))." << std::endl;
        return 1;
    }

    std::string input = argv[1];
    std::string output = argv[3];
    std::string config = argv[2];

    std::ifstream infile (input);
    int line_count = 0;
    int info_count = 0;
    int error_count = 0;
    int warn_count = 0;
    int unknown_count = 0;
    std::string line;
    
    if (!infile.is_open())
    {
        std::cerr<<"Log file could not be opened." << std::endl;
        return 1;
    }

    while (std::getline(infile, line))
    {
        std::string type = line.substr(line.find('['), (line.find(']') - line.find('[')) + 1);

        if (type == "[INFO]")
        {
            info_count ++;
        }
        else if (type == "[WARN]")
        {
            warn_count ++;
        }
        else if (type == "[ERROR]")
        {
            error_count ++;
        }
        else
        {
            unknown_count++;
        }
        line_count++;
    }

    std::ofstream outfile (output);
    
    if (outfile.is_open())
    { 
        outfile << "{\n";
        outfile << "\t\"total_lines\":" << line_count << ",\n";
        outfile << "\t\"level_counts\": {\n";
        outfile << "\t\t\"INFO\":" << info_count << ",\n";
        outfile << "\t\t\"WARN\":" << warn_count << ",\n";
        outfile << "\t\t\"ERROR\":" << error_count << ",\n";
        outfile << "\t\t\"UNKNOWN\":" << unknown_count << "\n";
        outfile << "\t}\n";
        outfile << "}\n";

        std::cout << "Operation successful, results in: " <<  output << std::endl;
        outfile.close();
    }
    else
    {
        std::cerr<<"Could not open the output file." << std::endl;
        return 1;
    }

    return 0;
}