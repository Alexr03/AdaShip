#include "Game.h"
#include "Helpers/iohelper.h"
#include "Menu.h"

using namespace std;

int main() {
//    iohelper::setDefaultFontColor();
    printf("\033[31mred text\n");
    printf("\033[33;44myellow on blue\n");
    printf("\033[0mdefault colors\n");
    Menu::start();

    return 0;
}
