#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <elf.h>

bool ReadData(const std::string& aPath, std::vector<unsigned char>& aData)
{
    aData.clear();

    // Check path
    if (aPath.empty())
    {
        std::cerr << "ERROR: Empty file name" << std::endl;
        return false;
    }

    // Open file
    std::fstream file;
    file.open(aPath, std::ios_base::in | std::ios_base::binary);
    if (!file.is_open())
    {
        std::cerr << "ERROR: Unable to open file " << aPath << std::endl;
        return false;
    }

    // Get file size
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios_base::beg);

    // Read data
    aData.resize(fileSize);
    file.read((char*)&aData[0], fileSize);

    return true;
}

void PrintHEX(const std::vector<unsigned char>& aData)
{
    for (const auto& i : aData)
    {
        std::cerr << (int)i;
    }

    std::cerr << "\n";
}

bool PrintElfHeader(const std::vector<unsigned char>& aData)
{
    if (aData.size() < EI_NIDENT)
    {
        return false;
    }

    // Print platform
    switch(aData[4])
    {
    case ELFCLASS32: {
        std::cout << "Platform : x32" << std::endl;
        break;
    }
    case ELFCLASS64: {
        std::cout << "Platform : x64" << std::endl;
        break;
    }
    default: {
        std::cout << "Platform : Unknown" << std::endl;
        break;
        }
    }

    // Print data encoding
    switch(aData[5])
    {
    case ELFDATA2LSB: {
        std::cout << "Data encoding: little endian" << std::endl;
        break;
        }
    case ELFDATA2MSB: {
        std::cout << "Data encoding: big endian" << std::endl;
        break;
        }
    default: {
        std::cout << "Data encoding: Unknown" << std::endl;
        break;
        }
    }

    // Print version
    std::cout << "ELF Version: " << (int)aData[6] << std::endl;

    return true;
}

int main ()
{
    std::vector<unsigned char> data;
    if (ReadData(std::string{"samples/simple.bin"}, data))
    {
        //PrintHEX(data);
        PrintElfHeader(data);
    }

    return 0;
}
