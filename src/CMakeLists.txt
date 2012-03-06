set(BAR_SRC
	bar.c
)

include_directories(
	"${PROJECT_SOURCE_DIR}/inc"
	"${FOO_INCLUDE_DIRS}"
)

add_library(${PROJECT_NAME}-shared SHARED ${BAR_SRC})
set_target_properties(${PROJECT_NAME}-shared PROPERTIES
	OUTPUT_NAME	${PROJECT_NAME}
	SOVERSION	${PACKAGE_MAJOR_VERSION}
	VERSION		${PACKAGE_VERSION}
)

target_link_libraries(${PROJECT_NAME}-shared
	foo-shared
)

install(TARGETS ${PROJECT_NAME}-shared EXPORT ${PROJECT_NAME}-targets LIBRARY DESTINATION "lib" )
install(EXPORT ${PROJECT_NAME}-targets DESTINATION "lib/cmake/${PROJECT_NAME}")
