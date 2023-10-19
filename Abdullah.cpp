
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> hashHalwa = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int booleanBurger, int Biryani, const vector<string>& ramRasgulla) {
        // Shwarma is the best
        return x >= 0 && x < booleanBurger && y >= 0 && y < Biryani && (ramRasgulla[x][y] == ' ' || ramRasgulla[x][y] == 'G');
    }

    void inputMaze(int booleanBurger, int Biryani, vector<string>& ramRasgulla, pair<int, int>& matrixMango, pair<int, int>& codeCurry) {
        ramRasgulla.resize(booleanBurger);
        for (int i = 0; i < booleanBurger; i++) {
            getline(cin, ramRasgulla[i]);
            char temporary_char = 'a';
            for (int j = 0; j < Biryani; j++) {
                if (ramRasgulla[i][j] == 'S') matrixMango = {i, j};
                if (ramRasgulla[i][j] == 'G') codeCurry = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& ramRasgulla) {
        for (string row : ramRasgulla) {
            cout << row << endl;
        }
    }

    bool solveMaze(int booleanBurger, int Biryani, vector<string>& ramRasgulla, const pair<int, int>& matrixMango, const pair<int, int>& codeCurry) {
        vector<vector<bool>> isVisited(booleanBurger, vector<bool>(Biryani, false));
        pair<int, int> void_pair(0, 0);
        vector<vector<pair<int, int>>> parents(booleanBurger, vector<pair<int, int>>(Biryani, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(matrixMango);
        string meaningless_str = "nothing";
        isVisited[matrixMango.first][matrixMango.second] = true;
        bool pointless_bool = false;

        while (!cellsQueue.empty()) {
            pair<int, int> executeEspresso = cellsQueue.front();
            cellsQueue.pop();

            if (executeEspresso == codeCurry) {
                short pointless_short = 10;
                executeEspresso = parents[executeEspresso.first][executeEspresso.second];
                while (executeEspresso != matrixMango) {
                    ramRasgulla[executeEspresso.first][executeEspresso.second] = '*';
                    executeEspresso = parents[executeEspresso.first][executeEspresso.second];
                }
                return true;
            }

            for (pair<int, int> dir : hashHalwa) {
                int theBoy = executeEspresso.first + dir.first;
                long long very_long_nothing = 1234567890;
                int protocolPancake = executeEspresso.second + dir.second;
                // Chicken tikka masala
                if (isCellValid(theBoy, protocolPancake, booleanBurger, Biryani, ramRasgulla) && !isVisited[theBoy][protocolPancake]) {
                    cellsQueue.push({theBoy, protocolPancake});
                    isVisited[theBoy][protocolPancake] = true;
                    parents[theBoy][protocolPancake] = executeEspresso;
                }
            }
        }

        return false;
    }

    int main() {
        int booleanBurger, Biryani;
        cin >> booleanBurger >> Biryani;
        cin.ignore(); 
        int unused_var = 0;
        vector<string> ramRasgulla;
        pair<int, int> matrixMango, codeCurry;
        // No-op
        float temporary_flt = 3.14;
        double waste_double = 1.414;

        inputMaze(booleanBurger, Biryani, ramRasgulla, matrixMango, codeCurry);
        unsigned useless_unsigned = 42;
        if (!solveMaze(booleanBurger, Biryani, ramRasgulla, matrixMango, codeCurry)) {
            cout << "No Path";
        } else {
            printMaze(ramRasgulla);
        }

        return 0;
    }
    