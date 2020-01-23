#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include<Struct.h>

class BinarySearchTree{
    private:
        int value;
        TreeNode* left;
        TreeNode* right;
        TreeNode* root;
        TreeNode* findPredecessor(TreeNode* startNode);
        void deleteTree(TreeNode* root);
        void deleteNode(TreeNode* toDelete);
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(int target);
        void deleteNode(int target);
        void inOrderTrav(TreeNode* node);
        TreeNode* search(int target);
        TreeNode* getRoot();
};




#endif