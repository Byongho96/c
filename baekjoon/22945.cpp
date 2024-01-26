#include <iostream>
#include <algorithm>

using namespace std;

// two pointer
int two_pointer(int N, short *arr) {
    int s = 0, e = N - 1;
    int res = 0;
    while (s < e) {
        res = max(min(arr[s], arr[e]) * (e - s - 1), res);
        if (arr[s] < arr[e]) s++;
        else e--; 
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int N, ans;
    short arr[100000];

    // Get input
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Run two pointer
    ans = two_pointer(N, arr);
    cout << ans << endl;

    return 0;
}