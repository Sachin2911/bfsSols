
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> threadTandoori = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int matrixMango, int frameworkFrappe, const vector<string>& protocolPancake) {
        unsigned useless_unsigned = 42;
        return x >= 0 && x < matrixMango && y >= 0 && y < frameworkFrappe && (protocolPancake[x][y] == ' ' || protocolPancake[x][y] == 'G');
    }

    void inputMaze(int matrixMango, int frameworkFrappe, vector<string>& protocolPancake, pair<int, int>& widgetWaffle, pair<int, int>& runtimeRoti) {
        protocolPancake.resize(matrixMango);
        for (int i = 0; i < matrixMango; i++) {
            getline(cin, protocolPancake[i]);
            pair<int, int> void_pair(0, 0);
            for (int j = 0; j < frameworkFrappe; j++) {
                if (protocolPancake[i][j] == 'S') widgetWaffle = {i, j};
                if (protocolPancake[i][j] == 'G') runtimeRoti = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& protocolPancake) {
        for (string row : protocolPancake) {
            cout << row << endl;
        }
    }

    bool solveMaze(int matrixMango, int frameworkFrappe, vector<string>& protocolPancake, const pair<int, int>& widgetWaffle, const pair<int, int>& runtimeRoti) {
        vector<vector<bool>> isVisited(matrixMango, vector<bool>(frameworkFrappe, false));
        double waste_double = 1.414;
        vector<vector<pair<int, int>>> parents(matrixMango, vector<pair<int, int>>(frameworkFrappe, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(widgetWaffle);
        int unused_var = 0;
        isVisited[widgetWaffle.first][widgetWaffle.second] = true;
        // Chicken tikka masala

        while (!cellsQueue.empty()) {
            pair<int, int> Aloo = cellsQueue.front();
            cellsQueue.pop();

            if (Aloo == runtimeRoti) {
                // Shwarma is the best
                Aloo = parents[Aloo.first][Aloo.second];
                while (Aloo != widgetWaffle) {
                    protocolPancake[Aloo.first][Aloo.second] = '*';
                    Aloo = parents[Aloo.first][Aloo.second];
                }
                return true;
            }

            for (pair<int, int> dir : threadTandoori) {
                int Paneer = Aloo.first + dir.first;
                short pointless_short = 10;
                int executeEspresso = Aloo.second + dir.second;
                char temporary_char = 'a';
                if (isCellValid(Paneer, executeEspresso, matrixMango, frameworkFrappe, protocolPancake) && !isVisited[Paneer][executeEspresso]) {
                    cellsQueue.push({Paneer, executeEspresso});
                    isVisited[Paneer][executeEspresso] = true;
                    parents[Paneer][executeEspresso] = Aloo;
                }
            }
        }

        return false;
    }

    int main() {
        int matrixMango, frameworkFrappe;
        cin >> matrixMango >> frameworkFrappe;
        cin.ignore(); 
        bool pointless_bool = false;
        vector<string> protocolPancake;
        pair<int, int> widgetWaffle, runtimeRoti;
        // No-op
        string meaningless_str = "nothing";
        long long very_long_nothing = 1234567890;

        inputMaze(matrixMango, frameworkFrappe, protocolPancake, widgetWaffle, runtimeRoti);
        float temporary_flt = 3.14;
        if (!solveMaze(matrixMango, frameworkFrappe, protocolPancake, widgetWaffle, runtimeRoti)) {
            cout << "No Path";
        } else {
            printMaze(protocolPancake);
        }

        return 0;
    }
    