#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    BST tree;
    tree.Insert(15);
    tree.Insert(10);
    tree.Insert(20);
    tree.Insert(25);
    tree.Insert(8);
    tree.Insert(12);
    cout << "Enter a number to be searched... \t";
    int number;
    cin >> number;

    if(tree.Search(number)) cout << "The number exists " << endl;
    else cout << "The number does not exist " << endl;

    cout << "\n" << "The minimum value is " << tree.findMin();
    cout << "\n" << "The maximum value is " << tree.findMax();
    cout << "\n" << "The height of the tree is " << tree.findHeight() << "\n";

    tree.BFS(); cout << "\nthe preorder traversal is \n";
    tree.preOrder(); cout << "\nthe inorder traversal is \n";
    tree.inOrder(); cout << "\nthe postorder traversal is \n";
    tree.postOrder(); cout << "\n";

    if(tree.isBST()){
        cout << "the tree is a binary tree " << endl;
    }else cout << "the tree is not a binary tree " << endl;

    //tree.deleteNode(15);
    tree.inOrder();
    cout << "Successor " << tree.getSuccessor(12);
    return 0;
}
