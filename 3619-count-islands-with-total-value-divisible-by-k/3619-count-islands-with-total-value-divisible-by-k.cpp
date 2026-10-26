class Solution {
public:
    long long bfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=true;
        long long sum=0;
        int dx[]={0,-1,0,1};
        int dy[]={-1,0,1,0};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            sum+=grid[r][c];

            for(int i=0;i<4;i++){
                int nr=r+dx[i];
                int nc=c+dy[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]!=0){
                    vis[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        unordered_map<long long,int> mp;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]!=0){
                    long long sum=bfs(i,j,grid,vis);
                    mp[sum]++;
                }
            }
        }

        int cnt=0;
        for(auto x:mp){
            //cout<<x.first<<" "<<x.second<<endl;
            if(x.first%k==0){
                cnt+=x.second;
            }
        }

        return cnt;
    }
};