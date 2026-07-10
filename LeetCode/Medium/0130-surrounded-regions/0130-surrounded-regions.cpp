class Solution {
public:
    void bfs(int p,int s,vector<vector<char>> &board,vector<vector<int>> &vis){
        int r=p;
        int c=s;
        int n=board.size();
        int m=board[0].size();

        queue<pair<int,int>> q;
        q.push({r,c});
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=1 && board[nrow][ncol]=='O'){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                
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
                        bfs(i,j,board,vis);
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