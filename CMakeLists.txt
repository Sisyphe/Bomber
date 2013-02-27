project(sfml_test2)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ./inc)

set(sfml_test2_SRCS
  src/collider.cpp
  src/main.cpp
  src/animatedsprite.cpp
  src/collision_manager.cpp
  src/anim.cpp
  src/bomb.cpp
  src/character.cpp
  src/drawbuffer.cpp
  src/imganim.cpp
  src/layer.cpp
  src/localuser.cpp
  src/map.cpp
  src/pausableclock.cpp
  src/tile.cpp
  src/user.cpp
)

set(sfml_test2_LIBS
  sfml-system
  sfml-window
  sfml-graphics
)

qt4_automoc(${sfml_test2_SRCS})
add_executable(sfml_test2 ${sfml_test2_SRCS})
target_link_libraries(sfml_test2 ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${sfml_test2_LIBS})
install(TARGETS sfml_test2 RUNTIME DESTINATION bin)
