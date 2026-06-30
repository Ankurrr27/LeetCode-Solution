class TrieNode {
public:
    TrieNode* child[26];
    bool end;

    TrieNode() {
        end = false;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class StreamChecker {
private:
    TrieNode* root;
    string stream;
    int maxLen;

    void insert(string word) {
        TrieNode* node = root;

        reverse(word.begin(), word.end());

        for (char c : word) {
            int idx = c - 'a';

            if (!node->child[idx])
                node->child[idx] = new TrieNode();

            node = node->child[idx];
        }

        node->end = true;
    }

public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        maxLen = 0;

        for (string &word : words) {
            insert(word);
            maxLen = max(maxLen, (int)word.size());
        }
    }

    bool query(char letter) {
        stream.push_back(letter);

        if (stream.size() > maxLen)
            stream.erase(stream.begin());

        TrieNode* node = root;

        for (int i = stream.size() - 1; i >= 0; i--) {
            int idx = stream[i] - 'a';

            if (!node->child[idx])
                return false;

            node = node->child[idx];

            if (node->end)
                return true;
        }

        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */