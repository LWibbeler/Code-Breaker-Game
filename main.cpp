#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.h"

int main() {


    const int SCREENX = 800, SCREENY = 800;

    //Initialize SFML window
    sf::RenderWindow window(sf::VideoMode(SCREENX, SCREENY), "Code Breaker");
    window.setFramerateLimit(60);

    //initialize game object
    Game game;
    sf::Event event;

    //Load font in from file
    sf::Font font;
    if (!font.loadFromFile("roboto.ttf")) {
        return -1;
    }

    //set color values used throughout the game
    sf::Color backgroundColor = sf::Color(64, 64, 64), green = sf::Color(12, 156, 74), yellow = sf::Color(237, 216, 24), white = sf::Color(255, 255, 255);

    while (window.isOpen()) {
        window.clear();
        
        //Draw static elements on screen
        sf::RectangleShape background;
        background.setSize(sf::Vector2f(SCREENX, SCREENY));
        background.setPosition(0, 0);
        background.setFillColor(backgroundColor);

        sf::Text title("Code Breaker", font, 70);
        sf::FloatRect titleRect = title.getLocalBounds();
        title.setOrigin(titleRect.left + titleRect.width / 2.0f, titleRect.top + titleRect.height / 2.0f);
        title.setPosition(sf::Vector2f(SCREENX / 2.0f, 75));
        title.setFillColor(white);
        title.setStyle(sf::Text::Bold);

        sf::Text message(game.getMessage(), font, 25);
        sf::FloatRect messageRect = message.getLocalBounds();
        message.setOrigin(messageRect.left + messageRect.width / 2.0f, messageRect.top + messageRect.height / 2.0f);
        message.setPosition(sf::Vector2f(SCREENX / 2.0f, 150));
        message.setFillColor(white);

        sf::Text row1("1:", font, 50);
        sf::FloatRect row1Rect = row1.getLocalBounds();
        row1.setOrigin(row1Rect.left + row1Rect.width / 2.0f, row1Rect.top + row1Rect.height / 2.0f);
        row1.setPosition(sf::Vector2f(75, 225));
        row1.setFillColor(white);
        row1.setStyle(sf::Text::Bold);

        sf::Text row2("2:", font, 50);
        sf::FloatRect row2Rect = row2.getLocalBounds();
        row2.setOrigin(row2Rect.left + row2Rect.width / 2.0f, row2Rect.top + row2Rect.height / 2.0f);
        row2.setPosition(sf::Vector2f(75, 300));
        row2.setFillColor(white);
        row2.setStyle(sf::Text::Bold);

        sf::Text row3("3:", font, 50);
        sf::FloatRect row3Rect = row3.getLocalBounds();
        row3.setOrigin(row3Rect.left + row3Rect.width / 2.0f, row3Rect.top + row3Rect.height / 2.0f);
        row3.setPosition(sf::Vector2f(75, 375));
        row3.setFillColor(white);
        row3.setStyle(sf::Text::Bold);

        sf::Text row4("4:", font, 50);
        sf::FloatRect row4Rect = row4.getLocalBounds();
        row4.setOrigin(row4Rect.left + row4Rect.width / 2.0f, row4Rect.top + row4Rect.height / 2.0f);
        row4.setPosition(sf::Vector2f(75, 450));
        row4.setFillColor(white);
        row4.setStyle(sf::Text::Bold);

        sf::Text row5("5:", font, 50);
        sf::FloatRect row5Rect = row5.getLocalBounds();
        row5.setOrigin(row5Rect.left + row5Rect.width / 2.0f, row5Rect.top + row5Rect.height / 2.0f);
        row5.setPosition(sf::Vector2f(75, 525));
        row5.setFillColor(white);
        row5.setStyle(sf::Text::Bold);

        sf::Text row6("6:", font, 50);
        sf::FloatRect row6Rect = row6.getLocalBounds();
        row6.setOrigin(row6Rect.left + row6Rect.width / 2.0f, row6Rect.top + row6Rect.height / 2.0f);
        row6.setPosition(sf::Vector2f(75, 600));
        row6.setFillColor(white);
        row6.setStyle(sf::Text::Bold);

        sf::Text row7("7:", font, 50);
        sf::FloatRect row7Rect = row7.getLocalBounds();
        row7.setOrigin(row7Rect.left + row7Rect.width / 2.0f, row7Rect.top + row7Rect.height / 2.0f);
        row7.setPosition(sf::Vector2f(75, 675));
        row7.setFillColor(white);
        row7.setStyle(sf::Text::Bold);

        sf::Text row8("8:", font, 50);
        sf::FloatRect row8Rect = row8.getLocalBounds();
        row8.setOrigin(row8Rect.left + row8Rect.width / 2.0f, row8Rect.top + row8Rect.height / 2.0f);
        row8.setPosition(sf::Vector2f(75, 750));
        row8.setFillColor(white);
        row8.setStyle(sf::Text::Bold);

        window.draw(background);
        window.draw(title);
        window.draw(message);
        window.draw(row1);
        window.draw(row2);
        window.draw(row3);
        window.draw(row4);
        window.draw(row5);
        window.draw(row6);
        window.draw(row7);
        window.draw(row8);

        // draw user-imputed codes
        for (int i = 0; i <= game.getGuessNum(); i++) {
            for (unsigned int j = 0; j < game.getGuesses().at(i).size(); j++) {
                sf::Text numText(std::to_string(game.getGuesses().at(i).at(j)), font, 50);
                sf::FloatRect numTextRect = numText.getLocalBounds();
                
                //set colors based on hint
                sf::Color color;
                if (i < game.getGuessNum()) {
                    if (game.getHints().at(i).at(j) == 1) {
                        color = yellow;
                    } else if (game.getHints().at(i).at(j) == 2) {
                        color = green;
                    } else {
                        color = white;
                    }
                } else {
                    color = white;
                }

                numText.setOrigin(numTextRect.left + numTextRect.width / 2.0f, numTextRect.top + numTextRect.height / 2.0f);
                numText.setPosition(sf::Vector2f((SCREENX / 2.0f) - 75 + 50 * j, 225 + 75 * i));
                numText.setFillColor(color);
                numText.setStyle(sf::Text::Bold);

                window.draw(numText);
            }
        }
        

    
        window.display();


        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } 
            //Check for keyboard events
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Backspace) {
                    game.keyPress(-1);
                } else if (event.key.code == sf::Keyboard::Num0 || event.key.code == sf::Keyboard::Numpad0) {
                    game.keyPress(0);
                } else if (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Numpad1) {
                    game.keyPress(1);
                } else if (event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Numpad2) {
                    game.keyPress(2);
                } else if (event.key.code == sf::Keyboard::Num3 || event.key.code == sf::Keyboard::Numpad3) {
                    game.keyPress(3);
                } else if (event.key.code == sf::Keyboard::Num4 || event.key.code == sf::Keyboard::Numpad4) {
                    game.keyPress(4);
                } else if (event.key.code == sf::Keyboard::Num5 || event.key.code == sf::Keyboard::Numpad5) {
                    game.keyPress(5);
                } else if (event.key.code == sf::Keyboard::Num6 || event.key.code == sf::Keyboard::Numpad6) {
                    game.keyPress(6);
                } else if (event.key.code == sf::Keyboard::Num7 || event.key.code == sf::Keyboard::Numpad7) {
                    game.keyPress(7);
                } else if (event.key.code == sf::Keyboard::Num8 || event.key.code == sf::Keyboard::Numpad8) {
                    game.keyPress(8);
                } else if (event.key.code == sf::Keyboard::Num9 || event.key.code == sf::Keyboard::Numpad9) {
                    game.keyPress(9);
                } else if (event.key.code == sf::Keyboard::Enter) {
                    game.checkNum();
                }
            }
        }
    }

    return 0;
}