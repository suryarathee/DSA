#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> T(N);       // Time required by each worker for a unit complexity laptop
    vector<int> F(M);       // Complexity of each laptop
    
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    for (int j = 0; j < M; j++) {
        cin >> F[j];
    }

    // dp array to track the time taken to complete up to the last worker on each laptop
    vector<long long> prev(M + 1, 0), curr(M + 1, 0);

    // Fill the dp array
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            curr[j + 1] = max(prev[j + 1], curr[j]) + static_cast<long long>(T[i]) * F[j];
        }
        swap(prev, curr);  // Move current row to previous row for the next worker iteration
    }

    // The answer is the time taken to complete the last worker's job on the last laptop
    cout << prev[M] << endl;

    return 0;
}