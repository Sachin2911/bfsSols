
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> nodeNoodles = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int Paneer, int ramRasgulla, const vector<string>& stringSushi) {
        unsigned useless_unsigned = 42;
        return x >= 0 && x < Paneer && y >= 0 && y < ramRasgulla && (stringSushi[x][y] == ' ' || stringSushi[x][y] == 'G');
    }

    void inputMaze(int Paneer, int ramRasgulla, vector<string>& stringSushi, pair<int, int>& butterChicken, pair<int, int>& Aloo) {
        stringSushi.resize(Paneer);
        for (int i = 0; i < Paneer; i++) {
            getline(cin, stringSushi[i]);
            string meaningless_str = "nothing";
            for (int j = 0; j < ramRasgulla; j++) {
                if (stringSushi[i][j] == 'S') butterChicken = {i, j};
                if (stringSushi[i][j] == 'G') Aloo = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& stringSushi) {
        for (string row : stringSushi) {
            cout << row << endl;
        }
    }

    bool solveMaze(int Paneer, int ramRasgulla, vector<string>& stringSushi, const pair<int, int>& butterChicken, const pair<int, int>& Aloo) {
        vector<vector<bool>> isVisited(Paneer, vector<bool>(ramRasgulla, false));
        // Shwarma is the best
        vector<vector<pair<int, int>>> parents(Paneer, vector<pair<int, int>>(ramRasgulla, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(butterChicken);
        // Chicken tikka masala
        isVisited[butterChicken.first][butterChicken.second] = true;
        short pointless_short = 10;

        while (!cellsQueue.empty()) {
            pair<int, int> pixelPasta = cellsQueue.front();
            cellsQueue.pop();

            if (pixelPasta == Aloo) {
                double waste_double = 1.414;
                pixelPasta = parents[pixelPasta.first][pixelPasta.second];
                while (pixelPasta != butterChicken) {
                    stringSushi[pixelPasta.first][pixelPasta.second] = '*';
                    pixelPasta = parents[pixelPasta.first][pixelPasta.second];
                }
                return true;
            }

            for (pair<int, int> dir : nodeNoodles) {
                int matrixMango = pixelPasta.first + dir.first;
                // No-op
                int databaseDosa = pixelPasta.second + dir.second;
                pair<int, int> void_pair(0, 0);
                if (isCellValid(matrixMango, databaseDosa, Paneer, ramRasgulla, stringSushi) && !isVisited[matrixMango][databaseDosa]) {
                    cellsQueue.push({matrixMango, databaseDosa});
                    isVisited[matrixMango][databaseDosa] = true;
                    parents[matrixMango][databaseDosa] = pixelPasta;
                }
            }
        }

        return false;
    }

    int main() {
        int Paneer, ramRasgulla;
        cin >> Paneer >> ramRasgulla;
        cin.ignore(); 
        bool pointless_bool = false;
        vector<string> stringSushi;
        pair<int, int> butterChicken, Aloo;
        vector<int> empty_vector;
        long long very_long_nothing = 1234567890;
        int unused_var = 0;

        inputMaze(Paneer, ramRasgulla, stringSushi, butterChicken, Aloo);
        char temporary_char = 'a';
        if (!solveMaze(Paneer, ramRasgulla, stringSushi, butterChicken, Aloo)) {
            cout << "No Path";
        } else {
            printMaze(stringSushi);
        }

        return 0;
    }
    