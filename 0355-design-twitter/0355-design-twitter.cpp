class Twitter {
public:
int timer = 0;
unordered_map<int,unordered_set<int>> followMap;
unordered_map<int, vector<pair<int,int>>> tweetMap;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({timer++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        vector<int> ans;

        if(tweetMap.count(userId) && !tweetMap[userId].empty()){
            int idx = tweetMap[userId].size() - 1;
            pq.push({
                tweetMap[userId][idx].first,
                tweetMap[userId][idx].second,
                userId,
                idx
            });
        }

        for(auto user : followMap[userId]){
            if(tweetMap.count(user) && !tweetMap[user].empty()){
                int idx = tweetMap[user].size() - 1;
                pq.push({
                    tweetMap[user][idx].first,
                    tweetMap[user][idx].second,
                    user,
                    idx
                });
            }
        }

        while(!pq.empty() && ans.size() < 10){
            auto top = pq.top();
            pq.pop();

            int tweet = top[1];
            int userId = top[2];
            int idx = top[3];

            ans.push_back(tweet);

            if(idx > 0){
                idx--;
                pq.push({
                    tweetMap[userId][idx].first,
                    tweetMap[userId][idx].second,
                    userId,
                    idx
                });
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) followMap[followerId].insert(followeeId);
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