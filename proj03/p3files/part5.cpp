#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <cmath>   // For abs()
#include "board.h"
#include "easycurses.h"

using namespace std;

struct Object {
    char type; 
    int r;
    int c;
    char state; 
};

void get_dr_dc(char dir, int& dr, int& dc) {
    dr = 0; dc = 0;
    if (dir == 'N') dr = -1;
    else if (dir == 'S') dr = 1;
    else if (dir == 'E') dc = 1;
    else if (dir == 'W') dc = -1;
}

char get_opposite(char dir) {
    if (dir == 'N') return 'S';
    if (dir == 'S') return 'N';
    if (dir == 'E') return 'W';
    if (dir == 'W') return 'E';
    return dir;
}

char get_left(char dir) {
    if (dir == 'N') return 'W';
    if (dir == 'W') return 'S';
    if (dir == 'S') return 'E';
    if (dir == 'E') return 'N';
    return dir;
}

char get_right(char dir) {
    if (dir == 'N') return 'E';
    if (dir == 'E') return 'S';
    if (dir == 'S') return 'W';
    if (dir == 'W') return 'N';
    return dir;
}

// Generates a random initial direction for Stars/Hunters
char get_random_dir() {
    int r = rand() % 4;
    if (r == 0) return 'N';
    if (r == 1) return 'S';
    if (r == 2) return 'E';
    return 'W';
}

// Logic for Player movement
void process_player(Object& player, int key, Board* b) {
    char intent_dir = player.state;

    // Map WASD or Arrow Keys (if easycurses supports them as characters)
    if (key == 'w' || key == 'N') intent_dir = 'N';
    else if (key == 's' || key == 'S') intent_dir = 'S';
    else if (key == 'a' || key == 'W') intent_dir = 'W';
    else if (key == 'd' || key == 'E') intent_dir = 'E';
    else if (key == ' ') intent_dir = 'P'; // Pause

    int next_r = player.r;
    int next_c = player.c;

    if (intent_dir != 'P') {
        int dr = 0, dc = 0;
        get_dr_dc(intent_dir, dr, dc);
        if (b->grid[player.r + dr][player.c + dc] != '#') {
            next_r = player.r + dr;
            next_c = player.c + dc;
        }
    }

    player.r = next_r;
    player.c = next_c;
    player.state = intent_dir;
}

// Logic for random Star movement
void process_star(Object& star, Board* b) {
    char intent_dir = star.state;
    
    // Stars occasionally change direction randomly (simulating file input from part 2)
    int r = rand() % 10;
    if (r == 0) intent_dir = get_left(star.state);
    else if (r == 1) intent_dir = get_right(star.state);

    char final_state = intent_dir;
    int next_r = star.r;
    int next_c = star.c;

    int dr = 0, dc = 0;
    get_dr_dc(intent_dir, dr, dc);
    
    if (b->grid[star.r + dr][star.c + dc] == '#') {
        char opp_dir = get_opposite(intent_dir);
        int opp_dr = -dr, opp_dc = -dc;
        
        if (b->grid[star.r + opp_dr][star.c + opp_dc] == '#') {
            final_state = intent_dir; 
            next_r = star.r;
            next_c = star.c;
        } else {
            final_state = opp_dir;
            next_r = star.r + opp_dr;
            next_c = star.c + opp_dc;
        }
    } else {
        next_r = star.r + dr;
        next_c = star.c + dc;
    }

    star.r = next_r;
    star.c = next_c;
    star.state = final_state;
}

