// You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. 
// You task is to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box 
// if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. 
// Of course, you can rotate a box so that any side functions as its base.
// It is also allowable to use multiple instances of the same type of box. 
// You task is to complete the function maxHeight which returns the height of the highest possible stack so formed.

// Approach: DP, Variation of Longest Increasing Subsequence(LIS)
// 1) Generate all 3 rotations of all boxes. The size of rotation array becomes 3 times the size of the original array. 
//   For simplicity, we consider width as always smaller than or equal to depth.
// 2) Sort the above generated 3n boxes in decreasing order of base area.
// 3) After sorting the boxes, the problem is same as LIS with following optimal substructure property.
// MSH(i) = Maximum possible Stack Height with box i at top of stack
// MSH(i) = { Max ( MSH(j) ) + height(i) } where j < i and width(j) > width(i) and depth(j) > depth(i).
// If there is no such j then MSH(i) = height(i)
// 4) To get overall maximum height, we return max(MSH(i)) where 0 < i < n

// Time Complexity : O(n^2)
// Auxiliary Space: O(n)

class Box {
public:
    int l,w,h;
    Box(int l,int w,int h): l(l), w(w), h(h) {}
    int baseArea() {
        return l*w;
    }
};

/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/
int maxHeight(int height[],int width[],int length[],int n){
    vector<Box> boxes;
    for(int i=0;i<n;i++){
        vector<int> dim {height[i], width[i], length[i]};
        for(int i=1;i<=6;i++){
            boxes.push_back(Box(dim[0],dim[1],dim[2]));
            next_permutation(dim.begin(),dim.end());
        }
    }

    sort(boxes.begin(),boxes.end(),[&](Box b1, Box b2){
        return b1.baseArea() > b2.baseArea(); 
    });
    
    vector<int> dp(6*n);
    int maxHeight=0;
    for(int i=0;i<6*n;i++){
        dp[i]=boxes[i].h;
        for(int j=i-1;j>=0;j--){
            if(boxes[j].l>boxes[i].l&&boxes[j].w>boxes[i].w){
                dp[i]=max(dp[i],dp[j]+boxes[i].h);
            }
        }
        maxHeight=max(maxHeight,dp[i]);
   }
    
    return maxHeight;
}