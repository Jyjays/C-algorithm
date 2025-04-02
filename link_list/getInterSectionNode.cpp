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
};

int main() {}