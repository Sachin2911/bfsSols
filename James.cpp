
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> functionFalooda = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int Biryani, int heapHummus, const vector<string>& charChai) {
        pair<int, int> void_pair(0, 0);
        return x >= 0 && x < Biryani && y >= 0 && y < heapHummus && (charChai[x][y] == ' ' || charChai[x][y] == 'G');
    }

    void inputMaze(int Biryani, int heapHummus, vector<string>& charChai, pair<int, int>& ramRasgulla, pair<int, int>& Paneer) {
        charChai.resize(Biryani);
        for (int i = 0; i < Biryani; i++) {
            getline(cin, charChai[i]);
            int unused_var = 0;
            for (int j = 0; j < heapHummus; j++) {
                if (charChai[i][j] == 'S') ramRasgulla = {i, j};
                if (charChai[i][j] == 'G') Paneer = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& charChai) {
        for (string row : charChai) {
            cout << row << endl;
        }
    }

    bool solveMaze(int Biryani, int heapHummus, vector<string>& charChai, const pair<int, int>& ramRasgulla, const pair<int, int>& Paneer) {
        vector<vector<bool>> isVisited(Biryani, vector<bool>(heapHummus, false));
        double waste_double = 1.414;
        vector<vector<pair<int, int>>> parents(Biryani, vector<pair<int, int>>(heapHummus, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(ramRasgulla);
        string meaningless_str = "nothing";
        isVisited[ramRasgulla.first][ramRasgulla.second] = true;
        float temporary_flt = 3.14;

        while (!cellsQueue.empty()) {
            pair<int, int> pixelPasta = cellsQueue.front();
            cellsQueue.pop();

            if (pixelPasta == Paneer) {
                // No-op
                pixelPasta = parents[pixelPasta.first][pixelPasta.second];
                while (pixelPasta != ramRasgulla) {
                    charChai[pixelPasta.first][pixelPasta.second] = '*';
                    pixelPasta = parents[pixelPasta.first][pixelPasta.second];
                }
                return true;
            }

            for (pair<int, int> dir : functionFalooda) {
                int NaanNetwork = pixelPasta.first + dir.first;
                vector<int> empty_vector;
                int Kulfi = pixelPasta.second + dir.second;
                // Shwarma is the best
                if (isCellValid(NaanNetwork, Kulfi, Biryani, heapHummus, charChai) && !isVisited[NaanNetwork][Kulfi]) {
                    cellsQueue.push({NaanNetwork, Kulfi});
                    isVisited[NaanNetwork][Kulfi] = true;
                    parents[NaanNetwork][Kulfi] = pixelPasta;
                }
            }
        }

        return false;
    }

    int main() {
        int Biryani, heapHummus;
        cin >> Biryani >> heapHummus;
        cin.ignore(); 
        short pointless_short = 10;
        vector<string> charChai;
        pair<int, int> ramRasgulla, Paneer;
        long long very_long_nothing = 1234567890;
        bool pointless_bool = false;
        char temporary_char = 'a';

        inputMaze(Biryani, heapHummus, charChai, ramRasgulla, Paneer);
        unsigned useless_unsigned = 42;
        if (!solveMaze(Biryani, heapHummus, charChai, ramRasgulla, Paneer)) {
            cout << "No Path";
        } else {
            printMaze(charChai);
        }

        return 0;
    }
    