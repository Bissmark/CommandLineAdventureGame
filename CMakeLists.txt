cmake_minimum_required(VERSION 3.10)
project(AdventureGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

find_package(SDL3 REQUIRED)
message(STATUS "SDL3 found: ${SDL3_FOUND}")
message(STATUS "SDL3 libraries: ${SDL3_LIBRARIES}")

add_executable(${PROJECT_NAME}
    main.cpp
    player.cpp
    dice.cpp
    character.cpp
    warrior.cpp
    mage.cpp
    rogue.cpp
    shaman.cpp
    enemy.cpp
    gnoll.cpp
    startStory.cpp
    encounter.cpp
    fight.cpp
    displayWindow.cpp
    characterCreationScreen.cpp
    combatScreen.cpp
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_impl_sdl3.cpp
    imgui/imgui_impl_sdlrenderer3.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui_demo.cpp
)

target_link_libraries(AdventureGame PRIVATE
    SDL3::SDL3
)

if(WIN32)
    # Find SDL3 DLL and copy it to build directory
    get_target_property(SDL3_DLL_PATH SDL3::SDL3 IMPORTED_LOCATION)
    if(SDL3_DLL_PATH)
        add_custom_command(TARGET AdventureGame POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SDL3_DLL_PATH}
            $<TARGET_FILE_DIR:AdventureGame>
        )
    endif()
endif()