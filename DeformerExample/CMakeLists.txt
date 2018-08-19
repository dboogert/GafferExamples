cmake_minimum_required(VERSION 3.12)
project(DeformerExample)

set(CMAKE_CXX_STANDARD 11)

add_library(DeformerExample SHARED src/DeformerExample/Deformer.cpp)
target_include_directories(DeformerExample PRIVATE include ${GAFFER_ROOT}/include)

install( TARGETS DeformerExample DESTINATION lib)

add_library(DeformerExampleModule SHARED src/DeformerExampleModule/DeformerBinding.cpp)
set_target_properties( DeformerExampleModule PROPERTIES PREFIX "" OUTPUT_NAME "_deformerExample" )

target_link_libraries(DeformerExampleModule DeformerExample)

target_include_directories(DeformerExampleModule PRIVATE include ${GAFFER_ROOT}/include ${GAFFER_ROOT}/include/python2.7)

install( TARGETS DeformerExampleModule DESTINATION python/DeformerExample )

file( GLOB deformerExampleModuleFiles python/DeformerExample/*.py)

install( FILES ${deformerExampleModuleFiles}
        DESTINATION python/DeformerExample )


file( GLOB deformerExampleUIModuleFiles python/DeformerExampleUI/*.py)

install( FILES ${deformerExampleUIModuleFiles}
        DESTINATION python/DeformerExampleUI )
