//
// Created by Khanh Nguyen on 3/23/23.
//

#include "DropDownMenu.h"

DropDownMenu::DropDownMenu()
{
    init();
}

void DropDownMenu::init()
{
    inputBox.setText("Menu");
    setUpPosition();
}

void DropDownMenu::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    menuItems.eventHandler(window, event);
    inputBox.eventHandler(window, event);

    for(Item i : menuItems) // if broken check iterators in itemlist
    {
        if(i.checkStates(SELECTED))
        {
            inputBox.setText(i.getText());
            inputBox.enableStates(ITEMS_HIDDEN);
        }
    }
}

void DropDownMenu::setPosition(sf::Vector2f position)
{
    inputBox.setPosition(position);
    setUpPosition();
}

void DropDownMenu::setUpPosition()
{
    sf::FloatRect i = inputBox.getGlobalBounds();
    menuItems.setPosition({i.left,i.top + i.height});
}

void DropDownMenu::push_back(std::string title)
{
    menuItems.addItem(title);
    setUpPosition();
}

void DropDownMenu::pop_back()
{

}

void DropDownMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(inputBox);
    if(!inputBox.checkStates(ITEMS_HIDDEN))
    {
        target.draw(menuItems);
    }

}
