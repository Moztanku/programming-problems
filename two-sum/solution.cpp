#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     for(int i=0; i<nums.size(); i++){
    //         for(int j=i+1; j<nums.size(); j++){
    //             if(nums[i]+nums[j] == target)
    //                 return {i,j};
    //         }
    //     }
    //     return {};
    // }

    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            if(m.find(target-nums[i]) != m.end())
                return {m[target-nums[i]], i};
            m[nums[i]] = i;
        }
        return {};
    }
};