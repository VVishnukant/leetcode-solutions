/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // step1 create the deep copy without random pointer
        Node* dummy = new Node(10);
        Node* tempc = dummy;
        Node* temp = head;
        while(temp){
            Node* a = new Node(temp->val);
            tempc->next = a;
            tempc = tempc->next;
            temp = temp->next;
        }
        Node* duplicate = dummy->next;
        // step2 create alternat connections (merge)

        Node* a= head;
        Node* b= duplicate;
        dummy = new Node(20);
        Node* tempd = dummy;
        while(a){
            tempd->next = a;
            a = a->next;
            tempd = tempd->next;
            tempd->next = b;
            b = b->next;
            tempd = tempd->next;
        }
        dummy = dummy->next;

        // step3 Assigning random pointer of duplicate

        Node* t1 = dummy; // t1 will traverse in the original list
        while(t1){
            Node* t2 = t1->next;// t2 is for duplicate
            if(t1->random){
                t2->random = t1->random->next;
            }
            t1 = t1->next->next;
        }

        // step4 seperating the lists
        Node* d1 = new Node(10);
        Node* d2 = new Node(20);
       t1 = d1;
        Node* t2 = d2;
        Node* t = dummy;
        while(t){
            t1->next = t;
            t = t->next;
            t1 = t1->next;

            t2->next = t;
            t = t->next;
            t2 = t2->next;
        }
        t1->next = NULL; 
        t2->next = NULL;
        d1 = d1->next; // original with random
        d2 = d2->next; // duplicate with random
        return d2;


    }
};