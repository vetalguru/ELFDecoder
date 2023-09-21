#ifndef ELFDECODER_H
#define ELFDECODER_H

#include <string>

namespace elf
{

class ElfDecoder
{
public:
  ElfDecoder();
  ~ElfDecoder();

  bool isParsed() const;

  bool open(const std::string& aPath);

private:
  bool readFile(const std::string& aFile);

private:
  bool m_isParsed;
};

} // namespace elf

#endif // ELFDECODER_H
