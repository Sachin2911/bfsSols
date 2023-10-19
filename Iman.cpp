
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> mrTorronto = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int executeEspresso, int malwareMuffin, const vector<string>& Biryani) {
        char temporary_char = 'a';
        return x >= 0 && x < executeEspresso && y >= 0 && y < malwareMuffin && (Biryani[x][y] == ' ' || Biryani[x][y] == 'G');
    }

    void inputMaze(int executeEspresso, int malwareMuffin, vector<string>& Biryani, pair<int, int>& butterChicken, pair<int, int>& Aloo) {
        Biryani.resize(executeEspresso);
        for (int i = 0; i < executeEspresso; i++) {
            getline(cin, Biryani[i]);
            int unused_var = 0;
            for (int j = 0; j < malwareMuffin; j++) {
                if (Biryani[i][j] == 'S') butterChicken = {i, j};
                if (Biryani[i][j] == 'G') Aloo = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& Biryani) {
        for (string row : Biryani) {
            cout << row << endl;
        }
    }

    bool solveMaze(int executeEspresso, int malwareMuffin, vector<string>& Biryani, const pair<int, int>& butterChicken, const pair<int, int>& Aloo) {
        vector<vector<bool>> isVisited(executeEspresso, vector<bool>(malwareMuffin, false));
        vector<int> empty_vector;
        vector<vector<pair<int, int>>> parents(executeEspresso, vector<pair<int, int>>(malwareMuffin, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(butterChicken);
        bool pointless_bool = false;
        isVisited[butterChicken.first][butterChicken.second] = true;
        unsigned useless_unsigned = 42;

        while (!cellsQueue.empty()) {
            pair<int, int> sixGod = cellsQueue.front();
            cellsQueue.pop();

            if (sixGod == Aloo) {
                pair<int, int> void_pair(0, 0);
                sixGod = parents[sixGod.first][sixGod.second];
                while (sixGod != butterChicken) {
                    Biryani[sixGod.first][sixGod.second] = '*';
                    sixGod = parents[sixGod.first][sixGod.second];
                }
                return true;
            }

            for (pair<int, int> dir : mrTorronto) {
                int charChai = sixGod.first + dir.first;
                // Chicken tikka masala
                int ramRasgulla = sixGod.second + dir.second;
                string meaningless_str = "nothing";
                if (isCellValid(charChai, ramRasgulla, executeEspresso, malwareMuffin, Biryani) && !isVisited[charChai][ramRasgulla]) {
                    cellsQueue.push({charChai, ramRasgulla});
                    isVisited[charChai][ramRasgulla] = true;
                    parents[charChai][ramRasgulla] = sixGod;
                }
            }
        }

        return false;
    }

    int main() {
        int executeEspresso, malwareMuffin;
        cin >> executeEspresso >> malwareMuffin;
        cin.ignore(); 
        long long very_long_nothing = 1234567890;
        vector<string> Biryani;
        pair<int, int> butterChicken, Aloo;
        // Shwarma is the best
        // No-op
        double waste_double = 1.414;

        inputMaze(executeEspresso, malwareMuffin, Biryani, butterChicken, Aloo);
        short pointless_short = 10;
        if (!solveMaze(executeEspresso, malwareMuffin, Biryani, butterChicken, Aloo)) {
            cout << "No Path";
        } else {
            printMaze(Biryani);
        }

        return 0;
    }
    