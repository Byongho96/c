#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int N = s.length();
        int mx = 0, left = 0;
        set<char> charSet;
        
        for (int right = 0; right < N; right++) {
            if (charSet.count(s[right])) {
                while (charSet.count(s[right])) {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }

            charSet.insert(s[right]);
            mx = max(mx, right - left + 1);
        }

        return mx;
    }
};

int main() {
    Solution solution;
    cout << "ans: " << solution.lengthOfLongestSubstring("pwwkew");
}