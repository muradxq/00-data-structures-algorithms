/**
 * Problem: Design Twitter
 * LeetCode #355
 * Difficulty: Medium
 * Pattern: System
 *
 * Implement Twitter with follow, unfollow, post, and news feed.
 *
 * Example:
 *   postTweet(1, 5), getNewsFeed(1) -> [5]
 *   follow(1, 2), postTweet(2, 6), getNewsFeed(1) -> [6, 5]
 */

#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
class Twitter {
public:
    Twitter() {
        // Your implementation here
    }
    
    void postTweet(int userId, int tweetId) {
        // Your implementation here
    }
    
    vector<int> getNewsFeed(int userId) {
        // Your implementation here
        // Return 10 most recent tweets
        return {};
    }
    
    void follow(int followerId, int followeeId) {
        // Your implementation here
    }
    
    void unfollow(int followerId, int followeeId) {
        // Your implementation here
    }
    
private:
    // Track tweets with timestamps, following relationships
};

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(Twitter, Example1) {
    Twitter twitter;
    twitter.postTweet(1, 5);
    auto feed = twitter.getNewsFeed(1);
    EXPECT_EQ(feed.size(), 1);
    EXPECT_EQ(feed[0], 5);
    
    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    feed = twitter.getNewsFeed(1);
    EXPECT_EQ(feed.size(), 2);
    EXPECT_EQ(feed[0], 6);
    
    twitter.unfollow(1, 2);
    feed = twitter.getNewsFeed(1);
    EXPECT_EQ(feed.size(), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
