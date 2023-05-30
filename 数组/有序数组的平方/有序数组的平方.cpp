#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SquareOfOrderedArray {
public:
    /**
     * 暴力解法
     * 首先取平方，然后进行排序
     * // 时间复杂度：O(n+nlogn)
     */
    vector<int> Brutal(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            A[i] *= A[i];
        }
        sort(A.begin(), A.end()); // 快速排序
        return A;
    }

    /**双指针法**/
    // 时间复杂度: O(n)
    vector<int> doublePoint(vector<int>& A) {

        int size = A.size();
        int i = 0;
        int j = A.size() - 1;

        vector<int> rAfterSorted(A.size(), 0);
        
        int index = size - 1;
        while (i != j) {
            if (A[i] * A[i] > A[j] * A[j]) {
                rAfterSorted[index] = A[i] * A[i];
                i++;
            }
            else {
                rAfterSorted[index] = A[j] * A[j];
                j--;
            }
            index--;
        } 
    }
};