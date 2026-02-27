#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int q;
    cin>>q;

    //Brute force T.C-> O(q*range)

    // while(q--){
    //     int l,r;
    //     cin>>l>>r;
    //     int minNum = INT_MAX;
    //     for(int i=l;i<=r;i++){
    //         minNum = min(minNum, nums[i]);
    //     }
    //     cout<<minNum<<"\n";
    // }


    //Sparse Table, Square root decomposition
    int k = log2(n);
    vector<vector<int>>table(k+1, vector<int>(n));

    table[0] = nums;

    
}




// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n; cin >> n;
//     vector<int> nums(n);
//     for(int i = 0; i < n; i++) cin >> nums[i];

//     int q; cin >> q;
//     vector<int> chunks(sqrt(n) + 1, INT_MAX);
//     int len = sqrt(n);
//     for(int i = 0; i < n; i++) {
//         chunks[i / len] = min(chunks[i / len], nums[i]);
//     }

//     for(int i = 0; i < q; i++) {
//         int l, r; cin >> l >> r;
//         int ans = INT_MAX;
//         for(int j = l; j <= r; ) {
//             if(j + len < r && j % len == 0) {
//                 ans = min(ans, chunks[j / len]);
//                 j += len;
//             }else {
//                 ans = min(ans, nums[j]);
//                 j += 1;
//             }
//         }
//         cout << ans << "\n";
//     }
// }