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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        //find the middle node using slow and fast pointers
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse the 2nd half of the list
        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        slow->next = nullptr; //split the list
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //merge the lists
        ListNode *first = head;
        ListNode *second = prev;
        while (second) {
            ListNode *nextFirst = first->next;
            ListNode *nextSecond = second->next;
            first->next = second;
            second->next = nextFirst;
            first = nextFirst;
            second = nextSecond;
        }
    }
};
