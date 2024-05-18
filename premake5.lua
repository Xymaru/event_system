workspace "eventsystem"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }
    startproject "eventsystem"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "dependencies.lua"

include "eventsystem"