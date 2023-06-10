cmake_minimum_required(VERSION 3.25)
include(FetchContent)

set(PROJECT_NAME main)
project (${PROJECT_NAME})

add_executable(${PROJECT_NAME} main.cpp)

# eigen
find_package(Eigen3 REQUIRED)

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_DIR}/include/
    PUBLIC ${EIGEN3_INCLUDE_DIR}
)

# add_subdirectory(test)

target_link_libraries(${PROJECT_NAME} PRIVATE
# external libs
    PUBLIC Eigen3::Eigen
)

# コンパイラ設定
set(CMAKE_C_COMPILER /usr/local/bin/gcc-13)
set(CMAKE_CXX_COMPILER /usr/local/bin/g++-13)

# コンパイラ関連
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_compile_options(${PROJECT_NAME} PUBLIC -O3 -march=native)