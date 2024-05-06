/*******************************************************************************************************************
 *                                                       Task 6                                                    *
 *******************************************************************************************************************/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int ROWS = 3;
const int COLS = 4;


/*******************************************************************************************************************
 *                                         Functions Prototypes                                                    *
 *******************************************************************************************************************/

int calculate_cost(const vector<vector<char>>& state);
void explore_moves(int row, int col, const vector<vector<char>>& current_state, vector<vector<char>>& neighbors);
vector<vector<char>> generate_neighbors(const vector<vector<char>>& current_state);


/*******************************************************************************************************************
 *                                        iterative_improvement Function                                           *
 *******************************************************************************************************************/

void iterative_improvement(vector<vector<char>>& initial_state) {
    vector<vector<char>> current_state = initial_state;
    int current_cost = calculate_cost(initial_state);
    
    while (true) {
        bool improvement = false;

        while (true) {
            vector<vector<char>> neighbors = generate_neighbors(current_state);
            
            vector<vector<char>> best_neighbor;
            int best_neighbor_cost = current_cost;
            
            for (const auto& neighbor : neighbors) {
                int neighbor_cost = calculate_cost(neighbor);
                
                if (neighbor_cost < best_neighbor_cost) {
                    best_neighbor = neighbor;
                    best_neighbor_cost = neighbor_cost;
                }
            }
            
            if (!best_neighbor.empty()) {
                current_state = best_neighbor;
                current_cost = best_neighbor_cost;
                improvement = true;
            } else {
                break;
            }
        }
        
        if (!improvement) {
            break;
        }
    }

    cout << "Final state:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << current_state[i][j] << " ";
        }
        cout << endl;
    }
}


/*******************************************************************************************************************
 *                                              calculate_cost Function                                            *
 *******************************************************************************************************************/

int calculate_cost(const vector<vector<char>>& state) {
    int cost = 0;
    // Iterate through the state and count the number of knights not in their goal positions
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // Check if the current square contains a knight and if it's not in its goal position
            if ((i == 0 && state[i][j] != 'W') || (i == ROWS - 1 && state[i][j] != 'B')) {
                cost++;
            }
        }
    }
    return cost;
}


/*******************************************************************************************************************
 *                                              explore_moves Function                                            *
 *******************************************************************************************************************/

void explore_moves(int row, int col, const vector<vector<char>>& current_state, vector<vector<char>>& neighbors) {
    const vector<pair<int, int>> moves = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};

    for (const auto& move : moves) {
        int new_row = row + move.first;
        int new_col = col + move.second;

        if (new_row >= 0 && new_row < ROWS && new_col >= 0 && new_col < COLS) {
            vector<vector<char>> neighbor_state = current_state;
            swap(neighbor_state[row][col], neighbor_state[new_row][new_col]);
            neighbors.push_back(neighbor_state);
        }
    }
}


/*******************************************************************************************************************
 *                                          generate_neighbors Function                                            *
 *******************************************************************************************************************/

vector<vector<char>> generate_neighbors(const vector<vector<char>>& current_state) {
    vector<vector<char>> neighbors;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (current_state[i][j] != '.') {
                explore_moves(i, j, current_state, neighbors);
            }
        }
    }

    return neighbors;
}


/*******************************************************************************************************************
 *                                                   main Function                                                 *
 *******************************************************************************************************************/

int main() {
    // Example usage
    vector<vector<char>> initial_state = {
        {'W', 'W', 'W'},
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'B', 'B', 'B'}
    };
    
    iterative_improvement(initial_state);
    
    return 0;
}
