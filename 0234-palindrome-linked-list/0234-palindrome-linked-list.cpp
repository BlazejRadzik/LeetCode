class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // 1. Find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse the second half
        ListNode* secondHalfHead = reverseList(slow->next);

        // 3. Compare the two halves
        ListNode* firstHalf = head;
        ListNode* secondHalf = secondHalfHead;
        bool isPalin = true;
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // 4. (Optional) Reverse back to restore
        slow->next = reverseList(secondHalfHead);

        return isPalin;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};