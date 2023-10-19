
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> cloudChutney = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    bool isCellValid(int x, int y, int NaanNetwork, int Biryani, const vector<string>& apiApplePie) {
        vector<int> empty_vector;
        return x >= 0 && x < NaanNetwork && y >= 0 && y < Biryani && (apiApplePie[x][y] == ' ' || apiApplePie[x][y] == 'G');
    }

    void inputMaze(int NaanNetwork, int Biryani, vector<string>& apiApplePie, pair<int, int>& frameworkFrappe, pair<int, int>& DrizzyDre) {
        apiApplePie.resize(NaanNetwork);
        for (int i = 0; i < NaanNetwork; i++) {
            getline(cin, apiApplePie[i]);
            double waste_double = 1.414;
            for (int j = 0; j < Biryani; j++) {
                if (apiApplePie[i][j] == 'S') frameworkFrappe = {i, j};
                if (apiApplePie[i][j] == 'G') DrizzyDre = {i, j};
            }
        }
    }

    void printMaze(const vector<string>& apiApplePie) {
        for (string row : apiApplePie) {
            cout << row << endl;
        }
    }

    bool solveMaze(int NaanNetwork, int Biryani, vector<string>& apiApplePie, const pair<int, int>& frameworkFrappe, const pair<int, int>& DrizzyDre) {
        vector<vector<bool>> isVisited(NaanNetwork, vector<bool>(Biryani, false));
        pair<int, int> void_pair(0, 0);
        vector<vector<pair<int, int>>> parents(NaanNetwork, vector<pair<int, int>>(Biryani, {-1, -1}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push(frameworkFrappe);
        bool pointless_bool = false;
        isVisited[frameworkFrappe.first][frameworkFrappe.second] = true;
        // Chicken tikka masala

        while (!cellsQueue.empty()) {
            pair<int, int> kernalKheer = cellsQueue.front();
            cellsQueue.pop();

            if (kernalKheer == DrizzyDre) {
                string meaningless_str = "nothing";
                kernalKheer = parents[kernalKheer.first][kernalKheer.second];
                while (kernalKheer != frameworkFrappe) {
                    apiApplePie[kernalKheer.first][kernalKheer.second] = '*';
                    kernalKheer = parents[kernalKheer.first][kernalKheer.second];
                }
                return true;
            }

            for (pair<int, int> dir : cloudChutney) {
                int protocolPancake = kernalKheer.first + dir.first;
                char temporary_char = 'a';
                int functionFalooda = kernalKheer.second + dir.second;
                // No-op
                if (isCellValid(protocolPancake, functionFalooda, NaanNetwork, Biryani, apiApplePie) && !isVisited[protocolPancake][functionFalooda]) {
                    cellsQueue.push({protocolPancake, functionFalooda});
                    isVisited[protocolPancake][functionFalooda] = true;
                    parents[protocolPancake][functionFalooda] = kernalKheer;
                }
            }
        }

        return false;
    }

    int main() {
        int NaanNetwork, Biryani;
        cin >> NaanNetwork >> Biryani;
        cin.ignore(); 
        long long very_long_nothing = 1234567890;
        vector<string> apiApplePie;
        pair<int, int> frameworkFrappe, DrizzyDre;
        short pointless_short = 10;
        // Shwarma is the best
        float temporary_flt = 3.14;

        inputMaze(NaanNetwork, Biryani, apiApplePie, frameworkFrappe, DrizzyDre);
        unsigned useless_unsigned = 42;
        if (!solveMaze(NaanNetwork, Biryani, apiApplePie, frameworkFrappe, DrizzyDre)) {
            cout << "No Path";
        } else {
            printMaze(apiApplePie);
        }

        return 0;
    }
    