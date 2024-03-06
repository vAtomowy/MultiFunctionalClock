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

# Podrzedny plik CMakeLists.txt dla testów jednostkowych GPIO 

list(APPEND SOURCE_TEST_DIRS
    ${CMAKE_CURRENT_LIST_DIR}/i2c_test.cpp
)
