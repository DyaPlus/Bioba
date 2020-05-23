workspace "Bioba-GameEngine"
    configurations { "Debug", "Release" , "Dist" }
    startproject "Editor"
    architecture "x64"

output_dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Bioba"
    location "Bioba"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. output_dir .. "/%{prj.name}")
    objdir ("bin-int/" .. output_dir .. "/%{prj.name}")
    files { 
    "%{prj.name}/src/**.h", 
    "%{prj.name}/src/**.cpp" 
    }

    includedirs {
    "%{prj.name}/vendor/spdlog/include",
	}

    filter { "system:windows" }
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
            
        defines {
        "BIO_BUILD_DLL",
        "BIO_WINDOWS_PLATFORM";
        }
        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. output_dir .. "/Editor")
		}

    filter { "configurations:Debug" }
        defines { "BIO_DEBUG" }
        symbols "On"
    filter { "configurations:Release" }
        defines { "BIO_RELEASE" }
        optimize "On"
    filter { "configurations:Dist" }
        defines { "BIO_DIST" }
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
        staticruntime "On"
        systemversion "latest"
            
        defines {
        "BIO_WINDOWS_PLATFORM"
        }

    filter { "configurations:Debug" }
        defines { "BIO_DEBUG" }
        symbols "On"
    filter { "configurations:Release" }
        defines { "BIO_RELEASE" }
        optimize "On"
    filter { "configurations:Dist" }
        defines { "BIO_DIST" }
        optimize "On"