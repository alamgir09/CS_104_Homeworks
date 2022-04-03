#ifndef BST_H
#define BST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>
#include <stdlib.h>  

/**
 * A templated class for a Node in a search tree.
 * The getters for parent/left/right are virtual so
 * that they can be overridden for future kinds of
 * search trees, such as Red Black trees, Splay trees,
 * and AVL trees.
 */
template <typename Key, typename Value>
class Node
{
public:
    Node(const Key& key, const Value& value, Node<Key, Value>* parent);
    virtual ~Node();

    const std::pair<const Key, Value>& getItem() const;
    std::pair<const Key, Value>& getItem();
    const Key& getKey() const;
    const Value& getValue() const;
    Value& getValue();

    virtual Node<Key, Value>* getParent() const;
    virtual Node<Key, Value>* getLeft() const;
    virtual Node<Key, Value>* getRight() const;

    void setParent(Node<Key, Value>* parent);
    void setLeft(Node<Key, Value>* left);
    void setRight(Node<Key, Value>* right);
    void setValue(const Value &value);

protected:
    std::pair<const Key, Value> item_;
    Node<Key, Value>* parent_;
    Node<Key, Value>* left_;
    Node<Key, Value>* right_;
};

/*
  -----------------------------------------
  Begin implementations for the Node class.
  -----------------------------------------
*/

/**
* Explicit constructor for a node.
*/
template<typename Key, typename Value>
Node<Key, Value>::Node(const Key& key, const Value& value, Node<Key, Value>* parent) :
    item_(key, value),
    parent_(parent),
    left_(NULL),
    right_(NULL)
{

}

/**
* Destructor, which does not need to do anything since the pointers inside of a node
* are only used as references to existing nodes. The nodes pointed to by parent/left/right
* are freed by the BinarySearchTree.
*/
template<typename Key, typename Value>
Node<Key, Value>::~Node()
{

}

/**
* A const getter for the item.
*/
template<typename Key, typename Value>
const std::pair<const Key, Value>& Node<Key, Value>::getItem() const
{
    return item_;
}

/**
* A non-const getter for the item.
*/
template<typename Key, typename Value>
std::pair<const Key, Value>& Node<Key, Value>::getItem()
{
    return item_;
}

/**
* A const getter for the key.
*/
template<typename Key, typename Value>
const Key& Node<Key, Value>::getKey() const
{
    return item_.first;
}

/**
* A const getter for the value.
*/
template<typename Key, typename Value>
const Value& Node<Key, Value>::getValue() const
{
    return item_.second;
}

/**
* A non-const getter for the value.
*/
template<typename Key, typename Value>
Value& Node<Key, Value>::getValue()
{
    return item_.second;
}

/**
* An implementation of the virtual function for retreiving the parent.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getParent() const
{
    return parent_;
}

/**
* An implementation of the virtual function for retreiving the left child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getLeft() const
{
    return left_;
}

/**
* An implementation of the virtual function for retreiving the right child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getRight() const
{
    return right_;
}

/**
* A setter for setting the parent of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setParent(Node<Key, Value>* parent)
{
    parent_ = parent;
}

/**
* A setter for setting the left child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setLeft(Node<Key, Value>* left)
{
    left_ = left;
}

/**
* A setter for setting the right child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setRight(Node<Key, Value>* right)
{
    right_ = right;
}

/**
* A setter for the value of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setValue(const Value& value)
{
    item_.second = value;
}

/*
  ---------------------------------------
  End implementations for the Node class.
  ---------------------------------------
*/

/**
* A templated unbalanced binary search tree.
*/
template <typename Key, typename Value>
class BinarySearchTree
{
public:
    BinarySearchTree(); //TODO
    virtual ~BinarySearchTree(); //TODO
    virtual void insert(const std::pair<const Key, Value>& keyValuePair); //TODO
    virtual void remove(const Key& key); //TODO
    void clear(); //TODO
    bool isBalanced() const; //TODO
    void print() const;
    bool empty() const;

    template<typename PPKey, typename PPValue>
    friend void prettyPrintBST(BinarySearchTree<PPKey, PPValue> & tree);
public:
    /**
    * An internal iterator class for traversing the contents of the BST.
    */
    class iterator  // TODO
    {
    public:
        iterator();

