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
	  
	  "../Vendor/Library/SFML/include"
   }

   links
   {
      "Snake-Engine"
   }
 
   libdirs
   {
		"../Vendor/Library/SFML/lib"
   }

   targetdir ("../Bin/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Bin/Intermediates/" .. OutputDir .. "/%{prj.name}")
   
   postbuildcommands {
	   '{COPY} "%{wks.location}Vendor\\Library\\SFML\\bin\\*.dll" "%{cfg.targetdir}"',
	   '{COPY} "%{cfg.projectdir}Assets" "%{cfg.targetdir}\\Assets"'
   }


   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }

   filter "configurations:Debug"
       --defines { "DEBUG" }
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