// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <iostream>

int Automata::on() {
    std::cout << "Automat on" << std::endl;
    SetState(WAIT);
    return 0;
}

int Automata::off() {
    std::cout << "Automat off" << std::endl;
    SetState(OFF);
    return 0;
}

int Automata::initMenuWithPrices() {
    std::string name[] = { "Raf", "Latte", "Americano" };
    int prices[] = { 50, 20, 10 };
    menu.insert(menu.begin(), name, name + 3);
    this->prices.insert(this->prices.begin(), prices, prices + 3);
    return 0;
}

int Automata::coin(int rub) {
    if (state == WAIT || state == ACCEPT) {
        SetCash(rub);
        SetState(ACCEPT);
        return rub;
    } else {
        std::cout << "error " << std::endl;
        return 0;
    }
}

int Automata::etMenu() {
    for (int i = 0; i < std::size(menu); i++) {
        std::cout << menu[i] << ' ' << prices[i] << std::endl;
    }
    return 0;
}

STATES Automata::getState() {
    std::cout << state << std::endl;
    return state;
}

int Automata::choice() {
    if (state == ACCEPT) {
        std::cout << "selected drink " << menu[1] << std::endl;
        SetState(CHECK);
        return 1;
    } else {
        return 0;
    }
}

int Automata::check() {
    if (state == CHECK) {
        if (cash >= prices[1]) {
            cash = cash - prices[1];
        } else {
            std::cout << "error " << std::endl;
        }
        return 0;
    }
    return 0;
}

int Automata::cancel() {
    SetState(WAIT);
    return 0;
}

int Automata::cook() {
    if (state == CHECK) {
        std::cout << "cook " << std::endl;
        SetState(COOK);
        if (cash > 0) {
            std::cout << "take cash " << cash << std::endl;
        } else { std::cout << "error " << std::endl; }
        finish();
    }
    return 0;
}

int Automata::finish() {
    SetState(WAIT);
    return 0;
}
