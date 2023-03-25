// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <iostream>

int Automata::on() {
    cout << "Automat on" << endl;
    SetState(WAIT);
    return 0;
}

int Automata::off() {
    cout << "Automat off" << endl;
    SetState(OFF);
    return 0;
}

int Automata::initMenuWithPrices() {
    string name[] = { "Raf", "Latte", "Americano" };
    int prices[] = { 50,20,10 };
    menu.insert(menu.begin(), name, name + 3);
    this->prices.insert(this->prices.begin(), prices, prices + 3);
    return 0;
}

int Automata::coin(int rub) {
    if (state == WAIT || state == ACCEPT)
    {
        SetCash(rub);
        SetState(ACCEPT);
        return rub;
    } else {
        cout << "error " << endl;
        return 0;
    }
}

int Automata::etMenu() {
    for (int i = 0; i < size(menu); i++) {
        cout << menu[i] << ' ' << prices[i] << endl;
    }
    return 0;
}

STATES Automata::getState() {
    cout << state << endl;
    return state;
}

int Automata::choice() {
    if (state == ACCEPT) {
        cout << "selected drink " << menu[1] << endl;
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
            cout << "error " << endl;
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
        cout << "cook " << endl;
        SetState(COOK);
        if (cash > 0) {
            cout << "take cash " << cash << endl;
        } else { cout << "error " << endl; }
        finish();
    }
    return 0;
}

int Automata::finish() {
    SetState(WAIT);
    return 0;
}
