#include "equal-paths.h"
#include <iostream> // only for testing purposes
using namespace std;


// You may add any prototypes of helper functions here
/*

*/
void areEqual(int leftHeight, int rightHeight, bool& isEqual)
{
    cout << "leftHeight is " << leftHeight << endl;
    cout << "rightHeight is " << rightHeight << endl;
    // if path only exists on either right or left, then paths are equal since only 1 exists
    if (leftHeight == 0 && rightHeight != 0) {isEqual = true;}
    else if (leftHeight != 0 && rightHeight == 0) {isEqual = true;}
    else {isEqual = (leftHeight == rightHeight);}
}

// referenced from lecture slides backtracking, counting nodes problem, finds max
int maxHeight(Node* root, bool& isEqual)
{
    if (root == NULL)
    {
        return 0;
    }else{
        int leftheight = maxHeight(root->left, isEqual);
        int rightheight = maxHeight(root->right, isEqual);
        areEqual(leftheight, rightheight, isEqual);
        return 1 + max(leftheight, rightheight);
    }
}

int max(int a, int b)
{
    if (a > b) {return a;}
    else {return b;}
}


bool equalPaths(Node * root)
{
    bool isEqual;
    // if tree is empty then all paths are equal
    if (root == NULL) 
    {
        return true;
    }else{
        isEqual = false;
        // maxHeight function will using reference, change value of isEqual as it finds max height
        int height = maxHeight(root, isEqual);
        cout << "Max height is " << height << endl;
        return isEqual;
    }
}

