
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cOver = 0;
        ListNode* ans = new ListNode(0);
        ListNode* tmp = ans;

        while (l1 || l2) {
            int sum = cOver;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            if (sum > 9) {
                cOver = 1;
                sum %= 10;
            }
            else {
                cOver = 0;
            }

            tmp->next = new ListNode(sum);
            tmp = tmp->next;
        }
        
        if (cOver) {
            tmp->next = new ListNode(cOver);
        }
        
        return ans->next;
    }
};