#ifndef RBBST_H
#define RBBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <algorithm>
#include "bst.h"

struct KeyError { };

/**
* A special kind of node for an AVL tree, which adds the balance as a data member, plus
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
    // Constructor/destructor.
    AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    char getBalance () const;
    void setBalance (char balance);
    void updateBalance(char diff);

    // Getters for parent, left, and right. These need to be redefined since they
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value>* getParent() const override;
    virtual AVLNode<Key, Value>* getLeft() const override;
    virtual AVLNode<Key, Value>* getRight() const override;

protected:
    signed char balance_; // added signed
};

/*
  -------------------------------------------------
  Begin implementations for the AVLNode class.
  -------------------------------------------------
*/

/**
* An explicit constructor to initialize the elements by calling the base class constructor and setting
* the color to red since every new node will be red when it is first inserted.
*/
template<class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value> *parent) :
    Node<Key, Value>(key, value, parent), balance_(0)
{

}

/**
* A destructor which does nothing.
*/
template<class Key, class Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* A getter for the balance of a AVLNode.
*/
template<class Key, class Value>
char AVLNode<Key, Value>::getBalance() const
{
    return balance_;
}

/**
* A setter for the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::setBalance(char balance)
{
    balance_ = balance;
}

/**
* Adds diff to the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::updateBalance(char diff)
{
    balance_ += diff;
}

/**
* An overridden function for getting the parent since a static_cast is necessary to make sure
* that our node is a AVLNode.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getParent() const
{
    return static_cast<AVLNode<Key, Value>*>(this->parent_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getLeft() const
{
    return static_cast<AVLNode<Key, Value>*>(this->left_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getRight() const
{
    return static_cast<AVLNode<Key, Value>*>(this->right_);
}


/*
  -----------------------------------------------
  End implementations for the AVLNode class.
  -----------------------------------------------
*/


template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
    virtual void insert (const std::pair<const Key, Value> &new_item); // TODO
    virtual void remove(const Key& key);  // TODO
protected:
    virtual void nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2);

    // Add helper functions here
    void rotateRight(AVLNode<Key,Value>* n); 
    void rotateLeft(AVLNode<Key,Value>* n);
    void insertFix(AVLNode<Key,Value>* p, AVLNode<Key,Value>* n);
    void removeFix(AVLNode<Key,Value>* n, int diff);


};

/*
 * Recall: If key is already in the tree, you should 
 * overwrite the current value with the updated value.
 */
template<class Key, class Value>
void AVLTree<Key, Value>::insert (const std::pair<const Key, Value> &new_item)
{
    // TODO
    //Insert copied from my BST function
    if (this->root_ == NULL)
   {
       this->root_ = new AVLNode<Key, Value>(new_item.first, new_item.second, NULL);
       static_cast<AVLNode<Key, Value>*>(this->root_)->setBalance(0);
       return;
   }else{
        AVLNode<Key, Value>* curr = static_cast<AVLNode<Key, Value>*>(this->root_);
        while (curr != NULL)
        {
            // greater than
            if (new_item.first > curr->getKey())
            {
                // if right node does exist, then traverse to it
                if (curr->getRight() != NULL)
                {
                    curr = curr->getRight();
                }else{
                    // new node and root_ = new node
                    AVLNode<Key, Value>* parent = curr;
                    curr = curr->getRight();
                    curr = new AVLNode<Key, Value>(new_item.first, new_item.second, parent);
                    static_cast<AVLNode<Key, Value>*>(curr)->setBalance(0);
                    parent->setRight(curr);

                    // check if conditions for insertFix()
                    if (parent->getBalance() == -1){parent->setBalance(0);}
                    else if (parent->getBalance() == 1){parent->setBalance(0);}
                    else if (parent->getBalance() == 0)
                    {
                        if (this->isLeftChild(curr)) {parent->updateBalance(-1);insertFix(parent, curr);}
                        else{parent->updateBalance(1);insertFix(parent, curr);}
                    }
                    break;
                }
                // less than
            }else if (new_item.first < curr->getKey()){
                // if left node does exist, then traverse to it
                if (curr->getLeft() != NULL)
                {
                curr = curr->getLeft();
                }else{
                    // new node and root_ = new node
                    AVLNode<Key, Value>* parent = curr;
                    curr = curr->getLeft();
                    curr = new AVLNode<Key, Value>(new_item.first, new_item.second, parent);
                    static_cast<AVLNode<Key, Value>*>(curr)->setBalance(0);
                    parent->setLeft(curr);

                    // check if conditions for insertFix()
                    if (parent->getBalance() == 1){parent->setBalance(0);}
                    else if (parent->getBalance() == -1){parent->setBalance(0);}
                    else if (parent->getBalance() == 0)
                    {
                        if (this->isLeftChild(curr)) {parent->updateBalance(-1);insertFix(parent, curr);}
                        else{parent->updateBalance(1);insertFix(parent, curr);}
                    }
                    break;
                }
                // equal to
            }else{
                // if root's key is == to keyValuePair.first
                curr->setValue(new_item.second);
                break;
            }
        }
   }
}

