project(basics)
include_directories(${_INCLUDE_DIRS})


add_executable( decomposition src/number_decomposition.cpp   )
add_executable( overloading src/functions_overloading.cpp  )
add_executable( structures src/testing_structures.cpp  )
add_executable( arguments src/passing_arguments.cpp  )
add_executable( using_pairs src/using_pairs.cpp)

