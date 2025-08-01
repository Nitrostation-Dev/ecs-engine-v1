#pragma once

#include <cstdint>

using Entity = uint32_t;
using ComponentId = uint8_t;

const Entity MAX_ENTITIES = 5000;
const ComponentId MAX_COMPONENT_TYPES = 32;