/*
 * Recall: The writeup specifies that if a node has 2 children you
 * should swap with the predecessor and then remove.
 */
template<class Key, class Value>
void AVLTree<Key, Value>:: remove(const Key& key)
{
    // TODO 

    AVLNode<Key, Value>* temp = static_cast<AVLNode<Key, Value>*>(this->internalFind(key));
    // if 0 children, just delete the NODE and NULL ptrs
    if (temp == NULL){return;}
            if (temp->getRight() == NULL && temp->getLeft() == NULL)
            {
                if (this->isLeftChild(temp))
                {
                    temp->getParent()->setLeft(NULL);
                }
                else if (this->isRightChild(temp))
                {
                    temp->getParent()->setRight(NULL);
                }
                else
                {
                    delete this->root_; // changed
                    this->root_ = NULL;
                }
                delete temp;
                return;
            }
            // else if 1 child, promote (link grandparent to child)
            // if left child
            else if (temp->getLeft() != NULL && temp->getRight() == NULL)
            {
                // if temp is a left child, set parent->setLeft() = child
                if (this->isLeftChild(temp))
                {
                    temp->getParent()->setLeft(temp->getLeft());
                    temp->getLeft()->setParent(temp->getParent());
                    delete temp;
                    return;
                }

                // if temp is a right child, set parent->setRight() = child
                else if (this->isRightChild(temp))
                {
                    temp->getParent()->setRight(temp->getLeft());
                    temp->getLeft()->setParent(temp->getParent());
                    delete temp;
                    return;
                }
                // parent is NULL
                else
                {
                    this->root_ = this->root_->getLeft(); // changed temp to root->
                    this->root_->setParent(NULL); 
                    delete temp; // changed
                    temp = NULL; // changed
                    return;
                }
                
            }
            // else if 1 child, promote (link grandparent to child)
            // if right child
            else if (temp->getRight() != NULL && temp->getLeft() == NULL)
            {
                // if temp is a left child, set parent->setLeft() = child
                if (this->isLeftChild(temp))
                {
                    temp->getParent()->setLeft(temp->getRight());
                    temp->getRight()->setParent(temp->getParent());
                    delete temp;
                    return;
                }

                // if temp is a right child, set parent->setRight() = child
                else if (this->isRightChild(temp))
                {
                    temp->getParent()->setRight(temp->getRight());
                    temp->getRight()->setParent(temp->getParent());
                    delete temp;
                    return;
                }

                // parent is NULL
                else
                {
                    this->root_ = this->root_->getRight(); // changed temp to root_->
                    this->root_->setParent(NULL); 
                    delete temp; // changed
                    temp = NULL; // changed
                    return;
                }
            }
            // else if 2 children, swap with predecessor, then do either 0 or 1 child case =========================SWAP==========================================
            else if (temp->getLeft() != NULL && temp->getRight() != NULL)
            {
                // swap
                AVLNode<Key, Value>* pred = static_cast<AVLNode<Key, Value>*>(this->predecessor(temp));
                nodeSwap(temp, pred);

                // 0 children case
                if (temp->getRight() == NULL && temp->getLeft() == NULL)
                {
                    if (this->isLeftChild(temp))
                    {
                        temp->getParent()->setLeft(NULL);
                    }
                    else if (this->isRightChild(temp))
                    {
                        temp->getParent()->setRight(NULL);
                    }
                    else
                    {
                        delete this->root_; // changed
                        this->root_ = NULL;
                    }
                    delete temp;
                    return;
                }
                // 1 child case
                // else if 1 child, promote (link grandparent to child)
                // if left child
                else if (temp->getLeft() != NULL && temp->getRight() == NULL)
                {
                    // if temp is a left child, set parent->setLeft() = child
                    if (this->isLeftChild(temp))
                    {
                        temp->getParent()->setLeft(temp->getLeft());
                        temp->getLeft()->setParent(temp->getParent());
                        delete temp;
                        return;
                    }

                    // if temp is a right child, set parent->setRight() = child
                    else if (this->isRightChild(temp))
                    {
                        temp->getParent()->setRight(temp->getLeft());
                        temp->getLeft()->setParent(temp->getParent());
                        delete temp;
                        return;
                    }
                    // parent is NULL
                    else
                    {
                        this->root_ = this->root_->getLeft(); // changed temp to root->
                        delete temp; // changed
                        this->root_->setParent(NULL); 
                        temp = NULL; // changed
                        return;
                    }
                    
                }
                // else if 1 child, promote (link grandparent to child)
                // if right child
                else if (temp->getRight() != NULL && temp->getLeft() == NULL)
                {
                    // if temp is a left child, set parent->setLeft() = child
                    if (this->isLeftChild(temp))
                    {
                        temp->getParent()->setLeft(temp->getRight());
                        temp->getRight()->setParent(temp->getParent());
                        delete temp;
                        return;
                    }

                    // if temp is a right child, set parent->setRight() = child
                    else if (this->isRightChild(temp))
                    {
                        temp->getParent()->setRight(temp->getRight());
                        temp->getRight()->setParent(temp->getParent());
                        delete temp;
                        return;
                    }

                    // parent is NULL
                    else
                    {
                        this->root_ = this->root_->getRight(); // changed temp to root_
                        delete temp; // changed
                        this->root_->setParent(NULL); 
                        temp = NULL; // changed
                        return;
                    }
                }
            }

}

