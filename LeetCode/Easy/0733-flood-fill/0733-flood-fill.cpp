class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int original=image[sr][sc];
        if(color==original) return image;

        queue <pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;

            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                image[nrow][ncol]==original){
                    q.push({nrow,ncol});
                    image[nrow][ncol]=color;
                }
            }

        }

        return image;


    }
};