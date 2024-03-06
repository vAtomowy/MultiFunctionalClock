# ----------------------------CMakeLists.txt MiniMAP--------------------------------
# ----------------------------------------------------------------------------------
# ├── Project
# |   └── [CMakeLists.txt]
# |   └── Test
# |       └── [CMakeLists.txt] <<<<<<<<<< [You are here] <<<<<<<<<
# |       ├── Unit
# |       |   ├── [CMakeLists.txt] 
# |       │   ├── App
# |       │   │   ├── [CMakeLists.txt]
# |       │   │   └── tests.c 
# |       │   └── Libs
# |       │       ├── [CMakeLists.txt] 
# |       │       └── MyLibs
# |       │           ├── [CMakeLists.txt] 
# |       │           ├── Low-Level
# |       |           |   ├── [CMakeLists.txt] 
# |       │           │   ├── GPIO
# |       │           │   │   └── [CMakeLists.txt]
# |       │           │   ├── I2C
# |       │           │   │   └── [CMakeLists.txt]
# |       │           │   ├── QSPI
# |       │           │   │   └── [CMakeLists.txt]
# |       │           │   └── UART
# |       │           │       └── [CMakeLists.txt]
# |       │           ├── Other
# |       │           │   └── [CMakeLists.txt]
# |       │           └── Devices
# |       │               └── [CMakeLists.txt]
# |       ├── Others
# |       │   ├── [CMakeLists.txt]
# |       │   └── <other files and directories>
# |       └── Integration
# |           ├── [CMakeLists.txt]
# |           └── <other files and directories>
# ----------------------------------------------------------------------------------

#add_subdirectory(App)
#add_subdirectory(Unit)

cmake_minimum_required(VERSION 3.5)
project(Test)

add_custom_target(Test
    COMMAND ${CMAKE_CTEST_COMMAND} --verbose
)

include(CTest)
# Ustaw kompilator
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)

# Ustaw ścieżkę do plików źródłowych
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}) 

set(INCLUDE_TEST_DIRS)
set(SOURCE_TEST_DIRS
    #${SRC_DIR}/Unit/Libs/MyLibs/Low-Level/GPIO/gpio_test.cpp
)

include(Unit/CMakeLists.txt)

# Dodaj pliki źródłowe z podrzędnego katalogu do listy plików źródłowych
# add_subdirectory(Unit)

message("Nazwa biblioteki w podrzędnym pliczku: ${SOURCE_TEST_DIRS}")

# Iteruj przez każdy plik źródłowy testu
foreach(TEST_SOURCE ${SOURCE_TEST_DIRS})
    # Uzyskaj nazwę testu (bez rozszerzenia)
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    
    message("TEST BUILDING: ${TEST_NAME}")
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_include_directories(${TEST_NAME} PUBLIC ${INCLUDE_TEST_DIRS})
    target_link_libraries(${TEST_NAME} PUBLIC CppUTest CppUTestExt)

    # Dodaj test jako cel testowy dla narzędzia CTest
    add_test(NAME ${TEST_NAME}  COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${TEST_NAME}.exe)
    message("TEST BUILDING: ${CMAKE_CURRENT_BINARY_DIR}/${TEST_NAME}.exe")

endforeach()
