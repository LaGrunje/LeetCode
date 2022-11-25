
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* current1 = l1->next;
        ListNode* current2 = l2->next;
        short current = (l1->val + l2->val) % 10;
        short digit = (l1->val + l2->val) / 10;
        ListNode* root = new ListNode(current);
        ListNode* ptr = root;
        while (current1 != nullptr || current2 != nullptr) {
            if (current1 == nullptr) {
                current = (current2->val + digit) % 10;
                digit = (current2->val + digit) / 10;
                current2 = current2->next;
            }
            else {
                if (current2 == nullptr){
                    current = (current1->val + digit) % 10;
                    digit = (current1->val + digit) / 10;
                    current1 = current1->next;
                }
                else {
                    current = (current2->val + current1->val + digit) % 10;
                    digit = (current2->val + current1->val  +digit) / 10;
                    current1 = current1->next;
                    current2 = current2->next;
                }
            }
            ListNode* tmp = new ListNode(current);
            ptr->next = tmp;
            ptr = ptr->next;
        }
        if (digit != 0)
        {
            ListNode* tmp = new ListNode(digit);
            ptr->next = tmp;
            ptr = ptr->next;
        }
        return root;
    }
};