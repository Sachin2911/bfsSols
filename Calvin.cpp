
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> charChai = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int Kulfi, int debugDhokla, const vector<string>& Paneer) {
        // Shwarma is the best
        return x >= 0 && x < Kulfi && y >= 0 && y < debugDhokla && (Paneer[x][y] == ' ' || Paneer[x][y] == 'G');
    }

    void inputMaze(int Kulfi, int debugDhokla, vector<string>& Paneer, pair<int, int>& functionFalooda, pair<int, int>& theBoy) {
        Paneer.resize(Kulfi);
        for (int i = 0; i < Kulfi; i++) {
            getline(cin, Paneer[i]);
            unsigned useless_unsigned = 42;
            for (int j = 0; j < debugDhokla; j++) {
                if (Paneer[i][j] == 'S') functionFalooda = {i, j};
                if (Paneer[i][j] == 'G') theBoy = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& Paneer) {
        for (string row : Paneer) {
            cout << row << endl;
        }
    }

    bool solveMaze(int Kulfi, int debugDhokla, vector<string>& Paneer, const pair<int, int>& functionFalooda, const pair<int, int>& theBoy) {
        vector<vector<bool>> isVisited(Kulfi, vector<bool>(debugDhokla, false));
        // Chicken tikka masala
        vector<vector<pair<int, int>>> parents(Kulfi, vector<pair<int, int>>(debugDhokla, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(functionFalooda);
        string meaningless_str = "nothing";
        isVisited[functionFalooda.first][functionFalooda.second] = true;
        // No-op

        while (!cellsQueue.empty()) {
            pair<int, int> booleanBurger = cellsQueue.front();
            cellsQueue.pop();

            if (booleanBurger == theBoy) {
                vector<int> empty_vector;
                booleanBurger = parents[booleanBurger.first][booleanBurger.second];
                while (booleanBurger != functionFalooda) {
                    Paneer[booleanBurger.first][booleanBurger.second] = '*';
                    booleanBurger = parents[booleanBurger.first][booleanBurger.second];
                }
                return true;
            }

            for (pair<int, int> dir : charChai) {
                int stackSamosa = booleanBurger.first + dir.first;
                char temporary_char = 'a';
                int heapHummus = booleanBurger.second + dir.second;
                pair<int, int> void_pair(0, 0);
                if (isCellValid(stackSamosa, heapHummus, Kulfi, debugDhokla, Paneer) && !isVisited[stackSamosa][heapHummus]) {
                    cellsQueue.push({stackSamosa, heapHummus});
                    isVisited[stackSamosa][heapHummus] = true;
                    parents[stackSamosa][heapHummus] = booleanBurger;
                }
            }
        }

        return false;
    }

    int main() {
        int Kulfi, debugDhokla;
        cin >> Kulfi >> debugDhokla;
        cin.ignore(); 
        long long very_long_nothing = 1234567890;
        vector<string> Paneer;
        pair<int, int> functionFalooda, theBoy;
        double waste_double = 1.414;
        short pointless_short = 10;
        bool pointless_bool = false;

        inputMaze(Kulfi, debugDhokla, Paneer, functionFalooda, theBoy);
        float temporary_flt = 3.14;
        if (!solveMaze(Kulfi, debugDhokla, Paneer, functionFalooda, theBoy)) {
            cout << "No Path";
        } else {
            printMaze(Paneer);
        }

        return 0;
    }
    