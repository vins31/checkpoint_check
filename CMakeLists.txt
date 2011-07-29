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
