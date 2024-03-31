// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(test_create, test_create) {
    Automata automat;
    EXPECT_EQ(OFF, automat.getState());
}

TEST(test_on, test_on) {
    Automata automat;
    automat.on();
    EXPECT_EQ(WAIT, automat.getState());
}

TEST(test_coin, test_coin) {
    Automata automat;
    automat.on();
    automat.coin(150);
    EXPECT_EQ(ACCEPT, automat.getState());
}

TEST(test_off, test_off) {
    Automata automat;
    automat.on();
    automat.off();
    EXPECT_EQ(OFF, automat.getState());
}

TEST(test_choice, test_choice) {
    Automata automat;
    automat.on();
    automat.coin(100);
    automat.choice(2);
    EXPECT_EQ(WAIT, automat.getState());
}

TEST(test_choice_v2, test_choice_v2) {
    Automata automat;
    automat.on();
    automat.coin(10);
    automat.choice(2);
    EXPECT_EQ(WAIT, automat.getState());
}

TEST(test_cook, test_cook) {
    Automata automat;
    automat.on();
    automat.cook();
    EXPECT_EQ(COOK, automat.getState());
}

TEST(test_cancel, test_cancel) {
    Automata automat;
    automat.cancel();
    EXPECT_EQ(WAIT, automat.getState());
}

TEST(test_full_work, test_full_work) {
    Automata automat;
    automat.on();
    automat.coin(10);
    automat.choice(2);
    automat.off();
    EXPECT_EQ(OFF, automat.getState());
}
