// Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.​
// The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, 
// you are the last one remaining and survive.

// For example, if n = 5 and k = 2, then the safe position is 3. Firstly, the person at position 2 is killed, then person at position 4 is killed, then person at position 1 is killed. Finally, the person at position 5 is killed. So the person at position 3 survives.
// If n = 7 and k = 3, then the safe position is 4. The persons at positions 3, 6, 2, 7, 5, 1 are killed in order, and person at position 4 survives.

// Approach 1: Brute Force, O(n*k)

/***************************************************************************************************************************/

// Approach 2: Recursion, O(n)
// After the first person (kth from beginning) is killed, n-1 persons are left. 
// So we call josephus(n – 1, k) to get the position with n-1 persons. 
// But the position returned by josephus(n – 1, k) will consider the position starting from k%n + 1. 
// So, we must make adjustments to the position returned by josephus(n – 1, k).
// josephus(n, k) = (josephus(n - 1, k) + k-1) % n + 1
// josephus(1, k) = 1

/*You are required to complete this method */
int josephus(int n, int k){
    if(n==1) return 1;
    // After k dies, n-1 ppl left. Subgame(n-1) starts from k+1
    int pos = k + josephus(n-1,k);  
    return (pos-1)%n+1;
}
