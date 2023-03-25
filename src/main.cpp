// Copyright 2022 UNN-IASR
#include <iostream>
#include "Automata.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    Automata coffe;
    coffe.on();
    coffe.etMenu();
    coffe.coin(30);
    coffe.choice();
    coffe.check();
    coffe.cook();
    coffe.off();
    return 0;
}
