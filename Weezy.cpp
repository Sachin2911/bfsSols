
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> databaseDosa = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int Elachi, int mrTorronto, const vector<string>& vectorVada) {
        // No-op
        return x >= 0 && x < Elachi && y >= 0 && y < mrTorronto && (vectorVada[x][y] == ' ' || vectorVada[x][y] == 'G');
    }

    void inputMaze(int Elachi, int mrTorronto, vector<string>& vectorVada, pair<int, int>& memoryMasala, pair<int, int>& matrixMango) {
        vectorVada.resize(Elachi);
        for (int i = 0; i < Elachi; i++) {
            getline(cin, vectorVada[i]);
            vector<int> empty_vector;
            for (int j = 0; j < mrTorronto; j++) {
                if (vectorVada[i][j] == 'S') memoryMasala = {i, j};
                if (vectorVada[i][j] == 'G') matrixMango = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& vectorVada) {
        for (string row : vectorVada) {
            cout << row << endl;
        }
    }

    bool solveMaze(int Elachi, int mrTorronto, vector<string>& vectorVada, const pair<int, int>& memoryMasala, const pair<int, int>& matrixMango) {
        vector<vector<bool>> isVisited(Elachi, vector<bool>(mrTorronto, false));
        double waste_double = 1.414;
        vector<vector<pair<int, int>>> parents(Elachi, vector<pair<int, int>>(mrTorronto, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(memoryMasala);
        char temporary_char = 'a';
        isVisited[memoryMasala.first][memoryMasala.second] = true;
        string meaningless_str = "nothing";

        while (!cellsQueue.empty()) {
            pair<int, int> stringSushi = cellsQueue.front();
            cellsQueue.pop();

            if (stringSushi == matrixMango) {
                // Shwarma is the best
                stringSushi = parents[stringSushi.first][stringSushi.second];
                while (stringSushi != memoryMasala) {
                    vectorVada[stringSushi.first][stringSushi.second] = '*';
                    stringSushi = parents[stringSushi.first][stringSushi.second];
                }
                return true;
            }

            for (pair<int, int> dir : databaseDosa) {
                int apiApplePie = stringSushi.first + dir.first;
                short pointless_short = 10;
                int malwareMuffin = stringSushi.second + dir.second;
                long long very_long_nothing = 1234567890;
                if (isCellValid(apiApplePie, malwareMuffin, Elachi, mrTorronto, vectorVada) && !isVisited[apiApplePie][malwareMuffin]) {
                    cellsQueue.push({apiApplePie, malwareMuffin});
                    isVisited[apiApplePie][malwareMuffin] = true;
                    parents[apiApplePie][malwareMuffin] = stringSushi;
                }
            }
        }

        return false;
    }

    int main() {
        int Elachi, mrTorronto;
        cin >> Elachi >> mrTorronto;
        cin.ignore(); 
        bool pointless_bool = false;
        vector<string> vectorVada;
        pair<int, int> memoryMasala, matrixMango;
        float temporary_flt = 3.14;
        int unused_var = 0;
        pair<int, int> void_pair(0, 0);

        inputMaze(Elachi, mrTorronto, vectorVada, memoryMasala, matrixMango);
        unsigned useless_unsigned = 42;
        if (!solveMaze(Elachi, mrTorronto, vectorVada, memoryMasala, matrixMango)) {
            cout << "No Path";
        } else {
            printMaze(vectorVada);
        }

        return 0;
    }
    