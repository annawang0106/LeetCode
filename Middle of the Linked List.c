//Method1 (best)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head){
    int length =0;
    struct ListNode* curr = head;
    while(curr != NULL){
        curr = curr -> next;
        length++;                       //計算link list長度
    }
    struct ListNode* result = head;     //
    for(int i =0; i<length/2 ; i++){
        result = result -> next;
    }
    return result;
}


//Method2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//龜兔賽跑，兔子比烏龜快2倍，當兔子到終點烏龜大約在一半的位子
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;     
}
