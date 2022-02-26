#include "llrec.h"
//#include <iostream>


//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    // std::cout << head->val << std::endl;

    if (head == NULL){
        // head = NULL;
        if(smaller != NULL) { smaller->next = NULL; }
        if(larger != NULL) { larger->next = NULL; }
        return;
    }else{
        if (head->val <= pivot){
            smaller = head;
            Node* newHead = head->next;
            smaller->next = NULL;
            //std::cout << "Smaller" << std::endl;
            llpivot(newHead,smaller->next,larger,pivot);
            head = NULL;

        }else{
            //std::cout << "Larger" << std::endl;
            larger = head;
            Node* newHead = head->next;
            larger->next = NULL;
            //std::cout << "H: " << head->val << "NH: " << newHead->val << std::endl;
            llpivot(newHead,smaller,larger->next,pivot);
            head = NULL;

        }
        //std::cout << "Smaller is " << smaller->val << std::endl;
        //std::cout << "Larger is " << larger->val << std::endl;
    }
}
