#pragma once

#ifdef CL_DEBUG
#define CL_ASSERT(x, ...) { if (!(x)) { CL_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak; } }
#else
#define CL_ASSERT(x, ...)
#endif
