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
        ListNode* lnode = l1;
        ListNode* rnode = l2;

        ListNode* result = new ListNode;
        ListNode* resnode = result;

        int sum = 0;
        int carry = 0;
        while(lnode != nullptr || rnode != nullptr){
            sum = carry;
            if(lnode != nullptr){
               sum += lnode->val;
               lnode = lnode->next;
            }
            if(rnode != nullptr){
               sum += rnode->val;
               rnode = rnode->next;
            }
            carry = sum / 10;
            sum %= 10;

            resnode->next = new ListNode(sum);
            resnode = resnode->next;
        }
        if(carry == 1)
            resnode->next = new ListNode(1);
        return result;
    }
};