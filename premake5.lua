include "./thirdparty/premake/premake_customization/solution_items.lua"

workspace "Trigger"
    architecture "x86_64"
    startproject "Test"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
    }
    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "thirdparty/premake"
group ""

include "Trigger"
include "Sandbox"
include "Test"