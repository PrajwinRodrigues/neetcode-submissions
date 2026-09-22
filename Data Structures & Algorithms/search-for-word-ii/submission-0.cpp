class Solution {
public:

    struct Node {
        Node* links[26];
        string word;

        Node() {
            word = "";

            for(int i = 0; i < 26; i++)
                links[i] = NULL;
        }
    };

    Node* root;

    void insert(string word) {
        Node* temp = root;

        for(char c : word) {
            int idx = c - 'a';

            if(temp->links[idx] == NULL)
                temp->links[idx] = new Node();

            temp = temp->links[idx];
        }

        temp->word = word;
    }

    void dfs(int r, int c, Node* node,
             vector<vector<char>>& board,
             vector<string>& ans) {

        int m = board.size();
        int n = board[0].size();

        // Out of bounds
        if(r < 0 || r >= m || c < 0 || c >= n)
            return;

        // Already visited
        if(board[r][c] == '#')
            return;

        char ch = board[r][c];

        // Character doesn't exist in Trie
        if(node->links[ch - 'a'] == NULL)
            return;

        Node* next = node->links[ch - 'a'];

        // Found a word
        if(next->word != "") {
            ans.push_back(next->word);

            // Don't add it again
            next->word = "";
        }

        // Mark visited
        board[r][c] = '#';

        // Four directions
        dfs(r + 1, c, next, board, ans);
        dfs(r - 1, c, next, board, ans);
        dfs(r, c + 1, next, board, ans);
        dfs(r, c - 1, next, board, ans);

        // Backtrack
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        root = new Node();

        // Build Trie
        for(string word : words)
            insert(word);

        vector<string> ans;

        int m = board.size();
        int n = board[0].size();

        // Start DFS from every cell
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(i, j, root, board, ans);
            }
        }

        return ans;
    }
};