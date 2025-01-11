
class Solution {
    struct Node {
        int freq;
        Node* links[26];
        Node() {
            freq = 0;
            for (int i = 0; i < 26; i++) links[i] = nullptr;
        }
    };
    class Trie {
    private:
        Node* root;
    public:
        Trie() {
            root = new Node();
        }
        void insertWord(string& word) {
            int i;
            Node* node = root;
            for (i = 0; i < word.size(); i++) {
                if (node->links[word[i] - 'a'] == NULL) {
                    node->links[word[i] - 'a'] = new Node();

                }
                node = node->links[word[i] - 'a'];
                node->freq++;
            }
        }
        int startsWith(string& word) {
            Node* node = root; int c = 0;
            for (int i = 0; i < word.size(); i++) {

                if (node->links[word[i] - 'a'] == NULL) return 0;
                node = node->links[word[i] - 'a'];
            }
            return node->freq;

        }
    };
public:

    int prefixCount(vector<string>& words, string pref) {
        Trie t;
        for (int i = 0; i < words.size(); i++) {
            t.insertWord(words[i]);
        }
        return t.startsWith(pref);
    }
};