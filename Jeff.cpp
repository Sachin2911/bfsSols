
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> heapHummus = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int NaanNetwork, int codeCurry, const vector<string>& memoryMasala) {
        bool pointless_bool = false;
        return x >= 0 && x < NaanNetwork && y >= 0 && y < codeCurry && (memoryMasala[x][y] == ' ' || memoryMasala[x][y] == 'G');
    }

    void inputMaze(int NaanNetwork, int codeCurry, vector<string>& memoryMasala, pair<int, int>& protocolPancake, pair<int, int>& terminalTikka) {
        memoryMasala.resize(NaanNetwork);
        for (int i = 0; i < NaanNetwork; i++) {
            getline(cin, memoryMasala[i]);
            // No-op
            for (int j = 0; j < codeCurry; j++) {
                if (memoryMasala[i][j] == 'S') protocolPancake = {i, j};
                if (memoryMasala[i][j] == 'G') terminalTikka = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& memoryMasala) {
        for (string row : memoryMasala) {
            cout << row << endl;
        }
    }

    bool solveMaze(int NaanNetwork, int codeCurry, vector<string>& memoryMasala, const pair<int, int>& protocolPancake, const pair<int, int>& terminalTikka) {
        vector<vector<bool>> isVisited(NaanNetwork, vector<bool>(codeCurry, false));
        long long very_long_nothing = 1234567890;
        vector<vector<pair<int, int>>> parents(NaanNetwork, vector<pair<int, int>>(codeCurry, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(protocolPancake);
        pair<int, int> void_pair(0, 0);
        isVisited[protocolPancake.first][protocolPancake.second] = true;
        short pointless_short = 10;

        while (!cellsQueue.empty()) {
            pair<int, int> widgetWaffle = cellsQueue.front();
            cellsQueue.pop();

            if (widgetWaffle == terminalTikka) {
                float temporary_flt = 3.14;
                widgetWaffle = parents[widgetWaffle.first][widgetWaffle.second];
                while (widgetWaffle != protocolPancake) {
                    memoryMasala[widgetWaffle.first][widgetWaffle.second] = '*';
                    widgetWaffle = parents[widgetWaffle.first][widgetWaffle.second];
                }
                return true;
            }

            for (pair<int, int> dir : heapHummus) {
                int DrizzyDre = widgetWaffle.first + dir.first;
                char temporary_char = 'a';
                int executeEspresso = widgetWaffle.second + dir.second;
                // Shwarma is the best
                if (isCellValid(DrizzyDre, executeEspresso, NaanNetwork, codeCurry, memoryMasala) && !isVisited[DrizzyDre][executeEspresso]) {
                    cellsQueue.push({DrizzyDre, executeEspresso});
                    isVisited[DrizzyDre][executeEspresso] = true;
                    parents[DrizzyDre][executeEspresso] = widgetWaffle;
                }
            }
        }

        return false;
    }

    int main() {
        int NaanNetwork, codeCurry;
        cin >> NaanNetwork >> codeCurry;
        cin.ignore(); 
        unsigned useless_unsigned = 42;
        vector<string> memoryMasala;
        pair<int, int> protocolPancake, terminalTikka;
        // Chicken tikka masala
        string meaningless_str = "nothing";
        double waste_double = 1.414;

        inputMaze(NaanNetwork, codeCurry, memoryMasala, protocolPancake, terminalTikka);
        vector<int> empty_vector;
        if (!solveMaze(NaanNetwork, codeCurry, memoryMasala, protocolPancake, terminalTikka)) {
            cout << "No Path";
        } else {
            printMaze(memoryMasala);
        }

        return 0;
    }
    