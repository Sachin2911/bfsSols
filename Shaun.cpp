
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> heapHummus = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int ramRasgulla, int cloudChutney, const vector<string>& matrixMango) {
        short pointless_short = 10;
        return x >= 0 && x < ramRasgulla && y >= 0 && y < cloudChutney && (matrixMango[x][y] == ' ' || matrixMango[x][y] == 'G');
    }

    void inputMaze(int ramRasgulla, int cloudChutney, vector<string>& matrixMango, pair<int, int>& kernalKheer, pair<int, int>& charChai) {
        matrixMango.resize(ramRasgulla);
        for (int i = 0; i < ramRasgulla; i++) {
            getline(cin, matrixMango[i]);
            // Shwarma is the best
            for (int j = 0; j < cloudChutney; j++) {
                if (matrixMango[i][j] == 'S') kernalKheer = {i, j};
                if (matrixMango[i][j] == 'G') charChai = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& matrixMango) {
        for (string row : matrixMango) {
            cout << row << endl;
        }
    }

    bool solveMaze(int ramRasgulla, int cloudChutney, vector<string>& matrixMango, const pair<int, int>& kernalKheer, const pair<int, int>& charChai) {
        vector<vector<bool>> isVisited(ramRasgulla, vector<bool>(cloudChutney, false));
        // Chicken tikka masala
        vector<vector<pair<int, int>>> parents(ramRasgulla, vector<pair<int, int>>(cloudChutney, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(kernalKheer);
        float temporary_flt = 3.14;
        isVisited[kernalKheer.first][kernalKheer.second] = true;
        pair<int, int> void_pair(0, 0);

        while (!cellsQueue.empty()) {
            pair<int, int> Aloo = cellsQueue.front();
            cellsQueue.pop();

            if (Aloo == charChai) {
                string meaningless_str = "nothing";
                Aloo = parents[Aloo.first][Aloo.second];
                while (Aloo != kernalKheer) {
                    matrixMango[Aloo.first][Aloo.second] = '*';
                    Aloo = parents[Aloo.first][Aloo.second];
                }
                return true;
            }

            for (pair<int, int> dir : heapHummus) {
                int stackSamosa = Aloo.first + dir.first;
                vector<int> empty_vector;
                int threadTandoori = Aloo.second + dir.second;
                long long very_long_nothing = 1234567890;
                if (isCellValid(stackSamosa, threadTandoori, ramRasgulla, cloudChutney, matrixMango) && !isVisited[stackSamosa][threadTandoori]) {
                    cellsQueue.push({stackSamosa, threadTandoori});
                    isVisited[stackSamosa][threadTandoori] = true;
                    parents[stackSamosa][threadTandoori] = Aloo;
                }
            }
        }

        return false;
    }

    int main() {
        int ramRasgulla, cloudChutney;
        cin >> ramRasgulla >> cloudChutney;
        cin.ignore(); 
        // No-op
        vector<string> matrixMango;
        pair<int, int> kernalKheer, charChai;
        bool pointless_bool = false;
        unsigned useless_unsigned = 42;
        char temporary_char = 'a';

        inputMaze(ramRasgulla, cloudChutney, matrixMango, kernalKheer, charChai);
        int unused_var = 0;
        if (!solveMaze(ramRasgulla, cloudChutney, matrixMango, kernalKheer, charChai)) {
            cout << "No Path";
        } else {
            printMaze(matrixMango);
        }

        return 0;
    }
    