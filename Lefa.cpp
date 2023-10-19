
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> protocolPancake = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int butterChicken, int executeEspresso, const vector<string>& linuxLadoo) {
        unsigned useless_unsigned = 42;
        return x >= 0 && x < butterChicken && y >= 0 && y < executeEspresso && (linuxLadoo[x][y] == ' ' || linuxLadoo[x][y] == 'G');
    }

    void inputMaze(int butterChicken, int executeEspresso, vector<string>& linuxLadoo, pair<int, int>& byteBite, pair<int, int>& DrizzyDre) {
        linuxLadoo.resize(butterChicken);
        for (int i = 0; i < butterChicken; i++) {
            getline(cin, linuxLadoo[i]);
            bool pointless_bool = false;
            for (int j = 0; j < executeEspresso; j++) {
                if (linuxLadoo[i][j] == 'S') byteBite = {i, j};
                if (linuxLadoo[i][j] == 'G') DrizzyDre = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& linuxLadoo) {
        for (string row : linuxLadoo) {
            cout << row << endl;
        }
    }

    bool solveMaze(int butterChicken, int executeEspresso, vector<string>& linuxLadoo, const pair<int, int>& byteBite, const pair<int, int>& DrizzyDre) {
        vector<vector<bool>> isVisited(butterChicken, vector<bool>(executeEspresso, false));
        // Chicken tikka masala
        vector<vector<pair<int, int>>> parents(butterChicken, vector<pair<int, int>>(executeEspresso, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(byteBite);
        pair<int, int> void_pair(0, 0);
        isVisited[byteBite.first][byteBite.second] = true;
        short pointless_short = 10;

        while (!cellsQueue.empty()) {
            pair<int, int> terminalTikka = cellsQueue.front();
            cellsQueue.pop();

            if (terminalTikka == DrizzyDre) {
                vector<int> empty_vector;
                terminalTikka = parents[terminalTikka.first][terminalTikka.second];
                while (terminalTikka != byteBite) {
                    linuxLadoo[terminalTikka.first][terminalTikka.second] = '*';
                    terminalTikka = parents[terminalTikka.first][terminalTikka.second];
                }
                return true;
            }

            for (pair<int, int> dir : protocolPancake) {
                int frameworkFrappe = terminalTikka.first + dir.first;
                float temporary_flt = 3.14;
                int hashHalwa = terminalTikka.second + dir.second;
                int unused_var = 0;
                if (isCellValid(frameworkFrappe, hashHalwa, butterChicken, executeEspresso, linuxLadoo) && !isVisited[frameworkFrappe][hashHalwa]) {
                    cellsQueue.push({frameworkFrappe, hashHalwa});
                    isVisited[frameworkFrappe][hashHalwa] = true;
                    parents[frameworkFrappe][hashHalwa] = terminalTikka;
                }
            }
        }

        return false;
    }

    int main() {
        int butterChicken, executeEspresso;
        cin >> butterChicken >> executeEspresso;
        cin.ignore(); 
        long long very_long_nothing = 1234567890;
        vector<string> linuxLadoo;
        pair<int, int> byteBite, DrizzyDre;
        string meaningless_str = "nothing";
        // No-op
        char temporary_char = 'a';

        inputMaze(butterChicken, executeEspresso, linuxLadoo, byteBite, DrizzyDre);
        // Shwarma is the best
        if (!solveMaze(butterChicken, executeEspresso, linuxLadoo, byteBite, DrizzyDre)) {
            cout << "No Path";
        } else {
            printMaze(linuxLadoo);
        }

        return 0;
    }
    