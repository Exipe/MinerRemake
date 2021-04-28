
#include <iostream>
#include "game/game.h"
#include "window/Window.h"

int main() {
    sf::RenderWindow renderWindow(sf::VideoMode(800, 600), "Miner++");
    renderWindow.setFramerateLimit(100);

    Game* game = Game::build(800, 600);
    Window window(renderWindow, *game);

    while(window.isOpen()) {
        window.update();
    }

    delete game;
}
