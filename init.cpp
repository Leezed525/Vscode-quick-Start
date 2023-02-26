#include <Windows.h>
#include <bits/stdc++.h>
#include <direct.h>
using namespace std;
#define ms(x, n) memset(x, n, sizeof(x));
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
inline int lowbit(int x) { return x & -x; }

// mingw编译器地址
string mingwPath = "";
// 需替换字符串
string pattern = "${mingwPath}";
// 当前目录
string currentPath;

// 获取必要参数(mingw编译器地址)
void getParamter() {
    printf("请输入你的mingw编译器的bin目录地址(按回车确定):\n");
    getline(cin, mingwPath);
    int len = mingwPath.length();
    // 替换所有'\' 变成 '/'
    for (int i = 0; i < len; i += 1) {
        if (mingwPath[i] == '\\') {
            mingwPath[i] = '/';
        }
    }
}

// 创建目标文件夹
void createDirectory() {
    // 生成的文件夹名称
    string directoryName = ".\\.vscode ";
    CreateDirectoryA(directoryName.c_str(), NULL);
}

// 替换字符串中所有的origin至target
string replaceByPattern(string s, string origin, string target) {
    int pos = s.find(origin);
    while (pos != -1) {
        s.replace(pos, origin.length(), target);
        pos = s.find(origin);
    }
    return s;
}

// 操作文件
void operateFile(string fileName) {
    // 读文件
    ifstream readFile;
    // 写文件
    ofstream writeFile;
    readFile.open(currentPath + "\\vscode copy\\" + fileName);
    writeFile.open(currentPath + "\\vscode_init\\" + fileName);
    if (readFile.is_open()) {
        string tmp;
        while (getline(readFile, tmp)) {
            tmp = replaceByPattern(tmp, pattern, mingwPath);
            // cout << tmp << endl;
            writeFile << tmp << endl;
        }
        readFile.close();
        writeFile.close();
    } else {
        cout << fileName + "文件不存在" << endl;
    }
}

// 落实配置
void implementConfiguration() {
    // 获取当前工作路径
    char buffer[256];
    currentPath = getcwd(buffer, 256);
    operateFile("c_cpp_properties.json");
    operateFile("launch.json");
    operateFile("settings.json");
    operateFile("tasks.json");
}

int main() {
    // 获取mingw编译器的地址
    getParamter();
    // 生成目标文件夹
    createDirectory();
    // 开始生成文件
    implementConfiguration();
    system("pause");
    return 0;
}