#ifndef ELFDECODER_H
#define ELFDECODER_H

#include <string>
#include <vector>

bool ReadData(const std::string& aPath, std::vector<unsigned char>& aData);

void PrintHEX(const std::vector<unsigned char>& aData);

bool PrintElfHeader(const std::vector<unsigned char>& aData);

#endif // ELFDECODER_H
