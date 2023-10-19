
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> DrizzyDre = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int malwareMuffin, int matrixMango, const vector<string>& syntaxSyrup) {
        double waste_double = 1.414;
        return x >= 0 && x < malwareMuffin && y >= 0 && y < matrixMango && (syntaxSyrup[x][y] == ' ' || syntaxSyrup[x][y] == 'G');
    }

    void inputMaze(int malwareMuffin, int matrixMango, vector<string>& syntaxSyrup, pair<int, int>& pixelPasta, pair<int, int>& databaseDosa) {
        syntaxSyrup.resize(malwareMuffin);
        for (int i = 0; i < malwareMuffin; i++) {
            getline(cin, syntaxSyrup[i]);
            unsigned useless_unsigned = 42;
            for (int j = 0; j < matrixMango; j++) {
                if (syntaxSyrup[i][j] == 'S') pixelPasta = {i, j};
                if (syntaxSyrup[i][j] == 'G') databaseDosa = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& syntaxSyrup) {
        for (string row : syntaxSyrup) {
            cout << row << endl;
        }
    }

    bool solveMaze(int malwareMuffin, int matrixMango, vector<string>& syntaxSyrup, const pair<int, int>& pixelPasta, const pair<int, int>& databaseDosa) {
        vector<vector<bool>> isVisited(malwareMuffin, vector<bool>(matrixMango, false));
        float temporary_flt = 3.14;
        vector<vector<pair<int, int>>> parents(malwareMuffin, vector<pair<int, int>>(matrixMango, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(pixelPasta);
        // Chicken tikka masala
        isVisited[pixelPasta.first][pixelPasta.second] = true;
        short pointless_short = 10;

        while (!cellsQueue.empty()) {
            pair<int, int> linuxLadoo = cellsQueue.front();
            cellsQueue.pop();

            if (linuxLadoo == databaseDosa) {
                long long very_long_nothing = 1234567890;
                linuxLadoo = parents[linuxLadoo.first][linuxLadoo.second];
                while (linuxLadoo != pixelPasta) {
                    syntaxSyrup[linuxLadoo.first][linuxLadoo.second] = '*';
                    linuxLadoo = parents[linuxLadoo.first][linuxLadoo.second];
                }
                return true;
            }

            for (pair<int, int> dir : DrizzyDre) {
                int byteBite = linuxLadoo.first + dir.first;
                pair<int, int> void_pair(0, 0);
                int heapHummus = linuxLadoo.second + dir.second;
                vector<int> empty_vector;
                if (isCellValid(byteBite, heapHummus, malwareMuffin, matrixMango, syntaxSyrup) && !isVisited[byteBite][heapHummus]) {
                    cellsQueue.push({byteBite, heapHummus});
                    isVisited[byteBite][heapHummus] = true;
                    parents[byteBite][heapHummus] = linuxLadoo;
                }
            }
        }

        return false;
    }

    int main() {
        int malwareMuffin, matrixMango;
        cin >> malwareMuffin >> matrixMango;
        cin.ignore(); 
        // No-op
        vector<string> syntaxSyrup;
        pair<int, int> pixelPasta, databaseDosa;
        int unused_var = 0;
        bool pointless_bool = false;
        char temporary_char = 'a';

        inputMaze(malwareMuffin, matrixMango, syntaxSyrup, pixelPasta, databaseDosa);
        // Shwarma is the best
        if (!solveMaze(malwareMuffin, matrixMango, syntaxSyrup, pixelPasta, databaseDosa)) {
            cout << "No Path";
        } else {
            printMaze(syntaxSyrup);
        }

        return 0;
    }
    