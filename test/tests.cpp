// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
TEST(Automata, TestOn) {
  Automata automata;
  automata.on();
  EXPECT_EQ(automata.getState(), Automata::WAIT);
}
TEST(Automata, TestOff) {
  Automata automata;
  automata.on();
  automata.off();
  EXPECT_EQ(automata.getState(), Automata::OFF);
}
TEST(Automata, TestWait) {
  Automata automata;
  automata.on();
  automata.coin(200);
  automata.cancel();
  EXPECT_EQ(automata.getState(), Automata::WAIT);
}
TEST(Automata, TestFinish) {
  Automata automata;
  automata.on();
  automata.coin(200);
  automata.choice(2);
  EXPECT_EQ(automata.getState(), Automata::WAIT);
}

TEST(Automata, TestMenu) {
  Automata automata;
  automata.on();
  automata.coin(200);
  automata.choice(10);
  EXPECT_EQ(automata.getState(), Automata::ACCEPT);
}
TEST(Automata, TestCash) {
  Automata automata;
  automata.on();
  automata.coin(10);
  automata.choice(2);
  EXPECT_EQ(automata.getState(), Automata::WAIT);
}
TEST(Automata, TestCoin) {
  Automata automata;
  automata.on();
  automata.choice(2);
  EXPECT_EQ(automata.getState(), Automata::WAIT);
}
TEST(Automata, TestAccept) {
  Automata automata;
  automata.coin(150);
  EXPECT_EQ(automata.getState(), Automata::OFF);
}
