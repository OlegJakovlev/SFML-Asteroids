#include "InputController.h"

InputController::InputController() {
    // Bind all actions to keys
    MyKeys key;

    /* SHOOT EVENT */
    // on left click
    key.InputType = MouseInput;
    key.EventType = sf::Event::MouseButtonPressed;
    key.MouseButton = sf::Mouse::Left;
    Binds.insert(std::pair<std::string, MyKeys>("Shoot", key));

    // on enter key
    key.InputType = KeyboardInput;
    key.EventType = sf::Event::KeyPressed;
    key.KeyCode = sf::Keyboard::Enter;
    Binds.insert(std::pair<std::string, MyKeys>("Shoot", key));

    /* BOOST EVENT */
    // on space click
    key.InputType = KeyboardInput;
    key.EventType = sf::Event::KeyPressed;
    key.KeyCode = sf::Keyboard::Space;
    Binds.insert(std::pair<std::string, MyKeys>("Boost", key));

    /* Rotate EVENT */
    // left
    key.InputType = KeyboardInput;
    key.EventType = sf::Event::KeyPressed;
    key.KeyCode = sf::Keyboard::A;
    Binds.insert(std::pair<std::string, MyKeys>("RotateLeft", key));

    // right
    key.InputType = KeyboardInput;
    key.EventType = sf::Event::KeyPressed;
    key.KeyCode = sf::Keyboard::D;
    Binds.insert(std::pair<std::string, MyKeys>("RotateRight", key));
}

void InputController::evaluateInput(const std::string& actionName, const sf::Event& e) {
    // Check if action bind exists
    if ((Binds.find(actionName)) == Binds.end()) return;

    // All binds for specific action
    std::pair<std::multimap<std::string, MyKeys>::iterator,
        std::multimap<std::string, MyKeys>::iterator> allActionBinds;
    allActionBinds = Binds.equal_range(actionName);

    // Compare action key to pressed
    for (std::multimap<std::string, MyKeys>::iterator it = allActionBinds.first;
        it != allActionBinds.second; ++it) {
        MyKeys k = (*it).second;

        if (k.EventType != e.type) continue;

        switch (k.InputType) {
        case KeyboardInput:
            if (k.KeyCode == e.key.code) return;
            break;

        case MouseInput:
            if (k.MouseButton == e.mouseButton.button) return;
            break;

        default:
            break;
        }
    }
}

bool InputController::isActionPressed(const std::string& actionName) {
    // Check if action bind exists
    if ((Binds.find(actionName)) == Binds.end()) return false;

    // All binds for specific action
    std::pair<std::multimap<std::string, MyKeys>::iterator,
        std::multimap<std::string, MyKeys>::iterator> allActionBinds;
    allActionBinds = Binds.equal_range(actionName);

    for (std::multimap<std::string, MyKeys>::iterator it = allActionBinds.first;
        it != allActionBinds.second; ++it) {
        MyKeys k = (*it).second;
        if (sf::Keyboard::isKeyPressed(k.KeyCode)) return true;
    }

    return false;
}
