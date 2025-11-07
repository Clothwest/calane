project "glad"
	kind "StaticLib"
	language "C"

	targetdir("../../../.bin/" .. outputDir .. "%{prj.name}/")
	objdir("../../../.bin-int/" .. outputDir .. "%{prj.name}/")

	files
	{
		"include/glad/glad.h",
		"include/KHR/khrplatform.h",
		"src/glad.c"
	}

	includedirs
	{
		"include"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "CL_DEBUG"
		symbols "On"
		runtime "Debug"

	filter "configurations:Release"
		defines "CL_RELEASE"
		optimize "Speed"
		runtime "Release"
