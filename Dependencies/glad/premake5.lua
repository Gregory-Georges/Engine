require "codeblocks"
workspace "Glad"
    architecture "x64"
    configurations
    {
        "Release"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    
	project "Glad"
	    kind "StaticLib"
	    language "C"
	    staticruntime "off"
	    
	    targetdir (".")
	    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

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

	    filter "configurations:Release"
		runtime "Release"
		optimize "on"
