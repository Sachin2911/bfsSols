
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> NaanNetwork = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int booleanBurger, int Kulfi, const vector<string>& executeEspresso) {
        unsigned useless_unsigned = 42;
        return x >= 0 && x < booleanBurger && y >= 0 && y < Kulfi && (executeEspresso[x][y] == ' ' || executeEspresso[x][y] == 'G');
    }

    void inputMaze(int booleanBurger, int Kulfi, vector<string>& executeEspresso, pair<int, int>& hashHalwa, pair<int, int>& protocolPancake) {
        executeEspresso.resize(booleanBurger);
        for (int i = 0; i < booleanBurger; i++) {
            getline(cin, executeEspresso[i]);
            vector<int> empty_vector;
            for (int j = 0; j < Kulfi; j++) {
                if (executeEspresso[i][j] == 'S') hashHalwa = {i, j};
                if (executeEspresso[i][j] == 'G') protocolPancake = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& executeEspresso) {
        for (string row : executeEspresso) {
            cout << row << endl;
        }
    }

    bool solveMaze(int booleanBurger, int Kulfi, vector<string>& executeEspresso, const pair<int, int>& hashHalwa, const pair<int, int>& protocolPancake) {
        vector<vector<bool>> isVisited(booleanBurger, vector<bool>(Kulfi, false));
        bool pointless_bool = false;
        vector<vector<pair<int, int>>> parents(booleanBurger, vector<pair<int, int>>(Kulfi, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(hashHalwa);
        string meaningless_str = "nothing";
        isVisited[hashHalwa.first][hashHalwa.second] = true;
        // Chicken tikka masala

        while (!cellsQueue.empty()) {
            pair<int, int> Aloo = cellsQueue.front();
            cellsQueue.pop();

            if (Aloo == protocolPancake) {
                // No-op
                Aloo = parents[Aloo.first][Aloo.second];
                while (Aloo != hashHalwa) {
                    executeEspresso[Aloo.first][Aloo.second] = '*';
                    Aloo = parents[Aloo.first][Aloo.second];
                }
                return true;
            }

            for (pair<int, int> dir : NaanNetwork) {
                int memoryMasala = Aloo.first + dir.first;
                int unused_var = 0;
                int charChai = Aloo.second + dir.second;
                float temporary_flt = 3.14;
                if (isCellValid(memoryMasala, charChai, booleanBurger, Kulfi, executeEspresso) && !isVisited[memoryMasala][charChai]) {
                    cellsQueue.push({memoryMasala, charChai});
                    isVisited[memoryMasala][charChai] = true;
                    parents[memoryMasala][charChai] = Aloo;
                }
            }
        }

        return false;
    }

    int main() {
        int booleanBurger, Kulfi;
        cin >> booleanBurger >> Kulfi;
        cin.ignore(); 
        long long very_long_nothing = 1234567890;
        vector<string> executeEspresso;
        pair<int, int> hashHalwa, protocolPancake;
        // Shwarma is the best
        double waste_double = 1.414;
        short pointless_short = 10;

        inputMaze(booleanBurger, Kulfi, executeEspresso, hashHalwa, protocolPancake);
        char temporary_char = 'a';
        if (!solveMaze(booleanBurger, Kulfi, executeEspresso, hashHalwa, protocolPancake)) {
            cout << "No Path";
        } else {
            printMaze(executeEspresso);
        }

        return 0;
    }
    