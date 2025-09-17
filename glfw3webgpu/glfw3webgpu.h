#ifndef HORRIBLE_GLFW3_WEB_GPU_H_
#define HORRIBLE_GLFW3_WEB_GPU_H_

#include <webgpu/webgpu.h>
#include <GLFW/glfw3.h>

#ifdef __cplusplus
extern "C" {
#endif        

WGPUSurface glfwGetWGPUSurface(WGPUInstance, GLFWwindow *);


#ifdef __cplusplus
}
#endif

#endif        // HORRIBLE_GLFW3_WEB_GPU_H_