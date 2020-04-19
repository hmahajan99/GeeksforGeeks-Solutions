// Given a binary matrix your task is to complete the function printMat which prints all unique rows of the given matrix. 
// The function takes three arguments the first argument is a matrix M and the next two arguments are row and col denoting the rows and columns of the matrix.
// Note : Dont print new line after each row instead print "$" without quotes .

// Approach 1: Brute Force
// Check each row with all processed rows
// Time complexity: O( ROW^2 x COL ) .for every row check if there is any other similar row.
// Auxiliary Space: O(1).

/***************************************************************************************************************************/

// Approach 2: Use Balanced BST, Set
// Find the decimal equivalent of each row and inserting them into a BST. 
// Time complexity: O( ROW x COL + ROW x log( ROW ) ) 
// Auxiliary Space: O( ROW ) to store the BST 

/***************************************************************************************************************************/

// Approach 3: Using Trie
// Trie is an efficient information retrieval data structure. Using Trie, search complexities can be brought to an optimal limit (key length)
// If we store keys in the binary search tree, a well-balanced BST will need time proportional to M * log N, where M is maximum string length and N is the number of keys in the tree. 
// Using Trie, we can search the key in O(M) time. However, the penalty is on Trie storage requirements.

// Time complexity: O( ROW x COL )
// Auxiliary Space: O( ROW x COL ), to store the Trie

// IMP: Since the matrix is boolean, a variant of Trie data structure can be used where each node will be having two children one for 0 and other for 1.

// Algorithm:
// Create a Trie where rows can be stored.
// Traverse through the matrix and insert the row into the Trie.
// Trie cannot store duplicate entries so the duplicates will be removed
// Traverse the Trie and print the rows.

/*You are required to complete this function*/

class TrieNode{
    public:
    char data;
    TrieNode** children;
    bool isTerminal;
    TrieNode(char ch){
        data=ch;
        isTerminal=false;
        children = new TrieNode*[2]; // since binaryString
        for(int i=0;i<2;i++) children[i]=NULL;
    }
};

class Trie{
    TrieNode* root;
    
    void insert(TrieNode* node, const string &binaryString, int i){
        if(i==binaryString.size()){
            node->isTerminal=true;
            return;
        } 
        int index = binaryString[i]-'0';
        if(!node->children[index]){
            node->children[index] = new TrieNode(binaryString[0]);
        }
        insert(node->children[index],binaryString,i+1);
    }
    
    bool search(TrieNode* node, const string &binaryString, int i){
        if(i==binaryString.size()){
            return node->isTerminal;
        } 
        int index = binaryString[i]-'0';
        if(!node->children[index]){
            return false;
        }
        return search(node->children[index],binaryString,i+1);
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

void printMat(int M[MAX][MAX],int row,int col){

    Trie t;
    for(int i=0;i<row;i++){
        string s="";
        for(int j=0;j<col;j++){
            s+=(char)('0'+M[i][j]);
        }
        if(!t.search(s)){
            for(int j=0;j<col;j++){
                cout<<M[i][j]<<" ";
            }
            cout<<"$";
            t.insert(s);
        }
        
    }

}

