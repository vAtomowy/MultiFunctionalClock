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
# |       |           |   ├── [CMakeLists.txt] <<<<<<<<<< [You are here] <<<<<<<<<
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

include( ${CMAKE_CURRENT_LIST_DIR}/GPIO/CMakeLists.txt)
include( ${CMAKE_CURRENT_LIST_DIR}/I2C/CMakeLists.txt)
# add_subdirectory(I2C)
# add_subdirectory(QSPI)
# add_subdirectory(UART)
