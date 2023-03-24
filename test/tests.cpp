// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
	Automata coffe1;
	coffe1.coin(50);
	STATES s = coffe1.getState();
	EXPECT_EQ(ACCEPT, s);
}

TEST(task2, test2) {
	Automata coffe1;
	coffe1.coin(50);
	int c = coffe1.GetCash();
	EXPECT_EQ(50, c);
}

TEST(task3, test3) {
	Automata coffe1;
	coffe1.coin(50);
	coffe1.check();
	int c = coffe1.GetCash();
	EXPECT_EQ(30, c);
}