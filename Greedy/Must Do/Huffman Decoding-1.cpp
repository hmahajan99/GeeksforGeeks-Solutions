// The task is to implement Huffman Encoding and Decoding.

// Prefix Codes, means the codes (bit sequences) are assigned in such a way that the code assigned to one character is not the prefix of code assigned to any other character. 
// This is how Huffman Coding makes sure that there is no ambiguity when decoding the generated bitstream.

// There are mainly two major parts in Huffman Coding
// 1) Build a Huffman Tree from input characters.
// 2) Traverse the Huffman Tree and assign codes to characters.

// Steps to build Huffman Tree
// Input is an array of unique characters along with their frequency of occurrences and output is Huffman Tree.
// 1. Create a leaf node for each unique character and build a min heap of all leaf nodes (Min Heap is used as a priority queue. The value of frequency field is used to compare two nodes in min heap. Initially, the least frequent character is at root)
// 2. Extract two nodes with the minimum frequency from the min heap.
// 3. Create a new internal node with a frequency equal to the sum of the two nodes frequencies. Make the first extracted node as its left child and the other extracted node as its right child. Add this node to the min heap.
// 4. Repeat steps#2 and #3 until the heap contains only one node. The remaining node is the root node and the tree is complete.

// To decode the encoded data we require the Huffman tree. We iterate through the binary encoded data. To find character corresponding to current bits, we use following simple steps.
// 1. We start from root and do following until a leaf is found.
// 2. If current bit is 0, we move to left node of the tree.
// 3. If the bit is 1, we move to right node of the tree.
// 4. If during traversal, we encounter a leaf node, we print character of that particular leaf node and then again continue the iteration of the encoded data starting from step 1.

// { Driver Code Starts
#include <bits/stdc++.h>
#define MAX_TREE_HT 256
using namespace std; 
map<char, string> codes;
map<char, int> freq;
struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;
 
    MinHeapNode(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};
void printCodes(struct MinHeapNode* root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
void storeCodes(struct MinHeapNode* root, string str)
{
    if (root==NULL)
        return;
    if (root->data != '$')
        codes[root->data]=str;
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
void HuffmanCodes(int size)
{
    struct MinHeapNode *left, *right, *top;
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
        minHeap.push(new MinHeapNode(v->first, v->second));
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    storeCodes(minHeap.top(), "");
}
void calcFreq(string str, int n)
{
    for (int i=0; i<str.size(); i++)
        freq[str[i]]++;
}
string decode_file(struct MinHeapNode* root, string s);
int main()
{
	int t;
	cin>>t;
	while(t--){
	codes.clear();
	freq.clear();
	minHeap=priority_queue <MinHeapNode*, vector<MinHeapNode*>, compare>();
    string str;
	cin>>str;
    string encodedString, decodedString;
    calcFreq(str, str.length());
    HuffmanCodes(str.length());
    /*cout << "Character With there Frequencies:\n";
    for (auto v=codes.begin(); v!=codes.end(); v++)
        cout << v->first <<' ' << v->second << endl;*/
    for (auto i: str)
        encodedString+=codes[i];
    //cout <</* "\nEncoded Huffman data:\n" << */encodedString << endl;
    decodedString = decode_file(minHeap.top(), encodedString);
    cout <</* "\nDecoded Huffman Data:\n" << */decodedString << endl;
	}
    return 0;
}
// } Driver Code Ends


/*Complete the function below 
Which contains 2 arguments 
1) root of the tree formed while encoding
2) Encoded String*/
string decode_file(struct MinHeapNode* root, string s){
    string ans="";
    MinHeapNode *node = root;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') node = node->left;
        else node = node->right;
        
        if(node->data!='$'){  // Leaf Node
            ans+=node->data;
            node=root;
        }
    }
    return ans;

}