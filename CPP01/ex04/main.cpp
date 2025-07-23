#include <iostream>
#include <fstream>
#include <string>

static void writeReplacedFile(std::ifstream& file, std::ofstream& newFile,
    std::string replaced, std::string replace)
{
    std::string line;
    std::string goodLine;
    size_t      index;

    while (std::getline(file, line))
    {
        index = line.find(replaced);
        if (replaced != replace)
        {
            while (index != std::string::npos)
            {
                line.erase(index, replaced.length());
                line.insert(index, replace);
                index = line.find(replaced, index + replace.length());
            }
        }
        newFile << line << std::endl;
    }
}

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        std::cout << "Error : tree parameters needed : filename, string replaced, new string" << std::endl;
        return 1;
    }
    else if (argc > 4)
    {
        std::cout << "Error : Only tree parameters needed : filename, string replaced, new string" << std::endl;
        return 1;
    }
    std::string fileName = argv[1];
    std::string newFile = fileName + ".replace";

    std::ifstream file(argv[1]);
    std::ofstream new_file(newFile.c_str());
    if (!file.is_open() || !new_file.is_open())
    {
        std::cout << "Error : Can't open the file" << std::endl;
        return 1;
    }
    writeReplacedFile(file, new_file, argv[2], argv[3]);
    file.close();
    new_file.close();
}