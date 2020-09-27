#include<cstdio>
typedef struct ListNode {
    int value;
    ListNode* next;
    ListNode(int value) {
        this->value = value;
        this->next = NULL;
    }
} ListNode;

// 将两个有序的单链表合并
ListNode* merge(ListNode* head1, ListNode* head2) {
    ListNode* tmpHead = new ListNode(0);
    ListNode* iter = tmpHead;
    while (head1 != NULL && head2 != NULL) {
        if (head1->value <= head2->value) {
            iter->next = head1;
            head1 = head1->next;
        } else {
            iter->next = head2;
            head2 = head2->next;
        }
        iter = iter->next;
    }
    if (head1 != NULL) {
        iter->next = head1;
    }
    if (head2 != NULL) {
        iter->next = head2;
    }
    ListNode* newHead = tmpHead->next;
    delete tmpHead;
    return newHead;
}

// 用大步小步算法求链表中间元素
ListNode* getMid(ListNode* head) {
    ListNode* fast = head->next;
    ListNode* slow = fast;
    ListNode* prev = head;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = NULL;
    return slow;
}

ListNode* merge_sort(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* mid = getMid(head);
    ListNode* head1 = merge_sort(head);
    ListNode* head2 = merge_sort(mid);
    return merge(head1, head2);
}

void* push(ListNode** head, int val) {
    ListNode* newHead = new ListNode(val);
    newHead->next = *head;
    *head = newHead;
}

void* printList(ListNode* head) {
    while (head != NULL) {
        printf("%d\t", head->value);
        head = head->next;
    }
}

int main() {
    ListNode* head = NULL;
    push(&head, 7);
    for(int i = 9; i > 0; i--) {
        push(&head, i);
    }
    head = merge_sort(head);
    printList(head);
}
