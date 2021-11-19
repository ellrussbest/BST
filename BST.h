#ifndef BST_H
#define BST_H
#include "Node.h"
#include <stack>
#include <iostream>
#include <queue>
#include <climits>


class BST
{
    public:
        BST();
        void Insert(int data);
        bool Search(int data);
        int findMin();
        int findMax();
        int findHeight();
        void BFS();
        void preOrder();
        void inOrder();
        void postOrder();
        //inorder traversal of a bst always gives the code in a sorted manner
        //you can use inorder traversal to check if the tree is a BST
        bool isBST();
        void deleteNode(int data);
        int getSuccessor(int data);

    protected:

    private:
        Node* root;
        Node* InsertRec(Node* root, int data);
        bool SearchRec(Node* root, int data);
        int findmax(Node* root);
        int findheight(Node* root);
        void bfs(Node* root);
        bool isBSTUtil(Node* root, int minVal, int maxVal);
        Node* deleteUtil(Node* root, int data);
        Node* findMinAddress(Node* root);
        int getSuccessorUtil(Node* temp);
        int minVal = INT_MIN;
        int maxVal = INT_MAX;

};

#endif // BST_H
