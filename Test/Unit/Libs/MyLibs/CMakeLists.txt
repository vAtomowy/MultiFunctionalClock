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
# │           ├── [CMakeLists.txt] <<<<<<<<<< [You are here] <<<<<<<<<
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

add_subdirectory(GPIO)
# add_subdirectory(I2C)
# add_subdirectory(QSPI)
# add_subdirectory(UART)