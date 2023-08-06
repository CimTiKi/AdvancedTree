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
TrieNode* getNode() {
    TrieNode* pNode = new TrieNode;

    pNode->isEndEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}
//Test whether a trie empty
bool isTrieEmpty(TrieNode* root) {
    if (!root)
        return true;
    TrieNode* pNode = root;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (pNode->children[i])
            return true;
    return false;
}
//Get the number of items in a trie 
unsigned int numberOfItem(TrieNode* root) {
    int result = 0;
    if (isTrieEmpty(root))
        return 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            if (root->children[i]->isEndEndOfWord)
                result += 1 + numberOfItem(root->children[i]);
            else
                result += numberOfItem(root->children[i]);

        }
    }
    return result;
}

//find the item in trie
bool findItem(TrieNode* root, string a)
{
    TrieNode* temp = root;
    int n = a.length();

    for (int i = 0; i < n; i++)
    {
        int k = a[i] - 'a';

        if (temp->children[k] == NULL)
            return false;
        temp = temp->children[k];
    }

    return (temp != NULL && temp->isEndEndOfWord);
}

//insert item into trie
void insertItem(TrieNode* root, string a)
{
    if (findItem(root, a))
        return;

    TrieNode* temp = root;
    int n = a.length();

    for (int i = 0; i < n; i++)
    {
        int k = a[i] - 'a';

        if (temp->children[k] == NULL) 
            temp->children[k] = getNode();  

        temp = temp->children[k];
    }

    temp->isEndEndOfWord = true;

}

//Remove item in trie
void removeItem(TrieNode* root, string a)
{

    TrieNode* temp = root;
    TrieNode* pre=root;
    int n = a.length();

    for (int i = 0; i < n; i++)
    {
        int k = a[i] - 'a';

        if (temp->children[k] == NULL)
             break;
        pre = temp;
        temp = temp->children[k];
    }

    if (temp != NULL && temp->isEndEndOfWord)
    {
        delete[]temp;

        if (isTrieEmpty(pre))
            pre->isEndEndOfWord = true;
    }
    else
        cout << "\nItem does not exist!!";
}
int main(){
	
}
int main(){
	
}
