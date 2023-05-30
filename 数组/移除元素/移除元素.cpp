#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 暴力法解决
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
                size--; // 此时数组的大小-1
            }
        }
        return size;

    }
};

// 双指针法（快满指针）
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

// 相向指针方法，基于元素顺序可以改变的题目描述改变了元素相对位置，确保了移动最少元素
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        while (leftIndex <= rightIndex) {
            // 找左边等于val的元素
            while (leftIndex <= rightIndex && nums[leftIndex] != val){
                ++leftIndex;
            }
            // 找右边不等于val的元素
            while (leftIndex <= rightIndex && nums[rightIndex] == val) {
                -- rightIndex;
            }
            // 将右边不等于val的元素覆盖左边等于val的元素
            if (leftIndex < rightIndex) {
                nums[leftIndex++] = nums[rightIndex--];
            }
        }
        return leftIndex;   // leftIndex一定指向了最终数组末尾的下一个元素
    }
};

// 删除排序数组的重复项，并返回剩余元素个数
class removeDuplicates {
public:
    // 使用额外O(n)的空间来存储经过删除重复元素后的元素
    int solution1(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        vector<int> numsAfterRemove;
        numsAfterRemove.push_back(nums[0]);
        for (int i = 1; i < size; i++) {
            if (nums[i] != nums[i-1])
                numsAfterRemove.push_back(nums[i]);
        }
        return numsAfterRemove.size();
    }

    // 使用双指针的方法，不需要额外存储空间
    int solution2(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int size = nums.size();
        int fastIndex = 1; // 快指针用于依次遍历数组元素
        int lowIndex = 0; // 慢指针用于存储非重复元素的位置
        while (fastIndex < size) {
            if (nums[fastIndex] != nums[lowIndex]) {
                ++lowIndex; // 因为不重复了，所以更新非重复元素位置
                nums[lowIndex] = nums[fastIndex];
            }
            fastIndex++;
        }
        return lowIndex + 1;
    }
};

class moveZero {
public:

    // 双指针法（快慢指针）
    int solution1(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int size = nums.size();
        int fastIndex = 0; // 快指针用于依次遍历数组元素
        int lowIndex = 0; // 慢指针用于存储最新非0元素的位置
        
        // 计算数组中有几个0，并移除数组中所有0元素
        int numsOfZero = 0;
        for (; fastIndex < size; fastIndex++) {
            if (nums[fastIndex] != 0) {
                nums[lowIndex] == nums[fastIndex];
                lowIndex++;
            }
            else {
                numsOfZero++;
            }
        }

        // 将所有零元素增加到非零元素后面
        for (;lowIndex < size; lowIndex++)  {
            nums[lowIndex] = 0;
        }

        return size - numsOfZero;
    }

    // 使用额外数组空间
    int solution2(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int size = nums.size();
        vector<int> numsAfterRearrange;
        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                numsAfterRearrange.push_back(nums[i]);
            } 
        }
        
        int numsOfZeros = size -numsAfterRearrange.size();
        for (int j = 0; j < numsOfZeros; j++) {
            numsAfterRearrange.push_back(0);
        }

        return size - numsOfZeros;
    }
};

class compareString {
public:

    // 使用快慢指针
    string removeBackSpace(string str) {
        int size = str.size();
        int fastIndex = 0; // 快指针用于遍历数组
        int lowIndex = -1; // 慢指针，指向结果数组的最新元素
        for (; fastIndex < size; fastIndex++) {
            if (str[fastIndex] != '#') {
                str[++lowIndex] = str[fastIndex];
            }
            else {
                lowIndex--;
                if (lowIndex < -1)
                    lowIndex = -1;
            }
        }

        str = str.substr(0, lowIndex + 1);
        return str;
    }

    int compareStr(string S, string T) {
        S = removeBackSpace(S);
        T = removeBackSpace(T);
        return S ==  T;
    }

    // 其实最好使用栈来进行处理，但这里不考虑
    
};

int main() {
    int n;
    cout << "请输入数组元素个数" << endl;
    cin >> n;
    vector<int> nums(n);

    cout << "请依次填充元素" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];  
    }
    
    cout << "请输入要移除的元素" << endl;
    int target;
    cin >> target;

    Solution1 solution2;
    cout << solution2.removeElement(nums, target) << endl;

}