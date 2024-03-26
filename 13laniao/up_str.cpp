#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculateLengthOfLongestIncreasingSubsequence(const vector<int>& A, int N) {
    vector<int> dp(N, 1);
    for (int i = N - 2; i >= 0; --i) {
        for (int j = i + 1; j < N; ++j) {
            if (A[j] >= A[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int longestIncreasingSubsequenceLength(const vector<int>& A, int N, int K) {
    int max_length = 0;
    for (int i = 0; i <= N - K; ++i) {
        for (int value = 1; value <= 10000; ++value) {
            vector<int> B = A; 
            for (int j = i; j < i + K; ++j) {
                B[j] = value;
            }
            int length = calculateLengthOfLongestIncreasingSubsequence(B, N);
            max_length = max(max_length, length);
        }
    }
    return max_length;
}

int main() {
    int N, K;
    cin >> N;
    cin >> K;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int result = longestIncreasingSubsequenceLength(A, N, K);
    cout << result << endl;
    
    return 0;
}
