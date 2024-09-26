cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(Curves)

add_library(${PROJECT_NAME} SHARED ./src/${PROJECT_NAME}.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/inc)
target_sources(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/inc/${PROJECT_NAME}.h)

add_executable(${PROJECT_NAME}Exe ./src/Main.cpp)
target_include_directories(${PROJECT_NAME}Exe PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/inc)
target_sources(${PROJECT_NAME}Exe PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/inc/${PROJECT_NAME}.h)
target_link_libraries(${PROJECT_NAME}Exe ${PROJECT_NAME})