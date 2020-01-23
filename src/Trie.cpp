#include<Trie.h>

Trie::Trie() {
    this->root.word = false;
    for(int i = 0 ; i < 26; ++i){
        this->root.nextNode[i] = NULL;
    }
}

Trie::~Trie(){
    TrieNode * iter = &(this->root);
    while(!this->nodeStack.empty()){
        TrieNode* toRelease = this->nodeStack.top();
        this->nodeStack.pop();
        delete toRelease;
    }
}


/** Inserts a word into the trie. */
void Trie::insert(string word) {
    TrieNode * iter = &(this->root);
    for(char c : word){
        int index = int(c) - 97;
        if(iter->nextNode[index] == NULL){
            iter->nextNode[index] = new TrieNode();
            this->nodeStack.push(iter->nextNode[index]);
        }
        iter = iter->nextNode[index];
    }
    iter->word = true;
}
    
/** Returns if the word is in the trie. */
bool Trie::search(string word) {
    TrieNode * iter = &(this->root);
    for(char c : word){
        int index = int(c) - 97;
        if(iter->nextNode[index] == NULL){
            return false;
        }else{
            iter = iter->nextNode[index];
        }
    }
    return iter->word;
}
    
/** Returns if there is any word in the trie that starts with the given prefix. */
bool Trie::startsWith(string prefix) {
    TrieNode * iter = &(this->root);
    for(char c : prefix){
        int index = int(c) - 97;
        if(iter->nextNode[index] == NULL){
            return false;
        }else{
            iter = iter->nextNode[index];
        }
    }
    return true;
}

/* Release all node by DFS.
Trie::~Trie(){
    TrieNode * iter = &(this->root);
    stack<TrieNode*> toDelete;
    DFSNode(iter, toDelete);
    while(!toDelete.empty()){
        TrieNode* toRelease = toDelete.top();
        toDelete.pop();
        delete toRelease;
    }
}

void Trie::DFSNode(TrieNode* node , stack<TrieNode*> & nodeSet){
    for(int i = 0 ; i < 26; ++i){
        if(node->nextNode[i] != NULL){
            nodeSet.push(node->nextNode[i]);
            DFSNode(node->nextNode[i], nodeSet);
        }
    }
}
*/