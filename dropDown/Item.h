//
// Created by Khanh Nguyen on 3/23/23.
//

#ifndef DROPDOWN_ITEM_H
#define DROPDOWN_ITEM_H

#include <SFML/Graphics.hpp>
#include "Position.h"
#include "MouseEvents.h"
#include "States.h"
class Item : public sf::Drawable, public States
{
public:
    Item();
    Item(std::string string);
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    sf::FloatRect getGlobalBounds();
    void setPosition(sf::Vector2f position);
    std::string getText();
private:
    void init();
    void setUpItem();
    void positionText();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    std::string title;
    sf::Text text;
    static sf::Font font;
    sf::RectangleShape box;
    sf::Color defaultColor = sf::Color::Red;

};


#endif //DROPDOWN_Item_H
