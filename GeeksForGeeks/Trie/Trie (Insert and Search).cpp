// Trie is an efficient information retrieval data structure. 
// Use this data structure to store Strings and search strings. 
// Your task is to use TRIE data structure and search the given string A. If found print 1 else 0.

// Approach 1: Storing children as array, TrieNode*[26]
// Each node contains an array of child pointers, one for each symbol in the alphabet.

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode** children;
    bool isTerminal;
    TrieNode(char ch){
        data=ch;
        isTerminal=false;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++) children[i]=NULL;
    }
};

class Trie{
    TrieNode* root;
    
    void insert(string word,TrieNode* node){
        if(word.size()==0){
            node->isTerminal=true;
            return;
        } 
        int index = word[0]-'a';
        if(!node->children[index]){
            node->children[index] = new TrieNode(word[0]);
        }
        insert(word.substr(1),node->children[index]);
    }
    
    bool search(string word,TrieNode* node){
        if(word.size()==0){
            return node->isTerminal;
        }
        int index = word[0]-'a';
        if(!node->children[index]) return false;
        return search(word.substr(1),node->children[index]);
    }
    
public:

    Trie(){
        root=new TrieNode('\0');
    }
    
    void insert(string word){
        insert(word,root);
    }    
    
    bool search(string word){
        return search(word,root);
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
	    Trie t;
	    int n;
	    cin>>n;
	    while(n--){
	        string s;
	        cin>>s;
	        t.insert(s);
	    }
	    string s;
	    cin>>s;
	    cout<<t.search(s)<<"\n";
	}
	return 0;
}

/***************************************************************************************************************************/

// Approach 2: Efficient way, using hash map to store children of a node
// Using HASHMAP for children, don’t waste space storing null pointers
// passing STRING by REFERENCE

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    unordered_map<char,TrieNode*> children;
    bool isTerminal;
    TrieNode(char ch){
        data=ch;
        isTerminal=false;
    }
};

class Trie{
    TrieNode* root;
    
    void insert(TrieNode* node, const string &word, int i){
        if(i==word.size()){
            node->isTerminal=true;
            return;
        } 
        char ch = word[i];
        if(!node->children.count(ch)){
            node->children[ch] = new TrieNode(ch);
        }
        insert(node->children[ch],word,i+1);
    }
    
    bool search(TrieNode* node, const string &word, int i){
        if(i==word.size()){
            return node->isTerminal;
        }
        char ch = word[i];
        if(!node->children.count(ch)){
            return false;
        }
        return search(node->children[ch],word,i+1);
    }
    
public:

    Trie(){
        root=new TrieNode('\0');
    }
    
    void insert(string word){
        insert(root,word,0);
    }    
    
    bool search(string word){
        return search(root,word,0);
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
	    Trie t;
	    int n;
	    cin>>n;
	    while(n--){
	        string s;
	        cin>>s;
	        t.insert(s);
	    }
	    string s;
	    cin>>s;
	    cout<<t.search(s)<<"\n";
	}
	return 0;
}