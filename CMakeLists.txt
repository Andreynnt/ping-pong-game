cmake_minimum_required(VERSION 3.7)
project(ping_pong)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Core/game_state.h Core/main_game.cpp Core/main_game.h Core/main_menu.cpp Core/main_menu.h
        Core/together_game.cpp Core/together_game.h Entities/background.cpp Entities/background.h Entities/ball.cpp
        Entities/ball.h Entities/entity.h Entities/paddle.h Entities/paddle_ai.cpp Entities/paddle_ai.h
        Entities/paddle_player.cpp Entities/paddle_player.h Entities/score.cpp Entities/score.h)

add_executable(ping_pong ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(ping_pong ${SFML_LIBRARIES})
endif ()