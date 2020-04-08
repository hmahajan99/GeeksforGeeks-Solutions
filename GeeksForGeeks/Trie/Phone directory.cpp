// Given a list of contacts which exist in a phone directory and a query string str. 
// The task is to implement search query for the phone directory. 
// Run a search query for each prefix p of the query string str(i.e from  index 1 to str length) 
// that prints all the distinct recommended contacts which have the same prefix as our query (p) in lexicographical order.

// Example:
// Input:
// 1
// 3
// geeikistest geeksforgeeks geeksfortest
// geeips

// Output:
// geeikistest geeksforgeeks geeksfortest
// geeikistest geeksforgeeks geeksfortest
// geeikistest geeksforgeeks geeksfortest
// geeikistest
// 0
// 0

// Explanation:
// By running the query on contact list, we get, 
// Suggestions based on "g" are: 
// geeikistest geeksforgeeks geeksfortest 
// Suggestions based on "ge" are:
// geeikistest geeksforgeeks geeksfortest
// Suggestions based on "gee" are:
// geeikistest geeksforgeeks geeksfortest
// Suggestions based on "geei" are:
// geeikistest
// No Results Found for "geeip", So print "0".
// No Results Found for "geeips", So print "0".


// User will enter the string character by character and we need to display suggestions with the prefix formed after every entered character.

// Approach 1
// For every prefix of the fiven string, traverse the trie.
// While traversing first match the prefix, and when it has been matched run a DFS from that point to get all words having that prefix

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    // IMP: USING MAP(instead of unordered_map), SINCE WANT TO TRAVERSE CHILDREN IN SORTED ORDER HERE
    map<char,TrieNode*> children;  
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
    
    void getWords(TrieNode* node, const string &word, string &curr, int &numWords){
        if(curr.size()<word.size()){
            // Prefix not yet matched [NOTE: Could match prefix ITERATIVELY too ]
            char ch = word[curr.size()];
            curr.push_back(ch);
            if(node->children.count(ch)){
                TrieNode *child = node->children[ch];
                getWords(child,word,curr,numWords);                
            } 
            return;
        }
        
        // Now prefix has been matched 

        if(node->isTerminal){
            numWords++;
            cout<<curr<<" ";
        } 
        
        for(auto p : node->children){
            char ch = p.first;
            TrieNode *child = node->children[ch];
            curr.push_back(ch);
            getWords(child,word,curr,numWords);                
            curr.pop_back();
        }

    }
    
public:

    Trie(){
        root=new TrieNode('\0');
    }
    
    void insert(string word){
        insert(root,word,0);
    }    
    
    void getWordsPrefixedBy(string word){
        // Prints all words in trie of which word is a prefix
        string curr="";
        int numWords=0;
        getWords(root,word,curr,numWords);
        if(numWords==0) cout<<0;
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
	    string p;
	    cin>>p;
	    string prefix="";
	    for(int i=0;i<p.size();i++){
	        prefix += p[i];
	        tr.getWordsPrefixedBy(prefix);
	        cout<<"\n";
	    }
	}
	
	
	return 0;
}

// Alternative: Matching prefix ITERATIVELY

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    // IMP: USING MAP(instead of unordered_map), SINCE WANT TO TRAVERSE CHILDREN IN SORTED ORDER HERE
    map<char,TrieNode*> children;  
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
    
    void getWords(TrieNode* node, string &curr, int &numWords){

        if(node->isTerminal){
            numWords++;
            cout<<curr<<" ";
        } 
        
        for(auto p : node->children){
            char ch = p.first;
            TrieNode *child = node->children[ch];
            curr.push_back(ch);
            getWords(child,curr,numWords);                
            curr.pop_back();
        }

    }
    
public:

    Trie(){
        root=new TrieNode('\0');
    }
    
    void insert(string word){
        insert(root,word,0);
    }    
    
    void getWordsPrefixedBy(string word){
        // Prints all words in trie of which word is a prefix
        string curr="";
        // Matching prefix iteratively
        TrieNode *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->children.count(word[i])) break;
            curr += word[i];
            node = node->children[word[i]];
        }

        int numWords=0;
        if(curr.size()==word.size()){
            getWords(node,curr,numWords);
        }
        if(numWords==0) cout<<0;

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
	    string p;
	    cin>>p;
	    string prefix="";
	    for(int i=0;i<p.size();i++){
	        prefix += p[i];
	        tr.getWordsPrefixedBy(prefix);
	        cout<<"\n";
	    }
	}
	
	
	return 0;
}


/***************************************************************************************************************************/

// Approach 2: Efficient 
// Avoiding traversing from root to prefix for each prefix
// Instead of checking again and again, we can maintain a pointer prevNode
// If the new prefix is not in the Trie, then all the string which are formed by entering characters after ‘prefix’ can’t be found in Trie too. 
// So we break the loop that is being used to generate prefixes one by one and print “No Result Found” for all remaining characters.

// NOTE: User will enter the string character by character 
// and we need to display suggestions with the prefix formed after every entered character.

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    // IMP: USING MAP(instead of unordered_map), SINCE WANT TO TRAVERSE CHILDREN IN SORTED ORDER HERE
    map<char,TrieNode*> children;  
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
    
    void getWords(TrieNode* node, string &curr, int &numWords){
        // DFS

        if(node->isTerminal){
            numWords++;
            cout<<curr<<" ";
        } 
        
        for(auto p : node->children){
            char ch = p.first;
            TrieNode *child = node->children[ch];
            curr.push_back(ch);
            getWords(child,curr,numWords);                
            curr.pop_back();
        }

    }
    
    int getWordsPrefixedBy(TrieNode* node,const string word){
        // word => string represented by path from root to node
        // Prints all words in trie going through current node
        string curr=word;
        int numWords=0;
        getWords(node,curr,numWords); // DFS from node
        return numWords;
    }
    
public:

    Trie(){
        root=new TrieNode('\0');
    }
    
    void insert(string word){
        insert(root,word,0);
    }    
    
    void solve(string s){
	    string prefix="";
	    TrieNode *currNode = root;
	    int i;
	    for(i=0;i<s.size();i++){
	        if(!currNode->children.count(s[i])) break;
	        prefix += s[i];
	        currNode = currNode->children[s[i]];
	        int numWords = getWordsPrefixedBy(currNode,prefix);
	        if(numWords==0) break;
	        cout<<"\n";
	    }
	    for(;i<s.size();i++){
	        cout<<0;
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
	    string p;
	    cin>>p;
	    tr.solve(p);
	}
	
	
	return 0;
}

