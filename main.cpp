#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

//add pragmas
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")


class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int res = 0;
        std::vector<std::pair<int, double>> pairs;
        for (int i = 0; i < pos.size(); i++) {
            double reaching_time = static_cast<double>(target - pos[i]) / speed[i];
            pairs.push_back({pos[i], reaching_time});
        }
        sort(pairs.rbegin(), pairs.rend());
        stack<double> s;
        for (int i = 0; i < pairs.size(); i++) {
            if (s.empty() || pairs[i].second > s.top()) {
                s.push(pairs[i].second);
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    std::vector<int> position = {10,8,0,5,3};
    std::vector<int> speed = {2,4,1,1,3};
    int target = 12;
    cout << s.carFleet(target, position, speed);
    return 0;
}
