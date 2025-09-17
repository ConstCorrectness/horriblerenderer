#ifndef HORRIBLE_UTILS_HPP_
#define HORRIBLE_UTILS_HPP_

#include <webgpu/webgpu.h>
#include <glfw/glfw3.h>



WGPUAdapter requestAdapterSync(WGPUInstance instance, WGPURequestAdapterOptions const *options);

void inspectAdapter(WGPUAdapter adapter);

WGPUDevice requestDeviceSync(WGPUAdapter adapter, WGPUDeviceDescriptor const *descriptor);

void inspectDevice(WGPUDevice device);

#endif      // HORRIBLE_UTILS_HPP_
