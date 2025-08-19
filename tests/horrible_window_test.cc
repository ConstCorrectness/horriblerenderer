#include <gtest/gtest.h>

#include "horriblerenderer/HorribleWindow.hpp"



TEST(HorribleTests, HorribleWindow) {
  HorribleWindow<decltype([](GLFWwindow *window) -> void { })> window;
  

}