#include <iostream>
#include "Automata.h"

void main() 
{
	setlocale(LC_ALL, "Russian");
	Automata coffe;
	coffe.on(); // off on возвращает automata() мб функцию в int
	coffe.etMenu();
	coffe.coin(30);
	coffe.choice();
	coffe.check();
	coffe.cook();
	coffe.off();

}