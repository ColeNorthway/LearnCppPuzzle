cmake_minimum_required(VERSION 4.1.0)
project(Puzzle)
add_executable(Puzzle main.cpp)
target_compile_options(Puzzle PRIVATE
	$<$<CONFIG:Release>:
		/std:c++20
		/O2
		/MT
		-Weverything
		-Werror
		-Wno-c++98-compat
		-Wno-c++98-c++11-compat-binary-literal
		-Wno-c++17-extensions
	>
	$<$<CONFIG:Debug>:
		/std:c++20
		/Od
		/Zi
		/MTd
		-Weverything
		-Wno-c++98-compat
		-Wno-c++98-c++11-compat-binary-literal
		-Wno-c++17-extensions
	>
)
