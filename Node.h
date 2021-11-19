#ifndef NODE_H
#define NODE_H
#include <iostream>


class Node
{
    public:
        Node(int data);
        friend class BST;

    protected:

    private:
        int data;
        Node* left;
        Node* right;
        Node* parent;
};

#endif // NODE_H
