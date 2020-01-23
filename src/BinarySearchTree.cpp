#include<BinarySearchTree.h>

BinarySearchTree::BinarySearchTree(){
    this->left = NULL;
    this->right = NULL;
    this->value = 0;
    this->root = NULL;
}

BinarySearchTree::~BinarySearchTree(){
    deleteTree(this->root);
}

void BinarySearchTree::deleteTree(TreeNode* root){
    TreeNode* traveler = root;
    if(traveler){
        deleteTree(traveler->left);
        deleteTree(traveler->right);
        cout << "delete Node : " << traveler->val << " ";
        delete traveler;
    }
}

void BinarySearchTree::insert(int target){
    TreeNode* traveler = this->root;
    if(this->root == NULL){
        this->root = new TreeNode(target);
        return;
    }
    while(traveler){
        if(traveler->val > target){
            if(traveler->left){
                traveler = traveler->left;
            }else{
                traveler->left = new TreeNode(target);
                traveler->left->parent = traveler;
                return;
            }
        }else if(traveler->val < target){
            if(traveler->right){
                traveler = traveler->right;
            }else{
                traveler->right = new TreeNode(target);
                traveler->right->parent = traveler;
                return;
            }
        }else{
            cout << "Value is already inserted." <<endl;
            return;
        }
    }
}

TreeNode* BinarySearchTree::findPredecessor(TreeNode* startNode){
    while(startNode->right){
        startNode = startNode->right;
    }
    return startNode;
}
void BinarySearchTree::deleteNode(int target){
    deleteNode(this->search(target));
}

void BinarySearchTree::deleteNode(TreeNode* toDelete){
    if(!toDelete){
        cout << "Node isn't exist.\n";
        return;
    }
    TreeNode* temp;
    if(toDelete->left && toDelete->right){
        temp = findPredecessor(toDelete->left);
        int setValue = temp->val;
        deleteNode(temp);
        toDelete->val = setValue;
        
    }else if(toDelete->left){
        toDelete->val = toDelete->left->val;
        temp = toDelete->left;
        toDelete->left = temp->left;
        toDelete->right = temp->right;
        temp->left->parent = temp->right->parent = toDelete;
        delete temp;
    }else if(toDelete->right){
        toDelete->val = toDelete->right->val;
        temp = toDelete->right;
        toDelete->left = temp->left;
        toDelete->right = temp->right;
        temp->left->parent = temp->right->parent = toDelete;
        delete temp;
    }else{
        temp = toDelete->parent;
        if(temp->left==toDelete){
            temp->left = NULL;
        }else{
            temp->right = NULL;
        }
        delete toDelete;
        
    }
}

TreeNode* BinarySearchTree::getRoot(){
    return this->root;
}

void BinarySearchTree::inOrderTrav(TreeNode* node){
    TreeNode* traveler = node;
    if(traveler){
        inOrderTrav(traveler->left);
        cout << traveler->val <<" ";
        inOrderTrav(traveler->right);
    }
}

TreeNode* BinarySearchTree::search(int target){
    TreeNode* traveler = this->root;
    while(traveler){
        if(traveler->val == target)
            return traveler;
        if(traveler->val > target){
            if(traveler->left){
                traveler = traveler->left;
            }else{
                return NULL;
            }
        }else{
            if(traveler->right){
                traveler = traveler->right;
            }else{
                return NULL;
            }
        }
    }
    return NULL;
}