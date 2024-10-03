
#include <iostream>

int main() {
int a[3][5] = {1,1,0};
    // 打印数组内容
    for (int i = 0; i < 3; ++i) {  // 2 行
        for (int j = 0; j < 5; ++j) {  // 5 列
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
