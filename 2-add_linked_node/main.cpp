#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::cout;
using std::endl;
using std::map;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// build input list node from a given vectort<int>
ListNode* buildListNodes(vector<int>& nums_inv)
{
    ListNode *dummy = new ListNode(0);
    ListNode *head;
    ListNode *ans;
    head = dummy;
    for (int i=0; i<nums_inv.size(); i++)
    {
        head->next = new ListNode(nums_inv[i]);
        head = head->next;
    }
    ans = dummy->next;
    delete dummy;
    return ans;
}

void printListNode(ListNode* ln)
{
    while (ln)
    {
        cout<<ln->val<<' ';
        ln = ln->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        int jump = 0;
        int cur_sum = 0;
        ListNode dummy(0);
        dummy.next = l1;
        ListNode* pre = &dummy;
        while(l1 && l2)
        {
            cur_sum = l1->val + l2->val + jump;
            jump = cur_sum / 10;
            cur_sum %= 10;
            l1->val = cur_sum;
            l1 = l1->next;
            l2 = l2->next;
            pre = pre->next;
        }
        l1 = l1 ? l1 : l2;
        pre->next = l1;
        while(l1)
        {
            cur_sum = l1->val + jump;
            jump = cur_sum / 10;
            cur_sum %= 10;
            l1->val = cur_sum;
            l1 = l1->next;
            pre = pre->next;
        }
        if (jump >0)
            pre->next = new ListNode(1);
        return head;
    }
};

int main(){
    auto sol = Solution();
    auto nums = vector<int>{4,1,2,3};
    auto nums2 = vector<int>{9,1,2,7};
    printListNode(buildListNodes(nums));
    printListNode(buildListNodes(nums2));
    auto ans = sol.addTwoNumbers(buildListNodes(nums), buildListNodes(nums2));
    printListNode(ans);
    return 0;
}