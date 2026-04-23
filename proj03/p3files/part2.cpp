#include <iostream>
#include <fstream>
#include <string>
#include "board.h"

using namespace std;

// Struct to track movable objects (Player and Stars)
struct Object {
    char type; // 'P' or '*'
    int r;
    int c;
    char state; // 'N', 'S', 'E', 'W', 'P'
};

// Helper function to get row/col deltas based on direction
void get_dr_dc(char dir, int& dr, int& dc) {
    dr = 0; dc = 0;
    if (dir == 'N') dr = -1;
    else if (dir == 'S') dr = 1;
    else if (dir == 'E') dc = 1;
    else if (dir == 'W') dc = -1;
}

// Helper to get opposite direction for bouncing
char get_opposite(char dir) {
    if (dir == 'N') return 'S';
    if (dir == 'S') return 'N';
    if (dir == 'E') return 'W';
    if (dir == 'W') return 'E';
    return dir;
}

// Helper to rotate left
char get_left(char dir) {
    if (dir == 'N') return 'W';
    if (dir == 'W') return 'S';
    if (dir == 'S') return 'E';
    if (dir == 'E') return 'N';
    return dir;
}

// Helper to rotate right
char get_right(char dir) {
    if (dir == 'N') return 'E';
    if (dir == 'E') return 'S';
    if (dir == 'S') return 'W';
    if (dir == 'W') return 'N';
    return dir;
}

// Process movement logic with bouncing
void process_movement(Object& obj, char cmd, int cmd_idx, Board* b) {
    char intent_dir;

    // Determine intent direction based on object type and command
    if (obj.type == 'P') {
        intent_dir = (cmd == 'K') ? obj.state : cmd;
    } else { // '*'
        if (cmd == 'K') intent_dir = obj.state;
        else if (cmd == 'L') intent_dir = get_left(obj.state);
        else if (cmd == 'R') intent_dir = get_right(obj.state);
        else intent_dir = obj.state;
    }

    string bounce_str = "";
    char final_state = intent_dir;
    int next_r = obj.r;
    int next_c = obj.c;

    if (intent_dir != 'P') {
        int dr = 0, dc = 0;
        get_dr_dc(intent_dir, dr, dc);
        
        // Check for wall collision in intended direction
        if (b->grid[obj.r + dr][obj.c + dc] == '#') {
            bounce_str = " Bounce!";
            char opp_dir = get_opposite(intent_dir);
            int opp_dr = -dr, opp_dc = -dc;
            
            // Check for wall collision in opposite direction
            if (b->grid[obj.r + opp_dr][obj.c + opp_dc] == '#') {
                bounce_str = " Bounce! Bounce!";
                final_state = intent_dir; // Retain original intended direction
                next_r = obj.r;
                next_c = obj.c;
            } else {
                final_state = opp_dir;
                next_r = obj.r + opp_dr;
                next_c = obj.c + opp_dc;
            }
        } else {
            next_r = obj.r + dr;
            next_c = obj.c + dc;
        }
    }

    // Print trace
    cout << (obj.type == 'P' ? "P" : "S") << cmd_idx 
         << " (" << obj.type << "," << obj.r << "," << obj.c << ")" << obj.state 
         << "->" << cmd << bounce_str 
         << " DRAW (" << obj.type << "," << next_r << "," << next_c << ")" << final_state << "\n";

    // Update object state
    obj.r = next_r;
    obj.c = next_c;
    obj.state = final_state;
}

int main() {
    string board_file, player_file, star_file;
    int num_frames;

    cout << "board file: ";
    cin >> board_file;
    cout << "player movement file: ";
    cin >> player_file;
    cout << "star movement file: ";
    cin >> star_file;
    cout << "#frames to run: ";
    cin >> num_frames;

    Board* b = load_board(board_file);
    if (!b) {
        cout << "Error: Board file not found!\n";
        return 1;
    }

    ifstream fin_p(player_file);
    if (!fin_p) {
        cout << "Error: Player file not found!\n";
        return 1;
    }

    ifstream fin_s(star_file);
    if (!fin_s) {
        cout << "Error: Star file not found!\n";
        return 1;
    }

    print_board(b);
    cout << "\n";

    // Initialize objects
    Object player = {'P', b->start.r, b->start.c, 'P'};
    
    Object* stars = new Object[b->num_Zs];
    for (int i = 0; i < b->num_Zs; i++) {
        stars[i] = {'*', b->spawns[i].r, b->spawns[i].c, 'E'};
    }

    // Initial draws
    cout << "DRAW (P," << player.r << "," << player.c << ")P\n";
    for (int i = 0; i < b->num_Zs; i++) {
        cout << "DRAW (*," << stars[i].r << "," << stars[i].c << ")E\n";
    }
    cout << "\n";

    // Simulation loop
    for (int f = 0; f < num_frames; f++) {
        cout << "=============FRAME " << f << "\n";
        cout << "Sleep\n";

        // Erase old positions
        cout << "ERASE (P," << player.r << "," << player.c << ")" << player.state << "\n";
        for (int i = 0; i < b->num_Zs; i++) {
            cout << "ERASE (*," << stars[i].r << "," << stars[i].c << ")" << stars[i].state << "\n";
        }

        // Always redraw goal
        cout << "DRAW (X," << b->goal.r << "," << b->goal.c << ")\n";

        // Process Player
        int p_idx; char p_cmd;
        if (fin_p >> p_idx >> p_cmd) {
            process_movement(player, p_cmd, p_idx, b);
        }

        // Process Stars
        for (int i = 0; i < b->num_Zs; i++) {
            int s_idx; char s_cmd;
            if (fin_s >> s_idx >> s_cmd) {
                process_movement(stars[i], s_cmd, s_idx, b);
            }
        }

        cout << "RefreshWindow\n";
        cout << "=============\n\n";
    }

    // Cleanup
    delete[] stars;
    free_board(b);

    return 0;
}