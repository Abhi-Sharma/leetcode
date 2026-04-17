class Solution {
public:
unordered_map<string,string> mpp;
int id = 1;
string base = "http://abhi.com/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = base + to_string(id++);
        mpp[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mpp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));