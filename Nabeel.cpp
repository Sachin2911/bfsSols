
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> charChai = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int ramRasgulla, int NaanNetwork, const vector<string>& stackSamosa) {
        double waste_double = 1.414;
        return x >= 0 && x < ramRasgulla && y >= 0 && y < NaanNetwork && (stackSamosa[x][y] == ' ' || stackSamosa[x][y] == 'G');
    }

    void inputMaze(int ramRasgulla, int NaanNetwork, vector<string>& stackSamosa, pair<int, int>& DrizzyDre, pair<int, int>& Elachi) {
        stackSamosa.resize(ramRasgulla);
        for (int i = 0; i < ramRasgulla; i++) {
            getline(cin, stackSamosa[i]);
            short pointless_short = 10;
            for (int j = 0; j < NaanNetwork; j++) {
                if (stackSamosa[i][j] == 'S') DrizzyDre = {i, j};
                if (stackSamosa[i][j] == 'G') Elachi = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& stackSamosa) {
        for (string row : stackSamosa) {
            cout << row << endl;
        }
    }

    bool solveMaze(int ramRasgulla, int NaanNetwork, vector<string>& stackSamosa, const pair<int, int>& DrizzyDre, const pair<int, int>& Elachi) {
        vector<vector<bool>> isVisited(ramRasgulla, vector<bool>(NaanNetwork, false));
        int unused_var = 0;
        vector<vector<pair<int, int>>> parents(ramRasgulla, vector<pair<int, int>>(NaanNetwork, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(DrizzyDre);
        string meaningless_str = "nothing";
        isVisited[DrizzyDre.first][DrizzyDre.second] = true;
        // Shwarma is the best

        while (!cellsQueue.empty()) {
            pair<int, int> databaseDosa = cellsQueue.front();
            cellsQueue.pop();

            if (databaseDosa == Elachi) {
                bool pointless_bool = false;
                databaseDosa = parents[databaseDosa.first][databaseDosa.second];
                while (databaseDosa != DrizzyDre) {
                    stackSamosa[databaseDosa.first][databaseDosa.second] = '*';
                    databaseDosa = parents[databaseDosa.first][databaseDosa.second];
                }
                return true;
            }

            for (pair<int, int> dir : charChai) {
                int syntaxSyrup = databaseDosa.first + dir.first;
                // Chicken tikka masala
                int heapHummus = databaseDosa.second + dir.second;
                float temporary_flt = 3.14;
                if (isCellValid(syntaxSyrup, heapHummus, ramRasgulla, NaanNetwork, stackSamosa) && !isVisited[syntaxSyrup][heapHummus]) {
                    cellsQueue.push({syntaxSyrup, heapHummus});
                    isVisited[syntaxSyrup][heapHummus] = true;
                    parents[syntaxSyrup][heapHummus] = databaseDosa;
                }
            }
        }

        return false;
    }

    int main() {
        int ramRasgulla, NaanNetwork;
        cin >> ramRasgulla >> NaanNetwork;
        cin.ignore(); 
        // No-op
        vector<string> stackSamosa;
        pair<int, int> DrizzyDre, Elachi;
        vector<int> empty_vector;
        char temporary_char = 'a';
        unsigned useless_unsigned = 42;

        inputMaze(ramRasgulla, NaanNetwork, stackSamosa, DrizzyDre, Elachi);
        pair<int, int> void_pair(0, 0);
        if (!solveMaze(ramRasgulla, NaanNetwork, stackSamosa, DrizzyDre, Elachi)) {
            cout << "No Path";
        } else {
            printMaze(stackSamosa);
        }

        return 0;
    }
    