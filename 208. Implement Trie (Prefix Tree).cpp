class TrieNode {
public:
    bool is_word;
    TrieNode* next[26];
    // Initialize your data structure here.
    TrieNode(bool b = false) {
        memset(next,0,sizeof(next));
        is_word = b;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for(auto w : word){
            if(p->next[w-'a'] == NULL) p->next[w-'a'] = new TrieNode();
            p = p->next[w-'a'];
        }
        p->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * p = root;
        for(auto w : word){
            if(p->next[w-'a'] == NULL) return false;
            p = p->next[w- 'a'];
        }
        return p->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode * p = root;
        for(auto w : prefix){
            if(p->next[w-'a'] == NULL) return false;
            p = p->next[w- 'a'];
        }
        return p!=NULL;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");