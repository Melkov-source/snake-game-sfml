-- premake5.lua
workspace "Snake"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Snake-Game"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"



include "Snake-Engine/Build-Snake-Engine.lua"
include "Snake-Game/Build-Snake-Game.lua"