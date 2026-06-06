#include "console_ui.h"
#include <iostream>

int main() {
    int w = termw();
    int h = termh();
    std::cout << "Terminal width: " << w << ", height: " << h << std::endl;

    clrtxt(std::string("Hello in red on default background\n"), RED, BG_DEFAULT);

    // Move cursor to 1, h to show mvc works
    mvc(1, h);
    clrtxt(std::string("Bottom-left text (green)\n"), GREEN, BG_DEFAULT);

    return 0;
}
