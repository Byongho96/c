#include <vector>

using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans = 0, hour, sm = 0;
        int dict[20001] = {0,}; 

        for (int i = 0; i < hours.size(); i++) {
            sm += hours[i] > 8 ? 1 : -1;
            if (dict[sm + 10000] == 0) {
                dict[sm + 10000] = i + 1;
            }
            
            if (sm > 0 ){
                ans = i + 1;
            } else if (dict[sm + 9999] > 0) {
                ans = max(ans, i + 1 - dict[sm + 9999]);
            }
        }
        return ans;
    }
};