workspace "Dark"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder.
IncludeDir = {}
IncludeDir["GLFW"] = "Dark/vendor/GLFW/include"
IncludeDir["Glad"] = "Dark/vendor/Glad/include"
IncludeDir["ImGui"] = "Dark/vendor/imgui"

include "Dark/vendor/GLFW"
include "Dark/vendor/Glad"
include "Dark/vendor/imgui"

project "Dark"
    location "Dark"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    pchheader "dkpch.h"
    pchsource "Dark/src/dkpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "DK_PLATFORM_WINDOWS",
            "DK_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "DK_DEBUG"
        symbols "On"
        buildoptions "/MDd"

    filter "configurations:Release"
        defines "DK_RELEASE"
        optimize "On"
        buildoptions "/MD"
    
    filter "configurations:Dist"
        defines "DK_DIST"
        optimize "On"
        buildoptions "/MD"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
       
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Dark/vendor/spdlog/include",
        "Dark/src"
    }

    links
    {
        "Dark"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "DK_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "DK_DEBUG"
        symbols "On"
        buildoptions "/MDd"

    filter "configurations:Release"
        defines "DK_RELEASE"
        optimize "On"
        buildoptions "/MD"
    
    filter "configurations:Dist"
        defines "DK_DIST"
        optimize "On"
        buildoptions "/MD"
