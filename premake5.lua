workspace "calane"
	architecture "x64"
	staticruntime "On"
	
	startproject "calane"

	configurations
	{
		"Debug",
		"Release"
	}

	buildoptions
	{
		"/utf-8"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/"

includeDirs = {}
includeDirs["glfw"] = "calane/vendor/glfw/include"
includeDirs["glad"] = "calane/vendor/glad/include"

include "calane/vendor/glfw"
include "calane/vendor/glad"

project "calane"
	location "calane"
	language "C++"
	cppdialect "C++17"

	targetdir(".bin/" .. outputDir .. "%{prj.name}/")
	objdir(".bin-int/" .. outputDir .. "%{prj.name}/")

	pchheader "clpch.h"
	pchsource "%{prj.name}/src/clpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",

		"%{prj.name}/vendor/fmt/include",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/glm/include",

		"%{includeDirs.glfw}",
		"%{includeDirs.glad}"
	}

	links
	{
		"opengl32.lib",
		"glfw",
		"glad"
	}

	defines
	{
		"FMT_HEADER_ONLY",
		"SPDLOG_FMT_EXTERNAL",
		"SPDLOG_HEADER_ONLY",
		"GLFW_INCLUDE_NONE"
	}

	filter "system:window"
		systemversion "latest"

	filter "configurations:Debug"
		kind "ConsoleApp"
		defines "CL_DEBUG"
		symbols "On"
		runtime "Debug"

	filter "configurations:Release"
		kind "WindowedApp"
		defines "CL_RELEASE"
		optimize "Speed"
		runtime "Release"
