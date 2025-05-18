file(GLOB_RECURSE SOURCES "*.cpp" "*.hpp")

add_library(searchNumberOfConnectedComponentsModule SHARED ${SOURCES})
target_link_libraries(searchNumberOfConnectedComponentsModule LINK_PRIVATE sc-memory)
target_include_directories(searchNumberOfConnectedComponentsModule PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})