template<class Key, class Value>
void AVLTree<Key, Value>::nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2)
{
    BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
    signed char tempB = n1->getBalance(); // added sign
    n1->setBalance(n2->getBalance());
    n2->setBalance(tempB);
}

template<class Key, class Value>
void AVLTree<Key, Value>::insertFix(AVLNode<Key,Value>* p, AVLNode<Key,Value>* n)
{
    // pre-condition: p and n are balanced: {-1, 0, 1}
    // post-condition: g, p, and n are balanced:
    // if p is null or parent(p) is null, return
    
    if (p == NULL || p->getParent() == NULL) return;
    // let g = parent(p)
    AVLNode<Key,Value>* g = p->getParent();
    // if p is left child -- (swap below if right child, swap left/right and +/-)
    if (this->isLeftChild(p))
    {

        // b(g) += -1; // update balance for now
        g->updateBalance(-1);
        // Case 1: if (b(g) = 0) return;
        if (g->getBalance() == 0) return;
        // Case 2: if (b(g) = -1) insertFix(g, p); // recurse
        else if (g->getBalance() == -1) insertFix(g, p);
        // Case 3: if (b(g) = -2) 
        else if (g->getBalance() == -2)
        {
            // if zig-zig then rotateRight(g); b(p) = b(g) = 0;
            if (this->isLeftChild(n))
            {
                rotateRight(g);
                p->setBalance(0);
                g->setBalance(0);
                return;
            }
            // if zig-zag then rotateLeft(p); rotateRight(g);
            else if (this->isLeftChild(n))
            {
                rotateLeft(p);
                rotateRight(g);

                // Case 3a: if (b(n) == -1) {b(p) = 0; b(g) = 1; b(n) = 0;}
                if (n->getBalance() == -1)
                {
                    p->setBalance(0);
                    g->setBalance(1);
                    n->setBalance(0);
                }
                // Case 3b: if (b(n) == 0) {b(p) = 0; b(g) = 0; b(n) = 0;}
                else if (n->getBalance() == 0)
                {
                    p->setBalance(0);
                    g->setBalance(0);
                    n->setBalance(0);
                }
                // Case 3c: if (b(n) == +1) {b(p) = -1; b(g) = 0; b(n) = 0;}
                else if (n->getBalance() == 1)
                {
                    p->setBalance(-1);
                    g->setBalance(0);
                    n->setBalance(0);
                }
                return;
            }
        }

    }else{ // assuming p is right child

        // b(g) += +1; // update balance for now
        g->updateBalance(1);
        // Case 1: if (b(g) = 0) return;
        if (g->getBalance() == 0) return;
        // Case 2: if (b(g) = +1) insertFix(g, p); // recurse
        else if (g->getBalance() == 1) insertFix(g, p);
        // Case 3: if (b(g) = +2) 
        else if (g->getBalance() == 2)
        {
            // if zig-zig then rotateLeft(g); b(p) = b(g) = 0;
            if (this->isRightChild(n))
            {
                rotateLeft(g);
                p->setBalance(0);
                g->setBalance(0);
                return;
            }
            // if zig-zag then rotateRight(p); rotateLeft(g);
            else if (this->isLeftChild(n))
            {
                rotateRight(p);
                rotateLeft(g);

                // Case 3a: if (b(n) == +1) {b(p) = 0; b(g) = -1; b(n) = 0;}
                if (n->getBalance() == 1)
                {
                    p->setBalance(0);
                    g->setBalance(-1);
                    n->setBalance(0);
                }
                // Case 3b: if (b(n) == 0) {b(p) = 0; b(g) = 0; b(n) = 0;}
                else if (n->getBalance() == 0)
                {
                    p->setBalance(0);
                    g->setBalance(0);
                    n->setBalance(0);
                }
                // Case 3c: if (b(n) == -1) {b(p) = +1; b(g) = 0; b(n) = 0;}
                else if (n->getBalance() == -1)
                {
                    p->setBalance(1);
                    g->setBalance(0);
                    n->setBalance(0);
                }
            }
        }
    }
}

