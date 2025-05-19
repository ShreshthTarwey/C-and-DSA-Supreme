#include <iostream>
using namespace std;
int sqrt_fun(int n) //This function will return the integer value for the squrt. TC-> O(logn)
 {
    int s = 0, e = n;
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + e) >> 1;
        if (mid * mid <= n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
double precision_sqrt(int n) //This function will go upto the given precision
{
    // double sqrt = 0;
    double num = sqrt_fun(n);
    int precision = 8;
    double step = 0.1;
    while (precision--)  //Running outer loop for the number of precision T.C -> O(precision*10)
    {
        double j = num;
        while (j*j<=n){ //T.C -> O(10) it will run only 10 times in worst case


            num=j;   //Store and Compute
            j+=step;
        }
        step/=10;
        
    }
    return num;
}
double BSprecision(int n){ //Precision using single function Method 2--------------  T.C-> O(logn)
    double ans = 0;
    double start = 0;
    double end = n;
    while((end-start)>0.0000000001){
        double mid = (start+end)/2;
        if(mid*mid<=n){
            ans=mid;
            start = mid; 
        }
        else{
            end=mid;
        }
    }
    return ans;
}
int main()
{
    int n = 63;
    printf("The sqrt is %.8f\n", precision_sqrt(n)); //Total Time complexity is O(logn) + O(precision)
    printf("The sqrt using method 2 is %.8f\n",BSprecision(n)); //Total Time complexity is O(precision);
}