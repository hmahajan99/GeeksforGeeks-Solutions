// Given a dictionary of words where each word follows CamelCase notation, 
// print all words in the dictionary that match with a given pattern consisting of uppercase characters only.

// For Input:
// 2
// 8
// Hi Hello HelloWorld HiTech HiGeek HiTechWorld HiTechCity HiTechLab
// HA
// 8
// Hi Hello HelloWorld HiTech HiGeek HiTechWorld HiTechCity HiTechLab
// HT
// Output is:
// No match found
// HiTech HiTechCity HiTechLab HiTechWorld 

// Approach: Trie
// The idea is to insert all dictionary keys into the Trie one by one. Here key refers to only Uppercase characters in original word in CamelCase notation. 
// Modify TrieNode to store list of words ending at this node
// After all dictionary words are processed, we search for the pattern in the trie and print all words that matches the pattern.
// Run a DFS from node which matches pattern

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    map<char,TrieNode*> children; // MAP, since want to traverse in lexographic order
    // storing list of words ending at this node
    // if words.size()>0 => isTerminal = true
    list<string> words; 
    TrieNode(char ch){
        data=ch;
    }
};

class Trie{
    TrieNode* root;
    
    void insert(TrieNode* node, const string &word, int i){
        if(i==word.size()){
            node->words.push_back(word);
            return;
        } 
        
        char ch = word[i];
        
        // Skip lower case characters when inserting into trie        
        if(!isupper(ch)){ // CCTYPE library
            insert(node,word,i+1);
            return;    
        }
        
        if(!node->children.count(ch)){
            node->children[ch] = new TrieNode(ch);
        }
        insert(node->children[ch],word,i+1);
    }
    
    void dfs(TrieNode* node, int &numWords){
        
        for(string word:node->words){
            numWords++;
            cout<<word<<" ";
        } 
        
        for(auto p : node->children){
            char ch = p.first;
            TrieNode *child = node->children[ch];
            dfs(child,numWords);                
        }
        
    }
    
public:

    Trie(){
        root=new TrieNode('\0');
    }
    
    void insert(string word){
        insert(root,word,0);
    }    
    
    void printAllWords(string pattern){
        // ITERATIVELY matching string pattern
	    TrieNode *currNode = root;
	    int i;
	    for(i=0;i<pattern.size();i++){
	        if(!currNode->children.count(pattern[i])) break;
	        currNode = currNode->children[pattern[i]];
	    }

      if(i<pattern.size()){
          cout<<"No match found\n";
          return;
      }        
      
      // Now run DFS from currNode to print all words
      int numWords=0;
      dfs(currNode,numWords);
      if(numWords==0){
          cout<<"No match found\n";
      }else{
          cout<<"\n";
      }

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
        string pattern;
        cin>>pattern;
        tr.printAllWords(pattern);
    }
	return 0;
}