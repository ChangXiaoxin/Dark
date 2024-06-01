#pragma once

#ifdef DK_PLATFORM_WINDOWS
    #ifdef DK_BUILD_DLL
        #define DARK_API __declspec(dllexport)
    #else
        #define DARK_API __declspec(dllimport)
    #endif // DK_BUILD_DLL
#else
    #error Dark only supports Windows!
#endif // DK_PLATFORM_WINDOWS

#define BIT(x) (1 << x)
