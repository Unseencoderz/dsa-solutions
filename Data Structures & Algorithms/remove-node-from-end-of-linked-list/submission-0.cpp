class Solution {
public:
    int LenLL(ListNode* head){
        int n = 0;
        while(head){
            n++;
            head = head->next;
        }
        return n;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = LenLL(head);
        int todelete = len - n;

        // Delete head
        if(todelete == 0){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* temp = head;
        for(int i = 1; i < todelete; i++){
            temp = temp->next;
        }

        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;

        return head;
    }
};