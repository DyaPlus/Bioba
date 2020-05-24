#pragma once
#include "biopch.h"

#ifdef BIO_WINDOWS_PLATFORM
	#ifdef BIO_BUILD_DLL
		#define BIO_API __declspec(dllexport)
	#else
		#define BIO_API __declspec(dllimport)
	#endif
#else
	#error Bioba Engine is supported only on windows
#endif

#ifdef BIO_ENABLE_ASSERT
	#define BIO_ENGINE_ASSERT(x) { if(!(x)) { BIO_ENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define BIO_EDITOR_ASSERT(x) { if(!(x)) { BIO_EDITOR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BIO_ENGINE_ASSERT(x) 
	#define BIO_EDITOR_ASSERT(x) 
#endif