class TrieNode {
public:
    TrieNode** children;
    bool isTerminal;

    TrieNode() {
        children = new TrieNode*[26];

        for(int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insertWord(string word) {
        insertWord(root, word, 0);
    }  

    bool searchWord(string word) {
        return searchWord(root, word, 0);
    }


private:

    void insertWord(TrieNode *root, const string& word, int index) {
        if(index == word.size()) {
            root->isTerminal = true;
            return;
        }

        int charIndex = word[index] - 'a';
        if(root->children[charIndex] == NULL) {
            root->children[charIndex] = new TrieNode();
        }

        insertWord(root->children[charIndex], word, index + 1);
    }


    bool searchWord(TrieNode* root, const string& word, int index) {
        if(index == word.size()) {
            return root->isTerminal;
        }

        char c = word[index];
        if(c != '.') {
            int charIndex = c - 'a';
            return root->children[charIndex] && searchWord(root->children[charIndex], word, index + 1);
        } else {
            for(int i = 0; i < 26; ++i) {
                if(root->children[i] && searchWord(root->children[i], word, index + 1)) {
                    return true;
                }
            }
            return false;
        }
    }

};

class WordDictionary {
    Trie* trie;
public:
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        trie->insertWord(word);
    }

    bool search(string word) {
        return trie->searchWord(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */