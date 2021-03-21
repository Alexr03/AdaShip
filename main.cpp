#include <iostream>
#include "Game.h"
#include "Helpers/iohelper.h"

using namespace std;

int main() {
    iohelper::setDefaultFontColor();
    std::cout << "Starting Game..." << std::endl;
    Game game{};
    game.Start();

    return 0;
}
