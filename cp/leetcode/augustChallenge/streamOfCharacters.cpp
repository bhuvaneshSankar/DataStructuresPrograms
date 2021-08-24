/*
Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
 

Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ALPHA_SIZE 26
class StreamChecker
{
public:
    struct TrieNode
    {
        bool isEndOfWord;
        struct TrieNode *children[ALPHA_SIZE];
    };
    deque<char> currQueryString;
    struct TrieNode *getNode()
    {
        // struct TrieNode* newnode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
        struct TrieNode *newnode = new TrieNode;
        newnode->isEndOfWord = false;
        for (int i = 0; i < ALPHA_SIZE; ++i)
        {
            newnode->children[i] = NULL;
        }
        return newnode;
    }
    struct TrieNode *root = getNode();
    void insert(string str)
    {
        struct TrieNode *curr = root;
        reverse(str.begin(), str.end());
        for (char ch : str)
        {
            int index = ch - 'a';
            if (curr->children[index] == NULL)
            {
                curr->children[index] = getNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
    bool findWord(deque<char> str)
    {
        struct TrieNode *curr = root;
        for (char ch : str)
        {
            int index = ch - 'a';
            if (!curr->children[index])
            {
                return false;
            }
            curr = curr->children[index];
            if (curr->isEndOfWord)
            {
                return true;
            }
        }
        return false;
    }
    StreamChecker(vector<string> &words)
    {
        struct TrieNode *curr;
        for (string str : words)
        {
            insert(str);
        }
    }

    bool query(char ch)
    {
        currQueryString.push_front(ch);
        return findWord(currQueryString);
    }
};
