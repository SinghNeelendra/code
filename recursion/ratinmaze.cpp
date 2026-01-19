class Solution {
  public:
    int dx[4]={1,0,0,-1};
    int dy[4]={0,-1,1,0};
    char dir[4]={'D','L','R','U'};
    bool safe(int sx, int sy, int i, int j,
              vector<vector<int>>& maze,
              vector<vector<bool>>& v) {

        if (i >= 0 && i < sx && j >= 0 && j < sy &&
            maze[i][j] == 1 && v[i][j] == false) {
            return true;
        }
        return false;
    }
    
    
   
    void solve(vector<vector<int>>& maze, int sx, int sy,
               int i, int j,
               vector<vector<bool>>& v,
               vector<string>& path,
               string ans) {
                    
         if (i == sx - 1 && j == sy - 1) {
            path.push_back(ans);
            return;
        }
        for(int k=0;k<4;k++){
            int newx=i+dx[k];
            int newy=j+dy[k];
            char newdir=dir[k];
            if(safe(sx,sy,newx,newy,maze,v)){
            v[newx][newy]=true;
            solve(maze,sx,sy,newx,newy,v,path,ans+newdir);
            v[newx][newy]=false;
        } 
        }
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
         
        int sx=maze.size();
        int sy=maze[0].size();
        vector<string> path;
        string ans="";
        vector<vector<bool>> v(sx,vector<bool>(sy,false));
        if(maze[0][0]==0){
            return path;
        }
        v[0][0]=true;
        solve(maze,sx,sy,0,0,v,path,ans);
        return path;
    }
};