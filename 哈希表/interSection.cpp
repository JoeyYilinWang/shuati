#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

class interSection {
public:

    // 暴力解法
    vector<int> Solution1(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();

        int size = size1 > size2 ? size1: size2;
        vector<int> result;

        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                if (nums1[i] == nums2[j]) {
                    result.push_back(nums2[j]);
                }
            }
        }

        // 对结果去重
        // 首先对元素进行排序
        sort(result.begin(), result.end());

        vector<int> result_after;

        int i = 1;
        result_after.push_back(result[i]);
        while (result[i] != result[i - 1] && i < result.size()) {
            result_after.push_back(result[i]);
        }

        return result_after;
    }
    
    // 使用set
    vector<int> Solution2(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums2.end());

        for (int num: nums2) {
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }

};