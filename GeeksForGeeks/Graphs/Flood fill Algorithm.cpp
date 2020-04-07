// Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), 
// your task is to replace color of the given pixel and all adjacent(excluding diagonally adjacent) same colored pixels with the given color K.

// Approach: Recursive, DFS

using namespace std;

bool isValid(int x,int y,int n,int m){
    if(x<0||x>=n||y<0||y>=m) return false;
    return true;
}

void floodFill(int grid[][100],int x,int y,int oldColor,int newColor,int n,int m){
    if(!isValid(x,y,n,m)) return;
    //cout<<x<<" "<<y<<" "<<grid[x][y]<<"\n";
    if(grid[x][y]!=oldColor) return;
    grid[x][y]=newColor;
    int dx[]={1,0,-1,0};
    int dy[]={0,-1,0,1};
    for(int k=0;k<4;k++){
        floodFill(grid,x+dx[k],y+dy[k],oldColor,newColor,n,m);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int grid[100][100];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        
        int x,y,newColor;
        cin>>x>>y>>newColor;
        if(grid[x][y]!=newColor){
            floodFill(grid,x,y,grid[x][y],newColor,n,m);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
        }
        
        cout<<"\n";
        
    }
	return 0;
}