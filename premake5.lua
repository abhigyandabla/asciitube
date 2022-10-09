-- premake5.lua

require "export-compile-commands"
workspace "gentobe"
   configurations { "Debug", "Release" }

project "gentobe"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
includedirs { "./include/" }
   files {  "src/**.cpp" }
   links{"ncurses"}

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

if _ACTION == "clean" then
   os.rmdir("./something")
end
