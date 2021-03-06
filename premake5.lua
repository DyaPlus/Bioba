workspace "Bioba-GameEngine"
    configurations { "Debug", "Release" , "Dist" }
    startproject "Editor"
    architecture "x64"

output_dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Bioba/vendor/GLFW/include"
IncludeDir["Glad"] = "Bioba/vendor/Glad/include"
IncludeDir["ImGui"] = "Bioba/vendor/ImGui"
IncludeDir["glm"] = "Bioba/vendor/glm"


include "Bioba/vendor/GLFW"
include "Bioba/vendor/Glad"
include "Bioba/vendor/ImGui"

project "Bioba"
    location "Bioba"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. output_dir .. "/%{prj.name}")
    objdir ("bin-int/" .. output_dir .. "/%{prj.name}")

    pchheader "biopch.h"
    pchsource "Bioba/src/biopch.cpp"
    
    files { 
    "%{prj.name}/src/**.h", 
    "%{prj.name}/src/**.cpp",
    "%{prj.name}/vendor/glm/glm/**.hpp",
    "%{prj.name}/vendor/glm/glm/**.inl"
    }

    includedirs {
    "%{prj.name}/src",
    "%{prj.name}/vendor/spdlog/include",
    "%{IncludeDir.GLFW}",
    "%{IncludeDir.Glad}",
    "%{IncludeDir.ImGui}",
    "%{IncludeDir.glm}"
    }
    
    links {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter { "system:windows" }
        cppdialect "C++17"
        systemversion "latest"
            
        defines {
        "BIO_BUILD_DLL",
        "BIO_WINDOWS_PLATFORM",
        "GLFW_INCLUDE_NONE",
        "BIO_ENABLE_ASSERT"
        }
        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. output_dir .. "/Editor")
		}

    filter { "configurations:Debug" }
        defines { "BIO_DEBUG" }
        runtime "Debug"
        symbols "On"
    filter { "configurations:Release" }
        defines { "BIO_RELEASE" }
        runtime "Release"
        optimize "On"
    filter { "configurations:Dist" }
        defines { "BIO_DIST" }
        runtime "Release"
        optimize "On"


project "Editor"
    location "Editor"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. output_dir .. "/%{prj.name}")
    objdir ("bin-int/" .. output_dir .. "/%{prj.name}")
    files { 
    "%{prj.name}/src/**.h", 
    "%{prj.name}/src/**.cpp" 
    }

    includedirs {
    "Bioba/vendor/spdlog/include",
    "Bioba/src"
	}

    links {
     "Bioba"
	}
    filter { "system:windows" }
        cppdialect "C++17"
        systemversion "latest"
            
        defines {
        "BIO_WINDOWS_PLATFORM"
        }

    filter { "configurations:Debug" }
        defines { "BIO_DEBUG" }
        runtime "Debug"
        symbols "On"
    filter { "configurations:Release" }
        defines { "BIO_RELEASE" }
        runtime "Release"
        optimize "On"
    filter { "configurations:Dist" }
        defines { "BIO_DIST" }
        runtime "Release"
        optimize "On"