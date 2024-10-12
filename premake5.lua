workspace "NemesTihamer-ProgCompetetion-V_2010-14"
    architecture "x64"

    configurations {
        "Debug",
        "FastDebug",
        "Release",
    }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Page 21"
    location "Page21"
    kind "ConsoleApp"
    language "C++"

    targetdir ("Bin/" .. outputDir .. "/%{prj.name}")
    objdir ("Obj/" .. outputDir .. "/%{prj.name}")

    files {
        "%{prj.name}/Src/**.cpp",
        "%{prj.name}/Headers/**.h",
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
