require "codeblocks"
workspace "glad"
    architecture "x64"
    configurations
    {
        "Dist"
    }


    outputdir = "."


project "glad"
    location "."
    kind "staticlib"
    language "C++"

    targetdir (outputdir)
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
        

        filter "Configurations:Dist"
            optimize "on"
