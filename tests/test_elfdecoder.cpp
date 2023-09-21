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

TEST(EldDecoder_Test, Constructor_WrongFileName)
{
  const std::string file{"WRONG_FILE_NAME"};
  elf::ElfDecoder decoder(file);

  EXPECT_FALSE(decoder.open(file));
  EXPECT_FALSE(decoder.isParsed());
}

TEST(EldDecoder_Test, Constructor_EmptyFileName)
{
  const std::string file{};
  elf::ElfDecoder decoder(file);

  EXPECT_FALSE(decoder.open(file));
  EXPECT_FALSE(decoder.isParsed());
}

TEST(EldDecoder_Test, Constructor_CurrentFileName)
{
  const std::string file{__FILE__};
  elf::ElfDecoder decoder(file);

  EXPECT_TRUE(decoder.open(file));
  EXPECT_TRUE(decoder.isParsed());
}

TEST(EldDecoder_Test, Constructor_Current_Open_Empty)
{
  const std::string file1{__FILE__};
  const std::string file2{};

  elf::ElfDecoder decoder(file1);

  EXPECT_TRUE(decoder.isParsed());
  EXPECT_FALSE(decoder.open(file2));
  EXPECT_FALSE(decoder.isParsed());
}

TEST(EldDecoder_Test, Constructor_Empty_Open_Current)
{
  const std::string file1{};
  const std::string file2{__FILE__};

  elf::ElfDecoder decoder(file1);

  EXPECT_FALSE(decoder.isParsed());
  EXPECT_TRUE(decoder.open(file2));
  EXPECT_TRUE(decoder.isParsed());
}
