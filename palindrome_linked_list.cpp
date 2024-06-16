#include <utility>


//!  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    int len(ListNode* head) {
        int count = 0;
        for(ListNode* curr = head; curr != nullptr; curr = curr->next) {
            ++count;
        }
        return count;
    }

    std::pair<ListNode*, ListNode*> reverse_mid(ListNode* head, int mid) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nxt = curr->next;

        for(int i = 0; i < mid; ++i) {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        return std::make_pair(prev, curr);
    }

    bool isPalindrome(ListNode* head) {
        int size_list = len(head);
        if (size_list <= 1) {
            return true;
        }

        int mid = size_list % 2 == 0 ? size_list / 2
                                     : size_list / 2 + 1;

        auto&&[left_h, right_h] = reverse_mid(head, mid);

        if (size_list % 2 != 0) {
            left_h = left_h->next;
        }

        for(; right_h != nullptr; right_h = right_h->next, left_h = left_h->next) {
            if (right_h->val != left_h->val) {
                return false;
            }
        }

        return true;

    }
};

int main() {


    return 0;
}