require "codeblocks"
workspace "Engine"
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
            "%**.h",
            "%**.hpp",
            "%**.cpp"
        }
        

        filter "Configurations:Dist"
            optimize "on"
