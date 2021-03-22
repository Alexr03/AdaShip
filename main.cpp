#include "Game.h"
#include "Helpers/iohelper.h"
#include "Menu.h"
#include <windows.h>

using namespace std;

int main() {
    // Fix for windows 10 color in console.
    system(("chcp "s + std::to_string(CP_UTF8)).c_str());
    iohelper::setDefaultFontColor();
    Menu::start();

    return 0;
}
