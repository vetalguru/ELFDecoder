#include "elfdecoder.h"

#include "utilities.h"

namespace elf
{

ElfDecoder::ElfDecoder()
  : m_isParsed(false)
{
}

ElfDecoder::~ElfDecoder()
{
}

bool ElfDecoder::isParsed() const
{
  return m_isParsed;
}

bool ElfDecoder::open(const std::string& aPath)
{
  m_isParsed = readFile(aPath);
  return m_isParsed;
}

bool ElfDecoder::readFile(const std::string& aFile)
{
  return ::IsExists(aFile);
}

} // namespace elf
