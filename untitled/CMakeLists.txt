cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(untitled main.cpp Cell.cpp Cell.h Field.cpp Field.h Player.cpp Player.h Controller.cpp Controller.h Drawer.cpp Drawer.h Event_Interface.cpp Event_Interface.h Event_Group_Bonus.cpp Event_Group_Bonus.h Event_Group_Damage.cpp Event_Group_Damage.h Event_Damage_Arrow.cpp Event_Damage_Arrow.h Event_Damage_Skull.cpp Event_Damage_Skull.h)

set(SFML_DIR "C:\\Users\\blood\\CLionProjects\\lib\\SFML\\GCC 7.3.0 MinGW (SEH) - 64-bit\\SFML-2.5.1\\lib\\cmake\\SFML")

target_link_libraries(untitled sfml-graphics)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED graphics network audio window system)
