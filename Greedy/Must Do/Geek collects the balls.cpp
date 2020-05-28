// There are two parallel roads, each containing N and M buckets, respectively. Each bucket may contain some balls. 
// The buckets on both roads are kept in such a way that they are sorted according to the number of balls in them. 
// Geek starts from the end of the road which has the bucket with a lower number of balls(i.e. if buckets are sorted in increasing order, then geek will start from the left side of the road).
// The geek can change the road only at the point of intersection(which means, buckets with the same number of balls on two roads). 
// Now you need to help Geek to collect the maximum number of balls.

// Example:
// Input:
// 1
// 5 5
// 1 4 5 6 8
// 2 3 4 6 9
// Output:
// 29

// Explanation:
// The path with maximum sum is (2,3,4)[5,6](9). Integers in [] are the buckets of first road and in () are the buckets of second road. So, max balls geek can collect is 29.

// Approach: Similar to merging 2 sorted arrays
// 1. Start withhead of both roads and find first common bucket. 
// 2. Keep track of sum of the buckets too while doing this and set head of result list based on greater sum till first common bucket.
// 3. After this till the current pointers of both roads don’t reach end of road, we need to adjust the next of prev pointers based on greater sum.
// This way it can be done in-place with constant extra space.
// Time complexity of the below solution is O(n).

#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n],b[m];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];
        
        int i=0,j=0;
        int sum1=0,sum2=0,ans=0;
        while(i<n&&j<m){
            if(a[i]<b[j]) sum1+=a[i++];
            else if(a[i]>b[j]) sum2+=b[j++];
            else {
                ans+=max(sum1,sum2);
                sum1=sum2=0;
                int temp=a[i];
                while(i<n&&a[i]==temp) sum1+=a[i++];
                while(j<m&&b[j]==temp) sum2+=b[j++];
                ans+=max(sum1,sum2);
                sum1=sum2=0;
            }
        }
        while(i<n) sum1+=a[i++];
        while(j<m) sum2+=b[j++];
        ans+=max(sum1,sum2);
        cout<<ans<<"\n";
    }
	return 0;
}
