#pragma once

#ifdef BIO_WINDOWS_PLATFORM
	#ifdef BIO_BUILD_DLL
		#define BIO_API __declspec(dllexport)
	#else
		#define BIO_API __declspec(dllimport)
	#endif
#else
	#error Bioba Engine is supported only on windows
#endif