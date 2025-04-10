#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Node {
 public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *cura = list1;
    ListNode *curb = list2;
    ListNode *cur_tail = nullptr;
    ListNode *new_head = nullptr;
    while (cura && curb) {
      if (cur_tail == nullptr) {
        if (cura->val < curb->val) {
          new_head = cura;
          cur_tail = cura;
          cura = cura->next;

        } else {
          new_head = curb;
          cur_tail = curb;
          curb = curb->next;
        }
        continue;
      }
      if (cura->val < curb->val) {
        cur_tail->next = cura;
        cura = cura->next;
      } else {
        cur_tail->next = curb;
        curb = curb->next;
      }
      cur_tail = cur_tail->next;
    }
    while (cura) {
      if (cur_tail == nullptr) {
        cur_tail = cura;
        new_head = cura;
        cura = cura->next;
        continue;
      }
      cur_tail->next = cura;
      cura = cura->next;
      cur_tail = cur_tail->next;
    }
    while (curb) {
      if (cur_tail == nullptr) {
        cur_tail = curb;
        new_head = curb;
        curb = curb->next;
        continue;
      }
      cur_tail->next = curb;
      curb = curb->next;
      cur_tail = cur_tail->next;
    }
    return new_head;
  }
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *cura = l1, *curb = l2;
    ListNode *up = new ListNode(0);
    ListNode *head = new ListNode(0), *cur = head;
    while (cura && curb) {
      cur->next = new ListNode(0);
      cur = cur->next;
      int res = cura->val + curb->val + up->val;
      up->val = res / 10;
      cur->val = res % 10;
      cura = cura->next;
      curb = curb->next;
    }
    while (cura) {
      cur->next = new ListNode(0);
      cur = cur->next;
      int res = cura->val + up->val;
      up->val = res / 10;
      cur->val = res % 10;
      cura = cura->next;
    }
    while (curb) {
      cur->next = new ListNode(0);
      cur = cur->next;
      int res = curb->val + up->val;
      up->val = res / 10;
      cur->val = res % 10;
      curb = curb->next;
    }
    if (up->val > 0) {
      cur->next = new ListNode(up->val);
    }
    head = head->next;
    return head;
  }
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    std::stack<ListNode *> s;
    ListNode *cur = head;

    // 1. 将链表节点压入栈
    while (cur) {
      s.push(cur);
      cur = cur->next;
    }

    // 2. 删除头结点的情况
    if (n == s.size()) {
      ListNode *newHead = head->next;
      delete head;
      return newHead;
    }

    // 3. 删除非头节点
    for (int i = 0; i < n; i++) {
      s.pop();
    }

    // 4. 找到待删除节点的前一个节点
    cur = s.top();
    ListNode *toDelete = cur->next;
    cur->next = toDelete->next;
    delete toDelete;  // 释放内存

    return head;
  }
  void swapNode(ListNode *a, ListNode *b) {
    ListNode *bn = b->next;
    b->next = a;
    a->next = bn;
  }
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *curA = head;

    ListNode *curB = curA->next;

    ListNode *new_head = curB;

    ListNode *last_tail = nullptr;
    while (curB) {
      ListNode *tmpA = curA, *tmpB = curB;
      if (curA->next->next && curB->next->next) {
        curA = curA->next->next;
        curB = curB->next->next;
      } else {
        curB = nullptr;
      }
      swapNode(tmpA, tmpB);
      if (last_tail) {
        last_tail->next = tmpB;
      }
      last_tail = tmpA;
    }
    return new_head;
  }
  pair<ListNode *, ListNode *> reverseChildLink(ListNode *head,
                                                ListNode *tail) {
    ListNode *last_node = nullptr;
    ListNode *cur = head;
    ListNode *next_node = cur->next;
    ListNode *end = tail->next;
    while (next_node != end) {
      last_node = cur;
      cur = next_node;
      next_node = next_node->next;
      cur->next = last_node;
    }
    return {tail, head};
  }
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *hair = new ListNode(0);
    hair->next = head;
    ListNode *cur = hair;
    ListNode *last_tail = hair;
    while (last_tail->next) {
      for (int i = 0; i < k; i++) {
        cur = cur->next;
        if (cur == nullptr) {
          return hair->next;
        }
      }
      ListNode *next_node = cur->next;
      auto [new_head, new_tail] = reverseChildLink(last_tail->next, cur);
      last_tail->next = new_head;
      last_tail = new_tail;
      last_tail->next = next_node;
      cur = last_tail;
    }
    return hair->next;
  }
  unordered_map<Node *, Node *> old2new;
  Node *copyRandomList(Node *head) {
    if (head == nullptr) {
      return head;
    }
    if (old2new.find(head) == old2new.end()) {
      Node *new_head = new Node(head->val);
      old2new[head] = new_head;
      new_head->next = copyRandomList(head->next);
      new_head->random = copyRandomList(head->random);
    }
    return old2new[head];
  }
  ListNode *sortList(ListNode *head) {
    vector<int> v;
    ListNode *cur = head;
    while (cur) {
      v.push_back(cur->val);
      cur = cur->next;
    }
    sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
    ListNode *new_head = new ListNode(0);
    cur = new_head;
    for (auto i : v) {
      cur->next = new ListNode(i);
      cur = cur->next;
    }
    return new_head->next;
  }
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    int len = lists.size();
    vector<int> array;
    for (auto cur : lists) {
      while (cur) {
        array.push_back(cur->val);
        cur = cur->next;
      }
    }
    sort(array.begin(), array.end(), greater<int>());
    ListNode *new_head = new ListNode(0);
    ListNode *cur = new_head;
    for (auto i : array) {
      cur->next = new ListNode(i);
      cur = cur->next;
    }
    return new_head->next;
  }
};
struct LRUNode {
  int key;
  int val;
  LRUNode *next;
  LRUNode *prev;
  LRUNode(int k, int x) : key(k), val(x) {};
};
class LRUCache {
 public:
 // NOTE - head和tail都指向了实际的节点，编写代码会有很多边界条件，很麻烦
 // 可以使用虚拟节点，head->next指向第一个节点，tail->prev指向最后一个，不用考虑nullptr
  LRUCache(int capacity) {
    this->capacity = capacity;
    head = nullptr;
    tail = nullptr;
  }