        std::pair<const Key,Value>& operator*() const;
        std::pair<const Key,Value>* operator->() const;

        bool operator==(const iterator& rhs) const;
        bool operator!=(const iterator& rhs) const;

        iterator& operator++();

    protected:
        friend class BinarySearchTree<Key, Value>;
        iterator(Node<Key,Value>* ptr);
        Node<Key, Value> *current_;
    };

public:
    iterator begin() const;
    iterator end() const;
    iterator find(const Key& key) const;
    Value& operator[](const Key& key);
    Value const & operator[](const Key& key) const;

protected:
    // Mandatory helper functions
    Node<Key, Value>* internalFind(const Key& k) const; // TODO
    Node<Key, Value> *getSmallestNode() const;  // TODO
    static Node<Key, Value>* predecessor(Node<Key, Value>* current); // TODO
    // Note:  static means these functions don't have a "this" pointer
    //        and instead just use the input argument.

    // Provided helper functions
    virtual void printRoot (Node<Key, Value> *r) const;
    virtual void nodeSwap( Node<Key,Value>* n1, Node<Key,Value>* n2) ;

    // Add helper functions here
    static Node<Key, Value>* successor(Node<Key, Value>* current); // TODO check it
    void traversal(Node<Key, Value>* root); //helper for clear
    bool isLeftChild(Node<Key, Value>* child); //helper for remove
    bool isRightChild(Node<Key, Value>* child); //helper for remove
    int isBalancedHelper(Node<Key, Value>* root, bool& isEqual) const; // helper for isBalanced
    void areEqual(int leftHeight, int rightHeight, bool& isEqual) const; // helper for isBalancedHelper
    int max(int a, int b) const; // helper for isBalanced
    //void doesIsEqual(bool& isEqual); // does all of isBalanced


protected:
    Node<Key, Value>* root_;
    // You should not need other data members
};

/*
--------------------------------------------------------------
Begin implementations for the BinarySearchTree::iterator class.
---------------------------------------------------------------
*/

/**
* Explicit constructor that initializes an iterator with a given node pointer.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::iterator::iterator(Node<Key,Value> *ptr)
{
    // TODO
    current_ = ptr;
}

/**
* A default constructor that initializes the iterator to NULL.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::iterator::iterator() 
{
    // TODO
    current_ = NULL;
}

/**
* Provides access to the item.
*/
template<class Key, class Value>
std::pair<const Key,Value> &
BinarySearchTree<Key, Value>::iterator::operator*() const
{
    return current_->getItem();
}

/**
* Provides access to the address of the item.
*/
template<class Key, class Value>
std::pair<const Key,Value> *
BinarySearchTree<Key, Value>::iterator::operator->() const
{
    return &(current_->getItem());
}

/**
* Checks if 'this' iterator's internals have the same value
* as 'rhs'
*/
template<class Key, class Value>
bool
BinarySearchTree<Key, Value>::iterator::operator==(
    const BinarySearchTree<Key, Value>::iterator& rhs) const
{
    // TODO
    return this->current_ == rhs.current_;
}

/**
* Checks if 'this' iterator's internals have a different value
* as 'rhs'
*/
template<class Key, class Value>
bool
BinarySearchTree<Key, Value>::iterator::operator!=(
    const BinarySearchTree<Key, Value>::iterator& rhs) const
{
    // TODO
    return !(this->current_ == rhs.current_);
}


/**
* Advances the iterator's location using an in-order sequencing
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator&
BinarySearchTree<Key, Value>::iterator::operator++()
{
    // TODO
    // will use successor helper function to do ++
    current_ = successor(this->current_);
    return *this;
}


/*
-------------------------------------------------------------
End implementations for the BinarySearchTree::iterator class.
-------------------------------------------------------------
*/

/*
-----------------------------------------------------
Begin implementations for the BinarySearchTree class.
-----------------------------------------------------
*/

