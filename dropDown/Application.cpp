//
// Created by Khanh Nguyen on 3/23/23.
//

#include "Application.h"

Application::Application() : window({1080,720,32}, "Drop Down Menu")
{

}

void Application::runApp()
{
    sf::Event event;
    DropDownMenu menu;
    menu.push_back("banana");
    menu.push_back("apple");
    menu.push_back("peanut");


    menu.setPosition({100,100});

    InputBox box;

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
            {
                window.close();
            }
        }
        menu.eventHandler(window, event);
        window.clear();
        window.draw(menu);
        window.display();
    }

}
