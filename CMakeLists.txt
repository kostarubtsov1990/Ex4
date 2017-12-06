cmake_minimum_required(VERSION 3.8)
project(Ex4Client)

set(CMAKE_CXX_STANDARD 98)

set(HEADER_FILES
        include/Board.h
        include/ReversiGame.h
        include/Game.h
        include/GameLogic.h
        include/Cell.h
        include/GameFlow.h
        include/MultiPlayerFlow.h
        include/DefaultLogic.h
        include/SinglePlayerFlow.h
        include/GameMenu.h
        include/ReversiGameMenu.h
        )

set(SOURCE_FILES
        src/Board.cpp
        src/ReversiGame.cpp
        src/Game.cpp
        src/GameLogic.cpp
        src/Cell.cpp
        src/GameFlow.cpp
        src/MultiPlayerFlow.cpp
        src/DefaultLogic.cpp
        src/SinglePlayerFlow.cpp
        src/GameMenu.cpp
        src/ReversiGameMenu.cpp
        )

add_library(reversiGame STATIC ${SOURCE_FILES} ${HEADER_FILES})

set(SOURCE_FILES main.cpp src/GameClient.cpp include/GameClient.h)
add_executable(Ex4Client ${SOURCE_FILES})

add_subdirectory(test)

target_link_libraries(Ex4Client reversiGame)


