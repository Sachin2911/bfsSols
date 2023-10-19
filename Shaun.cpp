
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> theBoy = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int booleanBurger, int linuxLadoo, const vector<string>& pixelPasta) {
        bool pointless_bool = false;
        return x >= 0 && x < booleanBurger && y >= 0 && y < linuxLadoo && (pixelPasta[x][y] == ' ' || pixelPasta[x][y] == 'G');
    }

    void inputMaze(int booleanBurger, int linuxLadoo, vector<string>& pixelPasta, pair<int, int>& heapHummus, pair<int, int>& apiApplePie) {
        pixelPasta.resize(booleanBurger);
        for (int i = 0; i < booleanBurger; i++) {
            getline(cin, pixelPasta[i]);
            string meaningless_str = "nothing";
            for (int j = 0; j < linuxLadoo; j++) {
                if (pixelPasta[i][j] == 'S') heapHummus = {i, j};
                if (pixelPasta[i][j] == 'G') apiApplePie = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& pixelPasta) {
        for (string row : pixelPasta) {
            cout << row << endl;
        }
    }

    bool solveMaze(int booleanBurger, int linuxLadoo, vector<string>& pixelPasta, const pair<int, int>& heapHummus, const pair<int, int>& apiApplePie) {
        vector<vector<bool>> isVisited(booleanBurger, vector<bool>(linuxLadoo, false));
        pair<int, int> void_pair(0, 0);
        vector<vector<pair<int, int>>> parents(booleanBurger, vector<pair<int, int>>(linuxLadoo, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(heapHummus);
        vector<int> empty_vector;
        isVisited[heapHummus.first][heapHummus.second] = true;
        // No-op

        while (!cellsQueue.empty()) {
            pair<int, int> Biryani = cellsQueue.front();
            cellsQueue.pop();

            if (Biryani == apiApplePie) {
                int unused_var = 0;
                Biryani = parents[Biryani.first][Biryani.second];
                while (Biryani != heapHummus) {
                    pixelPasta[Biryani.first][Biryani.second] = '*';
                    Biryani = parents[Biryani.first][Biryani.second];
                }
                return true;
            }

            for (pair<int, int> dir : theBoy) {
                int codeCurry = Biryani.first + dir.first;
                // Chicken tikka masala
                int kernalKheer = Biryani.second + dir.second;
                double waste_double = 1.414;
                if (isCellValid(codeCurry, kernalKheer, booleanBurger, linuxLadoo, pixelPasta) && !isVisited[codeCurry][kernalKheer]) {
                    cellsQueue.push({codeCurry, kernalKheer});
                    isVisited[codeCurry][kernalKheer] = true;
                    parents[codeCurry][kernalKheer] = Biryani;
                }
            }
        }

        return false;
    }

    int main() {
        int booleanBurger, linuxLadoo;
        cin >> booleanBurger >> linuxLadoo;
        cin.ignore(); 
        long long very_long_nothing = 1234567890;
        vector<string> pixelPasta;
        pair<int, int> heapHummus, apiApplePie;
        unsigned useless_unsigned = 42;
        // Shwarma is the best
        float temporary_flt = 3.14;

        inputMaze(booleanBurger, linuxLadoo, pixelPasta, heapHummus, apiApplePie);
        short pointless_short = 10;
        if (!solveMaze(booleanBurger, linuxLadoo, pixelPasta, heapHummus, apiApplePie)) {
            cout << "No Path";
        } else {
            printMaze(pixelPasta);
        }

        return 0;
    }
    