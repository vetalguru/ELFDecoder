#include "elfdecoder.h"

#include "utilities.h"

namespace elf
{

ElfDecoder::ElfDecoder()
  : m_isParsed(false)
{
}

ElfDecoder::ElfDecoder(const std::string &aPath)
  : m_isParsed(false)
{
    open(aPath);
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
  if (m_isParsed)
  {
    resetInternalStructures();
  }

  m_isParsed = readFile(aPath);
  return m_isParsed;
}

bool ElfDecoder::readFile(const std::string& aFile)
{
  return ::IsExists(aFile);
}

void ElfDecoder::resetInternalStructures()
{
  m_isParsed = false;
}

} // namespace elf
