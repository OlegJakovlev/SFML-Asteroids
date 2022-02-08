#pragma once

#ifndef InputController_H
#define InputController_H

#include <utility>
#include <map>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class InputController {
 private:
    enum InputType {
        KeyboardInput,
        MouseInput
    };

    struct MyKeys {
        InputType InputType;
        sf::Event::EventType EventType;
        bool isHeldDown;
        sf::Keyboard::Key KeyCode;
        sf::Mouse::Button MouseButton;
    };

 private:
    std::multimap<std::string, MyKeys> Binds;

 public:
    InputController();
    bool isActionPressed(const std::string& actionName);
};

#endif
