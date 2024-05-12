#pragma once

#include <vulkan/vulkan.h>

#define  VK_USE_PLATFORM_WIN32_KHR

#define  GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define  GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <limits>
#include <algorithm>

#include <map>
#include <optional>
#include <set>

#include <window.h>
#include <debug.h>