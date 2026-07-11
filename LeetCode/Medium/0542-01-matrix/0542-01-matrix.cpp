class Solution {
public:
    void bfs(vector<vector<int>>& mat,vector<vector<int>>& vis,vector<vector<int>>& res,queue <pair<pair<int,int>,int>> &q){
        int n=mat.size();
        int m=mat[0].size();

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;

            q.pop();
            
            res[r][c]=t;

            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=1){
                    
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=1;
                }
            }
        }



    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        queue <pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> res(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        bfs(mat,vis,res,q);
        return res;

    }
};