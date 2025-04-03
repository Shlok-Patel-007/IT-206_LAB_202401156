#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& entry : freq) {
            int number = entry.first;
            int count = entry.second;
            buckets[count].push_back(number);
        }
       vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k)
                    break;
            }
        }
        
        return result;
    }
};

