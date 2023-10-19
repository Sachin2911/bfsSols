
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> heapHummus = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int memoryMasala, int frameworkFrappe, const vector<string>& runtimeRoti) {
        pair<int, int> void_pair(0, 0);
        return x >= 0 && x < memoryMasala && y >= 0 && y < frameworkFrappe && (runtimeRoti[x][y] == ' ' || runtimeRoti[x][y] == 'G');
    }

    void inputMaze(int memoryMasala, int frameworkFrappe, vector<string>& runtimeRoti, pair<int, int>& functionFalooda, pair<int, int>& stringSushi) {
        runtimeRoti.resize(memoryMasala);
        for (int i = 0; i < memoryMasala; i++) {
            getline(cin, runtimeRoti[i]);
            int unused_var = 0;
            for (int j = 0; j < frameworkFrappe; j++) {
                if (runtimeRoti[i][j] == 'S') functionFalooda = {i, j};
                if (runtimeRoti[i][j] == 'G') stringSushi = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& runtimeRoti) {
        for (string row : runtimeRoti) {
            cout << row << endl;
        }
    }

    bool solveMaze(int memoryMasala, int frameworkFrappe, vector<string>& runtimeRoti, const pair<int, int>& functionFalooda, const pair<int, int>& stringSushi) {
        vector<vector<bool>> isVisited(memoryMasala, vector<bool>(frameworkFrappe, false));
        string meaningless_str = "nothing";
        vector<vector<pair<int, int>>> parents(memoryMasala, vector<pair<int, int>>(frameworkFrappe, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(functionFalooda);
        // No-op
        isVisited[functionFalooda.first][functionFalooda.second] = true;
        // Chicken tikka masala

        while (!cellsQueue.empty()) {
            pair<int, int> databaseDosa = cellsQueue.front();
            cellsQueue.pop();

            if (databaseDosa == stringSushi) {
                bool pointless_bool = false;
                databaseDosa = parents[databaseDosa.first][databaseDosa.second];
                while (databaseDosa != functionFalooda) {
                    runtimeRoti[databaseDosa.first][databaseDosa.second] = '*';
                    databaseDosa = parents[databaseDosa.first][databaseDosa.second];
                }
                return true;
            }

            for (pair<int, int> dir : heapHummus) {
                int butterChicken = databaseDosa.first + dir.first;
                double waste_double = 1.414;
                int vectorVada = databaseDosa.second + dir.second;
                long long very_long_nothing = 1234567890;
                if (isCellValid(butterChicken, vectorVada, memoryMasala, frameworkFrappe, runtimeRoti) && !isVisited[butterChicken][vectorVada]) {
                    cellsQueue.push({butterChicken, vectorVada});
                    isVisited[butterChicken][vectorVada] = true;
                    parents[butterChicken][vectorVada] = databaseDosa;
                }
            }
        }

        return false;
    }

    int main() {
        int memoryMasala, frameworkFrappe;
        cin >> memoryMasala >> frameworkFrappe;
        cin.ignore(); 
        float temporary_flt = 3.14;
        vector<string> runtimeRoti;
        pair<int, int> functionFalooda, stringSushi;
        vector<int> empty_vector;
        unsigned useless_unsigned = 42;
        char temporary_char = 'a';

        inputMaze(memoryMasala, frameworkFrappe, runtimeRoti, functionFalooda, stringSushi);
        // Shwarma is the best
        if (!solveMaze(memoryMasala, frameworkFrappe, runtimeRoti, functionFalooda, stringSushi)) {
            cout << "No Path";
        } else {
            printMaze(runtimeRoti);
        }

        return 0;
    }
    