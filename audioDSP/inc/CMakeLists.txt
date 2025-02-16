target_include_directories(${KT_LIB} PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/modules"   # Include modules directory
    "${CMAKE_CURRENT_SOURCE_DIR}/KTEffect"
    "${CMAKE_CURRENT_SOURCE_DIR}/primatives"
    "${CMAKE_CURRENT_SOURCE_DIR}/utils"  
)

#target_include_directories(${SOFTCLIP_LIB} PUBLIC 
#    "${CMAKE_CURRENT_SOURCE_DIR}/modules"   # Include modules directory
#    "${CMAKE_CURRENT_SOURCE_DIR}/KTEffect"
#    "${CMAKE_CURRENT_SOURCE_DIR}/primatives"
#    "${CMAKE_CURRENT_SOURCE_DIR}/utils"  
#)
