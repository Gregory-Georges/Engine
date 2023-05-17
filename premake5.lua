workspace "Engine"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }


    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "Engine"
    location "Engine"
    kind "sharedlib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

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

        postbuildcommands
        {

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



project "Test"
    location "Test"
    kind "ConsoleApp"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

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
            "Engine"
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