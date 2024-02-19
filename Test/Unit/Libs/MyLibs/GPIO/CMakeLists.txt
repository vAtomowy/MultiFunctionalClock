# ----------------------------CMakeLists.txt MiniMAP--------------------------------
# ----------------------------------------------------------------------------------
# ├── Project
# │   └── [CMakeLists.txt]
# │   └── Test
# │       └── [CMakeLists.txt] 
# │       ├── App
# │       │   ├── [CMakeLists.txt]
# │       │   └── tests.c
# │       └── MyLibs
# │           ├── [CMakeLists.txt] 
# │           └── Low-Level
# │               ├── GPIO
# │               │   └── [CMakeLists.txt] <<<<<<<<<< [You are here] <<<<<<<<<
# │               ├── I2C
# │               │   └── [CMakeLists.txt]
# │               ├── QSPI
# │               │   └── [CMakeLists.txt]
# │               └── UART
# │                   └── [CMakeLists.txt]
# │           ├── Other
# │               └── [CMakeLists.txt]
# │           └── Devices
# │               └── [CMakeLists.txt]
# ----------------------------------------------------------------------------------

# Podrzedny plik CMakeLists.txt dla testów jednostkowych

# (1) Dodaj pliki źródłowe testów
set(TEST_SOURCES
    gpio_test.cpp
)

# (2) Stwórz cel wykonawczy dla testów
add_executable(unit_tests ${TEST_SOURCES})

# (3) Dodaj biblioteki potrzebne do testów (CppUTest)
target_link_libraries(unit_tests CppUTest CppUTestExt)

# (4) Dodaj polecenie wykonania testów
add_custom_target(run_tests
    COMMAND x86_64-w64-mingw32-g++
    COMMENT "Running unit tests"
    DEPENDS gpio_tests
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
