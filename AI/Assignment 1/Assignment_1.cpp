#include <bits/stdc++.h>
using namespace std;

class BinaryGrid {
    int n, m;
    vector<vector<int>> grid;
    vector<vector<int>> visited;

    public:
    BinaryGrid(int n, int m) {
        this->n = n;
        this->m = m;

        vector<int> temp;
        int num;
        cout<<"Enter cells"<<endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>num;
                temp.push_back(num);
            }
            grid.push_back(temp);
            temp.clear();
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp.push_back(0);
            }
            visited.push_back(temp);
            temp.clear();
        }
    }

    int islandCount() {
        int count = 0;
        pair<int, int> directions[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] != 1) {
                    count++;
                    stack<vector<int>> s;
                    s.push({i, j});
                    visited[i][j] = 1;

                    while(!s.empty()) {
                        int currentn = s.top()[0];
                        int currentm = s.top()[1];
                        s.pop();

                        for (int i = 0; i < 4; i++) {
                            int newn = currentn + directions[i].first;
                            int newm = currentm + directions[i].second;
                            
                            if ((0 <= newn && newn < n) && (0 <= newm && newm < m)) {
                                if (grid[newn][newm] == 1 && visited[newn][newm] != 1) {
                                    s.push({newn, newm});
                                    visited[newn][newm] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

class BinaryMaze {
    vector<vector<int>> maze;
    vector<vector<int>> visited;
    int n, m;

    public:
    BinaryMaze(int n, int m) {
        this->n = n;
        this->m = m;
        
        vector<int> temp;
        int num;
        cout<<"Enter cells"<<endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>num;
                temp.push_back(num);
            }
            maze.push_back(temp);
            temp.clear();
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp.push_back(0);
            }
            visited.push_back(temp);
            temp.clear();
        }
    }

    int shortestPath(pair<int, int> source, pair<int, int> destination) {
        pair<int, int> directions[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<vector<int>> q;
        q.push({source.first, source.second, 0});
        visited[source.first][source.second] = 1;

        while (!q.empty()) {
            int currentn = q.front()[0];
            int currentm = q.front()[1];
            int distance = q.front()[2];
            q.pop();
            
            if (currentn == destination.first && currentm == destination.second) {
                return distance;
            }
            
            for (int i = 0; i < 4; i++) {
                int newn = currentn + directions[i].first;
                int newm = currentm + directions[i].second;
                
                if ((0 <= newn && newn < 9) && (0 <= newm && newm < 10)) {
                    if (maze[newn][newm] == 1 && visited[newn][newm] != 1) {
                        q.push({newn, newm, distance + 1});
                        visited[newn][newm] = 1;
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    int n, m;
    cout<<"Enter size of the matrix"<<endl;
    cin>>n>>m;

    int choice;
    while (true) {
        cout<<"MENU"<<endl;
        cout<<"1. DFS: Island Count"<<endl;
        cout<<"2. BFS: Binary Maze"<<endl;
        cout<<"3. Exit"<<endl;
        cin>>choice;

        switch(choice) {
            case 1: {
                BinaryGrid bg(n, m);
                cout<<bg.islandCount()<<endl;
                break;
            }

            case 2: {
                BinaryMaze bm(n, m);
                pair<int, int> source;
                cout<<"Enter source co-ordinates"<<endl;
                cin>>source.first>>source.second;
                pair<int, int> destination;
                cout<<"Enter destination co-ordinates"<<endl;
                cin>>destination.first>>destination.second;
                cout<<bm.shortestPath(source, destination)<<endl;
                break;
            }

            case 3: {
                exit(0);
            }

            default: {
                cout<<"Enter valid option"<<endl;
                break;
            }
        }
    }
}