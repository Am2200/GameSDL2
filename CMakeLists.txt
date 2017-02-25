cmake_minimum_required(VERSION 3.6)
project(Game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS  "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES    main.cpp
        source/Core.cpp
        headers/Core.h
        headers/FullSDL.h
        headers/ProcessManager.h
        headers/Stack.h
        headers/TextureManager.h
        headers/EnumTypes.h
        source/TextureManager.cpp
        headers/GraphicCore.h
        source/GraphicCore.cpp
        headers/StateManager.h
        source/StateManager.cpp
        headers/IOCore.h
        source/IOCore.cpp
        headers/AudioCore.h
        source/AudioCore.cpp)
add_executable(Game ${SOURCE_FILES})

target_link_libraries(Game SDL2main SDL2 SDL2_image SDL2_mixer SDL2_ttf)