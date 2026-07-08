class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,int node,vector<int> &vis){
        int n=isConnected.size();

        for(int j=0;j<n;j++){
            if(isConnected[node][j]==1 && !vis[j]){
                vis[j]=1;
                dfs(isConnected,j,vis);
            }
        
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
               vis[i]=1;
               dfs(isConnected,i,vis);
               count++;
            }
        }
        return count;
    }
};