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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1); //��Ž��
        ListNode* cur = res;
        int sum = 0; //��ӽ��
        bool carry = false; //�Ƿ��λ
        while (l1 != nullptr || l2 != nullptr) {
            sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (carry) { //��λ
                sum++;
            }
            //��ŵ�ǰλ����ӽ��
            cur->next = new ListNode(sum % 10);
            cur = cur->next;

            //�ж���һ���Ƿ���Ҫ��λ
            if (sum >= 10) {
                carry = true;
            }
            else {
                carry = false;
            }
        }
        if (carry) {
            cur->next = new ListNode(1);
        }

        return res->next;
    }
};