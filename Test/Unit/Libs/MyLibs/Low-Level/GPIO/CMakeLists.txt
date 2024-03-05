# ----------------------------CMakeLists.txt MiniMAP--------------------------------
# ----------------------------------------------------------------------------------
# ├── Project
# |   └── [CMakeLists.txt]
# |   └── Test
# |       └── [CMakeLists.txt]
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
# |       │           │   │   └── [CMakeLists.txt] <<<<<<<<<< [You are here] <<<<<<<<<
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

# Podrzedny plik CMakeLists.txt dla testów jednostkowych

# (4) Dodaj polecenie wykonania testów
add_custom_target(build_gpio_target
    COMMAND x86_64-w64-mingw32-g++ -o ${TEST_OUTPUT_PATH}/gpio_test ${CMAKE_CURRENT_SOURCE_DIR}/gpio_test.cpp -lCppUTest -lCppUTestExt
    COMMENT "Build unit GPIO tests"
)

# # Wykonaj niestandardowy cel podczas budowy całego projektu
# add_dependencies(${CMAKE_PROJECT_NAME} build_gpio_target)
