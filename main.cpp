#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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

int main ()
{
    std::vector<unsigned char> data;
    if (ReadData(std::string{"samples/simple.bin"}, data))
    {
        PrintHEX(data);
    }

    return 0;
}
