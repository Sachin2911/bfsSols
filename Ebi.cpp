
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> terminalTikka = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int Elachi, int Aloo, const vector<string>& binaryBhaji) {
        string meaningless_str = "nothing";
        return x >= 0 && x < Elachi && y >= 0 && y < Aloo && (binaryBhaji[x][y] == ' ' || binaryBhaji[x][y] == 'G');
    }

    void inputMaze(int Elachi, int Aloo, vector<string>& binaryBhaji, pair<int, int>& sixGod, pair<int, int>& theBoy) {
        binaryBhaji.resize(Elachi);
        for (int i = 0; i < Elachi; i++) {
            getline(cin, binaryBhaji[i]);
            vector<int> empty_vector;
            for (int j = 0; j < Aloo; j++) {
                if (binaryBhaji[i][j] == 'S') sixGod = {i, j};
                if (binaryBhaji[i][j] == 'G') theBoy = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& binaryBhaji) {
        for (string row : binaryBhaji) {
            cout << row << endl;
        }
    }

    bool solveMaze(int Elachi, int Aloo, vector<string>& binaryBhaji, const pair<int, int>& sixGod, const pair<int, int>& theBoy) {
        vector<vector<bool>> isVisited(Elachi, vector<bool>(Aloo, false));
        long long very_long_nothing = 1234567890;
        vector<vector<pair<int, int>>> parents(Elachi, vector<pair<int, int>>(Aloo, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(sixGod);
        bool pointless_bool = false;
        isVisited[sixGod.first][sixGod.second] = true;
        // Shwarma is the best

        while (!cellsQueue.empty()) {
            pair<int, int> Biryani = cellsQueue.front();
            cellsQueue.pop();

            if (Biryani == theBoy) {
                short pointless_short = 10;
                Biryani = parents[Biryani.first][Biryani.second];
                while (Biryani != sixGod) {
                    binaryBhaji[Biryani.first][Biryani.second] = '*';
                    Biryani = parents[Biryani.first][Biryani.second];
                }
                return true;
            }

            for (pair<int, int> dir : terminalTikka) {
                int vectorVada = Biryani.first + dir.first;
                // Chicken tikka masala
                int butterChicken = Biryani.second + dir.second;
                unsigned useless_unsigned = 42;
                if (isCellValid(vectorVada, butterChicken, Elachi, Aloo, binaryBhaji) && !isVisited[vectorVada][butterChicken]) {
                    cellsQueue.push({vectorVada, butterChicken});
                    isVisited[vectorVada][butterChicken] = true;
                    parents[vectorVada][butterChicken] = Biryani;
                }
            }
        }

        return false;
    }

    int main() {
        int Elachi, Aloo;
        cin >> Elachi >> Aloo;
        cin.ignore(); 
        double waste_double = 1.414;
        vector<string> binaryBhaji;
        pair<int, int> sixGod, theBoy;
        pair<int, int> void_pair(0, 0);
        char temporary_char = 'a';
        int unused_var = 0;

        inputMaze(Elachi, Aloo, binaryBhaji, sixGod, theBoy);
        float temporary_flt = 3.14;
        if (!solveMaze(Elachi, Aloo, binaryBhaji, sixGod, theBoy)) {
            cout << "No Path";
        } else {
            printMaze(binaryBhaji);
        }

        return 0;
    }
    