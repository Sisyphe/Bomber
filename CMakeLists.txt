project(sfml_test2)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(sfml_test2_SRCS sfml_test2.cpp main.cpp)
qt4_automoc(${sfml_test2_SRCS})
add_executable(sfml_test2 ${sfml_test2_SRCS})
target_link_libraries(sfml_test2 ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
install(TARGETS sfml_test2 RUNTIME DESTINATION bin)
