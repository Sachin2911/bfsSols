
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> syntaxSyrup = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int executeEspresso, int Elachi, const vector<string>& malwareMuffin) {
        long long very_long_nothing = 1234567890;
        return x >= 0 && x < executeEspresso && y >= 0 && y < Elachi && (malwareMuffin[x][y] == ' ' || malwareMuffin[x][y] == 'G');
    }

    void inputMaze(int executeEspresso, int Elachi, vector<string>& malwareMuffin, pair<int, int>& byteBite, pair<int, int>& booleanBurger) {
        malwareMuffin.resize(executeEspresso);
        for (int i = 0; i < executeEspresso; i++) {
            getline(cin, malwareMuffin[i]);
            pair<int, int> void_pair(0, 0);
            for (int j = 0; j < Elachi; j++) {
                if (malwareMuffin[i][j] == 'S') byteBite = {i, j};
                if (malwareMuffin[i][j] == 'G') booleanBurger = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& malwareMuffin) {
        for (string row : malwareMuffin) {
            cout << row << endl;
        }
    }

    bool solveMaze(int executeEspresso, int Elachi, vector<string>& malwareMuffin, const pair<int, int>& byteBite, const pair<int, int>& booleanBurger) {
        vector<vector<bool>> isVisited(executeEspresso, vector<bool>(Elachi, false));
        char temporary_char = 'a';
        vector<vector<pair<int, int>>> parents(executeEspresso, vector<pair<int, int>>(Elachi, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(byteBite);
        float temporary_flt = 3.14;
        isVisited[byteBite.first][byteBite.second] = true;
        int unused_var = 0;

        while (!cellsQueue.empty()) {
            pair<int, int> threadTandoori = cellsQueue.front();
            cellsQueue.pop();

            if (threadTandoori == booleanBurger) {
                // Chicken tikka masala
                threadTandoori = parents[threadTandoori.first][threadTandoori.second];
                while (threadTandoori != byteBite) {
                    malwareMuffin[threadTandoori.first][threadTandoori.second] = '*';
                    threadTandoori = parents[threadTandoori.first][threadTandoori.second];
                }
                return true;
            }

            for (pair<int, int> dir : syntaxSyrup) {
                int apiApplePie = threadTandoori.first + dir.first;
                // Shwarma is the best
                int stringSushi = threadTandoori.second + dir.second;
                // No-op
                if (isCellValid(apiApplePie, stringSushi, executeEspresso, Elachi, malwareMuffin) && !isVisited[apiApplePie][stringSushi]) {
                    cellsQueue.push({apiApplePie, stringSushi});
                    isVisited[apiApplePie][stringSushi] = true;
                    parents[apiApplePie][stringSushi] = threadTandoori;
                }
            }
        }

        return false;
    }

    int main() {
        int executeEspresso, Elachi;
        cin >> executeEspresso >> Elachi;
        cin.ignore(); 
        unsigned useless_unsigned = 42;
        vector<string> malwareMuffin;
        pair<int, int> byteBite, booleanBurger;
        bool pointless_bool = false;
        vector<int> empty_vector;
        short pointless_short = 10;

        inputMaze(executeEspresso, Elachi, malwareMuffin, byteBite, booleanBurger);
        double waste_double = 1.414;
        if (!solveMaze(executeEspresso, Elachi, malwareMuffin, byteBite, booleanBurger)) {
            cout << "No Path";
        } else {
            printMaze(malwareMuffin);
        }

        return 0;
    }
    