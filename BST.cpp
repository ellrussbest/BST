#include "BST.h"

BST::BST()
{
    root = NULL;
}

void BST ::Insert(int data){
    root = InsertRec(root, data);
}

Node* BST ::InsertRec(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
    }else if(data <= root -> data){
        root->left = InsertRec(root->left, data);
        root->left->parent = root;
    }else{
        root->right = InsertRec(root->right, data);
        root->right->parent = root;
    }

    return root;
}


bool BST ::Search(int data){
    return SearchRec(root, data);
}

bool BST ::SearchRec(Node* root, int data){
    if(root == NULL){
        return 0;
    }
    if(root ->data == data){
        return 1;
    }
    if(data <= root->data){
        return SearchRec(root->left, data);
    }else{
        return SearchRec(root->right, data);
    }
}

int BST ::findMin(){
    Node* temp = root;

    if(temp == NULL){
        std ::cout << "The tree is empty";
        return -1;
    }

    while(temp->left){
        temp = temp->left;
    }
    return temp->data;
}

int BST ::findMax(){
    return findmax(root);
}

int BST ::findmax(Node* root){
    if(root == NULL){
        std ::cout << "The tree is empty " << std ::endl;
        return -1;
    }else if(!root->right){
        return root->data;
    }else{
        return findmax(root->right);
    }
}

int BST ::findHeight(){
    return findheight(root);
}

int BST ::findheight(Node* root){
    if(root == NULL) return -1;
    else return std::max(findheight(root->left), findheight(root->right)) + 1;
}

void BST ::BFS(){
    bfs(root);
}

void BST ::bfs(Node* root){
    if (root == NULL) return;
    else{
        Node* temp = NULL;
        std ::queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            temp = q.front();
            std::cout << temp ->data << " ";
            q.pop();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

void BST:: preOrder(){
    if (root == NULL) return;
    else{
        Node* temp = NULL;
        std ::stack<Node*>st;
        st.push(root);

        while(!st.empty()){
            temp = st.top();
            std ::cout << temp->data << " ";
            st.pop();
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
        }
    }
}

void BST:: inOrder()
{
    std:: stack<Node *> st;
    Node *temp = root;

    while (temp || !st.empty())
    {
        /* Reach the left most Node of the
           temp Node */
        while (temp)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            st.push(temp);
            temp = temp->left;
        }

        /* temp must be NULL at this point */
        temp = st.top();
        st.pop();

        std:: cout << temp->data << " ";

        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        temp = temp->right;

    }
}

void BST:: postOrder(){
    std:: stack<Node*>st1;
    std:: stack<Node*>st2;

    if(root == NULL) return;
    st1.push(root);

    while(!st1.empty()){
        Node* temp = st1.top();
        st2.push(st1.top());
        st1.pop();

         if(temp->left){
            st1.push(temp->left);
         }

        if(temp->right){
            st1.push(temp->right);
         }
    }

    while(!st2.empty()){
        Node* temp = st2.top();
        std:: cout<<temp->data<<" ";
        st2.pop();
    }
}

bool BST:: isBST(){
    return isBSTUtil(root, minVal, maxVal);
}

bool BST:: isBSTUtil(Node* root, int minVal, int maxVal){
    if (root == NULL) return true;
    else if(root->data > minVal && root->data < maxVal &&
    isBSTUtil(root->left, minVal, root->data) &&
    isBSTUtil(root->right, root->data, maxVal))
    return true;
    else return false;
}

void BST ::deleteNode(int data){
    root = deleteUtil(root, data);
}

Node* BST ::deleteUtil(Node* root, int data){
    if (root == NULL) std::cout << "the tree is empty \n";
    else if(data < root->data) root->left = deleteUtil(root->left, data);
    else if(data > root->data) root->right = deleteUtil(root->right, data);
    else{
        //case 1: No child
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        //case 2: One child
        else if(root->left == NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
        }else if(root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        //case 3: Two children
        else{
            Node* temp = findMinAddress(root->right);
            root->data = temp->data;
            root->right = deleteUtil(root->right, temp->data);
        }
    }
    return root;
}

Node* BST ::findMinAddress(Node* root){
    if(root == NULL) return NULL;
    else{
        Node* temp = root;
        while(temp->left){
           temp = temp->left;
        }
        return temp;
    }
}

int BST ::getSuccessor(int data){
    Node* temp = root;

    while(temp){
        if(temp->data == data) break;
        else if(temp->data > data) temp = temp->left;
        else temp = temp->right;
    }

    if(temp == NULL){
        std ::cout << "There is no such record in the Binary tree. \n";
        return INT_MIN;
    }else{
        return getSuccessorUtil(temp);
    }

}

int BST ::getSuccessorUtil(Node* temp){
    if(temp->right) return findMinAddress(temp->right)->data;

    Node* temp2 = temp->parent;
    while (temp2 && temp == temp2->right) {
        temp = temp2;
        temp2 = temp2->parent;
    }

    if(temp2 == NULL){
        std ::cout << "This is the maximum value!!! There is no Successor...\n";
        return INT_MIN;
    }else return temp2->data;
}

