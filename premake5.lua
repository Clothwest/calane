workspace "calculator-for-planes"
	architecture "x64"
	staticruntime "On"
	
	startproject "cfp"

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

project "cfp"
	location "cfp"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir(".bin/" .. outputDir .. "%{prj.name}/")
	objdir(".bin-int/" .. outputDir .. "%{prj.name}/")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/fmt/include",
	}

	defines
	{
		"FMT_HEADER_ONLY"
	}

	filter "system:window"
		systemversion "latest"

	filter "configurations:Debug"
		defines "CFP_DEBUG"
		symbols "On"
		runtime "Debug"

	filter "configurations:Release"
		defines "CFP_RELEASE"
		optimize "Speed"
		runtime "Release"
