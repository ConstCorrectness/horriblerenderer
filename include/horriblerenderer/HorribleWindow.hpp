#ifndef HORRIBLE_WINDOW_HPP_
#define HORRIBLE_WINDOW_HPP_

#include <glad/gl.h>
#include <GLFW/glfw3.h>


#include <iostream>
#include <memory>
#include <string_view>
#include <functional>


class HorribleWindow {
public:
  // move-only type
  HorribleWindow(HorribleWindow const&) = delete;
  HorribleWindow& operator=(HorribleWindow const&) = delete;

  // move operations `noexcept`
  HorribleWindow(HorribleWindow&&) noexcept = default;
  HorribleWindow& operator=(HorribleWindow&&) noexcept = default;

  ~HorribleWindow() {
    window_.reset();
    glfwTerminate();
  }

  explicit HorribleWindow(int width = 640, int height = 480, 
    std::string_view title = "HorribleWindow", 
    GLFWmonitor *monitor = nullptr, 
    GLFWwindow* share = nullptr)
    : width_{width}, height_{height} {
    if (!glfwInit()) {
      std::cerr << "ERROR: glfwInit()\n";
      std::exit(1);
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindow(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE)
#endif        // __APPLE__


    GLFWwindow *w = glfwCreateWindow(width, height, title.data(), monitor, share);
    if (!w) {
      std::cerr << "ERROR: glfwCreateWindow()\n";
      glfwTerminate();
      std::exit(1);
    }

    window_ = { w, glfwDestroyWindow };



    glfwMakeContextCurrent(window_.get());
    glfwSwapInterval(1);


    if (!gladLoadGL(glfwGetProcAddress)) {
      std::cerr << "ERROR: gladLoadGL()\n";
      std::exit(1);
    }
  }


  bool mainLoop() {
    while (!glfwWindowShouldClose(window_.get())) {

      glViewport(0, 0, width_, height_);
      glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      glfwSwapBuffers(window_.get());
      glfwPollEvents();
    }

    return true;
  }
  
private:
  std::unique_ptr<GLFWwindow, void(*)(GLFWwindow *)> window_ {nullptr, glfwDestroyWindow};

  int width_ { };
  int height_ { };
};




#endif          // HORRIBLE_WINDOW_HPP_