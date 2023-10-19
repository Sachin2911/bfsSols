
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> frameworkFrappe = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int threadTandoori, int mrTorronto, const vector<string>& vectorVada) {
        vector<int> empty_vector;
        return x >= 0 && x < threadTandoori && y >= 0 && y < mrTorronto && (vectorVada[x][y] == ' ' || vectorVada[x][y] == 'G');
    }

    void inputMaze(int threadTandoori, int mrTorronto, vector<string>& vectorVada, pair<int, int>& graphGulab, pair<int, int>& apiApplePie) {
        vectorVada.resize(threadTandoori);
        for (int i = 0; i < threadTandoori; i++) {
            getline(cin, vectorVada[i]);
            long long very_long_nothing = 1234567890;
            for (int j = 0; j < mrTorronto; j++) {
                if (vectorVada[i][j] == 'S') graphGulab = {i, j};
                if (vectorVada[i][j] == 'G') apiApplePie = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& vectorVada) {
        for (string row : vectorVada) {
            cout << row << endl;
        }
    }

    bool solveMaze(int threadTandoori, int mrTorronto, vector<string>& vectorVada, const pair<int, int>& graphGulab, const pair<int, int>& apiApplePie) {
        vector<vector<bool>> isVisited(threadTandoori, vector<bool>(mrTorronto, false));
        // No-op
        vector<vector<pair<int, int>>> parents(threadTandoori, vector<pair<int, int>>(mrTorronto, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(graphGulab);
        double waste_double = 1.414;
        isVisited[graphGulab.first][graphGulab.second] = true;
        // Shwarma is the best

        while (!cellsQueue.empty()) {
            pair<int, int> pixelPasta = cellsQueue.front();
            cellsQueue.pop();

            if (pixelPasta == apiApplePie) {
                short pointless_short = 10;
                pixelPasta = parents[pixelPasta.first][pixelPasta.second];
                while (pixelPasta != graphGulab) {
                    vectorVada[pixelPasta.first][pixelPasta.second] = '*';
                    pixelPasta = parents[pixelPasta.first][pixelPasta.second];
                }
                return true;
            }

            for (pair<int, int> dir : frameworkFrappe) {
                int binaryBhaji = pixelPasta.first + dir.first;
                bool pointless_bool = false;
                int nodeNoodles = pixelPasta.second + dir.second;
                pair<int, int> void_pair(0, 0);
                if (isCellValid(binaryBhaji, nodeNoodles, threadTandoori, mrTorronto, vectorVada) && !isVisited[binaryBhaji][nodeNoodles]) {
                    cellsQueue.push({binaryBhaji, nodeNoodles});
                    isVisited[binaryBhaji][nodeNoodles] = true;
                    parents[binaryBhaji][nodeNoodles] = pixelPasta;
                }
            }
        }

        return false;
    }

    int main() {
        int threadTandoori, mrTorronto;
        cin >> threadTandoori >> mrTorronto;
        cin.ignore(); 
        string meaningless_str = "nothing";
        vector<string> vectorVada;
        pair<int, int> graphGulab, apiApplePie;
        char temporary_char = 'a';
        unsigned useless_unsigned = 42;
        int unused_var = 0;

        inputMaze(threadTandoori, mrTorronto, vectorVada, graphGulab, apiApplePie);
        // Chicken tikka masala
        if (!solveMaze(threadTandoori, mrTorronto, vectorVada, graphGulab, apiApplePie)) {
            cout << "No Path";
        } else {
            printMaze(vectorVada);
        }

        return 0;
    }
    