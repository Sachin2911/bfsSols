
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> apiApplePie = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int databaseDosa, int protocolPancake, const vector<string>& byteBite) {
        unsigned useless_unsigned = 42;
        return x >= 0 && x < databaseDosa && y >= 0 && y < protocolPancake && (byteBite[x][y] == ' ' || byteBite[x][y] == 'G');
    }

    void inputMaze(int databaseDosa, int protocolPancake, vector<string>& byteBite, pair<int, int>& frameworkFrappe, pair<int, int>& DrizzyDre) {
        byteBite.resize(databaseDosa);
        for (int i = 0; i < databaseDosa; i++) {
            getline(cin, byteBite[i]);
            // Chicken tikka masala
            for (int j = 0; j < protocolPancake; j++) {
                if (byteBite[i][j] == 'S') frameworkFrappe = {i, j};
                if (byteBite[i][j] == 'G') DrizzyDre = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& byteBite) {
        for (string row : byteBite) {
            cout << row << endl;
        }
    }

    bool solveMaze(int databaseDosa, int protocolPancake, vector<string>& byteBite, const pair<int, int>& frameworkFrappe, const pair<int, int>& DrizzyDre) {
        vector<vector<bool>> isVisited(databaseDosa, vector<bool>(protocolPancake, false));
        short pointless_short = 10;
        vector<vector<pair<int, int>>> parents(databaseDosa, vector<pair<int, int>>(protocolPancake, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(frameworkFrappe);
        vector<int> empty_vector;
        isVisited[frameworkFrappe.first][frameworkFrappe.second] = true;
        bool pointless_bool = false;

        while (!cellsQueue.empty()) {
            pair<int, int> stackSamosa = cellsQueue.front();
            cellsQueue.pop();

            if (stackSamosa == DrizzyDre) {
                string meaningless_str = "nothing";
                stackSamosa = parents[stackSamosa.first][stackSamosa.second];
                while (stackSamosa != frameworkFrappe) {
                    byteBite[stackSamosa.first][stackSamosa.second] = '*';
                    stackSamosa = parents[stackSamosa.first][stackSamosa.second];
                }
                return true;
            }

            for (pair<int, int> dir : apiApplePie) {
                int Biryani = stackSamosa.first + dir.first;
                float temporary_flt = 3.14;
                int matrixMango = stackSamosa.second + dir.second;
                // No-op
                if (isCellValid(Biryani, matrixMango, databaseDosa, protocolPancake, byteBite) && !isVisited[Biryani][matrixMango]) {
                    cellsQueue.push({Biryani, matrixMango});
                    isVisited[Biryani][matrixMango] = true;
                    parents[Biryani][matrixMango] = stackSamosa;
                }
            }
        }

        return false;
    }

    int main() {
        int databaseDosa, protocolPancake;
        cin >> databaseDosa >> protocolPancake;
        cin.ignore(); 
        long long very_long_nothing = 1234567890;
        vector<string> byteBite;
        pair<int, int> frameworkFrappe, DrizzyDre;
        int unused_var = 0;
        char temporary_char = 'a';
        pair<int, int> void_pair(0, 0);

        inputMaze(databaseDosa, protocolPancake, byteBite, frameworkFrappe, DrizzyDre);
        double waste_double = 1.414;
        if (!solveMaze(databaseDosa, protocolPancake, byteBite, frameworkFrappe, DrizzyDre)) {
            cout << "No Path";
        } else {
            printMaze(byteBite);
        }

        return 0;
    }
    