// Logic for Hunter tracking
void process_hunter(Object& hunter, Object& player, Board* b) {
    // 1. Flip a coin (50% chance to update tracking)
    if (rand() % 2 == 0) {
        int dc = player.c - hunter.c;
        int dr = player.r - hunter.r;

        if (abs(dc) >= abs(dr)) {
            if (dc < 0) hunter.state = 'W';
            else if (dc > 0) hunter.state = 'E';
        } else {
            if (dr < 0) hunter.state = 'N';
            else if (dr > 0) hunter.state = 'S';
        }
    }
    // If tails, keep current direction

    char final_state = hunter.state;
    int next_r = hunter.r;
    int next_c = hunter.c;

    int dr = 0, dc = 0;
    get_dr_dc(hunter.state, dr, dc);
    
    // Standard wall bouncing for hunters
    if (b->grid[hunter.r + dr][hunter.c + dc] == '#') {
        char opp_dir = get_opposite(hunter.state);
        int opp_dr = -dr, opp_dc = -dc;
        
        if (b->grid[hunter.r + opp_dr][hunter.c + opp_dc] == '#') {
            final_state = hunter.state; 
            next_r = hunter.r;
            next_c = hunter.c;
        } else {
            final_state = opp_dir;
            next_r = hunter.r + opp_dr;
            next_c = hunter.c + opp_dc;
        }
    } else {
        next_r = hunter.r + dr;
        next_c = hunter.c + dc;
    }

    hunter.r = next_r;
    hunter.c = next_c;
    hunter.state = final_state;
}

// Collision detection
bool check_collision(Object p, Object e) {
    return (p.r == e.r && p.c == e.c);
}

int main() {
    srand(time(0)); 

    string board_file;
    cout << "board file: ";
    cin >> board_file;

    Board* b = load_board(board_file);
    if (!b) {
        cout << "Error: Board file not found!\n";
        return 1;
    }

    Object player = {'P', b->start.r, b->start.c, 'P'};
    
    // Allocate Stars AND Hunters (One per spawn spot)
    Object* stars = new Object[b->num_Zs];
    Object* hunters = new Object[b->num_Zs];
    
    for (int i = 0; i < b->num_Zs; i++) {
        stars[i] = {'*', b->spawns[i].r, b->spawns[i].c, get_random_dir()};
        hunters[i] = {'K', b->spawns[i].r, b->spawns[i].c, get_random_dir()};
    }

    startCurses();

    int score = 0;
    bool game_over = false;
    bool won = false;

    // Main interactive loop
    while (!game_over) {
        // Draw static board
        for (int r = 0; r < b->rows; r++) {
            for (int c = 0; c < b->cols; c++) {
                drawChar(b->grid[r][c], r, c);
            }
        }

        drawChar('X', b->goal.r, b->goal.c);
        
        // Draw entities
        for (int i = 0; i < b->num_Zs; i++) {
            drawChar('*', stars[i].r, stars[i].c);
            drawChar('K', hunters[i].r, hunters[i].c);
        }
        drawChar('P', player.r, player.c);

        refreshWindow();

        // Check Win Condition
        if (player.r == b->goal.r && player.c == b->goal.c) {
            won = true;
            game_over = true;
            break;
        }

        // Check Loss Condition
        for (int i = 0; i < b->num_Zs; i++) {
            if (check_collision(player, stars[i]) || check_collision(player, hunters[i])) {
                game_over = true;
                break;
            }
        }
        if (game_over) break;

        // Get Input
        int key = inputChar();
        if (key == 'q') { // Emergency quit
            break;
        }

        // Process Logic
        process_player(player, key, b);

        for (int i = 0; i < b->num_Zs; i++) {
            process_star(stars[i], b);
            process_hunter(hunters[i], player, b);
        }

        score++;
        usleep(100000); // 0.1 seconds per frame
    }

    endCurses();

    // Print final results exactly as autograder expects
    cout << "board file: " << board_file << "\n";
    cout << "Player start: (" << b->start.r << "," << b->start.c << ")\n";
    cout << "Spawn spots :";
    for (int i = 0; i < b->num_Zs; i++) {
        cout << " (" << b->spawns[i].r << "," << b->spawns[i].c << ")";
    }
    cout << "\n";

    if (won) {
        cout << "You won, score = " << score << "\n";
    } else {
        cout << "You lost, they got you!\n";
    }

    delete[] stars;
    delete[] hunters;
    free_board(b);

    return 0;
}