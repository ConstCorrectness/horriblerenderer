#include <webgpu/webgpu.h>
#include <iostream>
#include <vector>
#include <cassert>


#ifdef __EMSCRIPTEN__
# include <emscripten.h>
#endif        // __EMSCRIPTEN__

#include "utils/utils.hpp"


int main(int, char const **) {

  std::cout << __cplusplus << std::endl;
  WGPUInstanceDescriptor desc { };
  desc.nextInChain = nullptr;

#ifdef WEBGPU_BACKEND_EMSCRIPTEN
  WGPUInstance instance = wgpuCreateInstance(nullptr);
#else
  WGPUInstance instance = wgpuCreateInstance(&desc);
#endif              // WEBGPU_BACKEND_EMSCRIPTEN


  if (!instance) {
    std::cerr << "ERROR: wgpuCreateInstance()\n";
    return 1;
  }

  std::cout << "WGPU instance: " << instance << std::endl;
  std::cout << "\n\nRequesting adapter..." << std::endl;

  WGPURequestAdapterOptions adapterOpts { };
  adapterOpts.nextInChain = nullptr;

  WGPUAdapter adapter = requestAdapterSync(instance, &adapterOpts);
  std::cout << "Got adapter: " << adapter << std::endl;


  inspectAdapter(adapter);


  std::cout << "\n\nRequesting device..." << std::endl;

  WGPUDeviceDescriptor deviceDesc { };
  deviceDesc.nextInChain = nullptr;
  deviceDesc.label = "Horrible Device";
  deviceDesc.requiredFeatureCount = 0;
  deviceDesc.requiredLimits = nullptr;
  deviceDesc.defaultQueue.nextInChain = nullptr;
  deviceDesc.defaultQueue.label = "Horrible Default Queue";
  
  // set the Device Lost Callback
  deviceDesc.deviceLostCallback = [](WGPUDeviceLostReason reason, char const* message, void* /* pUserData */) {
    std::cout << "Device lost: reason " << reason;
    if (message) 
      std::cout << " (" << message << ")";
    std::cout << std::endl;
  };

  WGPUDevice device = requestDeviceSync(adapter, &deviceDesc);

  std::cout << "Got device: " << device << std::endl;


  inspectDevice(device);


  WGPUQueue queue = wgpuDeviceGetQueue(device);




  // release WGPUInstance -> WGPUAdapter -> WGPUDevice
  // release WGPUQueue
  wgpuInstanceRelease(instance);
  wgpuAdapterRelease(adapter);
  wgpuDeviceRelease(device);
  wgpuQueueRelease(queue);

  return 0;
}