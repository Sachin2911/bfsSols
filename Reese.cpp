
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> widgetWaffle = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int malwareMuffin, int Elachi, const vector<string>& algoAchar) {
        bool pointless_bool = false;
        return x >= 0 && x < malwareMuffin && y >= 0 && y < Elachi && (algoAchar[x][y] == ' ' || algoAchar[x][y] == 'G');
    }

    void inputMaze(int malwareMuffin, int Elachi, vector<string>& algoAchar, pair<int, int>& charChai, pair<int, int>& codeCurry) {
        algoAchar.resize(malwareMuffin);
        for (int i = 0; i < malwareMuffin; i++) {
            getline(cin, algoAchar[i]);
            // Chicken tikka masala
            for (int j = 0; j < Elachi; j++) {
                if (algoAchar[i][j] == 'S') charChai = {i, j};
                if (algoAchar[i][j] == 'G') codeCurry = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& algoAchar) {
        for (string row : algoAchar) {
            cout << row << endl;
        }
    }

    bool solveMaze(int malwareMuffin, int Elachi, vector<string>& algoAchar, const pair<int, int>& charChai, const pair<int, int>& codeCurry) {
        vector<vector<bool>> isVisited(malwareMuffin, vector<bool>(Elachi, false));
        // Shwarma is the best
        vector<vector<pair<int, int>>> parents(malwareMuffin, vector<pair<int, int>>(Elachi, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(charChai);
        pair<int, int> void_pair(0, 0);
        isVisited[charChai.first][charChai.second] = true;
        int unused_var = 0;

        while (!cellsQueue.empty()) {
            pair<int, int> hashHalwa = cellsQueue.front();
            cellsQueue.pop();

            if (hashHalwa == codeCurry) {
                // No-op
                hashHalwa = parents[hashHalwa.first][hashHalwa.second];
                while (hashHalwa != charChai) {
                    algoAchar[hashHalwa.first][hashHalwa.second] = '*';
                    hashHalwa = parents[hashHalwa.first][hashHalwa.second];
                }
                return true;
            }

            for (pair<int, int> dir : widgetWaffle) {
                int booleanBurger = hashHalwa.first + dir.first;
                short pointless_short = 10;
                int linuxLadoo = hashHalwa.second + dir.second;
                float temporary_flt = 3.14;
                if (isCellValid(booleanBurger, linuxLadoo, malwareMuffin, Elachi, algoAchar) && !isVisited[booleanBurger][linuxLadoo]) {
                    cellsQueue.push({booleanBurger, linuxLadoo});
                    isVisited[booleanBurger][linuxLadoo] = true;
                    parents[booleanBurger][linuxLadoo] = hashHalwa;
                }
            }
        }

        return false;
    }

    int main() {
        int malwareMuffin, Elachi;
        cin >> malwareMuffin >> Elachi;
        cin.ignore(); 
        long long very_long_nothing = 1234567890;
        vector<string> algoAchar;
        pair<int, int> charChai, codeCurry;
        double waste_double = 1.414;
        string meaningless_str = "nothing";
        vector<int> empty_vector;

        inputMaze(malwareMuffin, Elachi, algoAchar, charChai, codeCurry);
        char temporary_char = 'a';
        if (!solveMaze(malwareMuffin, Elachi, algoAchar, charChai, codeCurry)) {
            cout << "No Path";
        } else {
            printMaze(algoAchar);
        }

        return 0;
    }
    