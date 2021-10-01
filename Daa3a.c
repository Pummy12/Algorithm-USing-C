#include <stdio.h>
int sqrtSearch(int low, int high, int N)
{
 
    // If the range is still valid
    if (low <= high) {
 
        // Find the mid-value of the range
        int mid = (low + high) / 2;
 
        // Base Case
        if ((mid * mid <= N)
            && ((mid + 1) * (mid + 1) > N)) {
            return mid;
        }
 
        // Condition to check if the
        // left search space is useless
        else if (mid * mid < N) {
            return sqrtSearch(mid + 1, high, N);
        }
        else {
            return sqrtSearch(low, mid - 1, N);
        }
    }
    return low;
}
 
// Driver Code
int main()
{
    //int N = 25;
    int num;
    printf("ENTER THE NUMBER");
    scanf("%d",&num);
    printf("%d",sqrtSearch(0, num, num));
    return 0;
}