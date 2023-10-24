#pragma once

#ifdef FL_PLATFORM_WINDOWS
	#ifdef FL_BUILD_DLL
		#define FLARE_API __declspec(dllexport)
	#else
		#define FLARE_API __declspec(dllimport)
	#endif
#else
	#error Windows Only Support
#endif
