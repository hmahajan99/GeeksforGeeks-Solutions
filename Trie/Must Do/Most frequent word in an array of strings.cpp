// Given an array containing N words consisting of lowercase characters. 
// Your task is to find the most frequent word in the array. 
// If multiple words have same frequency, then print the word whose first occurence occurs last in the array as compared to the other strings with same frequency.

// Approach: Store frequency in TrieNode, increment frequency when insert word
// getFrequency similar to search

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    unordered_map<char,TrieNode*> children;
    int freq;
    TrieNode(char ch){
        data=ch;
        freq=0;
    }
};

class Trie{
    TrieNode* root;
    
    void insert(TrieNode* node, const string &word, int i){
        if(i==word.size()){
            node->freq++;
            return;
        } 
        char ch = word[i];
        if(!node->children.count(ch)){
            node->children[ch] = new TrieNode(ch);
        }
        insert(node->children[ch],word,i+1);
    }
    
    int getFrequency(TrieNode* node, const string &word, int i){
        if(i==word.size()){
            return node->freq;
        }
        char ch = word[i];
        if(!node->children.count(ch)){
            return 0;
        }
        return getFrequency(node->children[ch],word,i+1);
    }
    
public:

    Trie(){
        root=new TrieNode('\0');
    }
    
    void insert(string word){
        insert(root,word,0);
    }    
    
    int getFrequency(string word){
        return getFrequency(root,word,0);
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
	    Trie tr;
        int n;
        cin>>n;
        vector<string> s;
        for(int i=1;i<=n;i++){
            string str;
            cin>>str;
            s.push_back(str);
            tr.insert(str);
        }

        // NOTE : JUST TO get AC
        // JUST SEE CONCEPT OF USING TRIE FOR FREQUENCY IN THIS QUES
        map<string,int> m;
        for(string str:s){
            m[str] = tr.getFrequency(str);
        }
        string sol;
        int value = 0;
        for(auto i = 0; i < n; i++){
            if(m[s[i]] >= value){
                value = m[s[i]];
                sol = s[i];
                m[s[i]] = -1;
            }
        }    
        cout<<sol<<"\n";


	}
	return 0;
}




