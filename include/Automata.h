// Copyright 2022 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <string>
#include <vector>

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK,
};

class Automata {
 public:
    void SetState(STATES state) { this->state = state; }
    void SetCash(int cash) { this->cash = cash; }
    int GetCash() { return cash; }
    int coin(int rub);
    int choice();
    int etMenu();
    int check();
    int cook();
    STATES getState();
    int on();
    int off();
    Automata() {
        cash = 0;
        SetState(OFF);
        initMenuWithPrices();
    }

 private:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;
    int initMenuWithPrices();
    int cancel();
    int finish();
};
#endif  // INCLUDE_AUTOMATA_H_
