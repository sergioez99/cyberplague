#Especificar donde se encuentran los ficheros cpp a compilar
target_sources(libModulos PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Motor2D/sprite.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/sprite.cpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/Motor2D/window.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window.cpp"
)

#Y donde se encuentran los .h
target_include_directories(libModulos PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}"
)

