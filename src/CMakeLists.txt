if(NOT DEFINED INSTALL_DEST)
	if(UNIX)
		set(INSTALL_DEST "/bin")
	else()
		set(INSTALL_DEST "C:/nicsmocs/bin/")
	endif()
endif()

add_executable(youtubeTimeSteps youtubeTimeSteps.cpp)
target_include_directories(youtubeTimeSteps PRIVATE ${CMAKE_SOURCE_DIR}/include)

if(UNIX AND ${CMAKE_SYSTEM_PROCESSOR} MATCHES "arm")
	target_link_directories(youtubeTimeSteps PRIVATE ${CMAKE_SOURCE_DIR}/lib/arm)
elseif (IS_MACOS)
	target_link_directories(youtubeTimeSteps PRIVATE ${CMAKE_SOURCE_DIR}/lib/macos)
else()
	target_link_directories(youtubeTimeSteps PRIVATE ${CMAKE_SOURCE_DIR}/lib)
endif()

target_link_libraries(youtubeTimeSteps debug nicsmocsd optimized nicsmocs)
install(TARGETS youtubeTimeSteps DESTINATION ${INSTALL_DEST})