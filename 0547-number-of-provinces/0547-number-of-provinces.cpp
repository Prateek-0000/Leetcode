class Solution {
public:
   void bfs(vector<vector<int>>& c , vector<int>&visited, int root ){
    queue<int>q;
    q.push(root);
    visited[root]=1;

    while(!q.empty()){
        int a = q.front();
        q.pop();

        for(int i = 0; i < visited.size(); i++){
            if(c[a][i]==1){
                if(visited[i]==0){
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
   }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        int ans = 0;

        for(int j = 0; j < n; j++){
            if(visited[j]==0){
                ans++;
                bfs(isConnected, visited, j);
            }
        }

        return ans;
    }
};