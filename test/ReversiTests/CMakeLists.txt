include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(reversiGamegTests test_DefaultLogic.cpp BoardTest.h BoardTest.cpp UpdateBoardTest.cpp UpdateBoardTest.h WinOrLoseTest.cpp WinOrLoseTest.h)

target_link_libraries(reversiGamegTests gtest gtest_main)
target_link_libraries(reversiGamegTests reversiGame)