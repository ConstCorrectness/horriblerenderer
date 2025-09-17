#ifndef HORRIBLE_WINDOW_HPP_
#define HORRIBLE_WINDOW_HPP_

#include <webgpu/webgpu.h>

#include <GLFW/glfw3.h>
#include "glfw3webgpu.h"

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include "horriblerenderer/HorribleWindow.hpp"



class HorribleWebGPU {
public:
  HorribleWebGPU(int width = 640, int height = 480, std::string const& title = "HorribleWebGPU") {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
    if (!window) {
      std::clog << "[ERROR]: glfwCreateWindow()\n";
      std::exit(1);
    }

    instance = wgpuCreateInstance(nullptr);

    surface = glfwGetWGPUSurface(instance, window);


    WGPURequestAdapterOptions adapterOpts { .nextInChain = nullptr, .compatibleSurface = surface };
    



  }

  ~HorribleWebGPU() {
    wgpuInstanceRelease(instance);
    wgpuAdapterRelease(adapter);
    wgpuDeviceRelease(device);
    wgpuQueueRelease(queue);
    wgpuSurfaceRelease(surface);

    glfwDestroyWindow(window);
    glfwTerminate();
  }


private:
  WGPUInstance  instance  { nullptr };
  WGPUAdapter   adapter   { nullptr };
  WGPUDevice    device    { nullptr };
  WGPUSurface   surface   { nullptr };
  WGPUQueue     queue     { nullptr };

  GLFWwindow*   window { nullptr };

};


#endif          // HORRIBLE_WINDOW_HPP_