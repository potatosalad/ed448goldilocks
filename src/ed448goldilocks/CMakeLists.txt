############################################################################
# CMakeLists.txt
#
#    Released under the MIT License.  See LICENSE.txt for license information.
#
############################################################################
set(CURVE448_SOURCE_FILES_C
	${GSOURCE_PATH}/c/ed448goldilocks/decaf.c
	${GSOURCE_PATH}/c/ed448goldilocks/elligator.c
	${GSOURCE_PATH}/c/ed448goldilocks/scalar.c
	${GSOURCE_PATH}/c/ed448goldilocks/eddsa.c
	${PROJECT_SOURCE_DIR}/src/ed448goldilocks/decaf_tables.c
)

SET_SOURCE_FILES_PROPERTIES(${GSOURCE_PATH}/c/ed448goldilocks/decaf.c PROPERTIES GENERATED 1)
SET_SOURCE_FILES_PROPERTIES(${GSOURCE_PATH}/c/ed448goldilocks/elligator.c PROPERTIES GENERATED 1)
SET_SOURCE_FILES_PROPERTIES(${GSOURCE_PATH}/c/ed448goldilocks/scalar.c PROPERTIES GENERATED 1)
SET_SOURCE_FILES_PROPERTIES(${GSOURCE_PATH}/c/ed448goldilocks/eddsa.c PROPERTIES GENERATED 1)
SET_SOURCE_FILES_PROPERTIES(${PROJECT_SOURCE_DIR}/src/ed448goldilocks/decaf_tables.c PROPERTIES GENERATED 1)

add_library(CURVE448 OBJECT ${CURVE448_SOURCE_FILES_C})
add_dependencies(CURVE448 generatedCode)
target_link_libraries(CURVE448 PRIVATE p448)
set_target_properties(CURVE448 PROPERTIES POSITION_INDEPENDENT_CODE True)
