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

# add_subdirectory(App)
add_subdirectory(Unit)



