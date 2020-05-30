// Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the destination at (n-1, n-1). 
// Find all possible paths that the rat can take to reach from source to destination. 
// The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).
// 0's represents blocked paths and 1 represent valid paths.
// For each test case output will be space separated sorted strings denoting all directions, which the rat could take to reach the destination.

// Approach: Backtracking
// Keep on marking the cells as visited and when we traversed all the paths possible from that cell, then unmark that cell for other different paths and remove the character from the path formed.

void getPaths(int i,int j,int m[MAX][MAX], int n,string &current,vector<string> &ans){
    if(i<0||j<0||i>=n||j>=n) return;
    if(m[i][j]==0||m[i][j]==2) return;
    if(i==n-1&&j==n-1){
        ans.push_back(current);
        return;
    }
    
    
    m[i][j]=2; // Mark visited
    int dx[] = {1,0,0,-1};
    int dy[] = {0,-1,1,0};
    char s[] = {'D','L','R','U'};
    for(int k=0;k<4;k++){
        int i2=i+dx[k], j2=j+dy[k];
        current.push_back(s[k]);
        getPaths(i2,j2,m,n,current,ans);
        current.pop_back();
    }    
    m[i][j]=1;

}


// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
vector<string> printPath(int m[MAX][MAX], int n) {
    vector<string> ans;
    string current = "";
    getPaths(0,0,m,n,current,ans);
    return ans;
}


