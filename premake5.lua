-- premake5.lua
workspace "gentobe"
   configurations { "Debug", "Release" }

project "gentobe"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files { "include/**.h", "src/**.cpp" }
   links{"ncurses"}

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
