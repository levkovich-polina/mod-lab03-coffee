#include "Automata.h"
#include <iostream>


Automata::Automata() {
    cash = 0;
    state = OFF;
}

void Automata::on() {
    if (state == OFF) {
        cash = 0;
        state = WAIT;
        getMenu();
    }
}

void Automata::off() {
    getChange();
    cash = 0;
    state = OFF;
}

void Automata::coin(unsigned int sum) {
    if (state == WAIT || state == ACCEPT) {
        cash += sum;
        state = ACCEPT;
    } else {
        std::cout << "Операция не может быть выполнена" << std::endl;
    }
}

void Automata::getMenu() {
    std::cout << "Меню:" << std::endl;
    for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
        std::cout << i + 1 << ") "
            << menu[i] << " -  " << prices[i]
            << std::endl;
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(unsigned int num) {
    if (state == ACCEPT) {
        if (0 < num && num <= sizeof(menu) / sizeof(menu[0])) {
            num_of_chosen_drink = num - 1;
            state = CHECK;
            check();
        } else {
            std::cout << "Неправильный выбор" << std::endl;
        }
    } else {
    std::cout << "Операция не может быть выполнена" << std::endl;
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        getChange();
        cash = 0;
        state = WAIT;
    } else {
        std::cout << "Операция не может быть выполнена" << std::endl;
    }
}

void Automata::check() {
    if (state == CHECK) {
        if (cash >= prices[num_of_chosen_drink]) {
            getChange(prices[num_of_chosen_drink]);
            cook();
        } else {
            std::cout << "Недостаточно средств" << std::endl;
            cancel();
        }
    }
}

void Automata::cook() {
    if (state == CHECK) {
        state = COOK;
        std::cout << "Твой " << menu[num_of_chosen_drink]
            << " готов" << std::endl;
        finish();
    }
}

void Automata::finish() {
    if (state == COOK) {
        cash = 0;
        state = WAIT;
    }
}

void Automata::getChange(unsigned int price) {
    if (cash - price != 0)
    std::cout << "Возьмите сдачу: " << cash - price << std::endl;
}
