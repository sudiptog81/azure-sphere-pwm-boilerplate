cmake_minimum_required(VERSION 3.10)

project(main C)

azsphere_configure_tools(TOOLS_REVISION "20.04")
azsphere_configure_api(TARGET_API_SET "5+Beta2004")

file(GLOB_RECURSE srcFiles src/*.c)
add_executable(${PROJECT_NAME} ${srcFiles})

target_link_libraries(${PROJECT_NAME} applibs pthread gcc_s c)

azsphere_target_hardware_definition(
    ${PROJECT_NAME} 
    TARGET_DIRECTORY "C:/Program Files (x86)/Microsoft Azure Sphere SDK/Hardware/avnet_mt3620_sk" 
    TARGET_DEFINITION "avnet_mt3620_sk.json"
)

azsphere_target_add_image_package(${PROJECT_NAME})
