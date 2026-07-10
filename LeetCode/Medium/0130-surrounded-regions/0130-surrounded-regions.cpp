class Solution {
public:
    void dfs(int p,int s,vector<vector<char>> &board,vector<vector<int>> &vis){
        
        int n=board.size();
        int m=board[0].size();

        
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        
        for(int i=0;i<4;i++){
                
            int nrow=p+drow[i];
            int ncol=s+dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=1 && board[nrow][ncol]=='O'){
                
                vis[nrow][ncol]=1;
                dfs(nrow,ncol,board,vis);
            }
                
            }

        

    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 ||j==m-1){
                    if(board[i][j]=='O'){
                        dfs(i,j,board,vis);
                        vis[i][j]=1;
                    }
                }
            }
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(board[i][j]=='O' && vis[i][j]!=1){
                    board[i][j]='X';
                }
            }
        }
    }
};