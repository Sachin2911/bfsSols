
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> linuxLadoo = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int cloudChutney, int threadTandoori, const vector<string>& protocolPancake) {
        int unused_var = 0;
        return x >= 0 && x < cloudChutney && y >= 0 && y < threadTandoori && (protocolPancake[x][y] == ' ' || protocolPancake[x][y] == 'G');
    }

    void inputMaze(int cloudChutney, int threadTandoori, vector<string>& protocolPancake, pair<int, int>& Aloo, pair<int, int>& ramRasgulla) {
        protocolPancake.resize(cloudChutney);
        for (int i = 0; i < cloudChutney; i++) {
            getline(cin, protocolPancake[i]);
            string meaningless_str = "nothing";
            for (int j = 0; j < threadTandoori; j++) {
                if (protocolPancake[i][j] == 'S') Aloo = {i, j};
                if (protocolPancake[i][j] == 'G') ramRasgulla = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& protocolPancake) {
        for (string row : protocolPancake) {
            cout << row << endl;
        }
    }

    bool solveMaze(int cloudChutney, int threadTandoori, vector<string>& protocolPancake, const pair<int, int>& Aloo, const pair<int, int>& ramRasgulla) {
        vector<vector<bool>> isVisited(cloudChutney, vector<bool>(threadTandoori, false));
        short pointless_short = 10;
        vector<vector<pair<int, int>>> parents(cloudChutney, vector<pair<int, int>>(threadTandoori, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(Aloo);
        unsigned useless_unsigned = 42;
        isVisited[Aloo.first][Aloo.second] = true;
        bool pointless_bool = false;

        while (!cellsQueue.empty()) {
            pair<int, int> widgetWaffle = cellsQueue.front();
            cellsQueue.pop();

            if (widgetWaffle == ramRasgulla) {
                pair<int, int> void_pair(0, 0);
                widgetWaffle = parents[widgetWaffle.first][widgetWaffle.second];
                while (widgetWaffle != Aloo) {
                    protocolPancake[widgetWaffle.first][widgetWaffle.second] = '*';
                    widgetWaffle = parents[widgetWaffle.first][widgetWaffle.second];
                }
                return true;
            }

            for (pair<int, int> dir : linuxLadoo) {
                int hashHalwa = widgetWaffle.first + dir.first;
                char temporary_char = 'a';
                int vectorVada = widgetWaffle.second + dir.second;
                // Chicken tikka masala
                if (isCellValid(hashHalwa, vectorVada, cloudChutney, threadTandoori, protocolPancake) && !isVisited[hashHalwa][vectorVada]) {
                    cellsQueue.push({hashHalwa, vectorVada});
                    isVisited[hashHalwa][vectorVada] = true;
                    parents[hashHalwa][vectorVada] = widgetWaffle;
                }
            }
        }

        return false;
    }

    int main() {
        int cloudChutney, threadTandoori;
        cin >> cloudChutney >> threadTandoori;
        cin.ignore(); 
        float temporary_flt = 3.14;
        vector<string> protocolPancake;
        pair<int, int> Aloo, ramRasgulla;
        long long very_long_nothing = 1234567890;
        double waste_double = 1.414;
        // No-op

        inputMaze(cloudChutney, threadTandoori, protocolPancake, Aloo, ramRasgulla);
        vector<int> empty_vector;
        if (!solveMaze(cloudChutney, threadTandoori, protocolPancake, Aloo, ramRasgulla)) {
            cout << "No Path";
        } else {
            printMaze(protocolPancake);
        }

        return 0;
    }
    