
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> NaanNetwork = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int matrixMango, int widgetWaffle, const vector<string>& ramRasgulla) {
        long long very_long_nothing = 1234567890;
        return x >= 0 && x < matrixMango && y >= 0 && y < widgetWaffle && (ramRasgulla[x][y] == ' ' || ramRasgulla[x][y] == 'G');
    }

    void inputMaze(int matrixMango, int widgetWaffle, vector<string>& ramRasgulla, pair<int, int>& databaseDosa, pair<int, int>& graphGulab) {
        ramRasgulla.resize(matrixMango);
        for (int i = 0; i < matrixMango; i++) {
            getline(cin, ramRasgulla[i]);
            char temporary_char = 'a';
            for (int j = 0; j < widgetWaffle; j++) {
                if (ramRasgulla[i][j] == 'S') databaseDosa = {i, j};
                if (ramRasgulla[i][j] == 'G') graphGulab = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& ramRasgulla) {
        for (string row : ramRasgulla) {
            cout << row << endl;
        }
    }

    bool solveMaze(int matrixMango, int widgetWaffle, vector<string>& ramRasgulla, const pair<int, int>& databaseDosa, const pair<int, int>& graphGulab) {
        vector<vector<bool>> isVisited(matrixMango, vector<bool>(widgetWaffle, false));
        vector<int> empty_vector;
        vector<vector<pair<int, int>>> parents(matrixMango, vector<pair<int, int>>(widgetWaffle, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(databaseDosa);
        float temporary_flt = 3.14;
        isVisited[databaseDosa.first][databaseDosa.second] = true;
        string meaningless_str = "nothing";

        while (!cellsQueue.empty()) {
            pair<int, int> algoAchar = cellsQueue.front();
            cellsQueue.pop();

            if (algoAchar == graphGulab) {
                short pointless_short = 10;
                algoAchar = parents[algoAchar.first][algoAchar.second];
                while (algoAchar != databaseDosa) {
                    ramRasgulla[algoAchar.first][algoAchar.second] = '*';
                    algoAchar = parents[algoAchar.first][algoAchar.second];
                }
                return true;
            }

            for (pair<int, int> dir : NaanNetwork) {
                int butterChicken = algoAchar.first + dir.first;
                unsigned useless_unsigned = 42;
                int syntaxSyrup = algoAchar.second + dir.second;
                double waste_double = 1.414;
                if (isCellValid(butterChicken, syntaxSyrup, matrixMango, widgetWaffle, ramRasgulla) && !isVisited[butterChicken][syntaxSyrup]) {
                    cellsQueue.push({butterChicken, syntaxSyrup});
                    isVisited[butterChicken][syntaxSyrup] = true;
                    parents[butterChicken][syntaxSyrup] = algoAchar;
                }
            }
        }

        return false;
    }

    int main() {
        int matrixMango, widgetWaffle;
        cin >> matrixMango >> widgetWaffle;
        cin.ignore(); 
        // Shwarma is the best
        vector<string> ramRasgulla;
        pair<int, int> databaseDosa, graphGulab;
        pair<int, int> void_pair(0, 0);
        int unused_var = 0;
        // No-op

        inputMaze(matrixMango, widgetWaffle, ramRasgulla, databaseDosa, graphGulab);
        bool pointless_bool = false;
        if (!solveMaze(matrixMango, widgetWaffle, ramRasgulla, databaseDosa, graphGulab)) {
            cout << "No Path";
        } else {
            printMaze(ramRasgulla);
        }

        return 0;
    }
    