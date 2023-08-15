require "codeblocks"
workspace "stb"
    architecture "x64"
    configurations
    {
        "Release"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    
	project "stb"
	    kind "StaticLib"
	    language "C"
	    staticruntime "on"
	    
	    targetdir (".")
	    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	    files
	    {
		"stb_image.cpp",
		"stb_image.h"
	    }

	    filter "configurations:Release"
		runtime "Release"
		optimize "on"
