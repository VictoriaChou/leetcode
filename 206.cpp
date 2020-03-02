// Reverse a singly linked list.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode* reverseList(ListNode* head) {
      ListNode* prev = NULL;
      ListNode* curr = head;
      while (curr != NULL)
      {
        ListNode* nextTmp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextTmp;
      }
      return prev;
    }
};