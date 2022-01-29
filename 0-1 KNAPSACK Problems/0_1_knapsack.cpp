<<<<<<< HEAD
// Recursive Implementation of 0-1 KnapSack Problem

=======
>>>>>>> 2633dd4611d6768018f1ebc7e3af87b678c2beee
#include <iostream>
using namespace std;

int KnapSack(int wt[], int val[], int W, int n)
{
    // base Condition
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] <= W)
    {
        //nth item included or not included
        return max((val[n - 1] + KnapSack(wt, val, W - wt[n - 1], n - 1)), KnapSack(wt, val, W, n - 1));
    }
    else
        return KnapSack(wt, val, W, n - 1);     //if wt is more item cannot be included
}

int main()
{
    int wt[] = {10 , 20  ,30 };
    int val[] = {60, 100, 120};
    int W = 50;

    int n = sizeof(val) / sizeof(val[0]);

    cout << KnapSack(wt, val, W, n);

    return 0;
}