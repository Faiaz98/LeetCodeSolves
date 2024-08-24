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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //edge case: if the input lists are empty, return nullptr
        if (lists.empty()) return nullptr;

        //lambda operator for priority queue (min-heap)
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val; //min-heap based on node values
        };

        //priority queue (min-heap) to store the nodes
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);

        //initialize the heap with the head of each list
        for (ListNode* list: lists) {
            if (list) minHeap.push(list);
        }

        //Dummy node to start the merged linked list
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy; // Pointer to the last node in the merged list

        //while there are nodes in the heap
        while (!minHeap.empty()) {
            //extract the smallest node
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            //Add the smallest node to the merged list
            tail->next = smallest;
            tail = tail->next;

            //if the extracted node has a next node, push it to the heap
            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }

        //return the merged list starting from the next node of the dummy
        return dummy->next;
    }
};
