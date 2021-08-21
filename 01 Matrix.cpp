class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visit(n,vector<int>(m,100000));//give 10000 that is a max value to all the n*m matrix cells
		//you can use INT_MAX also 
        //i am using visit vector to store my answer
        queue<pair<int,int>> q; //queue to store indexes
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});//push the indexes where 0 is found
                    visit[i][j] = 0;//mark those cells as 0 as it is 0 distance from 0
                }
            }
        }
        //now bfs search
        while(!q.empty()){
            
            int s = q.size();
            
            for(int i=0;i<s;i++){
                
                auto p = q.front();
                q.pop();
                
                int x = p.first;
                int y = p.second;
                //now we will check all the possible four direction and if in any direction if the distance from current cell is less than already presen distance for that cell change that cell's distance to new and puss this index to the queue 
                if(x+1<n && visit[x+1][y]>visit[x][y]+1){
                    q.push({x+1,y});
                    visit[x+1][y] = visit[x][y]+1;
                }
                
                if(y+1<m && visit[x][y+1]>visit[x][y]+1){
                    q.push({x,y+1});
                    visit[x][y+1] = visit[x][y]+1;
                }
                
                if(x-1>=0 && visit[x-1][y]>visit[x][y]+1){
                    q.push({x-1,y});
                    visit[x-1][y] = visit[x][y]+1;
                }
                
                if(y-1>=0 && visit[x][y-1]>visit[x][y]+1){
                    q.push({x,y-1});
                    visit[x][y-1] = visit[x][y]+1;
                }
                
            }
            
        }
        
        return visit;//return the 2d vectod we created
    }
};
