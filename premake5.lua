project "stc"
    kind "StaticLib"
    language "C"
    staticruntime "on"

    targetdir (Output.bin.."%{prj.name}")
    objdir (Output.obj.."%{prj.name}")

    files
    {
        "include/**.h",
        "src/**.h",
        "src/**.c"
    }

    includedirs
    {
        "src",
        "include"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug*"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release*"
        runtime "Release"
        optimize "on"