/**
* Default constructor for a BinarySearchTree, which sets the root to NULL.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::BinarySearchTree() 
{
    // TODO
    root_ = NULL;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::~BinarySearchTree()
{
    // TODO
    // destructor
    clear();
}

/**
 * Returns true if tree is empty
*/
template<class Key, class Value>
bool BinarySearchTree<Key, Value>::empty() const
{
    return root_ == NULL;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::print() const
{
    printRoot(root_);
    std::cout << "\n";
}

/**
* Returns an iterator to the "smallest" item in the tree
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::begin() const
{
    BinarySearchTree<Key, Value>::iterator begin(getSmallestNode());
    return begin;
}

/**
* Returns an iterator whose value means INVALID
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::end() const
{
    BinarySearchTree<Key, Value>::iterator end(NULL);
    return end;
}

/**
* Returns an iterator to the item with the given key, k
* or the end iterator if k does not exist in the tree
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::find(const Key & k) const
{
    Node<Key, Value> *curr = internalFind(k);
    BinarySearchTree<Key, Value>::iterator it(curr);
    return it;
}

/**
 * @precondition The key exists in the map
 * Returns the value associated with the key
 */
template<class Key, class Value>
Value& BinarySearchTree<Key, Value>::operator[](const Key& key)
{
    Node<Key, Value> *curr = internalFind(key);
    if(curr == NULL) throw std::out_of_range("Invalid key");
    return curr->getValue();
}
template<class Key, class Value>
Value const & BinarySearchTree<Key, Value>::operator[](const Key& key) const
{
    Node<Key, Value> *curr = internalFind(key);
    if(curr == NULL) throw std::out_of_range("Invalid key");
    return curr->getValue();
}

/**
* An insert method to insert into a Binary Search Tree.
* The tree will not remain balanced when inserting.
* Recall: If key is already in the tree, you should 
* overwrite the current value with the updated value.
*/
template<class Key, class Value>
void BinarySearchTree<Key, Value>::insert(const std::pair<const Key, Value> &keyValuePair)
{
    
    // TODO
   if (root_ == NULL)
   {
       root_ = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, NULL);
       //root_->setRight(NULL);
       //root_->setLeft(NULL);
       //root_ = curr;
       return;
   }else{
        Node<Key, Value>* curr = root_;
        while (curr != NULL)
        {
            // greater than
            if (keyValuePair.first > curr->getKey())
            {
                // if right node does exist, then traverse to it
                if (curr->getRight() != NULL)
                {
                    curr = curr->getRight();
                }else{
                    // new node and root_ = new node
                    Node<Key, Value>* parent = curr;
                    curr = curr->getRight();
                    curr = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, parent);
                    parent->setRight(curr);
                    break;
                }
                // less than
            }else if (keyValuePair.first < curr->getKey()){
                // if left node does exist, then traverse to it
                if (curr->getLeft() != NULL)
                {
                curr = curr->getLeft();
                }else{
                    // new node and root_ = new node
                    Node<Key, Value>* parent = curr;
                    curr = curr->getLeft();
                    curr = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, parent);
                    parent->setLeft(curr);
                    //this->printRoot(this->root_);
                    break;
                }
                // equal to
            }else{
                // if root's key is == to keyValuePair.first
                curr->setValue(keyValuePair.second);
                //this->printRoot(this->root_);
                break;
            }
        }
   }
   
}


