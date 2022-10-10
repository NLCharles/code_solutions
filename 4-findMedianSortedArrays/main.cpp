#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

using std::max;
using std::min;
size_t INT_MIN = -10e6;
class Solution
{
public:
    double findkmin(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int i1, i2, m, n; // numbers on the left side of i1/i2 are excluded from comparison
        int p1, p2;       // index bounder
        i1 = i2 = 0;
        p1 = p2 = 0;
        m = nums1.size();
        n = nums2.size();
        // main loop
        while (true)
        {
            // boundary condition
            if (i1 > m - 1)
                return nums2[i2 + k - 1]; // all numbers in nums1 are excluded
            if (i2 > n - 1)
                return nums1[i1 + k - 1]; // all numbers in nums2 are excluded
            if (k == 1)
                return nums1[i1] > nums2[i2] ? nums2[i2] : nums1[i1]; // one shot comparison
            // get mid index
            p1 = (i1 + k / 2 - 1) > m - 1 ? m - 1 : (i1 + k / 2 - 1); // find mid k
            p2 = (i2 + k / 2 - 1) > n - 1 ? n - 1 : (i2 + k / 2 - 1); // find mid k
            // remove numbers
            if (nums1[p1] > nums2[p2])
            {
                k -= p2 - i2 + 1;
                i2 = p2 + 1;
            }
            else
            {
                k -= p1 - i1 + 1;
                i1 = p1 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        bool odd = (m + n) % 2;
        int k = (m + n) / 2 + odd;
        double med = 0;
        med = findkmin(nums1, nums2, k);
        if (!odd)
        {
            med += findkmin(nums1, nums2, k + 1);
            med /= 2; // definition of median of an array of even size
        }
        return med;
    }
};