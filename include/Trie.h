#ifndef TRIE_H
#define TRIE_H
#include<Struct.h>


class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode root;
    Trie();
    ~Trie();
    /** Inserts a word into the trie. */
    void insert(string word);
    
    /** Returns if the word is in the trie. */
    bool search(string word);
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix);
    
private:
    stack<TrieNode*> nodeStack; 
    //void DFSNode(TrieNode* node , stack<TrieNode*>& nodeSet);
};

#endif