class Solution {
public:
   void bfs(vector<vector<int>> grid, vector<vector<int>>& visited,
            queue<tuple<int,int,int>>& q, int &t, int &s){

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){

            auto a = q.front();
            q.pop();

            int x = get<0>(a);
            int y = get<1>(a);
            int z = get<2>(a);

            t = max(t,z);

            if(x-1 >= 0){
                if(grid[x-1][y] == 1){
                    if(visited[x-1][y] == 0){
                        q.push({x-1,y,z+1});
                        s++;
                        visited[x-1][y] = 2;
                    }
                }
            }

            if(y-1 >= 0){
                if(grid[x][y-1] == 1){
                    if(visited[x][y-1] == 0){
                        q.push({x,y-1,z+1});
                        s++;
                        visited[x][y-1] = 2;
                    }
                }
            }

            if(x+1 < n){
                if(grid[x+1][y] == 1){
                    if(visited[x+1][y] == 0){
                        q.push({x+1,y,z+1});
                        s++;
                        visited[x+1][y] = 2;
                    }
                }
            }

            if(y+1 < m){
                if(grid[x][y+1] == 1){
                    if(visited[x][y+1] == 0){
                        q.push({x,y+1,z+1});
                        s++;
                        visited[x][y+1] = 2;
                    }
                }
            }
        }
   }

   int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<tuple<int,int,int>> q;

        int f = 0;
        int s = 0;
        int t = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == 1)
                {f++;t=-1;}

                if(grid[i][j] == 2){
                    q.push({i,j,0});
                    f++;
                    s++;
                    visited[i][j] = 2;
                }
            }
        }

        bfs(grid, visited, q, t, s);

        if(s < f)
            return -1;

        return t;
   }
};