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
        // {time,{user,ind}}
        priority_queue<pair<int,pair<int,int>>> pq;
        if(!tweetMap[userId].empty()){
            int index= tweetMap[userId].size()-1;
            pq.push({tweetMap[userId][index].second,{userId,index}});
        }
        for(auto followee: followMap[userId]){
            if(!tweetMap[followee].empty()){
                int index= tweetMap[followee].size()-1;
                pq.push({tweetMap[followee][index].second,{followee,index}});
            }
        }
        vector<int> ans;
        while(!pq.empty() && ans.size()<10){
            auto top = pq.top();
            int time = top.first;
            int user = top.second.first;
            int ind = top.second.second;
            pq.pop();
            ans.push_back(tweetMap[top.second.first][top.second.second].first);
            ind--;
            if(ind>=0){
                pq.push({tweetMap[user][ind].second,{user,ind}});
            }
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