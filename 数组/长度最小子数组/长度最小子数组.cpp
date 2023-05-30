#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 暴力解法
    // 时间复杂度很明显是O(n^2)
    int minSubArrayLen(int s, vector<int>& nums) {
        int result INT32_MAX;
        int sum = 0;
        int subLength = 0; 
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                sum = sum + nums[j];
                if (sum >= s) {
                    subLength = j - i + 1;
                    result = result < subLength ? result : subLength;
                    break; // 因为是寻找最小子串，在当前循环中如果上述条件满足，则j就不用往后找了，因为此时子串已经是最小了
                }
            }
        }
        return result == INT32_MAX ? 0 : result;
    }

    // 滑窗法，本质上也是双指针
    int slidingWindow(int s, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度

        // 滑动窗口的终止位置
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};