#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class isAnagram {
public:

    // 哈希解法
    // 世间复杂度：O(n)
    bool Solution1(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            // 不需要记住字母的ASCII，只需要求出相对数值就可以了
            record[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (record[i] != 0)
                return false;
        }

        return true;
    }

    // 暴力解法
    // 时间复杂度为：O(nlogn)
    bool Solution2(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;    
    }

};