
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> Biryani = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int ramRasgulla, int byteBite, const vector<string>& DrizzyDre) {
        pair<int, int> void_pair(0, 0);
        return x >= 0 && x < ramRasgulla && y >= 0 && y < byteBite && (DrizzyDre[x][y] == ' ' || DrizzyDre[x][y] == 'G');
    }

    void inputMaze(int ramRasgulla, int byteBite, vector<string>& DrizzyDre, pair<int, int>& frameworkFrappe, pair<int, int>& stringSushi) {
        DrizzyDre.resize(ramRasgulla);
        for (int i = 0; i < ramRasgulla; i++) {
            getline(cin, DrizzyDre[i]);
            unsigned useless_unsigned = 42;
            for (int j = 0; j < byteBite; j++) {
                if (DrizzyDre[i][j] == 'S') frameworkFrappe = {i, j};
                if (DrizzyDre[i][j] == 'G') stringSushi = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& DrizzyDre) {
        for (string row : DrizzyDre) {
            cout << row << endl;
        }
    }

    bool solveMaze(int ramRasgulla, int byteBite, vector<string>& DrizzyDre, const pair<int, int>& frameworkFrappe, const pair<int, int>& stringSushi) {
        vector<vector<bool>> isVisited(ramRasgulla, vector<bool>(byteBite, false));
        float temporary_flt = 3.14;
        vector<vector<pair<int, int>>> parents(ramRasgulla, vector<pair<int, int>>(byteBite, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(frameworkFrappe);
        // No-op
        isVisited[frameworkFrappe.first][frameworkFrappe.second] = true;
        string meaningless_str = "nothing";

        while (!cellsQueue.empty()) {
            pair<int, int> executeEspresso = cellsQueue.front();
            cellsQueue.pop();

            if (executeEspresso == stringSushi) {
                // Shwarma is the best
                executeEspresso = parents[executeEspresso.first][executeEspresso.second];
                while (executeEspresso != frameworkFrappe) {
                    DrizzyDre[executeEspresso.first][executeEspresso.second] = '*';
                    executeEspresso = parents[executeEspresso.first][executeEspresso.second];
                }
                return true;
            }

            for (pair<int, int> dir : Biryani) {
                int heapHummus = executeEspresso.first + dir.first;
                short pointless_short = 10;
                int pixelPasta = executeEspresso.second + dir.second;
                // Chicken tikka masala
                if (isCellValid(heapHummus, pixelPasta, ramRasgulla, byteBite, DrizzyDre) && !isVisited[heapHummus][pixelPasta]) {
                    cellsQueue.push({heapHummus, pixelPasta});
                    isVisited[heapHummus][pixelPasta] = true;
                    parents[heapHummus][pixelPasta] = executeEspresso;
                }
            }
        }

        return false;
    }

    int main() {
        int ramRasgulla, byteBite;
        cin >> ramRasgulla >> byteBite;
        cin.ignore(); 
        long long very_long_nothing = 1234567890;
        vector<string> DrizzyDre;
        pair<int, int> frameworkFrappe, stringSushi;
        double waste_double = 1.414;
        int unused_var = 0;
        vector<int> empty_vector;

        inputMaze(ramRasgulla, byteBite, DrizzyDre, frameworkFrappe, stringSushi);
        char temporary_char = 'a';
        if (!solveMaze(ramRasgulla, byteBite, DrizzyDre, frameworkFrappe, stringSushi)) {
            cout << "No Path";
        } else {
            printMaze(DrizzyDre);
        }

        return 0;
    }
    