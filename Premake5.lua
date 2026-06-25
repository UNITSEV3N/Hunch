outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"

workspace "Learn"
	architecture "x64"
	startproject "GuessingGame"
	
	configurations
	{
		"Debug",
		"Release"
	}

project "Guessing"
	location "Guessing"
	kind "ConsoleApp"
	language "C++"
	targetname "%{prj.name}"
	cppdialect "C++20"
	systemversion "latest"
	multiprocessorcompile "On"
	buildoptions { "/utf-8" }

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	filter "configurations:Debug"
		defines "OPENR_DEBUG"
		symbols "On"
		runtime "Debug"

	filter "configurations:Release"
		defines "OPENR_RELEASE"
		optimize "On"
		symbols "Off"
		runtime "Release"