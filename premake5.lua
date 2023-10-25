workspace "Flare"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Flare"
    location "Flare"
    kind "SharedLib"
    language "C++"

    targetdir ("Build/" .. OutputDir .. "/%{prj.name}")
    objdir ("Build/" .. OutputDir .. "/%{prj.name}/Int")

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp",
    }

    includedirs
    {
        '%{prj.name}/vendor/spdlog/include'
    }

    filter "system:windows"
        cppdialect "C++20"
        cdialect "C17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "FL_PLATFORM_WINDOWS",
            "FL_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../Build/" .. OutputDir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "HZ_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "HZ_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HZ_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("Build/" .. OutputDir .. "/%{prj.name}")
    objdir ("Build/" .. OutputDir .. "/%{prj.name}/Int")

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp",
    }

    includedirs
    {
        'Flare/vendor/spdlog/include',
        "Flare/Source"
    }

    links
    {
        "Flare"
    }

    filter "system:windows"
        cppdialect "C++20"
        cdialect "C17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "FL_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "HZ_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "HZ_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HZ_DIST"
        optimize "On"