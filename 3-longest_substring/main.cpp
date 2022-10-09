#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::vector;
using std::cout;
using std::endl;
using std::map;
using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2)
          return s.size();
        int i=0, j=0;
        int head=0, tail=0;
        int cur_max=0, max=0;
        char ch;
        int mask[256] = {0};
        for (j=0;j<s.size();j++)
        {
            ch = s[j];
            if (mask[ch] != 0)
            {
                cur_max = j-i;
                if (cur_max > max)
                {
                    max = cur_max;
                    head = i;
                    tail = j-1;
                }
                while(mask[ch] == 1 && i < j)
                {
                    mask[s[i]] = 0;
                    i++;
                }
            }
            mask[ch] = 1;
        }
        cur_max = j-i;
        if (cur_max > max)
        {
            max = cur_max;
            head = i;
            tail = j-1;
        }
        return tail - head + 1;
    }
};

int main(){
    auto sol = Solution();
    cout<< sol.lengthOfLongestSubstring("abcabcaefghabcabc");
    return 0;
}