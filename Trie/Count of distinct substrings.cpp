// Given a string of length N of lowercase alphabet characters. 
// The task is to complete the function countDistinctSubstring(), which returns the count of total number of distinct substrings of this string.

// Approach 1: Using unordered_set
// Store all generated substrings. Finally we return size of the set.

/***************************************************************************************************************************/

// Appraoch 2: Using SUFFIX TRIE
// The idea is create a Trie of all suffixes of given string. 
// Once the Trie is constructed, our answer is total number of nodes in the constructed Trie.
// How does this work?
//   Each root to node path of a Trie represents a prefix of words present in Trie. Here the words are suffixes of given string. So each node represents a prefix of suffixes.
//   IMP => Every substring of a string “str” is a prefix of a suffix of “str”.