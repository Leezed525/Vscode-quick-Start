# 快速vscode c++环境搭建
[toc]

## 手把手教程
https://blog.csdn.net/Leezed525/article/details/129509981

## 主要功能
+ vscode C++ 代码格式化配置
+ vscode C++ 环境配置
+ vscode C++ coderRunner配置
+ 将所有编译生成的exe文件统一放入zexe文件夹中
+ 增加设置防止vscode 编译c++时往c盘生成大量编译产物(编译多了之后就会非常大，现在我设置成了声称在.vscode夹中)
+ 增加了设置 可以使用按住ctrl 使用鼠标滚轮来进行字体的放大缩小

## 运行准备
请先下载好mingw编译器，具体的教程请看上面连接，然后运行init.exe就可以了，会自动生成.vscode文件夹

~~将vscode copy文件夹该名称  **.vscode**~~

~~将 .vscode中的配置文件修改，主要是三个文件中的编译器位置改成自己的~~

**对着cpp文件按F5就可以运行啦**

**或者使用coderunner ctrl+alt+n即可运行**
