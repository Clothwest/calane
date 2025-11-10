#pragma once

#ifdef CL_ENABLE_ASSERT
#define CL_ASSERT(x, ...) { if (!(x)) { CL_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak; } }
#else
#define CL_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
