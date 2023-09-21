#include <gtest/gtest.h>

#include <string>

#include "utilities.h"

TEST(Utilitites_Test, IsExists_EmptyFilename)
{
  const std::string file{};

  EXPECT_FALSE(::IsExists(file));
}

TEST(Utilitites_Test, IsExists_WrongFilename)
{
  const std::string file{"WRONG_FILE_NAME"};

  EXPECT_FALSE(::IsExists(file));
}

TEST(Utilitites_Test, IsExists_CurrentFilename)
{
  const std::string file{__FILE__};

  EXPECT_TRUE(::IsExists(file));
}
