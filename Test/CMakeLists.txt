# ----------------------------CMakeLists.txt MiniMAP--------------------------------
# ----------------------------------------------------------------------------------
# ├── Project
# │   └── [CMakeLists.txt]
# │   └── Test
# │       └── [CMakeLists.txt] <<<<<<<<<< [You are here] <<<<<<<<<
# │       ├── App
# │       │   ├── [CMakeLists.txt]
# │       │   └── tests.c
# │       └── MyLibs
# │           ├── [CMakeLists.txt]
# │           └── Low-Level
# │               ├── GPIO
# │               │   └── [CMakeLists.txt]
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

# add_subdirectory(App)
add_subdirectory(MyLibs)



