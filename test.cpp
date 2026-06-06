#include "console_ui.h"
#include <iostream>

int main() {
    int w = termw();
    int h = termh();
    std::cout << "终端信息（测试termw()和termh()的功能） - 终端宽度: " << w << ", 高度: " << h << std::endl;
    clrtxt(std::string("测试文本（测试clrtxt()的功能） - 红色文本，默认背景\n"), RED, BG_DEFAULT);
    mvc(1, h);
    clrtxt(std::string("测试文本（测试mvc()和clrtxt()的功能） - 底部，绿色文本，默认背景\n"), GREEN, BG_DEFAULT);
    return 0;
}
