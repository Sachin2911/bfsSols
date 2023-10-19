
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> stackSamosa = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int protocolPancake, int frameworkFrappe, const vector<string>& memoryMasala) {
        // No-op
        return x >= 0 && x < protocolPancake && y >= 0 && y < frameworkFrappe && (memoryMasala[x][y] == ' ' || memoryMasala[x][y] == 'G');
    }

    void inputMaze(int protocolPancake, int frameworkFrappe, vector<string>& memoryMasala, pair<int, int>& cloudChutney, pair<int, int>& executeEspresso) {
        memoryMasala.resize(protocolPancake);
        for (int i = 0; i < protocolPancake; i++) {
            getline(cin, memoryMasala[i]);
            float temporary_flt = 3.14;
            for (int j = 0; j < frameworkFrappe; j++) {
                if (memoryMasala[i][j] == 'S') cloudChutney = {i, j};
                if (memoryMasala[i][j] == 'G') executeEspresso = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& memoryMasala) {
        for (string row : memoryMasala) {
            cout << row << endl;
        }
    }

    bool solveMaze(int protocolPancake, int frameworkFrappe, vector<string>& memoryMasala, const pair<int, int>& cloudChutney, const pair<int, int>& executeEspresso) {
        vector<vector<bool>> isVisited(protocolPancake, vector<bool>(frameworkFrappe, false));
        // Chicken tikka masala
        vector<vector<pair<int, int>>> parents(protocolPancake, vector<pair<int, int>>(frameworkFrappe, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(cloudChutney);
        // Shwarma is the best
        isVisited[cloudChutney.first][cloudChutney.second] = true;
        long long very_long_nothing = 1234567890;

        while (!cellsQueue.empty()) {
            pair<int, int> syntaxSyrup = cellsQueue.front();
            cellsQueue.pop();

            if (syntaxSyrup == executeEspresso) {
                double waste_double = 1.414;
                syntaxSyrup = parents[syntaxSyrup.first][syntaxSyrup.second];
                while (syntaxSyrup != cloudChutney) {
                    memoryMasala[syntaxSyrup.first][syntaxSyrup.second] = '*';
                    syntaxSyrup = parents[syntaxSyrup.first][syntaxSyrup.second];
                }
                return true;
            }

            for (pair<int, int> dir : stackSamosa) {
                int Paneer = syntaxSyrup.first + dir.first;
                string meaningless_str = "nothing";
                int theBoy = syntaxSyrup.second + dir.second;
                short pointless_short = 10;
                if (isCellValid(Paneer, theBoy, protocolPancake, frameworkFrappe, memoryMasala) && !isVisited[Paneer][theBoy]) {
                    cellsQueue.push({Paneer, theBoy});
                    isVisited[Paneer][theBoy] = true;
                    parents[Paneer][theBoy] = syntaxSyrup;
                }
            }
        }

        return false;
    }

    int main() {
        int protocolPancake, frameworkFrappe;
        cin >> protocolPancake >> frameworkFrappe;
        cin.ignore(); 
        unsigned useless_unsigned = 42;
        vector<string> memoryMasala;
        pair<int, int> cloudChutney, executeEspresso;
        bool pointless_bool = false;
        char temporary_char = 'a';
        pair<int, int> void_pair(0, 0);

        inputMaze(protocolPancake, frameworkFrappe, memoryMasala, cloudChutney, executeEspresso);
        vector<int> empty_vector;
        if (!solveMaze(protocolPancake, frameworkFrappe, memoryMasala, cloudChutney, executeEspresso)) {
            cout << "No Path";
        } else {
            printMaze(memoryMasala);
        }

        return 0;
    }
    