#include "struct.h"

bool QueueFamilyIndices::isComplete() {
    return graphicsFamily.has_value() && presentFamily.has_value();
}

QueueFamilyIndices indices;