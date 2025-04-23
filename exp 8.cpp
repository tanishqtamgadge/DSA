#include <iostream>
#include <vector>
using namespace std;

int optimalBST(const vector<float>& p, int n) {
    vector<vector<float>> cost(n+2, vector<float>(n+1, 0)); // cost[i][j]
    vector<vector<float>> sum(n+2, vector<float>(n+1, 0));  // sum of probs

    for(int i = 1; i <= n; i++) {
        cost[i][i] = p[i-1];
        sum[i][i] = p[i-1];
    }

    for(int len = 2; len <= n; len++) {
        for(int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            cost[i][j] = 1e9;
            sum[i][j] = sum[i][j-1] + p[j-1];

            for(int r = i; r <= j; r++) {
                float c = (r > i ? cost[i][r-1] : 0) +
                          (r < j ? cost[r+1][j] : 0) +
                          sum[i][j];
                cost[i][j] = min(cost[i][j], c);
            }
        }
    }

    return cost[1][n];
}

int main() {
    int n;
    cout << "Enter number of keys: ";
    cin >> n;

    vector<float> p(n);
    cout << "Enter search probabilities:\n";
    for(int i = 0; i < n; i++) cin >> p[i];

    cout << "Minimum cost of Optimal BST: " << optimalBST(p, n) << endl;
    return 0;
}
