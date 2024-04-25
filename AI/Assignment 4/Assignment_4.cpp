#include<bits/stdc++.h>
using namespace std;

class NQueens {
private:
    int N;
    vector<int> queens;

    bool isSafe(int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (queens[i] == col || abs(row - i) == abs(col - queens[i])) {
                return false;
            }
        }
        return true;
    }

    bool solveUtil(int row) {
        if (row == N) {
            return true;
        }

        for (int col = 0; col < N; ++col) {
            if (isSafe(row, col)) {
                queens[row] = col;
                if (solveUtil(row + 1)) {
                    return true;
                }
                queens[row] = -1;
            }
            cout<<"\n";
            printSolution();
        }

        return false;
    }

public:
    NQueens(int n) : N(n) {
        queens.resize(N, -1);
    }

    void solve() {
        if (solveUtil(0)) {
            cout << "Solution found:" << endl;
            printSolution();
        } else {
            cout << "No solution exists!" << endl;
        }
    }

    void printSolution() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (queens[i] == j) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    NQueens nQueens(n);
    nQueens.solve();

    return 0;
}
