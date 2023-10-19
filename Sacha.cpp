
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> executeEspresso = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int codeCurry, int theBoy, const vector<string>& heapHummus) {
        float temporary_flt = 3.14;
        return x >= 0 && x < codeCurry && y >= 0 && y < theBoy && (heapHummus[x][y] == ' ' || heapHummus[x][y] == 'G');
    }

    void inputMaze(int codeCurry, int theBoy, vector<string>& heapHummus, pair<int, int>& syntaxSyrup, pair<int, int>& sixGod) {
        heapHummus.resize(codeCurry);
        for (int i = 0; i < codeCurry; i++) {
            getline(cin, heapHummus[i]);
            double waste_double = 1.414;
            for (int j = 0; j < theBoy; j++) {
                if (heapHummus[i][j] == 'S') syntaxSyrup = {i, j};
                if (heapHummus[i][j] == 'G') sixGod = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& heapHummus) {
        for (string row : heapHummus) {
            cout << row << endl;
        }
    }

    bool solveMaze(int codeCurry, int theBoy, vector<string>& heapHummus, const pair<int, int>& syntaxSyrup, const pair<int, int>& sixGod) {
        vector<vector<bool>> isVisited(codeCurry, vector<bool>(theBoy, false));
        int unused_var = 0;
        vector<vector<pair<int, int>>> parents(codeCurry, vector<pair<int, int>>(theBoy, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(syntaxSyrup);
        long long very_long_nothing = 1234567890;
        isVisited[syntaxSyrup.first][syntaxSyrup.second] = true;
        unsigned useless_unsigned = 42;

        while (!cellsQueue.empty()) {
            pair<int, int> stackSamosa = cellsQueue.front();
            cellsQueue.pop();

            if (stackSamosa == sixGod) {
                vector<int> empty_vector;
                stackSamosa = parents[stackSamosa.first][stackSamosa.second];
                while (stackSamosa != syntaxSyrup) {
                    heapHummus[stackSamosa.first][stackSamosa.second] = '*';
                    stackSamosa = parents[stackSamosa.first][stackSamosa.second];
                }
                return true;
            }

            for (pair<int, int> dir : executeEspresso) {
                int vectorVada = stackSamosa.first + dir.first;
                // No-op
                int protocolPancake = stackSamosa.second + dir.second;
                short pointless_short = 10;
                if (isCellValid(vectorVada, protocolPancake, codeCurry, theBoy, heapHummus) && !isVisited[vectorVada][protocolPancake]) {
                    cellsQueue.push({vectorVada, protocolPancake});
                    isVisited[vectorVada][protocolPancake] = true;
                    parents[vectorVada][protocolPancake] = stackSamosa;
                }
            }
        }

        return false;
    }

    int main() {
        int codeCurry, theBoy;
        cin >> codeCurry >> theBoy;
        cin.ignore(); 
        string meaningless_str = "nothing";
        vector<string> heapHummus;
        pair<int, int> syntaxSyrup, sixGod;
        // Shwarma is the best
        bool pointless_bool = false;
        char temporary_char = 'a';

        inputMaze(codeCurry, theBoy, heapHummus, syntaxSyrup, sixGod);
        pair<int, int> void_pair(0, 0);
        if (!solveMaze(codeCurry, theBoy, heapHummus, syntaxSyrup, sixGod)) {
            cout << "No Path";
        } else {
            printMaze(heapHummus);
        }

        return 0;
    }
    