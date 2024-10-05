// 127. Word Ladder

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    set<string> set(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    set.erase(beginWord);

    while(!q.empty()){
        string word = q.front().first;
        int s = q.front().second;
        q.pop();

        if(word == endWord){
            return s;
        }

        for(int i=0; i<word.size(); i++){
            char org = word[i];
            for(char ch='a'; ch<='z'; ch++){
                word[i] = ch;
                if(set.find(word) != set.end()){
                    q.push({word, s+1});
                    set.erase(word);
                }
            }
            word[i] = org;
        }
    }
    return 0;
}

// 126. Word Ladder 2

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

    unordered_set<string> set(wordList.begin(), wordList.end());
    if(set.find(endWord) == set.end()) return {};

    queue<vector<string>> q;
    q.push({beginWord});
    set.erase(beginWord);
    vector<vector<string>> ls;

    unordered_set<string> useOnLevel;
    useOnLevel.insert(beginWord);
    int level = 1;
    int minLevel = INT_MAX;

    while(!q.empty()){
        vector<string> v = q.front();
        string word = v.back();
        q.pop();

        if(v.size() > level){
            if(v.size() > minLevel) break;
            for(string it : useOnLevel){
                set.erase(it);
            }
            useOnLevel.clear();
            level = v.size();
        }

        if(word == endWord){
            minLevel = level;
            ls.push_back(v);
        }

        for(int i=0; i<word.size(); i++){
            char org = word[i];
            for(char ch='a'; ch<='z'; ch++){
                if(ch == org) continue;
                word[i] = ch;
                if(set.count(word) > 0){
                    v.push_back(word);
                    q.push(v);
                    v.pop_back();

                    // used word
                    useOnLevel.insert(word);
                }
            }
            word[i] = org;
        }
    }
    return ls;
}

// 126. for leetcode

class Solution {
    unordered_map<string, int> map;
    vector<vector<string>> ans;
    string b;
public:
    void dfs(string word, vector<string>& seq){
        if(word == b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int level = map[word];
        for(int i=0; i<word.size(); i++){
                char org = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(map.find(word) != map.end() 
                    && map[word] + 1 == level){
                        seq.push_back(word);
                        dfs(word, seq);
                        seq.pop_back();
                    }
                }
            word[i] = org;
        }

    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> set(wordList.begin(), wordList.end());
        b = beginWord;

        queue<string> q;
        q.push(beginWord);
        set.erase(beginWord);
        map[beginWord] = 1;

        while(!q.empty()){
            string word = q.front();
            int level = map[word];
            q.pop();

            if(word == endWord) break;

            for(int i=0; i<word.size(); i++){
                char org = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(set.count(word)){
                        q.push(word);
                        set.erase(word);
                        map[word] = level + 1;
                    }
                }
                word[i] = org;
            }
        }
        if(map.find(endWord) != map.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};