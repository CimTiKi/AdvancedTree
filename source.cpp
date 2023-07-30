#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

const int ALPHABET_SIZE =26;

using namespace std;

struct TrieNode{
    TrieNode* children[ALPHABET_SIZE];
    bool isEndEndOfWord;
};

//Returns new trie node 
TrieNode* getNode(){
    TrieNode* pNode = new TrieNode;
    
    pNode->isEndEndOfWord = false;
    
    for(int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    
    return pNode;
}
//Test whether a trie empty
bool isTrieEmpty(TrieNode* root){
    if(!root)
        return true;
    TrieNode* pNode = root;
    for(int i = 0; i < ALPHABET_SIZE; i++)
        if(pNode->children[i])
            return false;
    return true;
}
//Get the number of items in a trie 
unsigned int numberOfItem(TrieNode* root){
    int result = 0;
    if(isTrieEmpty(root))
        return 0;
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(root->children[i]){
            if(root->children[i]->isEndEndOfWord)
                result += 1 + numberOfItem(root->children[i]);
            else
                result += numberOfItem(root->children[i]);

        }
    }
    return result;
}
int main(){
	
}
