############################################################################
# CMakeLists.txt
#
#    Released under the MIT License.  See LICENSE.txt for license information.
#
############################################################################
set(P25519_HEADER_FILES
	${GSOURCE_PATH}/c/p25519/f_field.h
	${TARGET_ARCH_DIR_P25519}/f_impl.h
)
set(P25519_SOURCE_FILES_C
	${TARGET_ARCH_DIR_P25519}/f_impl.c
	f_arithmetic.c
	${GSOURCE_PATH}/c/p25519/f_generic.c
)

SET_SOURCE_FILES_PROPERTIES(${GSOURCE_PATH}/c/p25519/f_field.h PROPERTIES GENERATED 1)
SET_SOURCE_FILES_PROPERTIES(${GSOURCE_PATH}/c/p25519/f_generic.c PROPERTIES GENERATED 1)

add_library(p25519 OBJECT ${P25519_HEADER_FILES} ${P25519_SOURCE_FILES_C})
add_dependencies(p25519 generatorP25519)
target_include_directories(p25519
    PUBLIC ${GSOURCE_PATH}/include
    PUBLIC ${GSOURCE_PATH}/c/p25519
    PUBLIC ${TARGET_ARCH_DIR_P25519}
    PUBLIC ${PROJECT_SOURCE_DIR}/src/include/${TARGET_ARCH_DIR}
    PUBLIC ${PROJECT_SOURCE_DIR}/src/include
)

set_target_properties(p25519 PROPERTIES POSITION_INDEPENDENT_CODE True)
