#include "console_ui.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    int w = termw();
    int h = termh();
    std::cout << "终端信息（测试termw()和termh()的功能） - 终端宽度: " << w << ",高度: " << h << std::endl;
    clrtxt(std::string("测试文本（测试clrtxt()的功能） - 红色文本，默认背景\n"),RED,BG_DEFAULT);

    clrtxt(std::string("样式测试：加粗（Bold）\n"),YELLOW,BG_DEFAULT,TS_BOLD);
    clrtxt(std::string("样式测试：下划线（Underline）\n"),GREEN,BG_DEFAULT,TS_UNDERLINE);
    clrtxt(std::string("样式测试：反显（Reverse）\n"),CYAN,BG_DEFAULT,TS_REVERSE);
    clrtxt(std::string("样式测试：删除线（Strikethrough）\n"),RED,BG_DEFAULT,TS_STRIKETHROUGH);
    clrtxt(std::string("样式测试：斜体（Italic）\n"),BLUE,BG_DEFAULT,TS_ITALIC);

    mvc(1,h);
    clrtxt(std::string("底部信息：绿色文本 + 下划线\n"),GREEN,BG_DEFAULT,TS_UNDERLINE);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    return 0;
}
