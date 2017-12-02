cmake_minimum_required(VERSION 3.8)
project(Ex4)

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
#set(SOURCE_FILES main.cpp src/Board.cpp include/Board.h src/ReversiGame.cpp include/ReversiGame.h src/Game.cpp include/Game.h src/GameLogic.cpp include/GameLogic.h src/Cell.cpp include/Cell.h src/GameFlow.cpp include/GameFlow.h src/MultiPlayerFlow.cpp include/MultiPlayerFlow.h src/DefaultLogic.cpp include/DefaultLogic.h src/SinglePlayerFlow.cpp include/SinglePlayerFlow.h src/GameMenu.cpp include/GameMenu.h src/ReversiGameMenu.cpp include/ReversiGameMenu.h)
#add_executable(Ex3 ${SOURCE_FILES})

set(SOURCE_FILES main.cpp)
add_executable(Ex4 ${SOURCE_FILES})

target_link_libraries(Ex4 reversiGame)


