// Geek recently read about strings, and he got interested in them.
// Geek has a list containing N words (not necessarily distinct)-denoted by Li.Now, he will ask Q queries.
// Each query will consist of a string x.
// You need to tell How many strings in the List has the string x as its prefix.

// Approach: Modify TrieNode to store count of how many strings pass through this node
// We also need to store the count of all strings that have that prefix. 

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    unordered_map<char,TrieNode*> children;
    int count; // how many strings pass through this node
    TrieNode(char ch){
        data=ch;
        count=0;
    }
};

class Trie{
    TrieNode* root;
    
    void insert(TrieNode* node, const string &word, int i){
        node->count++;
        if(i==word.size()){
            return;
        } 
        char ch = word[i];
        if(!node->children.count(ch)){
            node->children[ch] = new TrieNode(ch);
        }
        insert(node->children[ch],word,i+1);
    }
    
    int getCount(TrieNode* node, const string &word, int i){
        // Similar to search
        if(i==word.size()){
            return node->count;
        }
        char ch = word[i];
        if(!node->children.count(ch)){
            return 0;
        }
        return getCount(node->children[ch],word,i+1);
    }
    
public:

    Trie(){
        root=new TrieNode('\0');
    }
    
    void insert(string word){
        insert(root,word,0);
    }    
    
    int getCount(string word){
        // How many strings have the string word as its prefix.
        return getCount(root,word,0);
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        Trie tr;
        int n;
        cin>>n;
        while(n--){
            string s;
            cin>>s;
            tr.insert(s);
        }
        int q;
        cin>>q;
        while(q--){
            string x;
            cin>>x;
            cout<<tr.getCount(x)<<"\n";
        }
    }

	return 0;
}