
file(GLOB_RECURSE KT_LIB_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/KTEffect/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modules/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/primatives/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/utils/*.cpp"
)

add_library(${KT_LIB} STATIC ${KT_LIB_SOURCES})

# Include directories for headers
target_include_directories(${KT_LIB} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/KTEffect"
    "${CMAKE_CURRENT_SOURCE_DIR}/modules"
    "${CMAKE_CURRENT_SOURCE_DIR}/primatives"
    "${CMAKE_CURRENT_SOURCE_DIR}/utils"
)

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
        ${CMAKE_SOURCE_DIR}/audioDSP/inc/KTEffect/KT_AdaptiveEQ.h  # Add header files explicitly
        DESTINATION ${DELIVERY_DIR_INC}                        # Copy directly to the inc folder
    )
endif()

# Ensure CMake knows how to install targets
include(GNUInstallDirs)
