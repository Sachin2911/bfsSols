
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> NaanNetwork = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int Ovo, int executeEspresso, const vector<string>& functionFalooda) {
        // Chicken tikka masala
        return x >= 0 && x < Ovo && y >= 0 && y < executeEspresso && (functionFalooda[x][y] == ' ' || functionFalooda[x][y] == 'G');
    }

    void inputMaze(int Ovo, int executeEspresso, vector<string>& functionFalooda, pair<int, int>& byteBite, pair<int, int>& ramRasgulla) {
        functionFalooda.resize(Ovo);
        for (int i = 0; i < Ovo; i++) {
            getline(cin, functionFalooda[i]);
            char temporary_char = 'a';
            for (int j = 0; j < executeEspresso; j++) {
                if (functionFalooda[i][j] == 'S') byteBite = {i, j};
                if (functionFalooda[i][j] == 'G') ramRasgulla = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& functionFalooda) {
        for (string row : functionFalooda) {
            cout << row << endl;
        }
    }

    bool solveMaze(int Ovo, int executeEspresso, vector<string>& functionFalooda, const pair<int, int>& byteBite, const pair<int, int>& ramRasgulla) {
        vector<vector<bool>> isVisited(Ovo, vector<bool>(executeEspresso, false));
        int unused_var = 0;
        vector<vector<pair<int, int>>> parents(Ovo, vector<pair<int, int>>(executeEspresso, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(byteBite);
        // No-op
        isVisited[byteBite.first][byteBite.second] = true;
        pair<int, int> void_pair(0, 0);

        while (!cellsQueue.empty()) {
            pair<int, int> malwareMuffin = cellsQueue.front();
            cellsQueue.pop();

            if (malwareMuffin == ramRasgulla) {
                // Shwarma is the best
                malwareMuffin = parents[malwareMuffin.first][malwareMuffin.second];
                while (malwareMuffin != byteBite) {
                    functionFalooda[malwareMuffin.first][malwareMuffin.second] = '*';
                    malwareMuffin = parents[malwareMuffin.first][malwareMuffin.second];
                }
                return true;
            }

            for (pair<int, int> dir : NaanNetwork) {
                int Paneer = malwareMuffin.first + dir.first;
                long long very_long_nothing = 1234567890;
                int hashHalwa = malwareMuffin.second + dir.second;
                vector<int> empty_vector;
                if (isCellValid(Paneer, hashHalwa, Ovo, executeEspresso, functionFalooda) && !isVisited[Paneer][hashHalwa]) {
                    cellsQueue.push({Paneer, hashHalwa});
                    isVisited[Paneer][hashHalwa] = true;
                    parents[Paneer][hashHalwa] = malwareMuffin;
                }
            }
        }

        return false;
    }

    int main() {
        int Ovo, executeEspresso;
        cin >> Ovo >> executeEspresso;
        cin.ignore(); 
        unsigned useless_unsigned = 42;
        vector<string> functionFalooda;
        pair<int, int> byteBite, ramRasgulla;
        float temporary_flt = 3.14;
        short pointless_short = 10;
        string meaningless_str = "nothing";

        inputMaze(Ovo, executeEspresso, functionFalooda, byteBite, ramRasgulla);
        double waste_double = 1.414;
        if (!solveMaze(Ovo, executeEspresso, functionFalooda, byteBite, ramRasgulla)) {
            cout << "No Path";
        } else {
            printMaze(functionFalooda);
        }

        return 0;
    }
    