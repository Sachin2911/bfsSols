
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> matrixMango = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int booleanBurger, int ramRasgulla, const vector<string>& linuxLadoo) {
        // Shwarma is the best
        return x >= 0 && x < booleanBurger && y >= 0 && y < ramRasgulla && (linuxLadoo[x][y] == ' ' || linuxLadoo[x][y] == 'G');
    }

    void inputMaze(int booleanBurger, int ramRasgulla, vector<string>& linuxLadoo, pair<int, int>& hashHalwa, pair<int, int>& debugDhokla) {
        linuxLadoo.resize(booleanBurger);
        for (int i = 0; i < booleanBurger; i++) {
            getline(cin, linuxLadoo[i]);
            bool pointless_bool = false;
            for (int j = 0; j < ramRasgulla; j++) {
                if (linuxLadoo[i][j] == 'S') hashHalwa = {i, j};
                if (linuxLadoo[i][j] == 'G') debugDhokla = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& linuxLadoo) {
        for (string row : linuxLadoo) {
            cout << row << endl;
        }
    }

    bool solveMaze(int booleanBurger, int ramRasgulla, vector<string>& linuxLadoo, const pair<int, int>& hashHalwa, const pair<int, int>& debugDhokla) {
        vector<vector<bool>> isVisited(booleanBurger, vector<bool>(ramRasgulla, false));
        int unused_var = 0;
        vector<vector<pair<int, int>>> parents(booleanBurger, vector<pair<int, int>>(ramRasgulla, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(hashHalwa);
        // Chicken tikka masala
        isVisited[hashHalwa.first][hashHalwa.second] = true;
        // No-op

        while (!cellsQueue.empty()) {
            pair<int, int> Aloo = cellsQueue.front();
            cellsQueue.pop();

            if (Aloo == debugDhokla) {
                double waste_double = 1.414;
                Aloo = parents[Aloo.first][Aloo.second];
                while (Aloo != hashHalwa) {
                    linuxLadoo[Aloo.first][Aloo.second] = '*';
                    Aloo = parents[Aloo.first][Aloo.second];
                }
                return true;
            }

            for (pair<int, int> dir : matrixMango) {
                int pixelPasta = Aloo.first + dir.first;
                vector<int> empty_vector;
                int executeEspresso = Aloo.second + dir.second;
                pair<int, int> void_pair(0, 0);
                if (isCellValid(pixelPasta, executeEspresso, booleanBurger, ramRasgulla, linuxLadoo) && !isVisited[pixelPasta][executeEspresso]) {
                    cellsQueue.push({pixelPasta, executeEspresso});
                    isVisited[pixelPasta][executeEspresso] = true;
                    parents[pixelPasta][executeEspresso] = Aloo;
                }
            }
        }

        return false;
    }

    int main() {
        int booleanBurger, ramRasgulla;
        cin >> booleanBurger >> ramRasgulla;
        cin.ignore(); 
        unsigned useless_unsigned = 42;
        vector<string> linuxLadoo;
        pair<int, int> hashHalwa, debugDhokla;
        string meaningless_str = "nothing";
        short pointless_short = 10;
        float temporary_flt = 3.14;

        inputMaze(booleanBurger, ramRasgulla, linuxLadoo, hashHalwa, debugDhokla);
        char temporary_char = 'a';
        if (!solveMaze(booleanBurger, ramRasgulla, linuxLadoo, hashHalwa, debugDhokla)) {
            cout << "No Path";
        } else {
            printMaze(linuxLadoo);
        }

        return 0;
    }
    