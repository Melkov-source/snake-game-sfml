project "Snake-Game"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   targetdir "Bin/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp" }

   includedirs
   {
      "Source",
	  
	  "../Snake-Engine/Source",
	  "../Snake-Engine/Source/Plugins/ImGui",
   }

   links
   {
        "Snake-Engine",
        "sfml-graphics", 
	    "sfml-window", 
	    "sfml-system",
	    "GL"
   }

   targetdir ("../Bin/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Bin/Intermediates/" .. OutputDir .. "/%{prj.name}")
   
    postbuildcommands {
	    '{COPY} "%{cfg.projectdir}Assets" "%{cfg.targetdir}\\Assets"'
    }


   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"
	   

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"