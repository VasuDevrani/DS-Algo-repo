class Solution{
    public:
    void getPaths(int i, int j, vector<string> &ans, string tmp, int n, vector<vector<int>> &m){
        if(i < 0 || j < 0 || i >= n || j >= n || m[i][j] == 0) return;
        if(i == n-1 && j == n-1){
            ans.push_back(tmp);
            return;
        }
        m[i][j] = 0;
        getPaths(i+1, j, ans, tmp + 'D', n, m);
        getPaths(i-1, j, ans, tmp + 'U', n, m);
        getPaths(i, j+1, ans, tmp + 'R', n, m);
        getPaths(i, j-1, ans, tmp + 'L', n, m);
        m[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        string tmp = "";
        getPaths(0, 0, ans, tmp, n, m);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
