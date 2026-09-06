class Solution {
public:

    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;
    unordered_map<string, int> level;

    void dfs(string word, string beginWord, vector<string>& path) {

        if(word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for(string p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if(!st.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);

        level[beginWord] = 0;

        bool found = false;

        while(!q.empty() && !found) {

            int sz = q.size();
            unordered_set<string> usedThisLevel;

            while(sz--) {

                string word = q.front();
                q.pop();

                int currLevel = level[word];

                for(int i = 0; i < word.size(); i++) {

                    char original = word[i];

                    for(char ch = 'a'; ch <= 'z'; ch++) {

                        word[i] = ch;

                        if(!st.count(word))
                            continue;

                        // First time we see this word
                        if(!level.count(word)) {

                            level[word] = currLevel + 1;

                            q.push(word);

                            usedThisLevel.insert(word);

                            parent[word].push_back(
                                word.substr(0, i) +
                                original +
                                word.substr(i + 1)
                            );
                        }

                        // Another shortest parent
                        else if(level[word] == currLevel + 1) {

                            parent[word].push_back(
                                word.substr(0, i) +
                                original +
                                word.substr(i + 1)
                            );
                        }

                        if(word == endWord)
                            found = true;
                    }

                    word[i] = original;
                }
            }
            // remove only after completing the whole level
            for(string word : usedThisLevel)
                st.erase(word);
        }

        if(!level.count(endWord))
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};