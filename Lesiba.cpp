
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> Biryani = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int vectorVada, int Aloo, const vector<string>& threadTandoori) {
        unsigned useless_unsigned = 42;
        return x >= 0 && x < vectorVada && y >= 0 && y < Aloo && (threadTandoori[x][y] == ' ' || threadTandoori[x][y] == 'G');
    }

    void inputMaze(int vectorVada, int Aloo, vector<string>& threadTandoori, pair<int, int>& byteBite, pair<int, int>& Paneer) {
        threadTandoori.resize(vectorVada);
        for (int i = 0; i < vectorVada; i++) {
            getline(cin, threadTandoori[i]);
            bool pointless_bool = false;
            for (int j = 0; j < Aloo; j++) {
                if (threadTandoori[i][j] == 'S') byteBite = {i, j};
                if (threadTandoori[i][j] == 'G') Paneer = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& threadTandoori) {
        for (string row : threadTandoori) {
            cout << row << endl;
        }
    }

    bool solveMaze(int vectorVada, int Aloo, vector<string>& threadTandoori, const pair<int, int>& byteBite, const pair<int, int>& Paneer) {
        vector<vector<bool>> isVisited(vectorVada, vector<bool>(Aloo, false));
        double waste_double = 1.414;
        vector<vector<pair<int, int>>> parents(vectorVada, vector<pair<int, int>>(Aloo, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(byteBite);
        long long very_long_nothing = 1234567890;
        isVisited[byteBite.first][byteBite.second] = true;
        string meaningless_str = "nothing";

        while (!cellsQueue.empty()) {
            pair<int, int> pixelPasta = cellsQueue.front();
            cellsQueue.pop();

            if (pixelPasta == Paneer) {
                pair<int, int> void_pair(0, 0);
                pixelPasta = parents[pixelPasta.first][pixelPasta.second];
                while (pixelPasta != byteBite) {
                    threadTandoori[pixelPasta.first][pixelPasta.second] = '*';
                    pixelPasta = parents[pixelPasta.first][pixelPasta.second];
                }
                return true;
            }

            for (pair<int, int> dir : Biryani) {
                int booleanBurger = pixelPasta.first + dir.first;
                // Chicken tikka masala
                int terminalTikka = pixelPasta.second + dir.second;
                float temporary_flt = 3.14;
                if (isCellValid(booleanBurger, terminalTikka, vectorVada, Aloo, threadTandoori) && !isVisited[booleanBurger][terminalTikka]) {
                    cellsQueue.push({booleanBurger, terminalTikka});
                    isVisited[booleanBurger][terminalTikka] = true;
                    parents[booleanBurger][terminalTikka] = pixelPasta;
                }
            }
        }

        return false;
    }

    int main() {
        int vectorVada, Aloo;
        cin >> vectorVada >> Aloo;
        cin.ignore(); 
        // No-op
        vector<string> threadTandoori;
        pair<int, int> byteBite, Paneer;
        // Shwarma is the best
        short pointless_short = 10;
        int unused_var = 0;

        inputMaze(vectorVada, Aloo, threadTandoori, byteBite, Paneer);
        char temporary_char = 'a';
        if (!solveMaze(vectorVada, Aloo, threadTandoori, byteBite, Paneer)) {
            cout << "No Path";
        } else {
            printMaze(threadTandoori);
        }

        return 0;
    }
    