#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    sf::Font font;
    sf::Text uiText;
    bool endGame;
    unsigned points;
    int health;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    bool mouseHeld;
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;
    void initVariables();
    void initWindow();
    void initFonts();
    void initText();
    void initEnemies();

public:
    Game();
    virtual ~Game();
    const bool running() const;
    const bool getEndGame() const;
    void spawnEnemy();
    void pollEvents();
    void updateMousePositions();
    void updateText();
    void updateEnemies();
    void update();
    void renderText(sf::RenderTarget& target);
    void renderEnemies(sf::RenderTarget& target);
    void render();
};