/**
* A remove method to remove a specific key from a Binary Search Tree.
* Recall: The writeup specifies that if a node has 2 children you
* should swap with the predecessor and then remove.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::remove(const Key& key)
{
    
    // TODO
    Node<Key, Value>* temp = internalFind(key);
    // if 0 children, just delete the NODE and NULL ptrs
    if (temp == NULL){return;}
            if (temp->getRight() == NULL && temp->getLeft() == NULL)
            {
                if (isLeftChild(temp))
                {
                    temp->getParent()->setLeft(NULL);
                }
                else if (isRightChild(temp))
                {
                    temp->getParent()->setRight(NULL);
                }
                else
                {
                    delete root_; // changed
                    root_ = NULL;
                }
                delete temp;
                return;
            }
            // else if 1 child, promote (link grandparent to child)
            // if left child
            else if (temp->getLeft() != NULL && temp->getRight() == NULL)
            {
                // if temp is a left child, set parent->setLeft() = child
                if (isLeftChild(temp))
                {
                    temp->getParent()->setLeft(temp->getLeft());
                    temp->getLeft()->setParent(temp->getParent());
                    delete temp;
                    return;
                }

                // if temp is a right child, set parent->setRight() = child
                else if (isRightChild(temp))
                {
                    temp->getParent()->setRight(temp->getLeft());
                    temp->getLeft()->setParent(temp->getParent());
                    delete temp;
                    return;
                }
                // parent is NULL
                else
                {
                    root_ = root_->getLeft(); // changed temp to root->
                    root_->setParent(NULL); 
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
                if (isLeftChild(temp))
                {
                    temp->getParent()->setLeft(temp->getRight());
                    temp->getRight()->setParent(temp->getParent());
                    delete temp;
                    return;
                }

                // if temp is a right child, set parent->setRight() = child
                else if (isRightChild(temp))
                {
                    temp->getParent()->setRight(temp->getRight());
                    temp->getRight()->setParent(temp->getParent());
                    delete temp;
                    return;
                }

                // parent is NULL
                else
                {
                    root_ = root_->getRight(); // changed temp to root_->
                    root_->setParent(NULL); 
                    delete temp; // changed
                    temp = NULL; // changed
                    return;
                }
            }
            // else if 2 children, swap with predecessor, then do either 0 or 1 child case =========================SWAP==========================================
            else if (temp->getLeft() != NULL && temp->getRight() != NULL)
            {
                // swap
                Node<Key, Value>* pred = predecessor(temp);
                nodeSwap(temp, pred);

                // 0 children case
                if (temp->getRight() == NULL && temp->getLeft() == NULL)
                {
                    if (isLeftChild(temp))
                    {
                        temp->getParent()->setLeft(NULL);
                    }
                    else if (isRightChild(temp))
                    {
                        temp->getParent()->setRight(NULL);
                    }
                    else
                    {
                        delete root_; // changed
                        root_ = NULL;
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
                    if (isLeftChild(temp))
                    {
                        temp->getParent()->setLeft(temp->getLeft());
                        temp->getLeft()->setParent(temp->getParent());
                        delete temp;
                        return;
                    }

                    // if temp is a right child, set parent->setRight() = child
                    else if (isRightChild(temp))
                    {
                        temp->getParent()->setRight(temp->getLeft());
                        temp->getLeft()->setParent(temp->getParent());
                        delete temp;
                        return;
                    }
                    // parent is NULL
                    else
                    {
                        root_ = root_->getLeft(); // changed temp to root->
                        delete temp; // changed
                        root_->setParent(NULL); 
                        temp = NULL; // changed
                        return;
                    }
                    
                }
                // else if 1 child, promote (link grandparent to child)
                // if right child
                else if (temp->getRight() != NULL && temp->getLeft() == NULL)
                {
                    // if temp is a left child, set parent->setLeft() = child
                    if (isLeftChild(temp))
                    {
                        temp->getParent()->setLeft(temp->getRight());
                        temp->getRight()->setParent(temp->getParent());
                        delete temp;
                        return;
                    }

                    // if temp is a right child, set parent->setRight() = child
                    else if (isRightChild(temp))
                    {
                        temp->getParent()->setRight(temp->getRight());
                        temp->getRight()->setParent(temp->getParent());
                        delete temp;
                        return;
                    }

                    // parent is NULL
                    else
                    {
                        root_ = root_->getRight(); // changed temp to root_
                        delete temp; // changed
                        root_->setParent(NULL); 
                        temp = NULL; // changed
                        return;
                    }
                }
            }
    }



    template<class Key, class Value>
    Node<Key, Value>*
    BinarySearchTree<Key, Value>::predecessor(Node<Key, Value>* current)
    {
        // TODO
        // if left child exists, predecessor is the right most node of the left subtree
        // else walk up the ancestor chain until you traverse the first right child pointer (find first node who is a right child of this parent, parent is predecessor)
        // if you get to the root w/o finding a node who is a right child, there is no predecessor
        if (current == NULL){return NULL;}
        if (current->getLeft() != NULL)
        {
            current = current->getLeft(); 
            while (current->getRight() != NULL)
            {
                current = current->getRight(); 
            }
            return current;
        }else{
            while (current->getParent() != NULL)
            {
                //current = current->getParent(); // changed order of this operation
                if (current == current->getParent()->getRight())
                {
                    return current->getParent();
                }
                current = current->getParent(); // changed order of this operation
            }
            // This return statement is only called if we reach root_
            return NULL;
        }


}

template<class Key, class Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::successor(Node<Key, Value>* current)
{
    // TODO
    // if right child exists, successor is the left most node of the right subtree
    // else walk up the ancestor chain until you traverse the first left child pointer (find first node who is a left child of their parent, parent is successor)
    // if you get to the root w/o finding a node who is a left child, there is no successor

    // if current is NULL return NULL
    if (current == NULL){return NULL;}


    if (current->getRight() != NULL)
    {
        current = current->getRight();
        while (current->getLeft() != NULL)
        {
            current = current->getLeft();
        }
        return current;
    }else{
        while(current->getParent() != NULL)
        {
            if (current == (current->getParent()->getLeft())) // isLeftChild(current)
            {
                return current->getParent();
            }
            current = current->getParent();
        }
        // this statement is only called if we reach root_
        return NULL;
    }
}

/**
* A method to remove all contents of the tree and
* reset the values in the tree for use again.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::clear()
{
    // TODO
    // post-order traversal
    // might have to create helper called traversal
    traversal(root_);
}


/**
* A helper function to find the smallest node in the tree.
*/
template<typename Key, typename Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::getSmallestNode() const
{
    // TODO
    // to find smallest node, simply traverse left until you hit nullptr, then return that node
    Node<Key, Value>* SmallestNode = root_;
    if (root_ == NULL){return NULL;}
    while (SmallestNode->getLeft() != NULL)
    {
        SmallestNode = SmallestNode->getLeft();
    }
    return SmallestNode;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::traversal(Node<Key, Value>* root)
{
    if (root == NULL)
    {
        return;
    }else{
        traversal(root->getLeft());
        traversal(root->getRight());
        // delete the node
        //std::cout << "------------------------------" << std::endl;
        //std::cout << "This is the node being deleted " << root->getKey() << std::endl;
        //std::cout << "------------------------------" << std::endl;
        delete root;
        root = NULL;
        //go back to previous node
        return;
    }
}

template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::isLeftChild(Node<Key, Value>* child)
{
    if (child == NULL){return NULL;}
    if (child->getParent() == NULL){return false;}
    return (child->getParent()->getLeft() == child);
}

template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::isRightChild(Node<Key, Value>* child)
{
    if (child == NULL){return NULL;}
    if (child->getParent() == NULL){return false;}
    return (child->getParent()->getRight() == child);
}

/**
* Helper function to find a node with given key, k and
* return a pointer to it or NULL if no item with that key
* exists
*/
template<typename Key, typename Value>
Node<Key, Value>* BinarySearchTree<Key, Value>::internalFind(const Key& key) const
{
    // TODO
    // Referenced from slides:
    // To find a node with a given key
    // if (nodeptr == null) the key dne, stop
    // else { check if current node's key equals the desired key, if (true) stop, return this node
    // if desired key is less-than current node's key, go left
    // if desired key is greater-than current node's key, go right
    // }
    Node<Key, Value>* temp = root_;
    while (temp != NULL)
    {
        if (key == temp->getKey())
        {
            return temp;
        }else if (key > temp->getKey()){
            temp = temp->getRight();
        }else{
            temp = temp->getLeft();
        }
    }
    return NULL;
}

/**
 * Return true iff the BST is balanced.
 */
template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::isBalanced() const
{
    // TODO
    // use the height checks he gave in lecture
    // partially equalPaths but repurposed
    bool isEqual;
        if (root_ == NULL)
    {
        isEqual = true;
        return isEqual;
    }else{
        isEqual = false;
        int height = isBalancedHelper(root_, isEqual);
        //std::cout << "Max height is " << height << std::endl;
        //this->printRoot(root_);
        return isEqual;
    }
}

template<typename Key, typename Value>
int BinarySearchTree<Key, Value>::isBalancedHelper(Node<Key, Value>* root, bool& isEqual) const
{
    // Traverse through the tree and check if it's balanced
    // Compare left and right height to see if they're balanced, like less than two of each other
    if (root == NULL)
    {
        return 0;
    }else{ 
        int leftheight = isBalancedHelper(root->getLeft(), isEqual);
        int rightheight = isBalancedHelper(root->getRight(), isEqual);
        areEqual(leftheight, rightheight, isEqual);
        return 1 + max(leftheight, rightheight);
    }
}

template<typename Key, typename Value>
int BinarySearchTree<Key, Value>::max(int a, int b) const
{
    if (a > b) return a;
    return b;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::areEqual(int leftHeight, int rightHeight, bool& isEqual) const
{
    //std::cout << "leftHeight is " << leftHeight << std::endl;
   //std::cout << "rightHeight is " << rightHeight << std::endl;
    // if path only exists on either right or left, then paths are equal since only 1 exists
    /*if (leftHeight == 0 && rightHeight != 0) {isEqual = false; return;}
    else if (leftHeight != 0 && rightHeight == 0) {isEqual = false; return;}
    else {*/
        if (abs(leftHeight) - abs(rightHeight) <= 1 && abs(leftHeight) - abs(rightHeight) >= -1 ) {isEqual = true; return;}
        isEqual = false;
    
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::nodeSwap( Node<Key,Value>* n1, Node<Key,Value>* n2)
{
    if((n1 == n2) || (n1 == NULL) || (n2 == NULL) ) {
        return;
    }
    Node<Key, Value>* n1p = n1->getParent();
    Node<Key, Value>* n1r = n1->getRight();
    Node<Key, Value>* n1lt = n1->getLeft();
    bool n1isLeft = false;
    if(n1p != NULL && (n1 == n1p->getLeft())) n1isLeft = true;
    Node<Key, Value>* n2p = n2->getParent();
    Node<Key, Value>* n2r = n2->getRight();
    Node<Key, Value>* n2lt = n2->getLeft();
    bool n2isLeft = false;
    if(n2p != NULL && (n2 == n2p->getLeft())) n2isLeft = true;


    Node<Key, Value>* temp;
    temp = n1->getParent();
    n1->setParent(n2->getParent());
    n2->setParent(temp);

    temp = n1->getLeft();
    n1->setLeft(n2->getLeft());
    n2->setLeft(temp);

    temp = n1->getRight();
    n1->setRight(n2->getRight());
    n2->setRight(temp);

    if( (n1r != NULL && n1r == n2) ) {
        n2->setRight(n1);
        n1->setParent(n2);
    }
    else if( n2r != NULL && n2r == n1) {
        n1->setRight(n2);
        n2->setParent(n1);

    }
    else if( n1lt != NULL && n1lt == n2) {
        n2->setLeft(n1);
        n1->setParent(n2);

    }
    else if( n2lt != NULL && n2lt == n1) {
        n1->setLeft(n2);
        n2->setParent(n1);

    }


    if(n1p != NULL && n1p != n2) {
        if(n1isLeft) n1p->setLeft(n2);
        else n1p->setRight(n2);
    }
    if(n1r != NULL && n1r != n2) {
        n1r->setParent(n2);
    }
    if(n1lt != NULL && n1lt != n2) {
        n1lt->setParent(n2);
    }

    if(n2p != NULL && n2p != n1) {
        if(n2isLeft) n2p->setLeft(n1);
        else n2p->setRight(n1);
    }
    if(n2r != NULL && n2r != n1) {
        n2r->setParent(n1);
    }
    if(n2lt != NULL && n2lt != n1) {
        n2lt->setParent(n1);
    }


    if(this->root_ == n1) {
        this->root_ = n2;
    }
    else if(this->root_ == n2) {
        this->root_ = n1;
    }

}

/**
 * Lastly, we are providing you with a print function,
   BinarySearchTree::printRoot().
   Just call it with a node to start printing at, e.g:
   this->printRoot(this->root_) // or any other node pointer

   It will print up to 5 levels of the tree rooted at the passed node,
   in ASCII graphics format.
   We hope it will make debugging easier!
  */

// include print function (in its own file because it's fairly long)
#include "print_bst.h"

/*
---------------------------------------------------
End implementations for the BinarySearchTree class.
---------------------------------------------------
*/

#endif
