#include "elfdecoder.h"

#include <elf.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool ReadData(const std::string& aPath, std::vector<unsigned char>& aData);
void PrintHEX(const std::vector<unsigned char>& aData);
bool PrintElfHeader(const std::vector<unsigned char>& aData);

int main ()
{
    std::vector<unsigned char> data;
    if (ReadData(std::string{"samples/simple.bin"}, data))
    {
        PrintHEX(data);
        PrintElfHeader(data);
    }

    return 0;
}

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
    std::ifstream file;
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
        switch(static_cast<uint8_t>(i))
        {
            case 0:   { std::cout << ".";     break; }  // null character
            case 1:   { std::cout << "[SOH]"; break; }  // start of header
            case 2:   { std::cout << "[STX]"; break; }  // start of text
            case 3:   { std::cout << "[ETX]"; break; }  // end of text
            case 4:   { std::cout << "[EOT]"; break; }  // end of transmission
            case 5:   { std::cout << "[ENQ]"; break; }  // enquiry
            case 6:   { std::cout << "[ACK]"; break; }  // acknowledge
            case 7:   { std::cout << "[BEL]"; break; }  // bell (ring)
            case 8:   { std::cout << "[BS]";  break; }  // backspace
            case 9:   { std::cout << "[HT]";  break; }  // horizontal tab
            case 10:  { std::cout << "[LF]";  break; }  // line feed
            case 11:  { std::cout << "[VT]";  break; }  // vertical tab
            case 12:  { std::cout << "[FF]";  break; }  // form feed
            case 13:  { std::cout << "[CR]";  break; }  // carriage return
            case 14:  { std::cout << "[SO]";  break; }  // shift out
            case 15:  { std::cout << "[SI]";  break; }  // shift in
            case 16:  { std::cout << "[DLE]"; break; }  // data link escape
            case 17:  { std::cout << "[DC1]"; break; }  // device control 1
            case 18:  { std::cout << "[DC2]"; break; }  // device control 2
            case 19:  { std::cout << "[DC3]"; break; }  // device control 3
            case 20:  { std::cout << "[DC4]"; break; }  // device control 4
            case 21:  { std::cout << "[NAK]"; break; }  // negative acknowledge
            case 22:  { std::cout << "[SYN]"; break; }  // synchronize
            case 23:  { std::cout << "[ETB]"; break; }  // end transmission block
            case 24:  { std::cout << "[CAN]"; break; }  // cancel
            case 25:  { std::cout << "[EM]";  break; }  // end of medium
            case 26:  { std::cout << "[SUB]"; break; }  // substitute
            case 27:  { std::cout << "[ESC]"; break; }  // escape
            case 28:  { std::cout << "[FS]";  break; }  // file separator
            case 29:  { std::cout << "[GS]";  break; }  // group separator
            case 30:  { std::cout << "[RS]";  break; }  // record separator
            case 31:  { std::cout << "[US]";  break; }  // unit separator
            case 127: { std::cout << "[DEL]"; break; }  // delete (rubout)
            default:  { std::cout << i;       break; }
        }
    }

    std::cout << "\n";
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
