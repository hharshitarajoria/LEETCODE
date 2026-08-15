class Twitter {
public:
    unordered_map<int, unordered_set<int>> followMap;
    // userId-> {tweetId,timestamp}
    unordered_map<int, vector<pair<int,int>>> tweetMap;
    int time;
    Twitter() {
        time=0;
    }
    void postTweet(int userId, int tweetId) {
        time++;
        tweetMap[userId].push_back({tweetId,time});
    } 
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> allTweets;
        for(auto tweet : tweetMap[userId]) {
            allTweets.push_back(tweet);
        }
        // Add tweets of people user follows
        for(int followee : followMap[userId]) {
            for(auto tweet : tweetMap[followee]) {
                allTweets.push_back(tweet);
            }
        }
        sort(allTweets.begin(), allTweets.end(),
            [](pair<int,int>& a, pair<int,int>& b) {
                return a.second > b.second;
            });
        
        vector<int> ans;
        for(int i=0; i< min(10, (int)allTweets.size());i++){
            ans.push_back(allTweets[i].first);
        }
        return ans;
    } 
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */