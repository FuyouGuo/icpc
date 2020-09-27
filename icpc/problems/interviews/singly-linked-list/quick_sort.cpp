#include<cstdio>
typedef struct SinglyLinkedListNode {
	int data;
	SinglyLinkedListNode* next;
	SinglyLinkedListNode(int data) {
		this->data = data;
	}
} SinglyLinkedListNode;
void swap(SinglyLinkedListNode* p, SinglyLinkedListNode* q) {
	int val = p->data;
	p->data = q->data;
	q->data = val;
}
SinglyLinkedListNode* get_partion(SinglyLinkedListNode* st, SinglyLinkedListNode* et) {
	if (st == NULL) {
		return st;
	}
	SinglyLinkedListNode* p = st;
	SinglyLinkedListNode* q = st->next;
	int val = st->data;
	while (q != et) {
		if (q->data < val) {
			p = p->next;
			swap(p, q);
		}
		q = q->next;
	}
	swap(p, st);
	return p;
}
void quick_sort(SinglyLinkedListNode* st, SinglyLinkedListNode* et) {
	if (st != et) {
		SinglyLinkedListNode* partion = get_partion(st, et);
		quick_sort(st, partion);
		quick_sort(partion->next, et);
	}
}
int main() {
    SinglyLinkedListNode *root = new SinglyLinkedListNode(3);
	SinglyLinkedListNode *p = root;
	for (int i = 5; i > 0; i--) {
		p->next = new SinglyLinkedListNode(i);
		p = p->next;
	}
    p->next = NULL;
	quick_sort(root, NULL);
	p = root;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	return 0;
}
