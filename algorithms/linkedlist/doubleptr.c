// https://labuladong.github.io/algo/di-yi-zhan-da78c/shou-ba-sh-8f30d/shuang-zhi-0f7cc/
#include <list/linklist.h>

// https://leetcode.cn/problems/linked-list-cycle/
/*
Time Complexity:
Space Complexity:
*/
bool hasCycle(LinkList head) {
  LinkList ptr1 = head, ptr2 = head;
  while (ptr1 && ptr2) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next->next;
    if (ptr1 == ptr2) return true;
  }
  return false;
}

// https://leetcode.cn/problems/linked-list-cycle-ii/
LinkList detectCycle(LinkList head) {
  LinkList slow = head, fast = head;
  while (slow && fast) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) break;  // `fast` meets `slow`
  }
  // no cycle
  if (fast == NULL || fast->next == NULL) return NULL;

  slow = head;
  while (fast != slow) {
    fast = fast->next;
    slow = slow->next;
  }

  return fast;
}

// https://leetcode.cn/problems/intersection-of-two-linked-lists/
LinkList getIntersectionNode(LinkList la, LinkList lb) {
  LinkList ptr1 = la, ptr2 = lb;
  while (ptr1 && ptr2) {
    if (ptr1->next == NULL)
      ptr1->next = lb;
    else
      ptr1 = ptr1->next;
    if (ptr2->next == NULL)
      ptr2->next = la;
    else
      ptr2 = ptr2->next;
  }

  return ptr1;
}

// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
LinkList removeNthFromEnd(LinkList head, int n) {
  LinkList dummy = (LinkList)malloc(sizeof(LNode));  // 🌟dummy
  LinkList first = head, second = dummy;
  for (int i = 0; i < n; i++) {
    first = first->next;
  }
  while (first) {
    first = first->next;
    second = second->next;
  }

  second->next = second->next->next;
  return dummy->next;
}

// https://leetcode.cn/problems/merge-two-sorted-lists/
LinkList mergeTwoLists(LinkList list1, LinkList list2) {
  LinkList dummy = (LinkList)malloc(sizeof(LNode));
  LinkList ptr = dummy;
  LinkList ptr1 = list1, ptr2 = list2;

  while (ptr1 && ptr2) {
    if (ptr1->data < ptr2->data) {
      ptr->next = ptr1;
      ptr1 = ptr1->next;
    } else {
      ptr->next = ptr2;
      ptr2 = ptr2->next;
    }
    ptr = ptr->next;
  }

  if (ptr1) ptr->next = ptr1;
  if (ptr2) ptr->next = ptr2;

  return dummy->next;
}

LinkList reverseList(LinkList head) {
  LinkList prev = NULL, curr = head;
  while (curr) {
    LinkList tmp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = tmp;
  }

  return prev;
}

// https://leetcode-cn.com/problems/swap-nodes-in-pairs/
LinkList swapPairs(LinkList head) {
  LinkList dummy = (LinkList)malloc(sizeof(LNode));
  dummy->next = head;
  LinkList ptr = dummy;

  while (ptr->next && ptr->next->next) {
    LinkList first = ptr->next;
    LinkList second = ptr->next->next;
    ptr->next = second;
    first->next = second->next;
    second->next = first;
    ptr = first;
  }

  return dummy->next;
}

// https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
LinkList reverseKGroup(LinkList head, int k) {
  LinkList dummy = (LinkList)malloc(sizeof(LNode));
  dummy->next = head;
  LinkList ptr = dummy;

  while (ptr) {
    // check if there are `k` nodes
    LinkList first = ptr->next;
    LinkList second = ptr->next;
    for (int i = 0; i < k; i++) {
      if (second == NULL) return dummy->next;
      second = second->next;
    }

    // reverse `k` nodes
    for (int i = 0; i < k - 1; i++) {
      LinkList tmp = first->next;
      first->next = tmp->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
    }
    ptr = first;
  }

  return dummy->next;
}

// https://leetcode.cn/problems/partition-list/
LinkList partition(LinkList head, int x) {
  LinkList dummy1 = (LinkList)malloc(sizeof(LNode));
  LinkList dummy2 = (LinkList)malloc(sizeof(LNode));
  LinkList ptr1 = dummy1, ptr2 = dummy2;
  LinkList ptr = head;

  while (ptr) {
    if (ptr->data < x) {
      ptr1->next = ptr;
      ptr1 = ptr1->next;
    } else {
      ptr2->next = ptr;
      ptr2 = ptr2->next;
    }
    LinkList tmp = ptr->next;
    ptr->next = NULL;
    ptr = tmp;
  }
  ptr1->next = dummy2->next;

  return dummy1->next;
}

// https://leetcode.cn/problems/middle-of-the-linked-list/
LinkList middleNode(LinkList head) {
  LinkList slow = head, fast = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

// https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
LinkList getKthFromEnd(LinkList head, int k) {
  LinkList first = head, second = head;
  for (int i = 0; i < k; i++) {
    first = first->next;
  }

  while (first) {
    first = first->next;
    second = second->next;
  }
  return second;
}

// https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
LinkList offerMergeTwoLists(LinkList l1, LinkList l2) {
  LinkList dummy = (LinkList)malloc(sizeof(LNode));
  LinkList ptr = dummy;
  LinkList ptr1 = l1, ptr2 = l2;

  while (ptr1 && ptr2) {
    if (ptr1->data < ptr2->data) {
      ptr->next = ptr1;
      ptr1 = ptr1->next;
    } else {
      ptr->next = ptr2;
      ptr2 = ptr2->next;
    }
    ptr = ptr->next;
  }

  if (ptr1) ptr->next = ptr1;
  if (ptr2) ptr->next = ptr2;

  return dummy->next;
}

LinkList reorderList(LinkList head) {
  if (head == NULL || head->next == NULL) return head;
  LinkList last = reorderList(head->next);
  head->next->next = head;
  head->next = NULL;
  return last;
}

// not useful for negative number
LinkList detectDuplicate(LinkList head) {
  int max = 0;
  LinkList ptr = head;
  while (ptr) {
    if (max < ptr->data) max = ptr->data;
    ptr = ptr->next;
  }

  LinkList prev = (LinkList)malloc(sizeof(LNode));
  Assert(prev, "fail!");
  prev->next = head;
  LinkList curr = head;
  int arr[max + 1];
  for (int i = 0; i <= max; i++) {
    arr[i] = 0;
  }

  if (head == NULL || head->next == NULL) return head;

  while (curr) {
    if (arr[curr->data] == 0) {
      arr[curr->data] = 1;
      prev = prev->next;
      curr = curr->next;
    } else {
      prev->next = curr->next;
      curr = curr->next;
    }
  }
  return head;
}

int main() {
  LinkList list1 = (LinkList)malloc(sizeof(LNode));
  list1->data = -1;
  LinkListInsert(&list1, 1, 3);
  LinkListInsert(&list1, 1, 3);
  LinkListInsert(&list1, 1, 0);
  LinkListInsert(&list1, 1, 0);
  LinkListInsert(&list1, 1, 0);
  LinkListInsert(&list1, 1, 0);

  detectDuplicate(list1);
  LinkList ptr = list1;
  while (ptr) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");

  return 0;
}