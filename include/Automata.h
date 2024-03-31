
#pragma once
#include <iostream>
#include <string>

class Automata {
 public:
  enum State { OFF, WAIT, ACCEPT, CHECK, COOK };

 private:
  double cash;
  std::string *menu;
  int *prices;
  State state;
  int count_menu;

 public:
  Automata();
  void on();
  void off();
  void coin(int);
  void getMenu();
  State getState();
  void choice(int);
  void cancel();

 private:
  void check(int);
  void cook(int);
  void finish(int);
};
