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
    bool isPalindrome(string s, int i, int j)
    {
        for (int l=0; l< (j-i) / 2; l++)
        {
            if (s[i+l] == s[j-l]) continue;
            return false;
        }
        return true;
    }

    int  mask[1000][1000]; // s[i][j] = s[j][i]

    bool isPalindrome_DP(string &s, int i, int j) // DP 
    {
        if (i==j) return true;
        if (i==j-1) return s[i] == s[j];
        return s[i] == s[j] && mask[i+1][j-1];
    }

    string longestPalindrome(string s) {
        int head=0,tail=0;
        int cur_max=0, max = 0;
        int i,j;
        bool flag;
        for (j=0;j<s.size();j++)
        {
            for (i=0; i<j+1; i++)
            {
                mask[i][j] = flag = isPalindrome_DP(s,i,j);
                if (flag)
                {
                    cur_max = j-i+1;
                    if (cur_max > max)
                    {
                        max =  cur_max;
                        head = i;
                    }
                }
            }
        }
        return s.substr(head, max);
    }
};
int main(){
    auto sol = Solution();
    cout<<sol.isPalindrome(string("abcba"),0,4)<<endl;
    cout<<sol.isPalindrome(string("abccba"),0,5)<<endl;
    cout<<sol.isPalindrome(string("abcbad"),0,5)<<endl;
    // cout<< sol.longestPalindrome("abcabcaefghabcabc");
    return 0;
}