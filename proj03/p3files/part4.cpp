/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       part4.cpp
 * Description: Interactive game simulation where the player moves using WASD 
 * keys to reach a goal while dodging randomly moving stars.
 * Date:        2026-04-28
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "board.h"
#include "easycurses.h"

using namespace std;

// Struct to track movable objects on the board
struct Object {
    char type; 
    int r;
    int c;
    char state; 
};

// Maps a directional character to row and column coordinate changes
void get_dr_dc(char dir, int& dr, int& dc) {
    dr = 0; dc = 0;
    if (dir == 'N') dr = -1;
    else if (dir == 'S') dr = 1;
    else if (dir == 'E') dc = 1;
    else if (dir == 'W') dc = -1;
}

// Returns the 180-degree opposite of the given direction
char get_opposite(char dir) {
    if (dir == 'N') return 'S';
    if (dir == 'S') return 'N';
    if (dir == 'E') return 'W';
    if (dir == 'W') return 'E';
    return dir;
}

// Handles interactive player movement based on user key presses
void process_player(Object& player, int key, Board* b) {
    char intent_dir = player.state;

    // Map WASD inputs to cardinal directions or pause
    if (key == 'w' || key == 'W') intent_dir = 'N';
    else if (key == 's' || key == 'S') intent_dir = 'S';
    else if (key == 'a' || key == 'A') intent_dir = 'W';
    else if (key == 'd' || key == 'D') intent_dir = 'E';
    else if (key == ' ') intent_dir = 'P';

    int next_r = player.r;
    int next_c = player.c;

    // Check for collisions with walls before moving the player
    if (intent_dir != 'P') {
        int dr = 0, dc = 0;
        get_dr_dc(intent_dir, dr, dc);
        
        if (b->grid[player.r + dr][player.c + dc] != '#') {
            next_r = player.r + dr;
            next_c = player.c + dc;
        }
    }

    // Apply the final validated position and state
    player.r = next_r;
    player.c = next_c;
    player.state = intent_dir;
}

// Handles the automated movement and wall-bouncing logic for stars
void process_star(Object& star, Board* b) {
    char intent_dir = star.state;
    char final_state = intent_dir;
    int next_r = star.r;
    int next_c = star.c;

    int dr = 0, dc = 0;
    get_dr_dc(intent_dir, dr, dc);
    
    // Process primary wall collision and directional bouncing
    if (b->grid[star.r + dr][star.c + dc] == '#') {
        char opp_dir = get_opposite(intent_dir);
        int opp_dr = -dr, opp_dc = -dc;
        
        // Handle double-bounce edge case where both directions are blocked
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
        // Move freely if no walls are in the way
        next_r = star.r + dr;
        next_c = star.c + dc;
    }

    // Apply the final validated position and state
    star.r = next_r;
    star.c = next_c;
    star.state = final_state;
}

// Checks if a player and an enemy occupy the exact same coordinates
bool check_collision(Object p, Object e) {
    return (p.r == e.r && p.c == e.c);
}

int main() {
    string board_file;
    
    // Prompt for file configurations
    cout << "board file: ";
    cin >> board_file;

    // Load the board from the provided file
    Board* b = load_board(board_file);
    if (!b) {
        return 1;
    }

    // Initialize the player object at the start position
    Object player = {'P', b->start.r, b->start.c, 'P'};
    
    // Dynamically allocate and initialize stars at the spawn spots
    Object* stars = new Object[b->num_Zs];
    for (int i = 0; i < b->num_Zs; i++) {
        stars[i] = {'*', b->spawns[i].r, b->spawns[i].c, 'E'};
    }

    // Transition the terminal into curses drawing mode
    startCurses();

    int score = 0;
    bool game_over = false;
    bool won = false;

    // Main game simulation loop
    while (!game_over) {
        // Draw the static background grid
        for (int r = 0; r < b->rows; r++) {
            for (int c = 0; c < b->cols; c++) {
                drawChar(b->grid[r][c], r, c);
            }
        }

        // Draw the target goal
        drawChar('X', b->goal.r, b->goal.c);
        
        // Draw all active entities
        for (int i = 0; i < b->num_Zs; i++) {
            drawChar('*', stars[i].r, stars[i].c);
        }
        drawChar('P', player.r, player.c);

        // Push all drawing updates to the terminal screen
        refreshWindow();

        // Check if the player successfully reached the goal
        if (player.r == b->goal.r && player.c == b->goal.c) {
            won = true;
            game_over = true;
            break;
        }

        // Check if the player collided with any enemy stars
        for (int i = 0; i < b->num_Zs; i++) {
            if (check_collision(player, stars[i])) {
                game_over = true;
                break;
            }
        }
        
        if (game_over) {
            break;
        }

        // Capture the user's latest key press
        int key = inputChar();
        
        // Provide an emergency exit key
        if (key == 'q' || key == 'Q') {
            break;
        }

        // Update the player's position based on input
        process_player(player, key, b);

        // Update the positions of all automated stars
        for (int i = 0; i < b->num_Zs; i++) {
            process_star(stars[i], b);
        }

        // Advance the score and sleep to control the frame rate
        score++;
        usleep(150000); 
    }

    // Return the terminal to its standard text mode
    endCurses();

    // Print final game statistics
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

    // Free dynamically allocated memory
    delete[] stars;
    free_board(b);

    return 0;
}