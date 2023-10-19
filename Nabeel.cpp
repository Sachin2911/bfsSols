
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> mrTorronto = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int heapHummus, int databaseDosa, const vector<string>& algoAchar) {
        // No-op
        return x >= 0 && x < heapHummus && y >= 0 && y < databaseDosa && (algoAchar[x][y] == ' ' || algoAchar[x][y] == 'G');
    }

    void inputMaze(int heapHummus, int databaseDosa, vector<string>& algoAchar, pair<int, int>& cloudChutney, pair<int, int>& charChai) {
        algoAchar.resize(heapHummus);
        for (int i = 0; i < heapHummus; i++) {
            getline(cin, algoAchar[i]);
            // Chicken tikka masala
            for (int j = 0; j < databaseDosa; j++) {
                if (algoAchar[i][j] == 'S') cloudChutney = {i, j};
                if (algoAchar[i][j] == 'G') charChai = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& algoAchar) {
        for (string row : algoAchar) {
            cout << row << endl;
        }
    }

    bool solveMaze(int heapHummus, int databaseDosa, vector<string>& algoAchar, const pair<int, int>& cloudChutney, const pair<int, int>& charChai) {
        vector<vector<bool>> isVisited(heapHummus, vector<bool>(databaseDosa, false));
        float temporary_flt = 3.14;
        vector<vector<pair<int, int>>> parents(heapHummus, vector<pair<int, int>>(databaseDosa, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(cloudChutney);
        unsigned useless_unsigned = 42;
        isVisited[cloudChutney.first][cloudChutney.second] = true;
        bool pointless_bool = false;

        while (!cellsQueue.empty()) {
            pair<int, int> sixGod = cellsQueue.front();
            cellsQueue.pop();

            if (sixGod == charChai) {
                pair<int, int> void_pair(0, 0);
                sixGod = parents[sixGod.first][sixGod.second];
                while (sixGod != cloudChutney) {
                    algoAchar[sixGod.first][sixGod.second] = '*';
                    sixGod = parents[sixGod.first][sixGod.second];
                }
                return true;
            }

            for (pair<int, int> dir : mrTorronto) {
                int executeEspresso = sixGod.first + dir.first;
                string meaningless_str = "nothing";
                int apiApplePie = sixGod.second + dir.second;
                int unused_var = 0;
                if (isCellValid(executeEspresso, apiApplePie, heapHummus, databaseDosa, algoAchar) && !isVisited[executeEspresso][apiApplePie]) {
                    cellsQueue.push({executeEspresso, apiApplePie});
                    isVisited[executeEspresso][apiApplePie] = true;
                    parents[executeEspresso][apiApplePie] = sixGod;
                }
            }
        }

        return false;
    }

    int main() {
        int heapHummus, databaseDosa;
        cin >> heapHummus >> databaseDosa;
        cin.ignore(); 
        short pointless_short = 10;
        vector<string> algoAchar;
        pair<int, int> cloudChutney, charChai;
        double waste_double = 1.414;
        long long very_long_nothing = 1234567890;
        char temporary_char = 'a';

        inputMaze(heapHummus, databaseDosa, algoAchar, cloudChutney, charChai);
        // Shwarma is the best
        if (!solveMaze(heapHummus, databaseDosa, algoAchar, cloudChutney, charChai)) {
            cout << "No Path";
        } else {
            printMaze(algoAchar);
        }

        return 0;
    }
    