template<class Key, class Value>
void AVLTree<Key, Value>::rotateRight(AVLNode<Key,Value>* n)
{
    //pseudo code here
    /*
    if (n == NULL){return;}
    AVLNode<Key, Value>* n2 = n->getLeft();
    AVLNode<Key, Value>* orphan = n2->getRight(); // the orphan that will need to be connected later
    AVLNode<Key, Value>* parent = n->getParent();
    if (this->isLeftChild(n) && parent != NULL)
    {
        parent->setLeft(n2);
    }
    else if (this->isRightChild(n) && parent != NULL)
    {
        parent->setRight(n2);
    }
    if (n2 != NULL) {n2->setRight(n);}
    n->setParent(n2);
    if (n2 != NULL) {n2->setParent(parent);}
    n->setLeft(orphan);
    if (orphan != NULL) orphan->setParent(n);
    */

}

template<class Key, class Value>
void AVLTree<Key, Value>::rotateLeft(AVLNode<Key,Value>* n)
{
    //pseudo code here
    /*
    if (n == NULL) return;
    AVLNode<Key, Value>* n2 = n->getRight();
    AVLNode<Key, Value>* orphan = n2->getLeft(); // the orphan that will need to be connected later
    AVLNode<Key, Value>* parent = n->getParent();
    if (this->isLeftChild(n) && parent != NULL)
    {
        parent->setLeft(n2);
    }
    else if (this->isRightChild(n) && parent != NULL)
    {
        parent->setRight(n2);
    }
    if (n2 != NULL) {n2->setLeft(n);}
    n->setParent(n2);
    if (n2 != NULL) {n2->setParent(parent);}
    n->setRight(orphan);
    if (orphan != NULL) orphan->setParent(n);
    */
}


#endif
