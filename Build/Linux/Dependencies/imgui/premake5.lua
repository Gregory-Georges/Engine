require "codeblocks"
workspace "imgui"
    architecture "x64"
    configurations
    {
        "Dist"
    }


    outputdir = "./"



------------------------------------------------------------------------------
-- ImGui
------------------------------------------------------------------------------

project "imgui"
    location "."
    kind "staticlib"
    language "C++"
    cppdialect "c++17"
    staticruntime "on"

    targetdir ("./")
    objdir ("./")
    
    	includedirs
    	{
    	    "."
    	}

        files
        {
            "*.h",
            "*.c",
            "*.hpp",
            "*.cpp"
        }

        defines
        {
            "PLATFORM_LINUX",
        }

        filter "Configurations:Dist"
            optimize "on"
            runtime "release"
