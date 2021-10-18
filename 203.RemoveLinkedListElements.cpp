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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return head;
        while(head->val == val) {
            if(head->next == nullptr) {
                delete head;
                return nullptr;
            }
            else {
                ListNode *tmp = head->next;
                delete head;
                head = tmp;
            }
        }
        
        
        ListNode *tmp = head;
        while(tmp != nullptr) {
            while(tmp->next != nullptr && tmp->next->val == val) {
                ListNode *next = tmp->next;
                tmp->next = next->next;
                delete next;
            }
            tmp = tmp->next;
        }
            
            
        return head;
    }
};