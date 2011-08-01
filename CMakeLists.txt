cmake_minimum_required(VERSION 2.6)
		
#Configuration du projet
project(checkpoint_check)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BUILD_TYPE})

set(LIBRARY_OUTPUT_PATH lib/${CMAKE_BUILD_TYPE})

include_directories(include)

#Génération de la liste des fichiers sources
file(
	GLOB_RECURSE
	source_files
	src/*
	include/*
)

#Déclaration de l'exécutable
add_executable(
	checkpoint_check
	${source_files}
)

add_library(
    _checkpoint_check 
    SHARED
    ${source_files} 
)

target_link_libraries(checkpoint_check -lm)

if (FORCE_CPU STREQUAL "32bits")
    message("Compiling on 32bits")
    add_definitions(                        -m32)
    set(CMAKE_EXE_LINKER_FLAGS                "${CMAKE_EXE_LINKER_FLAGS} -m32")
    set(CMAKE_SHARED_LIBRARY_C_FLAGS        "${CMAKE_SHARED_LIBRARY_C_FLAGS} -m32")
    set(CMAKE_SHARED_LIBRARY_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CXX_FLAGS} -m32")
    SET_TARGET_PROPERTIES(_checkpoint_check PROPERTIES OUTPUT_NAME "_checkpoint_check32")
endif (FORCE_CPU STREQUAL "32bits") 


