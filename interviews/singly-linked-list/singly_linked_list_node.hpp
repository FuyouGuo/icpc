#ifndef SINGLY_LINKED_LIST_NODE
#define SINGLY_LINKED_LIST_NODE
class SinglyLinkedListNode<T> {
    private T data;
    private SinglyLinkedListNode* next;
    public SinglyLinkedListNode(T data) {
        this->data = data;
        this->next = NULL;
    }
    public SinglyLinkedListNode(T data, SinglyLinkedListNode* next) {
        this->data = data;
        this->next = next;
    }
    public void push(SinglyLinkedListNode** head, T data) {
        SinglyLinkedListNode* newHead = new SinglyLinkedListNode(data);
        newHead->next = *head;
        *head = newHead;
    }
}
#endif
