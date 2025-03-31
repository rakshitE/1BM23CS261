bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    struct ListNode *a = head, *b = head;
    while (b != NULL && b->next != NULL) {
        a = a->next;
        b = b->next->next;
    }
    struct ListNode *current = head;
    int stack[100000];
    int index = 0;

    while (current != a) {
        stack[index++] = current->val;
        current = current->next;
    }

    if (b != NULL) {
        a = a->next;
    }

    while (a != NULL) {
        if (a->val != stack[--index]) {
            return false;
        }
        a = a->next;
    }
    return true;
}
