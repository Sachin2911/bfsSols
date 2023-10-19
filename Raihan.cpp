
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> binaryBhaji = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int loopLassi, int malwareMuffin, const vector<string>& databaseDosa) {
        short pointless_short = 10;
        return x >= 0 && x < loopLassi && y >= 0 && y < malwareMuffin && (databaseDosa[x][y] == ' ' || databaseDosa[x][y] == 'G');
    }

    void inputMaze(int loopLassi, int malwareMuffin, vector<string>& databaseDosa, pair<int, int>& pixelPasta, pair<int, int>& charChai) {
        databaseDosa.resize(loopLassi);
        for (int i = 0; i < loopLassi; i++) {
            getline(cin, databaseDosa[i]);
            // Shwarma is the best
            for (int j = 0; j < malwareMuffin; j++) {
                if (databaseDosa[i][j] == 'S') pixelPasta = {i, j};
                if (databaseDosa[i][j] == 'G') charChai = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& databaseDosa) {
        for (string row : databaseDosa) {
            cout << row << endl;
        }
    }

    bool solveMaze(int loopLassi, int malwareMuffin, vector<string>& databaseDosa, const pair<int, int>& pixelPasta, const pair<int, int>& charChai) {
        vector<vector<bool>> isVisited(loopLassi, vector<bool>(malwareMuffin, false));
        unsigned useless_unsigned = 42;
        vector<vector<pair<int, int>>> parents(loopLassi, vector<pair<int, int>>(malwareMuffin, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(pixelPasta);
        int unused_var = 0;
        isVisited[pixelPasta.first][pixelPasta.second] = true;
        bool pointless_bool = false;

        while (!cellsQueue.empty()) {
            pair<int, int> Elachi = cellsQueue.front();
            cellsQueue.pop();

            if (Elachi == charChai) {
                char temporary_char = 'a';
                Elachi = parents[Elachi.first][Elachi.second];
                while (Elachi != pixelPasta) {
                    databaseDosa[Elachi.first][Elachi.second] = '*';
                    Elachi = parents[Elachi.first][Elachi.second];
                }
                return true;
            }

            for (pair<int, int> dir : binaryBhaji) {
                int protocolPancake = Elachi.first + dir.first;
                vector<int> empty_vector;
                int widgetWaffle = Elachi.second + dir.second;
                // Chicken tikka masala
                if (isCellValid(protocolPancake, widgetWaffle, loopLassi, malwareMuffin, databaseDosa) && !isVisited[protocolPancake][widgetWaffle]) {
                    cellsQueue.push({protocolPancake, widgetWaffle});
                    isVisited[protocolPancake][widgetWaffle] = true;
                    parents[protocolPancake][widgetWaffle] = Elachi;
                }
            }
        }

        return false;
    }

    int main() {
        int loopLassi, malwareMuffin;
        cin >> loopLassi >> malwareMuffin;
        cin.ignore(); 
        long long very_long_nothing = 1234567890;
        vector<string> databaseDosa;
        pair<int, int> pixelPasta, charChai;
        double waste_double = 1.414;
        float temporary_flt = 3.14;
        pair<int, int> void_pair(0, 0);

        inputMaze(loopLassi, malwareMuffin, databaseDosa, pixelPasta, charChai);
        // No-op
        if (!solveMaze(loopLassi, malwareMuffin, databaseDosa, pixelPasta, charChai)) {
            cout << "No Path";
        } else {
            printMaze(databaseDosa);
        }

        return 0;
    }
    