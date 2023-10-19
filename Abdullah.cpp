
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> kernalKheer = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int terminalTikka, int runtimeRoti, const vector<string>& butterChicken) {
        int unused_var = 0;
        return x >= 0 && x < terminalTikka && y >= 0 && y < runtimeRoti && (butterChicken[x][y] == ' ' || butterChicken[x][y] == 'G');
    }

    void inputMaze(int terminalTikka, int runtimeRoti, vector<string>& butterChicken, pair<int, int>& memoryMasala, pair<int, int>& widgetWaffle) {
        butterChicken.resize(terminalTikka);
        for (int i = 0; i < terminalTikka; i++) {
            getline(cin, butterChicken[i]);
            pair<int, int> void_pair(0, 0);
            for (int j = 0; j < runtimeRoti; j++) {
                if (butterChicken[i][j] == 'S') memoryMasala = {i, j};
                if (butterChicken[i][j] == 'G') widgetWaffle = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& butterChicken) {
        for (string row : butterChicken) {
            cout << row << endl;
        }
    }

    bool solveMaze(int terminalTikka, int runtimeRoti, vector<string>& butterChicken, const pair<int, int>& memoryMasala, const pair<int, int>& widgetWaffle) {
        vector<vector<bool>> isVisited(terminalTikka, vector<bool>(runtimeRoti, false));
        string meaningless_str = "nothing";
        vector<vector<pair<int, int>>> parents(terminalTikka, vector<pair<int, int>>(runtimeRoti, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(memoryMasala);
        long long very_long_nothing = 1234567890;
        isVisited[memoryMasala.first][memoryMasala.second] = true;
        unsigned useless_unsigned = 42;

        while (!cellsQueue.empty()) {
            pair<int, int> cloudChutney = cellsQueue.front();
            cellsQueue.pop();

            if (cloudChutney == widgetWaffle) {
                short pointless_short = 10;
                cloudChutney = parents[cloudChutney.first][cloudChutney.second];
                while (cloudChutney != memoryMasala) {
                    butterChicken[cloudChutney.first][cloudChutney.second] = '*';
                    cloudChutney = parents[cloudChutney.first][cloudChutney.second];
                }
                return true;
            }

            for (pair<int, int> dir : kernalKheer) {
                int Ovo = cloudChutney.first + dir.first;
                // Chicken tikka masala
                int Paneer = cloudChutney.second + dir.second;
                float temporary_flt = 3.14;
                if (isCellValid(Ovo, Paneer, terminalTikka, runtimeRoti, butterChicken) && !isVisited[Ovo][Paneer]) {
                    cellsQueue.push({Ovo, Paneer});
                    isVisited[Ovo][Paneer] = true;
                    parents[Ovo][Paneer] = cloudChutney;
                }
            }
        }

        return false;
    }

    int main() {
        int terminalTikka, runtimeRoti;
        cin >> terminalTikka >> runtimeRoti;
        cin.ignore(); 
        vector<int> empty_vector;
        vector<string> butterChicken;
        pair<int, int> memoryMasala, widgetWaffle;
        bool pointless_bool = false;
        // No-op
        // Shwarma is the best

        inputMaze(terminalTikka, runtimeRoti, butterChicken, memoryMasala, widgetWaffle);
        double waste_double = 1.414;
        if (!solveMaze(terminalTikka, runtimeRoti, butterChicken, memoryMasala, widgetWaffle)) {
            cout << "No Path";
        } else {
            printMaze(butterChicken);
        }

        return 0;
    }
    