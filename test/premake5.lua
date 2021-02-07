project "Test"
	kind "ConsoleApp"
	language "C++"
    warnings "Extra"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Trigger/src",
        "%{wks.location}/thirdparty/catch2/src",
        "%{wks.location}/thirdparty/catch2_simple",
	}

	links
	{
		"Trigger"
	}

	filter "system:windows"
		systemversion "latest"

    filter "configurations:Debug"
		defines "TR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "TR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "TR_DIST"
		runtime "Release"
		optimize "on"

    filter "configurations:Test"
        defines "TR_TEST"
