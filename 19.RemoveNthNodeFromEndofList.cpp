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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *nth_last = head;
        ListNode *last = head;
        for(int i=0; i<n; i++) {
            if(last->next == nullptr) {
                if(i == n-1) {
                    ListNode *curr = head;
                    head = head->next;
                    delete curr;
                }
                return head;
            }
            
            last = last->next;
        }
        
        while(last->next != nullptr) {
            nth_last = nth_last->next;
            last = last->next;
        }
        
        ListNode *next = nth_last->next;
        nth_last->next = next->next;
        delete next;
        
        return head;
    }
};