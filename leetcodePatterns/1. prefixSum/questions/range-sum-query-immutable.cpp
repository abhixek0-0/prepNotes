// https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
private:
    vector<int> prefix; // init an array

public:
    NumArray(vector<int>& nums) {
        // we will have size+1 cus 1st entry in prefix[] will be 0
        // this will avoid size==0 checks
        prefix.resize(nums.size() + 1); // first gotta give size
        prefix[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        // +1, ie prefix is shifted by 1
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
