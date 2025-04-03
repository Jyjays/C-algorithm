#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     stack<ListNode*> st,st2;
    //     while (headA -> next) {
    //         st.push(headA);
    //         headA = headA->next;
    //     }
    //     while (headB -> next) {
    //         st2.push(headB);
    //         headB = headB -> next;
    //     }
    //     ListNode * lastnode = nullptr;
    //     while (st.top() != st2.top()) {
    //         lastnode = st.top();
    //         st.pop();
    //         st2.pop();
    //     }
    //     return lastnode;
    //   }
    // 用栈找，费时费空间
    int len1 = 0;
    int len2 = 0;
    ListNode *curA = headA;
    ListNode *curB = headB;
    while (curA) {
      len1++;
      curA = curA->next;
    }
    while (curB) {
      len2++;
      curB = curB->next;
    }
    if (len1 < len2) {
      swap(len1, len2);
      swap(headA, headB);
    };
    int diff = len1 - len2;
    curA = headA;
    curB = headB;
    while (diff) {
      curA = curA->next;
      diff--;
    }
    while (len2--) {
      if (curA == curB) {
        return curA;
      }
      curA = curA->next;
      curB = curB->next;
    }
    return nullptr;
  }
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *cur_node = head;
    ListNode *last_node = nullptr;
    ListNode *next_node = cur_node->next;
    while (next_node) {
      last_node = cur_node;
      cur_node = next_node;
      next_node = next_node->next;
      cur_node->next = last_node;
    }
    head->next = nullptr;
    return cur_node;
  }
  bool isPalindrome(ListNode *head) {
    int len = 0;
    ListNode *cur = head;
    while (cur) {
      len++;
      cur = cur->next;
    }
    bool isj = len % 2;
    int half = len / 2;
    cur = head;
    stack<int> s;
    while (half--) {
      s.push(cur->val);
      cur = cur->next;
    }
    if (isj) cur = cur->next;
    while (cur) {
      if (s.top() != cur->val) {
        return false;
      }
      cur = cur->next;
      s.pop();
    }
    return true;
  }
  bool hasCycle(ListNode *head) {
    // int len = 0;
    // ListNode* cur = head;
    // while (cur) {
    //   if(len > 10000) {
    //     return false;
    //   }
    //   len++;
    //   cur = cur->next;
    // }
    // return true;
    if (head == nullptr || head->next == nullptr) {
      return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast) {
      if (fast == nullptr || fast->next == nullptr) {
        return false;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    return true;
  }
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast != nullptr) {
        slow = slow->next;
        if (fast->next == nullptr) {
            return nullptr;
        }
        fast = fast->next->next;
        // NOTE -  get the inter of the cycle
        if (fast == slow) {
            ListNode *ptr = head;
            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return nullptr;

}
};

int main() {}