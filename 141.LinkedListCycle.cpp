/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return false;
        
        ListNode *slower = head;
        ListNode *faster = head->next;
        while(1) {
            if(slower == faster)
                return true;
            if(faster->next == nullptr || faster->next->next == nullptr)
                return false;
                
            slower = slower->next;
            faster = faster->next->next;
        }
    }
};