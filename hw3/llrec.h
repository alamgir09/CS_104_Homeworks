#ifndef LLREC_H
#define LLREC_H
#include <cstdlib>
#include <iostream> //For TESTING purposes

/**
 * Node struct for both problems
 */
struct Node
{
    int val;
    Node *next;

    Node(int v, Node* n) : val(v), next(n) {}
};


/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than or equal to the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.
 *
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @pre: smaller and larger may containing garbage (do NOT have
 *       to be NULL)
 *
 * @param[inout] head
 *   Reference to the head pointer to the input list.
 *   Should be set to NULL upon return
 * @param[out] smaller
 *   Reference to a head pointer for the list of nodes with values
 *   less than or equal to the pivot
 * @param[out] larger
 *   Reference to a head pointer for the list of nodes with values
 *   greater than the pivot
 * @param[in] pivot
 *   Pivot value
 *
 */
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot);

/**
 * Given a linked list pointed to by head, removes (filters out) nodes
 * whose value does not meet the criteria given by the predicate
 * function object, pred (i.e. pred should be a function object that implements
 * `bool operator()(int value)` and returns *true* for items that should
 * be *removed/filtered*.  Removed items should be deallocated.
 *
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @param[in] head
 *   Reference to the head pointer to the input list.
 * @param[in] pred
 *   Predicate object implementing: `bool operator()(int value)` that
 *   returns true if a node (based on its value) should be removed.
 * @return a head pointer to the resulting list (since the head pointer
 *   may change [i.e. be filtered])
 *
 */
template <typename Comp>
Node* llfilter(Node* head, Comp pred);

//*****************************************************************************
// Since template implementations should be in a header file, we will
// implement the above function now.
//*****************************************************************************

template <typename Comp>
Node* llfilter(Node* head, Comp pred)
{
    //*********************************************
    // Provide your implementation below
    //*********************************************
    Node* temp = nullptr;
    //if (head == NULL) {return head;}
    if (head->next == NULL)
    {
        //std::cout << "Recursion has ended" << std::endl;
        //std::cout << "This is the last step bc" << std::endl;
        //std::cout << "Head is " << head << std::endl;
        std::cout << "Head's value is " << head->val << std::endl;
        //std::cout << "In first if " << std::endl;
        if (pred(head->val)){
            std::cout << "In first if " << std::endl;
            return NULL;
        }
        return head;
    }else{
        if (pred(head->val)){
            temp = head;
            head = head->next;
            delete temp;
            llfilter(head, pred);
            // std::cout << "This is what head is " << head << std::endl;
            return head;
        }
        else if (pred(head->next->val))
        {
            // std::cout << "odd val is right now " << head->val << std::endl;
            temp = head->next;
            head->next = head->next->next;
            delete temp;
            // std::cout << "Now the changed node val is " << head->val << std::endl;
            llfilter(head, pred);
            //std::cout << "This is the last step odd" << std::endl;
            return head;
        }else{
            // std::cout << "even val is right now " << head->val << std::endl;
            llfilter(head->next, pred);
            //std::cout << "This is the last step even" << std::endl;
            return head;
        }
        //std::cout << "Head first val is " << head->val << std::endl;
        //std::cout << "The pointer is " << head->next << std::endl;
    }
}

#endif
