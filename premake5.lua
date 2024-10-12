workspace "NemesTihamer-ProgCompetetion-V_2010-14"
    architecture "x64"

    configurations {
        "Debug",
        "FastDebug",
        "Release",
    }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Page21"
    location "Page21"
    kind "ConsoleApp"
    language "C++"

    targetdir ("%{prj.location}/Bin/" .. outputDir)
    objdir ("%{prj.location}/Obj/" .. outputDir)

    files {
        "%{prj.location}/Src/**.cpp",
        "%{prj.location}/Headers/**.h",
    }

    includedirs {
        "%{prj.location}/Headers/",
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

    filter "configurations:Debug"
        symbols "On"

    filter "configurations:FastDebug"
        optimize "On"

    filter "configurations:Release"
        optimize "On"
