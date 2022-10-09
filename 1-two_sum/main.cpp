#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::cout;
using std::endl;
using std::map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> table;
        vector<int> ans;
        for (int i=0; i<nums.size();i++)
        {
            int val = nums[i];
            auto it = table.find(target-val);
            if (it == table.end())
            {
                table[val] = i;
                continue;
            }
            if (it->second != i)
            {
                ans.push_back(i);
                ans.push_back(it->second);
                break;
            }
        }
        return ans;
    }
};





int main(){
    auto sol = Solution();
    auto nums = vector<int>{0,1,2,3};
    auto ans = sol.twoSum(nums, 5);
    cout<<ans[0]<<' '<<ans[1]<<endl;
    return 0;
}