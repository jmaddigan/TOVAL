add_executable(${KT_EXE} "KT_AdaptiveEQ_test.cpp")
#add_executable(${MODULE_TESTS} "Module_tests.cpp")

target_link_libraries(${KT_EXE} ${KT_LIB})
#target_link_libraries(${MODULE_TESTS} ${SOFTCLIP_LIB})  # Link all module libraries to the one module test executable

