#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "gtest/gtest.h"

using namespace ftxui;
using namespace ftxui;

TEST(TextTest, ScreenHeightSmaller) {
  auto element = text(L"test");
  Screen screen(2, 0);
  Render(screen, element.get());

  EXPECT_EQ("", screen.ToString());
}

TEST(TextTest, ScreenSmaller) {
  auto element = text(L"test");
  Screen screen(2, 1);
  Render(screen, element.get());

  EXPECT_EQ("te", screen.ToString());
}

TEST(TextTest, ScreenFit) {
  auto element = text(L"test");
  Screen screen(4, 1);
  Render(screen, element.get());

  EXPECT_EQ("test", screen.ToString());
}

TEST(TextTest, ScreenBigger) {
  auto element = text(L"test");
  Screen screen(6, 1);
  Render(screen, element.get());

  EXPECT_EQ("test  ", screen.ToString());
}

TEST(TextTest, ScreenBigger2) {
  auto element = text(L"test");
  Screen screen(6, 2);
  Render(screen, element.get());

  EXPECT_EQ("test  \n      ", screen.ToString());
}
