#include <iostream>
#include <string>
#include "Automata.h"

int main() {
    Automata automat = Automata();
    automat.on();
     automat.off();
    automat.coin(150);
    automat.coin(200);
    automat.cancel();
    automat.coin(0);
    automat.getMenu();
    automat.choice(1);
    automat.check(1);
    automat.coin(50);
    automat.choice(2);
    automat.check(2);
    automat.cook();
    automat.finish();

}
