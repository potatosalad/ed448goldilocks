############################################################################
# CMakeLists.txt
#
#    Released under the MIT License.  See LICENSE.txt for license information.
#
############################################################################
set(P448_HEADER_FILES
	${GSOURCE_PATH}/c/p448/f_field.h
	${TARGET_ARCH_DIR_P448}/f_impl.h
)
set(P448_SOURCE_FILES_C
	${TARGET_ARCH_DIR_P448}/f_impl.c
	f_arithmetic.c
	${GSOURCE_PATH}/c/p448/f_generic.c
)

SET_SOURCE_FILES_PROPERTIES(${GSOURCE_PATH}/c/p448/f_field.h PROPERTIES GENERATED 1)
SET_SOURCE_FILES_PROPERTIES(${GSOURCE_PATH}/c/p448/f_generic.c PROPERTIES GENERATED 1)

add_library(p448 OBJECT ${P448_HEADER_FILES} ${P448_SOURCE_FILES_C})
add_dependencies(p448 generatorP448)
target_include_directories(p448
    PUBLIC ${GSOURCE_PATH}/include
    PUBLIC ${GSOURCE_PATH}/c/p448
    PUBLIC ${TARGET_ARCH_DIR_P448}
    PUBLIC ${PROJECT_SOURCE_DIR}/src/include/${TARGET_ARCH_DIR}
    PUBLIC ${PROJECT_SOURCE_DIR}/src/include
)

set_target_properties(p448 PROPERTIES POSITION_INDEPENDENT_CODE True)
