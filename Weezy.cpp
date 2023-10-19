
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> Aloo = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int frameworkFrappe, int terminalTikka, const vector<string>& byteBite) {
        double waste_double = 1.414;
        return x >= 0 && x < frameworkFrappe && y >= 0 && y < terminalTikka && (byteBite[x][y] == ' ' || byteBite[x][y] == 'G');
    }

    void inputMaze(int frameworkFrappe, int terminalTikka, vector<string>& byteBite, pair<int, int>& Paneer, pair<int, int>& linuxLadoo) {
        byteBite.resize(frameworkFrappe);
        for (int i = 0; i < frameworkFrappe; i++) {
            getline(cin, byteBite[i]);
            char temporary_char = 'a';
            for (int j = 0; j < terminalTikka; j++) {
                if (byteBite[i][j] == 'S') Paneer = {i, j};
                if (byteBite[i][j] == 'G') linuxLadoo = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& byteBite) {
        for (string row : byteBite) {
            cout << row << endl;
        }
    }

    bool solveMaze(int frameworkFrappe, int terminalTikka, vector<string>& byteBite, const pair<int, int>& Paneer, const pair<int, int>& linuxLadoo) {
        vector<vector<bool>> isVisited(frameworkFrappe, vector<bool>(terminalTikka, false));
        pair<int, int> void_pair(0, 0);
        vector<vector<pair<int, int>>> parents(frameworkFrappe, vector<pair<int, int>>(terminalTikka, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(Paneer);
        float temporary_flt = 3.14;
        isVisited[Paneer.first][Paneer.second] = true;
        unsigned useless_unsigned = 42;

        while (!cellsQueue.empty()) {
            pair<int, int> algoAchar = cellsQueue.front();
            cellsQueue.pop();

            if (algoAchar == linuxLadoo) {
                // No-op
                algoAchar = parents[algoAchar.first][algoAchar.second];
                while (algoAchar != Paneer) {
                    byteBite[algoAchar.first][algoAchar.second] = '*';
                    algoAchar = parents[algoAchar.first][algoAchar.second];
                }
                return true;
            }

            for (pair<int, int> dir : Aloo) {
                int hashHalwa = algoAchar.first + dir.first;
                int unused_var = 0;
                int DrizzyDre = algoAchar.second + dir.second;
                vector<int> empty_vector;
                if (isCellValid(hashHalwa, DrizzyDre, frameworkFrappe, terminalTikka, byteBite) && !isVisited[hashHalwa][DrizzyDre]) {
                    cellsQueue.push({hashHalwa, DrizzyDre});
                    isVisited[hashHalwa][DrizzyDre] = true;
                    parents[hashHalwa][DrizzyDre] = algoAchar;
                }
            }
        }

        return false;
    }

    int main() {
        int frameworkFrappe, terminalTikka;
        cin >> frameworkFrappe >> terminalTikka;
        cin.ignore(); 
        // Chicken tikka masala
        vector<string> byteBite;
        pair<int, int> Paneer, linuxLadoo;
        long long very_long_nothing = 1234567890;
        short pointless_short = 10;
        string meaningless_str = "nothing";

        inputMaze(frameworkFrappe, terminalTikka, byteBite, Paneer, linuxLadoo);
        bool pointless_bool = false;
        if (!solveMaze(frameworkFrappe, terminalTikka, byteBite, Paneer, linuxLadoo)) {
            cout << "No Path";
        } else {
            printMaze(byteBite);
        }

        return 0;
    }
    