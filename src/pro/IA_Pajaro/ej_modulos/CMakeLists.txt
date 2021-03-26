#Especificar donde se encuentran los ficheros cpp a compilar
target_sources(libModulos PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Nodo.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Pathfinding.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Pajaro.cpp"
)

#Y donde se encuentran los .h
target_include_directories(libModulos PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}"
)

