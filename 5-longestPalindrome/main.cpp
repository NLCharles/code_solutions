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
    string longestPalindrome(string s) {

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