#pragma once
#if defined( WIN32 )

#if defined( RAMBER_IMPORT )
#define RAMBER_API __declspec( dllimport )
#else
#define RAMBER_API __declspec( dllexport )
#endif

#else

#define RAMBER_API __attribute__(( __visibility__( "default" ) ))

#endif
