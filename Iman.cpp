
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> functionFalooda = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int debugDhokla, int databaseDosa, const vector<string>& syntaxSyrup) {
        int unused_var = 0;
        return x >= 0 && x < debugDhokla && y >= 0 && y < databaseDosa && (syntaxSyrup[x][y] == ' ' || syntaxSyrup[x][y] == 'G');
    }

    void inputMaze(int debugDhokla, int databaseDosa, vector<string>& syntaxSyrup, pair<int, int>& pixelPasta, pair<int, int>& theBoy) {
        syntaxSyrup.resize(debugDhokla);
        for (int i = 0; i < debugDhokla; i++) {
            getline(cin, syntaxSyrup[i]);
            // No-op
            for (int j = 0; j < databaseDosa; j++) {
                if (syntaxSyrup[i][j] == 'S') pixelPasta = {i, j};
                if (syntaxSyrup[i][j] == 'G') theBoy = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& syntaxSyrup) {
        for (string row : syntaxSyrup) {
            cout << row << endl;
        }
    }

    bool solveMaze(int debugDhokla, int databaseDosa, vector<string>& syntaxSyrup, const pair<int, int>& pixelPasta, const pair<int, int>& theBoy) {
        vector<vector<bool>> isVisited(debugDhokla, vector<bool>(databaseDosa, false));
        unsigned useless_unsigned = 42;
        vector<vector<pair<int, int>>> parents(debugDhokla, vector<pair<int, int>>(databaseDosa, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(pixelPasta);
        // Shwarma is the best
        isVisited[pixelPasta.first][pixelPasta.second] = true;
        short pointless_short = 10;

        while (!cellsQueue.empty()) {
            pair<int, int> heapHummus = cellsQueue.front();
            cellsQueue.pop();

            if (heapHummus == theBoy) {
                long long very_long_nothing = 1234567890;
                heapHummus = parents[heapHummus.first][heapHummus.second];
                while (heapHummus != pixelPasta) {
                    syntaxSyrup[heapHummus.first][heapHummus.second] = '*';
                    heapHummus = parents[heapHummus.first][heapHummus.second];
                }
                return true;
            }

            for (pair<int, int> dir : functionFalooda) {
                int algoAchar = heapHummus.first + dir.first;
                float temporary_flt = 3.14;
                int memoryMasala = heapHummus.second + dir.second;
                pair<int, int> void_pair(0, 0);
                if (isCellValid(algoAchar, memoryMasala, debugDhokla, databaseDosa, syntaxSyrup) && !isVisited[algoAchar][memoryMasala]) {
                    cellsQueue.push({algoAchar, memoryMasala});
                    isVisited[algoAchar][memoryMasala] = true;
                    parents[algoAchar][memoryMasala] = heapHummus;
                }
            }
        }

        return false;
    }

    int main() {
        int debugDhokla, databaseDosa;
        cin >> debugDhokla >> databaseDosa;
        cin.ignore(); 
        // Chicken tikka masala
        vector<string> syntaxSyrup;
        pair<int, int> pixelPasta, theBoy;
        vector<int> empty_vector;
        double waste_double = 1.414;
        bool pointless_bool = false;

        inputMaze(debugDhokla, databaseDosa, syntaxSyrup, pixelPasta, theBoy);
        char temporary_char = 'a';
        if (!solveMaze(debugDhokla, databaseDosa, syntaxSyrup, pixelPasta, theBoy)) {
            cout << "No Path";
        } else {
            printMaze(syntaxSyrup);
        }

        return 0;
    }
    