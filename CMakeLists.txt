cmake_minimum_required(VERSION 3.12)
project(MinerRemake)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

include_directories(${SFML_INCLUDE_DIR})
include_directories(include)
include_directories(game)
include_directories(game/font)
include_directories(game/mining)
include_directories(game/scene)
include_directories(game/scene/node)
include_directories(game/scene/node/implement)
include_directories(game/sprite)
include_directories(game/stage)
include_directories(game/stage/implement)
include_directories(window)

add_executable(MinerRemake
        game/font/FontKeeping.cpp
        game/font/FontKeeping.h
        game/font/Text.cpp
        game/font/Text.h
        game/mining/Mining.cpp
        game/mining/Mining.h
        game/mining/Ore.cpp
        game/mining/Ore.h
        game/mining/OreIdentification.h
        game/scene/node/implement/CasinoTableModel.cpp
        game/scene/node/implement/CasinoTableModel.h
        game/scene/node/implement/SpriteModel.cpp
        game/scene/node/implement/SpriteModel.h
        game/scene/node/implement/TextModel.cpp
        game/scene/node/implement/TextModel.h
        game/scene/node/Anchor.cpp
        game/scene/node/Anchor.h
        game/scene/node/Node.cpp
        game/scene/node/Node.h
        game/scene/node/NodeModel.h
        game/scene/Scene.cpp
        game/scene/Scene.h
        game/sprite/Sprite.cpp
        game/sprite/Sprite.h
        game/sprite/SpriteKeeping.cpp
        game/sprite/SpriteKeeping.h
        game/stage/implement/CasinoStage.cpp
        game/stage/implement/CasinoStage.h
        game/stage/implement/MenuStage.cpp
        game/stage/implement/MenuStage.h
        game/stage/implement/MineStage.cpp
        game/stage/implement/MineStage.h
        game/stage/Stage.h
        game/stage/StageBuilding.cpp
        game/stage/StageBuilding.h
        game/stage/StageHandler.cpp
        game/stage/StageHandler.h
        game/stage/StageIdentification.h
        game/Game.cpp
        game/Game.h
        game/MessageBox.cpp
        game/MessageBox.h
        game/Model.cpp
        game/Model.h
        game/Progress.cpp
        game/Progress.h
        window/Rendering.cpp
        window/Rendering.h
        window/Window.cpp
        window/Window.h
        main.cpp)

target_link_libraries(MinerRemake sfml-graphics)