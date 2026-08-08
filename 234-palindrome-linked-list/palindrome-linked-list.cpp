
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

    ListNode* reversedlinkedlist(ListNode* head) {

        // Base case
        if (head == nullptr || head->next == nullptr)
            return head;

        // Reverse the rest of the list
        ListNode* newhead = reversedlinkedlist(head->next);

        // Connect current node to the end
        ListNode* front = head->next;
        front->next = head;

        // Current node becomes the last node
        head->next = nullptr;

        return newhead;
    }

    bool isPalindrome(ListNode* head) {

        // Empty list or single node
        if (head == nullptr || head->next == nullptr)
            return true;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // For odd length, skip the middle node
        if (fast != nullptr) {
            slow = slow->next;
        }

        // Reverse second half
        ListNode* newhead = reversedlinkedlist(slow);

        // Compare first half and reversed second half
        ListNode* first = head;
        ListNode* second = newhead;

        while (second != nullptr) {

            if (first->val != second->val) {
                // Restore the list
                reversedlinkedlist(newhead);
                return false;
            }

            first = first->next;
            second = second->next;
        }

        // Restore the original list
        reversedlinkedlist(newhead);

        return true;
    }
};
