#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <sys/stat.h>

namespace
{

inline bool IsExists(const std::string& file)
{
  struct stat st = {};
  return (stat(file.c_str(), &st) == 0);
}

} // namespace

#endif // UTILITIES_H
