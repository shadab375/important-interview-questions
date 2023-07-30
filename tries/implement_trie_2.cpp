#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *childs[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
};
class Trie
{
private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            if (curr->childs[ch - 'a'] == NULL)
            {
                curr->childs[ch - 'a'] = new Node();
            }
            curr = curr->childs[ch - 'a'];
            curr->cntPrefix++;
        }
        curr->cntEndWith++;
    }

    int countWordsEqualTo(string &word)
    {
        Node *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            if (curr->childs[ch - 'a'] != NULL)
            {
                curr = curr->childs[ch - 'a'];
            }
            else
            {
                return 0;
            }
        }
        return curr->cntEndWith;
    }

    int countWordsStartingWith(string &word)
    {
        Node *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            if (curr->childs[ch - 'a'] != NULL)
            {
                curr = curr->childs[ch - 'a'];
            }
            else
            {
                return 0;
            }
        }
        return curr->cntPrefix;
    }

    void erase(string &word)
    {
        Node *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            if (curr->childs[ch - 'a'] != NULL)
            {
                curr = curr->childs[ch - 'a'];
                curr->cntPrefix--;
            }
            else
            {
                return;
            }
        }
        curr->cntEndWith--;
    }
};
