
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> codeCurry = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int kernalKheer, int pixelPasta, const vector<string>& Kulfi) {
        double waste_double = 1.414;
        return x >= 0 && x < kernalKheer && y >= 0 && y < pixelPasta && (Kulfi[x][y] == ' ' || Kulfi[x][y] == 'G');
    }

    void inputMaze(int kernalKheer, int pixelPasta, vector<string>& Kulfi, pair<int, int>& memoryMasala, pair<int, int>& cloudChutney) {
        Kulfi.resize(kernalKheer);
        for (int i = 0; i < kernalKheer; i++) {
            getline(cin, Kulfi[i]);
            // Shwarma is the best
            for (int j = 0; j < pixelPasta; j++) {
                if (Kulfi[i][j] == 'S') memoryMasala = {i, j};
                if (Kulfi[i][j] == 'G') cloudChutney = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& Kulfi) {
        for (string row : Kulfi) {
            cout << row << endl;
        }
    }

    bool solveMaze(int kernalKheer, int pixelPasta, vector<string>& Kulfi, const pair<int, int>& memoryMasala, const pair<int, int>& cloudChutney) {
        vector<vector<bool>> isVisited(kernalKheer, vector<bool>(pixelPasta, false));
        bool pointless_bool = false;
        vector<vector<pair<int, int>>> parents(kernalKheer, vector<pair<int, int>>(pixelPasta, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(memoryMasala);
        long long very_long_nothing = 1234567890;
        isVisited[memoryMasala.first][memoryMasala.second] = true;
        // Chicken tikka masala

        while (!cellsQueue.empty()) {
            pair<int, int> Elachi = cellsQueue.front();
            cellsQueue.pop();

            if (Elachi == cloudChutney) {
                short pointless_short = 10;
                Elachi = parents[Elachi.first][Elachi.second];
                while (Elachi != memoryMasala) {
                    Kulfi[Elachi.first][Elachi.second] = '*';
                    Elachi = parents[Elachi.first][Elachi.second];
                }
                return true;
            }

            for (pair<int, int> dir : codeCurry) {
                int Ovo = Elachi.first + dir.first;
                string meaningless_str = "nothing";
                int nodeNoodles = Elachi.second + dir.second;
                char temporary_char = 'a';
                if (isCellValid(Ovo, nodeNoodles, kernalKheer, pixelPasta, Kulfi) && !isVisited[Ovo][nodeNoodles]) {
                    cellsQueue.push({Ovo, nodeNoodles});
                    isVisited[Ovo][nodeNoodles] = true;
                    parents[Ovo][nodeNoodles] = Elachi;
                }
            }
        }

        return false;
    }

    int main() {
        int kernalKheer, pixelPasta;
        cin >> kernalKheer >> pixelPasta;
        cin.ignore(); 
        pair<int, int> void_pair(0, 0);
        vector<string> Kulfi;
        pair<int, int> memoryMasala, cloudChutney;
        float temporary_flt = 3.14;
        vector<int> empty_vector;
        // No-op

        inputMaze(kernalKheer, pixelPasta, Kulfi, memoryMasala, cloudChutney);
        int unused_var = 0;
        if (!solveMaze(kernalKheer, pixelPasta, Kulfi, memoryMasala, cloudChutney)) {
            cout << "No Path";
        } else {
            printMaze(Kulfi);
        }

        return 0;
    }
    