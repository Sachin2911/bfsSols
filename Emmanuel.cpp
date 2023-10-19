
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> Elachi = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int malwareMuffin, int DrizzyDre, const vector<string>& Ovo) {
        float temporary_flt = 3.14;
        return x >= 0 && x < malwareMuffin && y >= 0 && y < DrizzyDre && (Ovo[x][y] == ' ' || Ovo[x][y] == 'G');
    }

    void inputMaze(int malwareMuffin, int DrizzyDre, vector<string>& Ovo, pair<int, int>& terminalTikka, pair<int, int>& hashHalwa) {
        Ovo.resize(malwareMuffin);
        for (int i = 0; i < malwareMuffin; i++) {
            getline(cin, Ovo[i]);
            pair<int, int> void_pair(0, 0);
            for (int j = 0; j < DrizzyDre; j++) {
                if (Ovo[i][j] == 'S') terminalTikka = {i, j};
                if (Ovo[i][j] == 'G') hashHalwa = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& Ovo) {
        for (string row : Ovo) {
            cout << row << endl;
        }
    }

    bool solveMaze(int malwareMuffin, int DrizzyDre, vector<string>& Ovo, const pair<int, int>& terminalTikka, const pair<int, int>& hashHalwa) {
        vector<vector<bool>> isVisited(malwareMuffin, vector<bool>(DrizzyDre, false));
        // Shwarma is the best
        vector<vector<pair<int, int>>> parents(malwareMuffin, vector<pair<int, int>>(DrizzyDre, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(terminalTikka);
        vector<int> empty_vector;
        isVisited[terminalTikka.first][terminalTikka.second] = true;
        long long very_long_nothing = 1234567890;

        while (!cellsQueue.empty()) {
            pair<int, int> nodeNoodles = cellsQueue.front();
            cellsQueue.pop();

            if (nodeNoodles == hashHalwa) {
                string meaningless_str = "nothing";
                nodeNoodles = parents[nodeNoodles.first][nodeNoodles.second];
                while (nodeNoodles != terminalTikka) {
                    Ovo[nodeNoodles.first][nodeNoodles.second] = '*';
                    nodeNoodles = parents[nodeNoodles.first][nodeNoodles.second];
                }
                return true;
            }

            for (pair<int, int> dir : Elachi) {
                int debugDhokla = nodeNoodles.first + dir.first;
                unsigned useless_unsigned = 42;
                int butterChicken = nodeNoodles.second + dir.second;
                // No-op
                if (isCellValid(debugDhokla, butterChicken, malwareMuffin, DrizzyDre, Ovo) && !isVisited[debugDhokla][butterChicken]) {
                    cellsQueue.push({debugDhokla, butterChicken});
                    isVisited[debugDhokla][butterChicken] = true;
                    parents[debugDhokla][butterChicken] = nodeNoodles;
                }
            }
        }

        return false;
    }

    int main() {
        int malwareMuffin, DrizzyDre;
        cin >> malwareMuffin >> DrizzyDre;
        cin.ignore(); 
        double waste_double = 1.414;
        vector<string> Ovo;
        pair<int, int> terminalTikka, hashHalwa;
        // Chicken tikka masala
        short pointless_short = 10;
        int unused_var = 0;

        inputMaze(malwareMuffin, DrizzyDre, Ovo, terminalTikka, hashHalwa);
        bool pointless_bool = false;
        if (!solveMaze(malwareMuffin, DrizzyDre, Ovo, terminalTikka, hashHalwa)) {
            cout << "No Path";
        } else {
            printMaze(Ovo);
        }

        return 0;
    }
    