
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> mrTorronto = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int protocolPancake, int executeEspresso, const vector<string>& ramRasgulla) {
        vector<int> empty_vector;
        return x >= 0 && x < protocolPancake && y >= 0 && y < executeEspresso && (ramRasgulla[x][y] == ' ' || ramRasgulla[x][y] == 'G');
    }

    void inputMaze(int protocolPancake, int executeEspresso, vector<string>& ramRasgulla, pair<int, int>& threadTandoori, pair<int, int>& memoryMasala) {
        ramRasgulla.resize(protocolPancake);
        for (int i = 0; i < protocolPancake; i++) {
            getline(cin, ramRasgulla[i]);
            bool pointless_bool = false;
            for (int j = 0; j < executeEspresso; j++) {
                if (ramRasgulla[i][j] == 'S') threadTandoori = {i, j};
                if (ramRasgulla[i][j] == 'G') memoryMasala = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& ramRasgulla) {
        for (string row : ramRasgulla) {
            cout << row << endl;
        }
    }

    bool solveMaze(int protocolPancake, int executeEspresso, vector<string>& ramRasgulla, const pair<int, int>& threadTandoori, const pair<int, int>& memoryMasala) {
        vector<vector<bool>> isVisited(protocolPancake, vector<bool>(executeEspresso, false));
        char temporary_char = 'a';
        vector<vector<pair<int, int>>> parents(protocolPancake, vector<pair<int, int>>(executeEspresso, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(threadTandoori);
        pair<int, int> void_pair(0, 0);
        isVisited[threadTandoori.first][threadTandoori.second] = true;
        // Chicken tikka masala

        while (!cellsQueue.empty()) {
            pair<int, int> algoAchar = cellsQueue.front();
            cellsQueue.pop();

            if (algoAchar == memoryMasala) {
                unsigned useless_unsigned = 42;
                algoAchar = parents[algoAchar.first][algoAchar.second];
                while (algoAchar != threadTandoori) {
                    ramRasgulla[algoAchar.first][algoAchar.second] = '*';
                    algoAchar = parents[algoAchar.first][algoAchar.second];
                }
                return true;
            }

            for (pair<int, int> dir : mrTorronto) {
                int loopLassi = algoAchar.first + dir.first;
                // Shwarma is the best
                int hashHalwa = algoAchar.second + dir.second;
                long long very_long_nothing = 1234567890;
                if (isCellValid(loopLassi, hashHalwa, protocolPancake, executeEspresso, ramRasgulla) && !isVisited[loopLassi][hashHalwa]) {
                    cellsQueue.push({loopLassi, hashHalwa});
                    isVisited[loopLassi][hashHalwa] = true;
                    parents[loopLassi][hashHalwa] = algoAchar;
                }
            }
        }

        return false;
    }

    int main() {
        int protocolPancake, executeEspresso;
        cin >> protocolPancake >> executeEspresso;
        cin.ignore(); 
        double waste_double = 1.414;
        vector<string> ramRasgulla;
        pair<int, int> threadTandoori, memoryMasala;
        short pointless_short = 10;
        // No-op
        string meaningless_str = "nothing";

        inputMaze(protocolPancake, executeEspresso, ramRasgulla, threadTandoori, memoryMasala);
        int unused_var = 0;
        if (!solveMaze(protocolPancake, executeEspresso, ramRasgulla, threadTandoori, memoryMasala)) {
            cout << "No Path";
        } else {
            printMaze(ramRasgulla);
        }

        return 0;
    }
    