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
        insertWord(root, word);
    }

    bool searchWord(string word) {
        return searchWord(root, word);
    }

private:

    void insertWord(TrieNode *root, string word) {
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL){
            child = root -> children[index];
        } else {
            child = new TrieNode();
            root -> children[index] = child;
        }

        insertWord(child, word.substr(1));
    }

    bool searchWord(TrieNode* root, string word) {
        if(word.size() == 0) {
            return root -> isTerminal;
        }

        if(word[0] != '.') {
            int index = word[0] - 'a';

            if(root -> children[index] != NULL) {
                TrieNode* child = root -> children[index];
                return searchWord(child, word.substr(1));
            } else {
                return false;
            }
        } else {
            for(int i = 0; i < 26; ++i) {
                if(root -> children[i] != NULL) {
                    if (searchWord(root->children[i], word.substr(1))) {
                        return true;
                    }
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