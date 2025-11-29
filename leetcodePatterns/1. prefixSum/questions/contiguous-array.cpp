// https://leetcode.com/problems/contiguous-array

#include <unordered_map>

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // thought process - 
        // assume a graph w 1 is increasing and 0 is decreasing
        // there might be a point on which graph comes back more than once
        // that means number of element bw those points have equal 0s and 1s (balanced w +-)
        // for all such points, find the one w max no of elements in bw
        unordered_map<int, int> mp; // hashmap to track recurring points
        int maxLen = 0;
        int prefix = 0; // (prefix sum wo storing) movement of graph: +1 for 1, -1 for 0
        mp[0] = -1; // edge case, prefix sum starts w index 1 of prefix array but index 0 of nums[]
        // so need to account for that position as well ie -1 wrt nums
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i] > 0 ? 1 : -1;
            if (mp.find(prefix) != mp.end()) { // if recurring, keep number of elements (if > current answer)
                maxLen = std::max(maxLen, i - mp[prefix]);
            } else { // track
                mp[prefix] = i;
            }
        }
        return maxLen;
    }
};