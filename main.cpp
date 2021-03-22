#include "Game.h"
#include "Helpers/iohelper.h"
#include "Menu.h"
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main() {
#ifdef _WIN32
    // Fix for windows 10 color in console.
    system(("chcp "s + std::to_string(CP_UTF8)).c_str());
#endif

    iohelper::setDefaultFontColor();
    Menu::start();

    return 0;
}
