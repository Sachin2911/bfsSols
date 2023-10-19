
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> booleanBurger = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int matrixMango, int binaryBhaji, const vector<string>& stackSamosa) {
        unsigned useless_unsigned = 42;
        return x >= 0 && x < matrixMango && y >= 0 && y < binaryBhaji && (stackSamosa[x][y] == ' ' || stackSamosa[x][y] == 'G');
    }

    void inputMaze(int matrixMango, int binaryBhaji, vector<string>& stackSamosa, pair<int, int>& Elachi, pair<int, int>& nodeNoodles) {
        stackSamosa.resize(matrixMango);
        for (int i = 0; i < matrixMango; i++) {
            getline(cin, stackSamosa[i]);
            long long very_long_nothing = 1234567890;
            for (int j = 0; j < binaryBhaji; j++) {
                if (stackSamosa[i][j] == 'S') Elachi = {i, j};
                if (stackSamosa[i][j] == 'G') nodeNoodles = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& stackSamosa) {
        for (string row : stackSamosa) {
            cout << row << endl;
        }
    }

    bool solveMaze(int matrixMango, int binaryBhaji, vector<string>& stackSamosa, const pair<int, int>& Elachi, const pair<int, int>& nodeNoodles) {
        vector<vector<bool>> isVisited(matrixMango, vector<bool>(binaryBhaji, false));
        double waste_double = 1.414;
        vector<vector<pair<int, int>>> parents(matrixMango, vector<pair<int, int>>(binaryBhaji, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(Elachi);
        // No-op
        isVisited[Elachi.first][Elachi.second] = true;
        string meaningless_str = "nothing";

        while (!cellsQueue.empty()) {
            pair<int, int> protocolPancake = cellsQueue.front();
            cellsQueue.pop();

            if (protocolPancake == nodeNoodles) {
                vector<int> empty_vector;
                protocolPancake = parents[protocolPancake.first][protocolPancake.second];
                while (protocolPancake != Elachi) {
                    stackSamosa[protocolPancake.first][protocolPancake.second] = '*';
                    protocolPancake = parents[protocolPancake.first][protocolPancake.second];
                }
                return true;
            }

            for (pair<int, int> dir : booleanBurger) {
                int Ovo = protocolPancake.first + dir.first;
                pair<int, int> void_pair(0, 0);
                int stringSushi = protocolPancake.second + dir.second;
                // Shwarma is the best
                if (isCellValid(Ovo, stringSushi, matrixMango, binaryBhaji, stackSamosa) && !isVisited[Ovo][stringSushi]) {
                    cellsQueue.push({Ovo, stringSushi});
                    isVisited[Ovo][stringSushi] = true;
                    parents[Ovo][stringSushi] = protocolPancake;
                }
            }
        }

        return false;
    }

    int main() {
        int matrixMango, binaryBhaji;
        cin >> matrixMango >> binaryBhaji;
        cin.ignore(); 
        // Chicken tikka masala
        vector<string> stackSamosa;
        pair<int, int> Elachi, nodeNoodles;
        int unused_var = 0;
        bool pointless_bool = false;
        char temporary_char = 'a';

        inputMaze(matrixMango, binaryBhaji, stackSamosa, Elachi, nodeNoodles);
        short pointless_short = 10;
        if (!solveMaze(matrixMango, binaryBhaji, stackSamosa, Elachi, nodeNoodles)) {
            cout << "No Path";
        } else {
            printMaze(stackSamosa);
        }

        return 0;
    }
    