cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE Toolchain-arm-gcc.cmake)

# Allow assembler
enable_language(ASM)

project(MultiFunctionalClock)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})

include(ExternalProject)
ExternalProject_Add(newTest
SOURCE_DIR ${SRC_DIR}/Test
DOWNLOAD_COMMAND ""
INSTALL_COMMAND "ninja -v"
TEST_COMMAND "ctest --verbose"
)
add_subdirectory(${SRC_DIR}/Test)  # Test jest podrzędnym projektem

set(INCLUDE_DIRS
    ${SRC_DIR}/App/Inc
    ${SRC_DIR}/Libs/MyLibs/Low-Level/GPIO/Inc/
    ${SRC_DIR}/Libs/CMSIS/Include
    ${SRC_DIR}/Libs/CMSIS/Device/ST/STM32L4xx/Include
    ${SRC_DIR}/Libs/STM32L4xx_HAL_Driver/Inc/
    ${SRC_DIR}/Libs/STM32L4xx_HAL_Driver/Inc/Legacy
    ${SRC_DIR}/Test/Others/
)

set(C_SRCS
    ${SRC_DIR}/App/Src/main.c
    ${SRC_DIR}/App/Src/stm32l4xx_hal_msp.c
    ${SRC_DIR}/App/Src/stm32l4xx_it.c
    ${SRC_DIR}/App/Src/syscalls.c
    ${SRC_DIR}/App/Src/sysmem.c
    ${SRC_DIR}/App/Src/system_stm32l4xx.c
    ${SRC_DIR}/Libs/MyLibs/Low-Level/GPIO/Src/gpio.c
    ${SRC_DIR}/Libs/STM32L4xx_HAL_Driver/src/stm32l4xx_hal.c
    ${SRC_DIR}/Libs/STM32L4xx_HAL_Driver/src/stm32l4xx_hal_cortex.c
    ${SRC_DIR}/Libs/STM32L4xx_HAL_Driver/src/stm32l4xx_hal_dma.c
    ${SRC_DIR}/Libs/STM32L4xx_HAL_Driver/src/stm32l4xx_hal_dma_ex.c
    ${SRC_DIR}/Libs/STM32L4xx_HAL_Driver/src/stm32l4xx_hal_exti.c
    ${SRC_DIR}/Libs/STM32L4xx_HAL_Driver/src/stm32l4xx_hal_flash.c
    ${SRC_DIR}/Libs/STM32L4xx_HAL_Driver/src/stm32l4xx_hal_flash_ex.c
    ${SRC_DIR}/Libs/STM32L4xx_HAL_Driver/src/stm32l4xx_hal_flash_ramfunc.c
    ${SRC_DIR}/Libs/STM32L4xx_HAL_Driver/src/stm32l4xx_hal_gpio.c
    ${SRC_DIR}/Libs/STM32L4xx_HAL_Driver/src/stm32l4xx_hal_pwr.c
    ${SRC_DIR}/Libs/STM32L4xx_HAL_Driver/src/stm32l4xx_hal_pwr_ex.c
    ${SRC_DIR}/Libs/STM32L4xx_HAL_Driver/src/stm32l4xx_hal_rcc.c
    ${SRC_DIR}/Libs/STM32L4xx_HAL_Driver/src/stm32l4xx_hal_rcc_ex.c
    ${SRC_DIR}/Test/Others/GPIO_TEST.c
)

set(ASM_SRCS
    ${SRC_DIR}/App/Startup/startup_stm32l431rctx.s
)

set(GLOBAL_DEFINES
    -DDEBUG
    -DUSE_HAL_DRIVER
    -DSTM32L431xx
)

# Do linkowania bibliotek 
set(LINKED_LIBS
    # libLibrary.a [sama nazwe bez lib na początku oraz .a na końcu] 
)

link_directories(
    # sciezka do bibliotek statycznych 
)

include_directories(${INCLUDE_DIRS})
add_definitions(${GLOBAL_DEFINES})

include(compiler_flags.cmake)

## ------------------------------TESTS-------------------------------
# Tests TODO: (only Debug !)
# Folder exist ?
if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/Test")
    # If no, create it !
    file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/Test")
endif()

# Ustaw zmienną z nazwą pliku wykonywalnego
set(TEST_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/Test)

option(COMPILE_TESTS "Compile the tests" ON)
if(COMPILE_TESTS)
    message(STATUS "Compiling tests...")
    # add_subdirectory(Test)
endif()



set(TEST_PATH ${SRC_DIR}/Test)
message(STATUS "TEST_PATH: ${TEST_PATH}")

set_property(DIRECTORY PROPERTY ADDITIONAL_MAKE_CLEAN_FILES TEST_OUTPUT_PATH)
## ------------------------------------------------------------------

add_arm_executable(${CMAKE_PROJECT_NAME} ${CPP_SRCS} ${C_SRCS} ${ASM_SRCS})

arm_link_libraries(${CMAKE_PROJECT_NAME} ${LINKED_LIBS})


