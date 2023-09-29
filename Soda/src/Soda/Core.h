#pragma once

// NOW This is where we have our ASSERTS and... well basically the MACROS we want to use in our project

// #include "Logger.h"

// We use this BIT operation to make checking easier on the compiler without bools to check if an IsEventHappning is true or not
#define BIT(x) (1 << x)

// this is the binding function that binds the function you specify to a certain lamda
#define BIND_FN(x) std::bind(&x, this, std::placeholders::_1)


// if we are in Windows then we use this code
#ifdef SD_PLATFORM_WIN
	// shortening the __declspec(dllimport/dllexport) thing
	#ifdef SD_DLL_BUILD
		#define SD_DLL __declspec(dllexport)
	#else
		#define SD_DLL __declspec(dllimport)
	#endif
#else
	#error Sorry bruh... Soda Engine is only on Windows right now!
	// yeaaa ill add other platforms later... soon... idk.
#endif

#ifdef SD_ENABLE_ASSERTS // This sets if you want ASSERT functions in the project
	// this is for the user
	#define SD_ASSERT(x, ...)\
		{if(!(x))\
		{\
			SD_ERROR("ERRORRR... while asserting {0}", __VA_ARGS__);\
			__debugbreak();\
		}}
	// this is for the Engine
	#define SD_ENGINE_ASSERT(x, ...)\
		{if(!(x))\
		{\
			SD_ENGINE_ERROR("ERRORRR... while asserting {0}", __VA_ARGS__);\
			__debugbreak();\
		}}
#else
	// well if you dont want ASSERTS (prob dont in Release or Dist) then this is your part
	#define SD_ASSERT(x, ...)
	#define SD_ENGINE_ASSERT(x, ...)
#endif