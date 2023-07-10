require "codeblocks"
workspace "Engine"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }


    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"



------------------------------------------------------------------------------
-- Engine
------------------------------------------------------------------------------

project "Engine"
    location "Engine"
    kind "sharedlib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    pchheader "pch.hpp"
    pchsource "pch.cpp"
    
    	includedirs
    	{
    	    "Dependencies/glad/include",
    	    "Dependencies/imgui"
    	}
    	
    	postbuildcommands
    	{
    	    "cp ../bin/" .. outputdir .. "/%{prj.name}/libEngine.so ../Test/"
    	}

        files
        {
            "%{prj.name}/**.h",
            "%{prj.name}/**.c",
            "%{prj.name}/**.hpp",
            "%{prj.name}/**.cpp"
        }

        defines
        {
            "PLATFORM_LINUX",
        }
        
        links
        {
            "fmt",
            "spdlog",
            "glfw",
            "GL",
            "Dependencies/glad/glad",
            "Dependencies/imgui/imgui"
        }


        filter "Configurations:Debug"
            defines "ENGINE_DEBUG"
            optimize "on"

        filter "Configurations:Release"
            defines "ENGINE_RELEASE"
            optimize "on"

        filter "Configurations:Dist"
            defines "ENGINE_DIST"
            optimize "on"



------------------------------------------------------------------------------
-- Test
------------------------------------------------------------------------------

project "Test"
    location "Test"
    kind "ConsoleApp"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")
    
        files
        {
            "%{prj.name}/**.cpp",
            "%{prj.name}/**.hpp",
            "%{prj.name}/**.c",
            "%{prj.name}/**.h"
        }
        
        includedirs
        {
            "include",
            "Dependencies/glad/include",
            "Dependencies/imgui/imgui"
        }
    	
    	files
        {
            "%{prj.name}/**.h",
            "%{prj.name}/**.hpp",
            "%{prj.name}/**.cpp"
        }

        defines
        {
            "PLATFORM_LINUX",
        }

        links
        {
            "fmt",
            "spdlog",
            "glfw",
            "GL",
            "Engine",
            "Dependencies/glad/glad",
            "Dependencies/imgui/imgui"
        }


        filter "Configurations:Debug"
            defines "ENGINE_DEBUG"
            optimize "on"

        filter "Configurations:Release"
            defines "ENGINE_RELEASE"
            optimize "on"

        filter "Configurations:Dist"
            defines "ENGINE_DIST"
            optimize "on"
            
            
       
------------------------------------------------------------------------------
-- glad
------------------------------------------------------------------------------
     
project "glad"
    location "Dependencies/glad"
    kind "sharedlib"
    language "C++"

    targetdir ("Dependencies/glad/")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
        files
        {
            "Dependencies/glad/src/glad.c"
        }
        
        includedirs
        {
            "Dependencies/glad/include"
        }
        

        filter "Configurations:Debug"
            optimize "on"

        filter "Configurations:Release"
            optimize "on"

        filter "Configurations:Dist"
            optimize "on"
            
            
            
------------------------------------------------------------------------------
-- imgui
------------------------------------------------------------------------------
     
project "imgui"
    location "Dependencies/imgui"
    kind "sharedlib"
    language "C++"

    targetdir ("Dependencies/imgui/")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
        files
        {
            "Dependencies/imgui/*.cpp",
            "Dependencies/imgui/backends/imgui_impl_opengl3.cpp",
            "Dependencies/imgui/backends/imgui_impl_glfw.cpp"
        }
        
        includedirs
        {
            "Dependencies/imgui/"
        }

        filter "Configurations:Debug"
            optimize "on"

        filter "Configurations:Release"
            optimize "on"

        filter "Configurations:Dist"
            optimize "on"
            
            
            

