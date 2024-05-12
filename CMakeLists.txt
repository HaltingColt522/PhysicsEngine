cmake_minimum_required(VERSION 3.25)

include(FetchContent)

project(PhysicsEngine VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)

find_package(Vulkan REQUIRED)

FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw.git GIT_TAG master)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
       glm
       GIT_REPOSITORY https://github.com/g-truc/glm.git
       GIT_TAG ${IGG_GLM_TAG}
)
FetchContent_MakeAvailable(glm)

file(GLOB SRC_files CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

add_executable(PhysicsEngine ${SRC_files})
target_include_directories(${PROJECT_NAME} PUBLIC "header" PUBLIC ${Vulkan_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE glfw Vulkan::Vulkan glm)