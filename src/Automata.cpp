//Copyright 2024 <levkovich-polina>
#include "Automata.h"
Automata::Automata() {
    cash = 0;
    state = OFF;
    menu = { "Кофе", "Чай", "Молоко", "Какао" };
    prices = { 100, 30, 20, 50 };
}

void Automata::on() {
    if (state == OFF)
        state = WAIT;
}

    void Automata::off() {
        if (state == WAIT)
            state = OFF;
    }

void Automata::coin(int money) {
    cash += money;
    state = ACCEPT;
}

std::string Automata::getMenu() {
    std::string result = "";
    for (int i = 0; i < menu.size(); i++) {
        result += menu[i] + " - " + std::to_string(prices[i]) + "\n";
    }
    return result;
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int choice) {
    if (state == ACCEPT) {
        state = CHECK;
        if (check(choice)) {
            cash -= prices[choice];
            cook();
            finish();
        } else {
            cancel();
        }
    }
}

bool Automata::check(int choice) {
    return cash >= prices[choice];
}

void Automata::cancel() {
    cash = 0;
    state = WAIT;
}

void Automata::cook() {
    state = COOK;
}

void Automata::finish() {
    state = WAIT;
}
