#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "board.h"
#include "easycurses.h"

using namespace std;

// Struct to track movable objects Player and Stars
struct Object {
    char type; 
    int r;
    int c;
    char state; 
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
void process_movement(Object& obj, char cmd, Board* b) {
    char intent_dir;

    if (obj.type == 'P') {
        intent_dir = (cmd == 'K') ? obj.state : cmd;
    } else { 
        if (cmd == 'K') intent_dir = obj.state;
        else if (cmd == 'L') intent_dir = get_left(obj.state);
        else if (cmd == 'R') intent_dir = get_right(obj.state);
        else intent_dir = obj.state;
    }

    char final_state = intent_dir;
    int next_r = obj.r;
    int next_c = obj.c;

    if (intent_dir != 'P') {
        int dr = 0, dc = 0;
        get_dr_dc(intent_dir, dr, dc);
        
        // Check for wall collision in intended direction
        if (b->grid[obj.r + dr][obj.c + dc] == '#') {
            char opp_dir = get_opposite(intent_dir);
            int opp_dr = -dr, opp_dc = -dc;
            
            // Check for wall collision in opposite direction
            if (b->grid[obj.r + opp_dr][obj.c + opp_dc] == '#') {
                final_state = intent_dir; 
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

    // Update object state silently
    obj.r = next_r;
    obj.c = next_c;
    obj.state = final_state;
}

int main() {
    string board_file, player_file, star_file;
    int num_frames;

    // Prompt User BEFORE starting curses
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
    ifstream fin_s(star_file);

    // Initialize objects
    Object player = {'P', b->start.r, b->start.c, 'P'};
    Object* stars = new Object[b->num_Zs];
    for (int i = 0; i < b->num_Zs; i++) {
        stars[i] = {'*', b->spawns[i].r, b->spawns[i].c, 'E'};
    }

    // Start curses mode
    startCurses();

    // Initial draw of the static board
    for (int r = 0; r < b->rows; r++) {
        for (int c = 0; c < b->cols; c++) {
            drawChar(b->grid[r][c], r, c);
        }
    }

    // Draw initial entities
    drawChar('X', b->goal.r, b->goal.c);
    drawChar('P', player.r, player.c);
    for (int i = 0; i < b->num_Zs; i++) {
        drawChar('*', stars[i].r, stars[i].c);
    }

    // Simulation loop
    for (int f = 0; f < num_frames; f++) {
        // Sleep for microseconds
        usleep(150000); 

        // Erase old positions
        drawChar(' ', player.r, player.c);
        for (int i = 0; i < b->num_Zs; i++) {
            drawChar(' ', stars[i].r, stars[i].c);
        }

        // Redraw goal
        drawChar('X', b->goal.r, b->goal.c);

        // Process Player
        int p_idx; char p_cmd;
        if (fin_p >> p_idx >> p_cmd) {
            process_movement(player, p_cmd, b);
        }

        // Process Stars
        for (int i = 0; i < b->num_Zs; i++) {
            int s_idx; char s_cmd;
            if (fin_s >> s_idx >> s_cmd) {
                process_movement(stars[i], s_cmd, b);
            }
        }

        // Draw new positions
        drawChar('P', player.r, player.c);
        for (int i = 0; i < b->num_Zs; i++) {
            drawChar('*', stars[i].r, stars[i].c);
        }

        refreshWindow();
    }

    // Cleanup
    endCurses();

    delete[] stars;
    free_board(b);

    return 0;
}