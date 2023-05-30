#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int loop = n / 2; // 四条边循环几次
        int startx = 0, starty = 0; // 循环起点
        int offset = 1; // 每次循环的边界
        int mid = n / 2; // 判断是否存在中心位置
        int count = 1; // 用于填充矩阵的数字

        int i, j;

        while (loop--) {
            for (j = starty; j < n - offset; j++) {
                res[startx][j] = count++;
            }

            for (i = startx; i < n - offset; i++) {
                res[i][j] = count++;
            }

            for (; j > starty; j--) {
                res[i][j] = count++;
            }

            for (; i > startx; i--) {
                res[i][j] = count++;
            }

            startx++;
            starty++;
            offset++;
        }

        if (mid == 1) {
            res[mid][mid] = count;
        }
        return res;
    }
};