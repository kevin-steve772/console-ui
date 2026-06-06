# Copilot 指南：console-ui

目的：为未来的 Copilot 会话提供针对本仓库的关键信息，使建议更准确、可执行。

构建、测试与静态检查命令
- 仓库中未配置专门的构建脚本或 CI。
- 快速编译并运行（Linux/macOS）：
  - 编译并运行（Linux 示例）：g++ -std=c++17 -Wall test.cpp -o test && ./test
  - 运行（单独）：./test
- 快速编译并运行（MSVC）：
  - 编译：cl /EHsc test.cpp
  - 运行：test.exe
- 单测说明：仓库仅包含一个测试程序（test.cpp）。构建该二进制并运行即可验证功能。
- 静态检查：仓库未配置 linter。可在需要时建议使用 clang-tidy、cpplint 或添加 CMake/Makefile 后整合工具。

高层架构概览
- 单头文件实现（header-only）：所有功能在 console_ui.h 中以 inline 函数实现，便于直接包含使用。
- 公共 API（inline 函数）：
  - mvc(x, y)：使用 ANSI 转义序列将光标移动到列 x、行 y。
  - clrtxt(text, txtcolor, bgcolor, style)：打印带颜色和样式的文本，输出后重置样式。
  - hc(), sc()：隐藏 / 显示光标（ANSI 序列）。
  - setup()：在 Windows 上启用虚拟终端（ENABLE_VIRTUAL_TERMINAL_PROCESSING）；POSIX 上为 noop。
  - termh(), termw()：获取终端高度/宽度；Windows 通过 Console API，POSIX 通过 ioctl(TIOCGWINSZ)，失败时分别返回 24/80 作为默认值。
- 枚举（Color、BgColor、TextStyle）直接对应 ANSI SGR 数值常量。
- 实现说明：所有函数声明为 inline，以保持头文件单一实现并避免链接问题。

关键约定与仓库惯用模式
- 头文件即库：直接包含 console_ui.h 即可使用，无需额外构建步骤。
- printf 与 std::string 混用：clrtxt 接受 std::string，但使用 printf(text.c_str()) 输出，注意格式化安全性。
- 枚举数值为权威来源：不要更改枚举的数值（外部调用可能依赖这些具体的 ANSI 码）。
- clrtxt 的特殊处理：当 style 为 TS_NONE（0）时，会使用不带 style 的格式化字符串。
- Windows 特殊处理：需要在程序启动早期调用 setup() 才能在 Windows 控制台正确显示 ANSI 颜色/样式。
- 头文件风格注意：header 包含了 using namespace std; 在扩展公共接口时避免引入命名冲突。

仓库重要文件
- console_ui.h：整个库的 API 与实现。
- test.cpp：示例/测试程序，演示 termw/termh、clrtxt、mvc、样式等功能。
- test/：包含已编译的测试二进制（非构建脚本目录）。

检测到的 AI 助手配置文件
- 仓库根目录未发现常见的助手配置文件（如 CLAUDE.md、.cursorrules、AGENTS.md、CONVENTIONS.md 等）。若添加这些文件，请在文件中说明 Copilot 的使用偏好映射。

Copilot 会话使用建议
- 修改建议：优先进行小范围、头文件本地的变更；将单头文件拆分为多文件或引入构建系统前，请先与维护者确认。
- 保持枚举数值不变，除非明确需要并与调用方协调。
- 若要添加自动化测试，请同时添加 CMakeLists.txt 或 Makefile，并在 README 中记录构建与运行命令；否则可使用本文中提供的 g++/cl 命令进行快速验证。
