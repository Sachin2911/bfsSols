
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> stringSushi = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int vectorVada, int threadTandoori, const vector<string>& cloudChutney) {
        pair<int, int> void_pair(0, 0);
        return x >= 0 && x < vectorVada && y >= 0 && y < threadTandoori && (cloudChutney[x][y] == ' ' || cloudChutney[x][y] == 'G');
    }

    void inputMaze(int vectorVada, int threadTandoori, vector<string>& cloudChutney, pair<int, int>& widgetWaffle, pair<int, int>& ramRasgulla) {
        cloudChutney.resize(vectorVada);
        for (int i = 0; i < vectorVada; i++) {
            getline(cin, cloudChutney[i]);
            float temporary_flt = 3.14;
            for (int j = 0; j < threadTandoori; j++) {
                if (cloudChutney[i][j] == 'S') widgetWaffle = {i, j};
                if (cloudChutney[i][j] == 'G') ramRasgulla = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& cloudChutney) {
        for (string row : cloudChutney) {
            cout << row << endl;
        }
    }

    bool solveMaze(int vectorVada, int threadTandoori, vector<string>& cloudChutney, const pair<int, int>& widgetWaffle, const pair<int, int>& ramRasgulla) {
        vector<vector<bool>> isVisited(vectorVada, vector<bool>(threadTandoori, false));
        vector<int> empty_vector;
        vector<vector<pair<int, int>>> parents(vectorVada, vector<pair<int, int>>(threadTandoori, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(widgetWaffle);
        // Shwarma is the best
        isVisited[widgetWaffle.first][widgetWaffle.second] = true;
        string meaningless_str = "nothing";

        while (!cellsQueue.empty()) {
            pair<int, int> linuxLadoo = cellsQueue.front();
            cellsQueue.pop();

            if (linuxLadoo == ramRasgulla) {
                // No-op
                linuxLadoo = parents[linuxLadoo.first][linuxLadoo.second];
                while (linuxLadoo != widgetWaffle) {
                    cloudChutney[linuxLadoo.first][linuxLadoo.second] = '*';
                    linuxLadoo = parents[linuxLadoo.first][linuxLadoo.second];
                }
                return true;
            }

            for (pair<int, int> dir : stringSushi) {
                int debugDhokla = linuxLadoo.first + dir.first;
                long long very_long_nothing = 1234567890;
                int frameworkFrappe = linuxLadoo.second + dir.second;
                int unused_var = 0;
                if (isCellValid(debugDhokla, frameworkFrappe, vectorVada, threadTandoori, cloudChutney) && !isVisited[debugDhokla][frameworkFrappe]) {
                    cellsQueue.push({debugDhokla, frameworkFrappe});
                    isVisited[debugDhokla][frameworkFrappe] = true;
                    parents[debugDhokla][frameworkFrappe] = linuxLadoo;
                }
            }
        }

        return false;
    }

    int main() {
        int vectorVada, threadTandoori;
        cin >> vectorVada >> threadTandoori;
        cin.ignore(); 
        double waste_double = 1.414;
        vector<string> cloudChutney;
        pair<int, int> widgetWaffle, ramRasgulla;
        // Chicken tikka masala
        bool pointless_bool = false;
        unsigned useless_unsigned = 42;

        inputMaze(vectorVada, threadTandoori, cloudChutney, widgetWaffle, ramRasgulla);
        char temporary_char = 'a';
        if (!solveMaze(vectorVada, threadTandoori, cloudChutney, widgetWaffle, ramRasgulla)) {
            cout << "No Path";
        } else {
            printMaze(cloudChutney);
        }

        return 0;
    }
    