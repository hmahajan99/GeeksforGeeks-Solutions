// Similar to InterviewBit/Graphs/Word Search Board

// Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. 
// Find all possible words that can be formed by a sequence of adjacent characters. 
// Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.

// Example:
// Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
//        boggle[][]   = {{'G','I','Z'},
//                        {'U','E','K'},
//                        {'Q','S','E'}};
// Output:  Following words of dictionary are present
//          GEEKS, QUIZ

// Approach 1: Using DFS, See InterviewBit/Graphs/Word Search Board for code
// Do the following for every word in the dictionary
// We do depth first traversal starting from every cell where the character matches first character of string
// We keep track of visited cells to make sure that a cell is considered only once in a word

/***************************************************************************************************************************/

// Approach 2: Trie based optimized solution
// Optimization - If many strings in the dictionary have common prefixes this approach would be better,
//                than calling DFS seperately for each string

// 1. Create an Empty trie and insert all words of given dictionary into trie
// 2. After that we have pick only those character in boggle[][] which are child of root of Trie
// 3. search a word in a trie which start with character that we pick in step 2

//       After insertion, Trie looks like (leaf nodes are in RED )
//                        root
//                     /   |   \ 
//                     G   F     Q
//                  /  |   |     |
//                 O   E   O     U
//                     |   |     |
//                     E   R     I
//                     |         |  
//                     K         Z 
//                     |   
//                     S   
//       We pick ‘G’ boggle[0][0] , ‘Q’ boggle[2][0] (they both are present in boggle matrix)

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

class Sol{
    TrieNode* root;
    int n,m;
    vector<vector<bool>> vis;
    vector<vector<char>> boggle;
    set<string> ans;
    vector<int> dx,dy;

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
    
    bool isValid(int i,int j){
        if(i<0||i>=m||j<0||j>=n) return false;
        return true;
    }
    
    void dfsUtil(int i,int j,TrieNode* node,string &curr){
        vis[i][j]=true;
       if(node->isTerminal) ans.insert(curr);

        for(int k=0;k<8;k++){
            int x = i+dx[k], y = j+dy[k];
            if(isValid(x,y)&&!vis[x][y]){
                curr.push_back(boggle[x][y]);
                if(node->children.count(boggle[x][y])){
                    dfsUtil(x,y,node->children[boggle[x][y]],curr);
                }
                curr.pop_back();
            }
        }
        
        vis[i][j]=false; // Mark unnvisited
    }
    
    void dfs(){
        if(!root) return;
        vis = vector<vector<bool>>(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(root->children.count(boggle[i][j])){
                    string curr = "";
                    curr += boggle[i][j];
                    dfsUtil(i,j,root->children[boggle[i][j]],curr);
                }
            }
        }
    }
    
public:

    Sol(){
        root=new TrieNode('\0');
        dx = {1,1,0,-1,-1,-1,0,1};
        dy = {0,-1,-1,-1,0,1,1,1};
    }
    
    void insert(string word){
        insert(root,word,0);
    }    
    
    void setBoggle(int row,int col){
        this->n=col;
        this->m=row;
        // M*N
        boggle = vector<vector<char>>(m,vector<char>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>boggle[i][j];
            }
        }        
    }
    
    void printSol(){
        
        dfs();
        if(!ans.size()){
            cout<<-1<<"\n";
            return;
        }
        for(string s:ans){
            cout<<s<<" ";
        }
        cout<<"\n";
    }

};

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        Sol sol;
        while(x--){
            string s;
            cin>>s;
            sol.insert(s);
        }
        int row,col;
        cin>>row>>col;
        sol.setBoggle(row,col);
        sol.printSol();

    }
	return 0;
}