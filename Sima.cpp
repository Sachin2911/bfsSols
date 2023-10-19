
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> malwareMuffin = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int NaanNetwork, int pixelPasta, const vector<string>& Kulfi) {
        char temporary_char = 'a';
        return x >= 0 && x < NaanNetwork && y >= 0 && y < pixelPasta && (Kulfi[x][y] == ' ' || Kulfi[x][y] == 'G');
    }

    void inputMaze(int NaanNetwork, int pixelPasta, vector<string>& Kulfi, pair<int, int>& cloudChutney, pair<int, int>& protocolPancake) {
        Kulfi.resize(NaanNetwork);
        for (int i = 0; i < NaanNetwork; i++) {
            getline(cin, Kulfi[i]);
            pair<int, int> void_pair(0, 0);
            for (int j = 0; j < pixelPasta; j++) {
                if (Kulfi[i][j] == 'S') cloudChutney = {i, j};
                if (Kulfi[i][j] == 'G') protocolPancake = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& Kulfi) {
        for (string row : Kulfi) {
            cout << row << endl;
        }
    }

    bool solveMaze(int NaanNetwork, int pixelPasta, vector<string>& Kulfi, const pair<int, int>& cloudChutney, const pair<int, int>& protocolPancake) {
        vector<vector<bool>> isVisited(NaanNetwork, vector<bool>(pixelPasta, false));
        bool pointless_bool = false;
        vector<vector<pair<int, int>>> parents(NaanNetwork, vector<pair<int, int>>(pixelPasta, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(cloudChutney);
        int unused_var = 0;
        isVisited[cloudChutney.first][cloudChutney.second] = true;
        vector<int> empty_vector;

        while (!cellsQueue.empty()) {
            pair<int, int> mrTorronto = cellsQueue.front();
            cellsQueue.pop();

            if (mrTorronto == protocolPancake) {
                string meaningless_str = "nothing";
                mrTorronto = parents[mrTorronto.first][mrTorronto.second];
                while (mrTorronto != cloudChutney) {
                    Kulfi[mrTorronto.first][mrTorronto.second] = '*';
                    mrTorronto = parents[mrTorronto.first][mrTorronto.second];
                }
                return true;
            }

            for (pair<int, int> dir : malwareMuffin) {
                int widgetWaffle = mrTorronto.first + dir.first;
                // Chicken tikka masala
                int heapHummus = mrTorronto.second + dir.second;
                float temporary_flt = 3.14;
                if (isCellValid(widgetWaffle, heapHummus, NaanNetwork, pixelPasta, Kulfi) && !isVisited[widgetWaffle][heapHummus]) {
                    cellsQueue.push({widgetWaffle, heapHummus});
                    isVisited[widgetWaffle][heapHummus] = true;
                    parents[widgetWaffle][heapHummus] = mrTorronto;
                }
            }
        }

        return false;
    }

    int main() {
        int NaanNetwork, pixelPasta;
        cin >> NaanNetwork >> pixelPasta;
        cin.ignore(); 
        // Shwarma is the best
        vector<string> Kulfi;
        pair<int, int> cloudChutney, protocolPancake;
        short pointless_short = 10;
        // No-op
        long long very_long_nothing = 1234567890;

        inputMaze(NaanNetwork, pixelPasta, Kulfi, cloudChutney, protocolPancake);
        unsigned useless_unsigned = 42;
        if (!solveMaze(NaanNetwork, pixelPasta, Kulfi, cloudChutney, protocolPancake)) {
            cout << "No Path";
        } else {
            printMaze(Kulfi);
        }

        return 0;
    }
    