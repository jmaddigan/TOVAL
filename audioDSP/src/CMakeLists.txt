# Define the static library for KTEffect
add_library(${KT_LIB} STATIC
    KTEffect/KTdelay.cpp     # KTEffect1 source file
)

# Define the static library for Module1
add_library(${SOFTCLIP_LIB} STATIC
    modules/softClip.cpp    # softClip source file
)

# Specify the include directories for KTEffect library
target_include_directories(${KT_LIB} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/KTEffect"   # Include KTEffect directory
    "${CMAKE_CURRENT_SOURCE_DIR}/include"    # Additional include paths, if necessary
)

# Specify the include directories for Module1 library
target_include_directories(${SOFTCLIP_LIB} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/modules"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"    # Additional include paths for module headers
)

# Link module1_lib with KT_LIB
# This ensures that KT_LIB can use functions from module1_lib
target_link_libraries(${KT_LIB} PRIVATE ${SOFTCLIP_LIB})

# Handle DELIVERY option
if(DELIVERY)
    message(STATUS "DELIVERY option enabled: copying libraries to delivery folder")

    # Define delivery directories based on the toolchain name
    set(DELIVERY_DIR_LIB "${CMAKE_SOURCE_DIR}/delivery/${TOOLCHAIN_NAME}/lib")
    set(DELIVERY_DIR_INC "${CMAKE_SOURCE_DIR}/delivery/${TOOLCHAIN_NAME}/inc")

    # Ensure the directories exist
    file(MAKE_DIRECTORY ${DELIVERY_DIR_LIB})
    file(MAKE_DIRECTORY ${DELIVERY_DIR_INC})

    # Install the KTEffect library to the delivery lib folder
    install(TARGETS ${KT_LIB}
            ARCHIVE DESTINATION ${DELIVERY_DIR_LIB}
            LIBRARY DESTINATION ${DELIVERY_DIR_LIB}
            RUNTIME DESTINATION ${DELIVERY_DIR_LIB})

    # Install the headers directly into the delivery inc folder
    install(FILES
        ${CMAKE_SOURCE_DIR}/audioDSP/inc/KTEffect/KTdelay.h  # Add header files explicitly
        DESTINATION ${DELIVERY_DIR_INC}                        # Copy directly to the inc folder
    )
endif()

# Ensure CMake knows how to install targets
include(GNUInstallDirs)
