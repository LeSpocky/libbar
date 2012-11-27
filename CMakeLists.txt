project(bar)
cmake_minimum_required(VERSION 2.8.8)

# package version
set(PACKAGE_MAJOR_VERSION "0")
set(PACKAGE_MINOR_VERSION "1")
set(PACKAGE_BUILD_VERSION "0")
set(PACKAGE_VERSION "${PACKAGE_MAJOR_VERSION}.${PACKAGE_MINOR_VERSION}.${PACKAGE_BUILD_VERSION}")

# include modules
include(CMakePackageConfigHelpers)	# cmake 2.8.8
include(FeatureSummary)
include(GNUInstallDirs)				# cmake 2.8.5

# set requirements (used here and in cmake package config script
set(FIND_REQUIRED_PACKAGES "
find_package(FOO 0.1.0 REQUIRED)
")
configure_file(
	find_req_pkgs.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/find_req_pkgs.cmake
)
include(${CMAKE_CURRENT_BINARY_DIR}/find_req_pkgs.cmake)

# add subdirectories (creating targets)
add_subdirectory("inc")
add_subdirectory("src")

# write cmake package config scripts (after targets created)
configure_package_config_file(bar-config.cmake.in
	"${CMAKE_CURRENT_BINARY_DIR}/bar-config.cmake"
	INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
	PATH_VARS CMAKE_INSTALL_INCLUDEDIR
	NO_CHECK_REQUIRED_COMPONENTS_MACRO
)
write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/bar-config-version.cmake"
	VERSION ${PACKAGE_VERSION}
	COMPATIBILITY AnyNewerVersion
)
install(FILES
	"${CMAKE_CURRENT_BINARY_DIR}/bar-config.cmake"
	"${CMAKE_CURRENT_BINARY_DIR}/bar-config-version.cmake"
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
)

# status and debug output
feature_summary(WHAT ALL)
