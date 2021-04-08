#Especificar donde se encuentran los ficheros cpp a compilar
target_sources(libModulos PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Motor2D/M_Sprite.cpp"
 
    "${CMAKE_CURRENT_SOURCE_DIR}/Motor2D/M_Window.cpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/TinyXML/tinyxml.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/TinyXML/tinystr.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/TinyXML/tinyxmlerror.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/TinyXML/tinyxmlparser.cpp"


    "${CMAKE_CURRENT_SOURCE_DIR}/Entidad.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/NPC.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/NPCs/Zombi.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/NPCs/Soldado.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/NPCs/Mago.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/NPCs/Pajaro.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/AI_Agent.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Map.cpp"
)

#Y donde se encuentran los .h
target_include_directories(libModulos PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}"
)

