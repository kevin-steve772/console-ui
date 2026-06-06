# console-ui

版本：v1.1.0

## 简介
一个C++头文件，用于控制台用户界面程序的开发。
基于ANSI转义序列实现，支持Windows、Linux和macOS等平台。
> 此项目含AI生成内容。

## 仓库里有什么?
`test.cpp` - 测试程序源代码。

`console_ui.h` - 头文件本身。

`README.md` - 你现在在看的自述文件。

`test` - 编译的测试程序(Linux环境)。

## 怎么用？
- 把`console_ui.h`放到你的项目目录并在源代码中引用：
  `#include "console_ui.h"`

- 使用示例：
  - clrtxt("Hello", RED, BG_DEFAULT);                      // 普通彩色文本
  - clrtxt("Warning", YELLOW, BG_DEFAULT, TS_BOLD);      // 粗体黄色文本
  - clrtxt("Info", CYAN, BG_BLACK, TS_UNDERLINE);        // 带下划线的青色文本

## 包含函数
- `mvc(x,y)` - 将光标移动到指定位置（列 x, 行 y）。

- `clrtxt(text, txtcolor = DEFAULT, bgcolor = BG_DEFAULT, style = TS_NONE)`
  - 输出带颜色和可选文本样式的文本，函数会在文本后重置样式。
  - 可用的文本样式（TextStyle 枚举）：
    - `TS_NONE`（默认）
    - `TS_BOLD`（粗体）
    - `TS_DIM`（暗色）
    - `TS_ITALIC`（斜体）
    - `TS_UNDERLINE`（下划线）
    - `TS_BLINK`（闪烁）
    - `TS_REVERSE`（反色）
    - `TS_HIDDEN`（隐藏）
    - `TS_STRIKETHROUGH`（删除线）

- `hc()` - 隐藏光标。

- `sc()` - 显示光标。

- `setup()` - 在 Windows 上启用虚拟终端（VT）处理以支持 ANSI 转义序列；其他平台（例如Linux和macOS）为 no-op。

- `termh()` - 返回终端高度（行数），平台依赖，失败时返回 24（大部分终端默认高度）。

- `termw()` - 返回终端宽度（列数），平台依赖，失败时返回 80（大部分终端默认宽度）。

## 已实现 / 变更
- 在 v1.1.0 中：为 `clrtxt()` 添加了可选的 `style` 参数，并在头文件中新增 `TextStyle` 枚举以支持多种文本样式。

## 未来会加入的功能
- [ ] 支持更多颜色（例如256色或24位真彩色）。
