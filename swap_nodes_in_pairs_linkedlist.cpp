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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) { 
            return head;  //if the list is empty or contains only one node, return head
        }

        //create a dummy node to ease the operations on the list
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            //swapping nodes
            prev->next = second;
            first->next = second->next;
            second->next = first;

            //move to the next pair of nodes
            prev = first;
        }

        //update the head after swapping
        head = dummy->next;
        delete dummy; //free the memory allocated for the dummy node

        return head;
    }
};
