
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> databaseDosa = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int Elachi, int sixGod, const vector<string>& NaanNetwork) {
        long long very_long_nothing = 1234567890;
        return x >= 0 && x < Elachi && y >= 0 && y < sixGod && (NaanNetwork[x][y] == ' ' || NaanNetwork[x][y] == 'G');
    }

    void inputMaze(int Elachi, int sixGod, vector<string>& NaanNetwork, pair<int, int>& codeCurry, pair<int, int>& algoAchar) {
        NaanNetwork.resize(Elachi);
        for (int i = 0; i < Elachi; i++) {
            getline(cin, NaanNetwork[i]);
            // Shwarma is the best
            for (int j = 0; j < sixGod; j++) {
                if (NaanNetwork[i][j] == 'S') codeCurry = {i, j};
                if (NaanNetwork[i][j] == 'G') algoAchar = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& NaanNetwork) {
        for (string row : NaanNetwork) {
            cout << row << endl;
        }
    }

    bool solveMaze(int Elachi, int sixGod, vector<string>& NaanNetwork, const pair<int, int>& codeCurry, const pair<int, int>& algoAchar) {
        vector<vector<bool>> isVisited(Elachi, vector<bool>(sixGod, false));
        short pointless_short = 10;
        vector<vector<pair<int, int>>> parents(Elachi, vector<pair<int, int>>(sixGod, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(codeCurry);
        double waste_double = 1.414;
        isVisited[codeCurry.first][codeCurry.second] = true;
        unsigned useless_unsigned = 42;

        while (!cellsQueue.empty()) {
            pair<int, int> malwareMuffin = cellsQueue.front();
            cellsQueue.pop();

            if (malwareMuffin == algoAchar) {
                char temporary_char = 'a';
                malwareMuffin = parents[malwareMuffin.first][malwareMuffin.second];
                while (malwareMuffin != codeCurry) {
                    NaanNetwork[malwareMuffin.first][malwareMuffin.second] = '*';
                    malwareMuffin = parents[malwareMuffin.first][malwareMuffin.second];
                }
                return true;
            }

            for (pair<int, int> dir : databaseDosa) {
                int theBoy = malwareMuffin.first + dir.first;
                // Chicken tikka masala
                int DrizzyDre = malwareMuffin.second + dir.second;
                vector<int> empty_vector;
                if (isCellValid(theBoy, DrizzyDre, Elachi, sixGod, NaanNetwork) && !isVisited[theBoy][DrizzyDre]) {
                    cellsQueue.push({theBoy, DrizzyDre});
                    isVisited[theBoy][DrizzyDre] = true;
                    parents[theBoy][DrizzyDre] = malwareMuffin;
                }
            }
        }

        return false;
    }

    int main() {
        int Elachi, sixGod;
        cin >> Elachi >> sixGod;
        cin.ignore(); 
        string meaningless_str = "nothing";
        vector<string> NaanNetwork;
        pair<int, int> codeCurry, algoAchar;
        pair<int, int> void_pair(0, 0);
        int unused_var = 0;
        // No-op

        inputMaze(Elachi, sixGod, NaanNetwork, codeCurry, algoAchar);
        float temporary_flt = 3.14;
        if (!solveMaze(Elachi, sixGod, NaanNetwork, codeCurry, algoAchar)) {
            cout << "No Path";
        } else {
            printMaze(NaanNetwork);
        }

        return 0;
    }
    