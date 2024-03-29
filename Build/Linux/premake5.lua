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
    kind "staticlib"
    language "C++"
    cppdialect "c++17"
    staticruntime "on"

    targetdir ("Engine")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    pchheader "pch.hpp"
    pchsource "pch.cpp"
    
    	includedirs
    	{
    	    ".",
    	    "Dependencies/fmt/include",
    	    "Dependencies/glad/include",
    	    "Dependencies/glfw/include",
    	    "Dependencies/glm/glm/",
    	    "Dependencies/imgui",
    	    "Dependencies/spdlog/include",
    	    "Dependencies/stb"
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
            "Dependencies/fmt/fmt",
            "Dependencies/glad/glad",
            "Dependencies/glfw/src/glfw3",
            "Dependencies/glm/glm",
            "Dependencies/imgui/imgui",
            "Dependencies/spdlog/spdlog",
            "Dependencies/stb/stb"
        }


        filter "Configurations:Debug"
            defines "ENGINE_DEBUG"
            symbols "on"
            runtime "debug"

        filter "Configurations:Release"
            defines "ENGINE_RELEASE"
            optimize "on"
            runtime "release"

        filter "Configurations:Dist"
            defines "ENGINE_DIST"
            optimize "on"
            runtime "release"



------------------------------------------------------------------------------
-- Test
------------------------------------------------------------------------------

project "Test"
    location "Test"
    kind "ConsoleApp"
    language "C++"
    cppdialect "c++17"
    staticruntime "on"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")
    
        includedirs
        {
            "."
        }
    
        files
        {
            "%{prj.name}/**.cpp",
            "%{prj.name}/**.hpp",
            "%{prj.name}/**.c",
            "%{prj.name}/**.h",
            "%{prj.name}/**.glsl"
        }

        defines
        {
            "PLATFORM_LINUX"
        }

        links
        {
            "Engine/Engine",
            
            -- Links from Engine
            "Dependencies/fmt/fmt",
            "Dependencies/glad/glad",
            "Dependencies/glfw/src/glfw3",
            "Dependencies/glm/glm",
            "Dependencies/imgui/imgui",
            "Dependencies/spdlog/spdlog",
            "Dependencies/stb/stb"
        }
        
        dependson
        {
            "Engine"
        }


        filter "Configurations:Debug"
            symbols "on"

        filter "Configurations:Release"
            optimize "on"

        filter "Configurations:Dist"
            optimize "on"
