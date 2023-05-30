#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    map<char, int> cnt_T, cnt_S;
    bool check() {
        for (const auto& p: cnt_T) {
            if (p.second > cnt_S[p.first]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string S, string T) {

        // 使用map统计T中所有字符
        for (int i = 0; i < T.size(); i++) {
            ++cnt_T[T[i]];
        }
        
        int left = 0; // 左指针初始化 
        int ansL = -1, ansR = -1;
        int len_cur = INT32_MAX; // 初始化当前最小子串长度

        // 定义右指针并初始化，依次循环
        for (int right = 0; right < S.size(); right++) {

            char s = S[right];
            // 如果T中存在该字符，则将S上该字符的统计加1，S仅保存与T相同的元素
            if (cnt_T.find(s) != cnt_T.end()) {
                ++cnt_S[s];
            }
            
            // 如果子串满足则更新子串长度，纪录当前左指针
            while (check() && left <= right) {
                if (right - left + 1 < len_cur ) {
                    len_cur = right - left +1;
                    ansL = left;
                }

                if (cnt_S.find(S[left]) != cnt_S.end()) {
                    --cnt_S[S[left]];
                }
                ++left;
            }
        }
        return ansL == -1 ? string() : S.substr(ansL, len_cur);
    }
};