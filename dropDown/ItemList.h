//
// Created by Khanh Nguyen on 3/23/23.
//

#ifndef DROPDOWN_ITEMLIST_H
#define DROPDOWN_ITEMLIST_H
#include "Item.h"
#include <vector>
#include <iostream>

class ItemList : public sf::Drawable
{
public:
    ItemList();
    std::vector<Item> list;

    void addItem(std::string title);
    void removeItem();
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    std::vector<Item>::iterator begin();
    std::vector<Item>::iterator end();

    void setPosition(sf::Vector2f position);

    Item & operator [] (int i);


    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    int size();

    void updatePosition();

private:



};


#endif //DROPDOWN_ITEMLIST_H
