#pragma once

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

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

#include <vkInstance.h>
#include <win32Surface.h>
#include <debug.h>

#include <glm/common.hpp>

#include <fstream>

#ifndef Unicode
#define Unicode
#endif
#include "Windows.h"