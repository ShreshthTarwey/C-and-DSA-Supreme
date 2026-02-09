#include<bits/stdc++.h>

using namespace std;

Node* mergeTwoLists(Node* list1, Node* list2) {
        if (list1 == NULL) {
            return list2;
        } else if (list2 == NULL) {
            return list1;
        }

        Node* main = NULL;
       

        if (list1->data <= list2->data) {
            main = list1;
            list1 = list1->next;
        } else {
            main = list2;
            list2 = list2->next;
        }
        Node* temp = main;
        Node* p1 = list1;
        Node* p2 = list2;

        while (p1 != NULL && p2 != NULL) {
            if (p1->data <= p2->data) {
                temp->next = p1;
                p1 = p1->next;
            } else {
                temp->next = p2;
                p2 = p2->next;
            }
            temp = temp->next;
        }

        while (p1 != NULL) {
            temp->next = p1;
            p1 = p1->next;
            temp = temp->next;
        }
        while(p2!=NULL){
            temp->next = p2;
            p2 = p2->next;
            temp = temp->next;
        }
        return main;
    }
int main(){

}