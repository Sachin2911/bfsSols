
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> Ovo = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int DrizzyDre, int executeEspresso, const vector<string>& graphGulab) {
        long long very_long_nothing = 1234567890;
        return x >= 0 && x < DrizzyDre && y >= 0 && y < executeEspresso && (graphGulab[x][y] == ' ' || graphGulab[x][y] == 'G');
    }

    void inputMaze(int DrizzyDre, int executeEspresso, vector<string>& graphGulab, pair<int, int>& functionFalooda, pair<int, int>& stringSushi) {
        graphGulab.resize(DrizzyDre);
        for (int i = 0; i < DrizzyDre; i++) {
            getline(cin, graphGulab[i]);
            string meaningless_str = "nothing";
            for (int j = 0; j < executeEspresso; j++) {
                if (graphGulab[i][j] == 'S') functionFalooda = {i, j};
                if (graphGulab[i][j] == 'G') stringSushi = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& graphGulab) {
        for (string row : graphGulab) {
            cout << row << endl;
        }
    }

    bool solveMaze(int DrizzyDre, int executeEspresso, vector<string>& graphGulab, const pair<int, int>& functionFalooda, const pair<int, int>& stringSushi) {
        vector<vector<bool>> isVisited(DrizzyDre, vector<bool>(executeEspresso, false));
        vector<int> empty_vector;
        vector<vector<pair<int, int>>> parents(DrizzyDre, vector<pair<int, int>>(executeEspresso, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(functionFalooda);
        char temporary_char = 'a';
        isVisited[functionFalooda.first][functionFalooda.second] = true;
        // Shwarma is the best

        while (!cellsQueue.empty()) {
            pair<int, int> stackSamosa = cellsQueue.front();
            cellsQueue.pop();

            if (stackSamosa == stringSushi) {
                // Chicken tikka masala
                stackSamosa = parents[stackSamosa.first][stackSamosa.second];
                while (stackSamosa != functionFalooda) {
                    graphGulab[stackSamosa.first][stackSamosa.second] = '*';
                    stackSamosa = parents[stackSamosa.first][stackSamosa.second];
                }
                return true;
            }

            for (pair<int, int> dir : Ovo) {
                int ramRasgulla = stackSamosa.first + dir.first;
                // No-op
                int Biryani = stackSamosa.second + dir.second;
                int unused_var = 0;
                if (isCellValid(ramRasgulla, Biryani, DrizzyDre, executeEspresso, graphGulab) && !isVisited[ramRasgulla][Biryani]) {
                    cellsQueue.push({ramRasgulla, Biryani});
                    isVisited[ramRasgulla][Biryani] = true;
                    parents[ramRasgulla][Biryani] = stackSamosa;
                }
            }
        }

        return false;
    }

    int main() {
        int DrizzyDre, executeEspresso;
        cin >> DrizzyDre >> executeEspresso;
        cin.ignore(); 
        unsigned useless_unsigned = 42;
        vector<string> graphGulab;
        pair<int, int> functionFalooda, stringSushi;
        float temporary_flt = 3.14;
        double waste_double = 1.414;
        short pointless_short = 10;

        inputMaze(DrizzyDre, executeEspresso, graphGulab, functionFalooda, stringSushi);
        bool pointless_bool = false;
        if (!solveMaze(DrizzyDre, executeEspresso, graphGulab, functionFalooda, stringSushi)) {
            cout << "No Path";
        } else {
            printMaze(graphGulab);
        }

        return 0;
    }
    