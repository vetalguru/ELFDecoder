#include <gtest/gtest.h>

#include <string>

#include "elfdecoder.h"

TEST(EldDecoder_Test, IsParsed_Default)
{
  elf::ElfDecoder decoder;

  EXPECT_FALSE(decoder.isParsed());
}

TEST(EldDecoder_Test, Open_WrongFileName)
{
  const std::string file{"WRONG_FILE_NAME"};
  elf::ElfDecoder decoder;

  EXPECT_FALSE(decoder.open(file));
  EXPECT_FALSE(decoder.isParsed());
}

TEST(EldDecoder_Test, Open_EmptyFileName)
{
  const std::string file{};
  elf::ElfDecoder decoder;

  EXPECT_FALSE(decoder.open(file));
  EXPECT_FALSE(decoder.isParsed());
}

TEST(EldDecoder_Test, Open_CurrentFileName)
{
  const std::string file{__FILE__};
  elf::ElfDecoder decoder;

  EXPECT_TRUE(decoder.open(file));
  EXPECT_TRUE(decoder.isParsed());
}
