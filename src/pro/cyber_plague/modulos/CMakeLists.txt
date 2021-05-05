#Especificar donde se encuentran los ficheros cpp a compilar
target_sources(libModulos PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Motor2D/M_Sprite.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Motor2D/M_Window.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Motor2D/M_View.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Motor2D/M_Input.cpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/Tools/Vector2D.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Tools/posInterpolada.cpp"
    
    "${CMAKE_CURRENT_SOURCE_DIR}/Animacion.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Entidad.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Entidades/NPC.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Entidades/NPC.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Entidades/Player.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Entidades/NPCs/Zombi.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Entidades/NPCs/Soldado.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Entidades/NPCs/Mago.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Entidades/NPCs/Pajaro.cpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/Entidades/Armas/Arma.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Entidades/Armas/Tipo_de_Arma/Arco.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Entidades/Armas/Tipo_de_Arma/Lanzallamas.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Entidades/Armas/Tipo_de_Arma/Laser.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Entidades/Armas/Tipo_de_Arma/Rayo.cpp"
    
    "${CMAKE_CURRENT_SOURCE_DIR}/AI_Agent.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Moneda.cpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/Map.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/CyberPlague.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Menu.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Mundo.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/TinyXML/tinystr.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/TinyXML/tinyxml.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/TinyXML/tinyxmlparser.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/TinyXML/tinyxmlerror.cpp"
)

#Y donde se encuentran los .h
target_include_directories(libModulos PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}"
)

