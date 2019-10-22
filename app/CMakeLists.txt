add_library(App STATIC
    src/AMainLoop.cpp
    src/Nibbler.cpp
    src/Input.cpp
)

target_link_libraries(App
    sfml-graphics
    sfml-window
    sfml-system
    Engine
    Renderer
    Models
)

add_executable(nibbler src/main.cpp)
target_link_libraries(nibbler App)
