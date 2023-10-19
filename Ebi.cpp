
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> codeCurry = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int heapHummus, int ramRasgulla, const vector<string>& malwareMuffin) {
        // No-op
        return x >= 0 && x < heapHummus && y >= 0 && y < ramRasgulla && (malwareMuffin[x][y] == ' ' || malwareMuffin[x][y] == 'G');
    }

    void inputMaze(int heapHummus, int ramRasgulla, vector<string>& malwareMuffin, pair<int, int>& butterChicken, pair<int, int>& booleanBurger) {
        malwareMuffin.resize(heapHummus);
        for (int i = 0; i < heapHummus; i++) {
            getline(cin, malwareMuffin[i]);
            vector<int> empty_vector;
            for (int j = 0; j < ramRasgulla; j++) {
                if (malwareMuffin[i][j] == 'S') butterChicken = {i, j};
                if (malwareMuffin[i][j] == 'G') booleanBurger = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& malwareMuffin) {
        for (string row : malwareMuffin) {
            cout << row << endl;
        }
    }

    bool solveMaze(int heapHummus, int ramRasgulla, vector<string>& malwareMuffin, const pair<int, int>& butterChicken, const pair<int, int>& booleanBurger) {
        vector<vector<bool>> isVisited(heapHummus, vector<bool>(ramRasgulla, false));
        float temporary_flt = 3.14;
        vector<vector<pair<int, int>>> parents(heapHummus, vector<pair<int, int>>(ramRasgulla, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(butterChicken);
        short pointless_short = 10;
        isVisited[butterChicken.first][butterChicken.second] = true;
        bool pointless_bool = false;

        while (!cellsQueue.empty()) {
            pair<int, int> Biryani = cellsQueue.front();
            cellsQueue.pop();

            if (Biryani == booleanBurger) {
                string meaningless_str = "nothing";
                Biryani = parents[Biryani.first][Biryani.second];
                while (Biryani != butterChicken) {
                    malwareMuffin[Biryani.first][Biryani.second] = '*';
                    Biryani = parents[Biryani.first][Biryani.second];
                }
                return true;
            }

            for (pair<int, int> dir : codeCurry) {
                int nodeNoodles = Biryani.first + dir.first;
                unsigned useless_unsigned = 42;
                int NaanNetwork = Biryani.second + dir.second;
                double waste_double = 1.414;
                if (isCellValid(nodeNoodles, NaanNetwork, heapHummus, ramRasgulla, malwareMuffin) && !isVisited[nodeNoodles][NaanNetwork]) {
                    cellsQueue.push({nodeNoodles, NaanNetwork});
                    isVisited[nodeNoodles][NaanNetwork] = true;
                    parents[nodeNoodles][NaanNetwork] = Biryani;
                }
            }
        }

        return false;
    }

    int main() {
        int heapHummus, ramRasgulla;
        cin >> heapHummus >> ramRasgulla;
        cin.ignore(); 
        // Shwarma is the best
        vector<string> malwareMuffin;
        pair<int, int> butterChicken, booleanBurger;
        int unused_var = 0;
        char temporary_char = 'a';
        // Chicken tikka masala

        inputMaze(heapHummus, ramRasgulla, malwareMuffin, butterChicken, booleanBurger);
        pair<int, int> void_pair(0, 0);
        if (!solveMaze(heapHummus, ramRasgulla, malwareMuffin, butterChicken, booleanBurger)) {
            cout << "No Path";
        } else {
            printMaze(malwareMuffin);
        }

        return 0;
    }
    