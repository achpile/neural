CMAKE_MINIMUM_REQUIRED ( VERSION 2.8 )
PROJECT ( neural )

INCLUDE_DIRECTORIES ("include" "include/meta" "include/steam" )
FILE ( GLOB SRC "src/*/*.cpp" )


IF ( WIN32 )

        SET ( CMAKE_CXX_FLAGS  "-DSFML_STATIC -s -std=c++11" )
        SET ( CMAKE_EXE_LINKER_FLAGS  "-mwindows -static-libgcc -static-libstdc++ -static -Wl,-Bstatic -Wl,-rpath,./lib/" )
        SET ( CMAKE_LINK_LIBS steam_api sfml-audio-s sfml-graphics-s sfml-window-s sfml-system-s winmm opengl32 gdi32 freetype glew jpeg opengl32 openal32 pthread FLAC vorbisfile vorbisenc vorbis ogg sndfile m jansson )

ELSEIF ( APPLE )

        SET ( CMAKE_RESOURCE  "" )
        SET ( CMAKE_CXX_FLAGS  "-std=c++11" )
        SET ( CMAKE_EXE_LINKER_FLAGS  "-L./lib -Wl,-rpath,./lib/" )
        SET ( CMAKE_LINK_LIBS steam_api sfml-audio sfml-graphics sfml-window sfml-system m jansson )

ELSEIF ( UNIX )

        SET ( CMAKE_RESOURCE  "" )
        SET ( CMAKE_CXX_FLAGS  "-s -std=c++11" )
        SET ( CMAKE_EXE_LINKER_FLAGS  "-s -static-libgcc -static-libstdc++ -L./lib -Wl,-rpath,./lib/" )
        SET ( CMAKE_LINK_LIBS steam_api sfml-audio sfml-graphics sfml-window sfml-system m jansson )

ENDIF ( )


ADD_EXECUTABLE ( neural ${SRC} ${CMAKE_RESOURCE} )
TARGET_LINK_LIBRARIES ( neural  ${CMAKE_LINK_LIBS} )
