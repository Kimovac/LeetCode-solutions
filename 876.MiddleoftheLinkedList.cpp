/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*start = head;
        int n = 0;
        while(head != nullptr) {
            n++;
            head = head->next;
        }
    
        n = n/2;
        while(n > 0) {
            n--;
            start = start->next;
        }
        
        return start;
    }
};