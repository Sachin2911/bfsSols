import random
import os

RANDOM_VARIABLES = [
    "butterChicken", "Elachi", "Kulfi", "Paneer", "Aloo", "Biryani", 
    "DrizzyDre", "Ovo", "sixGod", "theBoy", "mrTorronto", 
    "byteBite", "ramRasgulla", "pixelPasta", "codeCurry", "loopLassi", 
    "algoAchar", "functionFalooda", "NaanNetwork", "debugDhokla", "hashHalwa", 
    "graphGulab", "nodeNoodles", "heapHummus", "binaryBhaji", "linuxLadoo",
    "vectorVada", "stackSamosa", "threadTandoori", "executeEspresso", "runtimeRoti", 
    "kernalKheer", "databaseDosa", "cloudChutney", "widgetWaffle", "memoryMasala",
    "apiApplePie", "stringSushi", "frameworkFrappe", "malwareMuffin", "protocolPancake", 
    "syntaxSyrup", "matrixMango", "booleanBurger", "charChai", "terminalTikka"
]

NO_OP_LINES = [
    "// No-op",
    "// Chicken tikka masala",
    "// Shwarma is the best",
    "int unused_var = 0;",
    "float temporary_flt = 3.14;",
    "string meaningless_str = \"nothing\";",
    "bool pointless_bool = false;",
    "char temporary_char = 'a';",
    "double waste_double = 1.414;",
    "unsigned useless_unsigned = 42;",
    "short pointless_short = 10;",
    "long long very_long_nothing = 1234567890;",
    "vector<int> empty_vector;",
    "pair<int, int> void_pair(0, 0);",
]

def generate_random_bfs_code():
    used_vars = []
    used_no_ops = []

    def get_unique_random_variable():
        var = random.choice(RANDOM_VARIABLES)
        while var in used_vars:
            var = random.choice(RANDOM_VARIABLES)
        used_vars.append(var)
        return var
    
    def get_unique_no_op_line():
        no_op = random.choice(NO_OP_LINES)
        while no_op in used_no_ops:
            no_op = random.choice(NO_OP_LINES)
        used_no_ops.append(no_op)
        return no_op

    rows = get_unique_random_variable()
    cols = get_unique_random_variable()
    maze_grid = get_unique_random_variable()
    start_point = get_unique_random_variable()
    end_point = get_unique_random_variable()
    current_cell = get_unique_random_variable()
    directions = get_unique_random_variable()
    newX = get_unique_random_variable()
    newY = get_unique_random_variable()

    bfs_code_template = f"""
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <string>

    using namespace std;

    vector<pair<int, int>> {directions} = {{{{1, 0}}, {{0, -1}}, {{-1, 0}}, {{0, 1}}}}; // down, left, up, right

    bool isCellValid(int x, int y, int {rows}, int {cols}, const vector<string>& {maze_grid}) {{
        {get_unique_no_op_line()}
        return x >= 0 && x < {rows} && y >= 0 && y < {cols} && ({maze_grid}[x][y] == ' ' || {maze_grid}[x][y] == 'G');
    }}

    void inputMaze(int {rows}, int {cols}, vector<string>& {maze_grid}, pair<int, int>& {start_point}, pair<int, int>& {end_point}) {{
        {maze_grid}.resize({rows});
        for (int i = 0; i < {rows}; i++) {{
            getline(cin, {maze_grid}[i]);
            {get_unique_no_op_line()}
            for (int j = 0; j < {cols}; j++) {{
                if ({maze_grid}[i][j] == 'S') {start_point} = {{i, j}};
                if ({maze_grid}[i][j] == 'G') {end_point} = {{i, j}};
            }}
        }}
    }}

    void printMaze(const vector<string>& {maze_grid}) {{
        for (string row : {maze_grid}) {{
            cout << row << endl;
        }}
    }}

    bool solveMaze(int {rows}, int {cols}, vector<string>& {maze_grid}, const pair<int, int>& {start_point}, const pair<int, int>& {end_point}) {{
        vector<vector<bool>> isVisited({rows}, vector<bool>({cols}, false));
        {get_unique_no_op_line()}
        vector<vector<pair<int, int>>> parents({rows}, vector<pair<int, int>>({cols}, {{-1, -1}}));

        queue<pair<int, int>> cellsQueue;
        cellsQueue.push({start_point});
        {get_unique_no_op_line()}
        isVisited[{start_point}.first][{start_point}.second] = true;
        {get_unique_no_op_line()}

        while (!cellsQueue.empty()) {{
            pair<int, int> {current_cell} = cellsQueue.front();
            cellsQueue.pop();

            if ({current_cell} == {end_point}) {{
                {get_unique_no_op_line()}
                {current_cell} = parents[{current_cell}.first][{current_cell}.second];
                while ({current_cell} != {start_point}) {{
                    {maze_grid}[{current_cell}.first][{current_cell}.second] = '*';
                    {current_cell} = parents[{current_cell}.first][{current_cell}.second];
                }}
                return true;
            }}

            for (pair<int, int> dir : {directions}) {{
                int {newX} = {current_cell}.first + dir.first;
                {get_unique_no_op_line()}
                int {newY} = {current_cell}.second + dir.second;
                {get_unique_no_op_line()}
                if (isCellValid({newX}, {newY}, {rows}, {cols}, {maze_grid}) && !isVisited[{newX}][{newY}]) {{
                    cellsQueue.push({{{newX}, {newY}}});
                    isVisited[{newX}][{newY}] = true;
                    parents[{newX}][{newY}] = {current_cell};
                }}
            }}
        }}

        return false;
    }}

    int main() {{
        int {rows}, {cols};
        cin >> {rows} >> {cols};
        cin.ignore(); 
        {get_unique_no_op_line()}
        vector<string> {maze_grid};
        pair<int, int> {start_point}, {end_point};
        {get_unique_no_op_line()}
        {get_unique_no_op_line()}
        {get_unique_no_op_line()}

        inputMaze({rows}, {cols}, {maze_grid}, {start_point}, {end_point});
        {get_unique_no_op_line()}
        if (!solveMaze({rows}, {cols}, {maze_grid}, {start_point}, {end_point})) {{
            cout << "No Path";
        }} else {{
            printMaze({maze_grid});
        }}

        return 0;
    }}
    """
    
    return bfs_code_template

def main():
    names = ["Jeff", "Abdullah", "James", "Hadi", "Raihan", "Ebi", "Iman", "Nabeel", "Sima", "Emmanuel", "Terry", "Lefa", "Shaun", "Tetelo", "Haseeb", "Weezy", "Lesiba","Abdul", "Boaz", "Reese", "Ethan", "Jaairdan", "Sacha", "Seb", "Ash", "Yoon", "Calvin"] 
    for name in names:
        with open(f"{name}.cpp", "w") as file:
            file.write(generate_random_bfs_code())

if __name__ == "__main__":
    main()
