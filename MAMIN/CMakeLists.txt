cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(untitled main.cpp FieldCell/Cell.cpp FieldCell/Cell.h FieldCell/Field.cpp FieldCell/Field.h Player.cpp Player.h Controller/Command_Reader.cpp Controller/Command_Reader.h Drawer.cpp Drawer.h Event_Groups/Event_Interface.cpp Event_Groups/Event_Interface.h Event_Groups/Event_Group_Bonus.cpp Event_Groups/Event_Group_Bonus.h Event_Groups/Event_Group_Damage.cpp Event_Groups/Event_Group_Damage.h Events/Event_Damage_Arrow.cpp Events/Event_Damage_Arrow.h Events/Event_Damage_Skull.cpp Events/Event_Damage_Skull.h Event_Groups/Event_Group_Else.cpp Event_Groups/Event_Group_Else.h Events/Event_Else_Wall.cpp Events/Event_Else_Wall.h Events/Event_ELse_None.cpp Events/Event_ELse_None.h Events/Event_Else_Player.cpp Events/Event_Else_Player.h Events/Event_Bonus_Potion.cpp Events/Event_Bonus_Potion.h Events/Event_Bonus_Coin.cpp Events/Event_Bonus_Coin.h Events/Event_Bonus_Key.cpp Events/Event_Bonus_Key.h Controller/Controller_p.cpp Controller/Controller_p.h)

set(SFML_DIR "C:\\Users\\blood\\CLionProjects\\lib\\SFML\\GCC 7.3.0 MinGW (SEH) - 64-bit\\SFML-2.5.1\\lib\\cmake\\SFML")

target_link_libraries(untitled sfml-graphics)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED graphics network audio window system)