  int get(int key) {
    auto iter = m.find(key);
    if (iter == m.end()) {
      return -1;
    }
    LRUNode *node = iter->second;
    if (head != node && tail != node) {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      node->next = head;
      head->prev = node;
    } else if (node == tail && head != tail) {
      tail = tail->prev;
      tail->next = nullptr;
      node->next = head;
      head->prev = node;
    }
    head = node;
    return node->val;
  }

  void put(int key, int value) {
    // put to the head and evict the tail.
    auto iter = m.find(key);
    if (iter == m.end()) {
      // not found

      LRUNode *node = new LRUNode(key, value);
      m[key] = node;
      if (head == nullptr) {
        head = node;
        tail = head;
        return;
      }
      node->next = head;
      head->prev = node;
      head = node;
      if (m.size() > capacity) {
        int del = tail->key;
        m.erase(del);
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
      }
    } else {
      LRUNode *node = iter->second;
      if (head != node && tail != node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = head;
        head->prev = node;
      } else if (node == tail && head != tail) {
        tail = tail->prev;
        tail->next = nullptr;
        node->next = head;
        head->prev = node;
      }
      head = node;
      node -> val = value;
    }
  }

 private:
  LRUNode *head;
  LRUNode *tail;
  unordered_map<int, LRUNode *> m;
  int capacity;
};

int main() {
  LRUCache lru(2);
  string op;
  while (true) {
    cin >> op;
    if (op == "g") {
      int k;
      cin >> k;
      cout << lru.get(k) << endl;
    } else if (op == "p") {
      int k, v;
      cin >> k >> v;
      lru.put(k, v);

    } else {
      // Handle unknown command
    }
  }

  return 0;
}