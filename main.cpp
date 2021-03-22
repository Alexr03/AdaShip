#include "Game.h"
#include "Helpers/iohelper.h"
#include "Menu.h"

using namespace std;

int main() {
    iohelper::setDefaultFontColor();
    Menu::start();

    return 0;
}
