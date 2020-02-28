/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 两数相加， 考察链表
#include<iostream>

using namespace std;
class Solution {
  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = l1; 
        ListNode* q = l2;
        ListNode* curr = dummyHead;
        int carry = 0; // 进位
        while(p != NULL || q != NULL) {
            int a = p != NULL ? p -> val : 0;
            int b = q != NULL ? q -> val : 0;
            int sum = carry + a + b;
            carry = sum / 10;
            curr -> next = new ListNode(sum % 10);
            curr = curr -> next;
            if(p != NULL) p = p -> next;
            if(q != NULL) q = q -> next;
        }
        if(carry > 0) {
            curr -> next = new ListNode(1);
        }
        return dummyHead -> next;
    }
};