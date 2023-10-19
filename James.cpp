
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> loopLassi = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int Ovo, int Biryani, const vector<string>& Kulfi) {
        // No-op
        return x >= 0 && x < Ovo && y >= 0 && y < Biryani && (Kulfi[x][y] == ' ' || Kulfi[x][y] == 'G');
    }

    void inputMaze(int Ovo, int Biryani, vector<string>& Kulfi, pair<int, int>& linuxLadoo, pair<int, int>& stackSamosa) {
        Kulfi.resize(Ovo);
        for (int i = 0; i < Ovo; i++) {
            getline(cin, Kulfi[i]);
            bool pointless_bool = false;
            for (int j = 0; j < Biryani; j++) {
                if (Kulfi[i][j] == 'S') linuxLadoo = {i, j};
                if (Kulfi[i][j] == 'G') stackSamosa = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& Kulfi) {
        for (string row : Kulfi) {
            cout << row << endl;
        }
    }

    bool solveMaze(int Ovo, int Biryani, vector<string>& Kulfi, const pair<int, int>& linuxLadoo, const pair<int, int>& stackSamosa) {
        vector<vector<bool>> isVisited(Ovo, vector<bool>(Biryani, false));
        double waste_double = 1.414;
        vector<vector<pair<int, int>>> parents(Ovo, vector<pair<int, int>>(Biryani, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(linuxLadoo);
        int unused_var = 0;
        isVisited[linuxLadoo.first][linuxLadoo.second] = true;
        // Shwarma is the best

        while (!cellsQueue.empty()) {
            pair<int, int> executeEspresso = cellsQueue.front();
            cellsQueue.pop();

            if (executeEspresso == stackSamosa) {
                vector<int> empty_vector;
                executeEspresso = parents[executeEspresso.first][executeEspresso.second];
                while (executeEspresso != linuxLadoo) {
                    Kulfi[executeEspresso.first][executeEspresso.second] = '*';
                    executeEspresso = parents[executeEspresso.first][executeEspresso.second];
                }
                return true;
            }

            for (pair<int, int> dir : loopLassi) {
                int NaanNetwork = executeEspresso.first + dir.first;
                short pointless_short = 10;
                int threadTandoori = executeEspresso.second + dir.second;
                unsigned useless_unsigned = 42;
                if (isCellValid(NaanNetwork, threadTandoori, Ovo, Biryani, Kulfi) && !isVisited[NaanNetwork][threadTandoori]) {
                    cellsQueue.push({NaanNetwork, threadTandoori});
                    isVisited[NaanNetwork][threadTandoori] = true;
                    parents[NaanNetwork][threadTandoori] = executeEspresso;
                }
            }
        }

        return false;
    }

    int main() {
        int Ovo, Biryani;
        cin >> Ovo >> Biryani;
        cin.ignore(); 
        long long very_long_nothing = 1234567890;
        vector<string> Kulfi;
        pair<int, int> linuxLadoo, stackSamosa;
        string meaningless_str = "nothing";
        pair<int, int> void_pair(0, 0);
        float temporary_flt = 3.14;

        inputMaze(Ovo, Biryani, Kulfi, linuxLadoo, stackSamosa);
        char temporary_char = 'a';
        if (!solveMaze(Ovo, Biryani, Kulfi, linuxLadoo, stackSamosa)) {
            cout << "No Path";
        } else {
            printMaze(Kulfi);
        }

        return 0;
    }
    