/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       part6.cpp
 * Description: Multi-stage interactive game simulation using a linked list. 
 * Reads a script file, manages progression, computes scores, and handles
 * win/loss conditions including retries against both randomly moving stars 
 * and actively tracking hunters.
 * Date:        2026-04-28
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "board.h"
#include "easycurses.h"

using namespace std;

// Node structure to hold the configuration for each stage in a linked list
struct StageNode {
    string board_file;
    int num_ships;
    int num_hunters;
    int points;
    StageNode* next;
};

// Structure to track the position and state of all movable entities
struct Object {
    char type; 
    int r;
    int c;
    char state; 
};

// Appends a new stage configuration to the end of the linked list
void append_stage(StageNode*& head, string b_file, int ships, int hunters, int pts) {
    StageNode* temp = new StageNode;
    temp->board_file = b_file;
    temp->num_ships = ships;
    temp->num_hunters = hunters;
    temp->points = pts;
    temp->next = nullptr;

    if (head == nullptr) {
        head = temp;
    } else {
        StageNode* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

// Converts a directional state character into row and column coordinate shifts
void get_dr_dc(char dir, int& dr, int& dc) {
    dr = 0; dc = 0;
    if (dir == 'N') dr = -1;
    else if (dir == 'S') dr = 1;
    else if (dir == 'E') dc = 1;
    else if (dir == 'W') dc = -1;
}

// Returns the 180-degree opposite of the current direction
char get_opposite(char dir) {
    if (dir == 'N') return 'S';
    if (dir == 'S') return 'N';
    if (dir == 'E') return 'W';
    if (dir == 'W') return 'E';
    return dir;
}

// Returns the direction resulting from a 90-degree left turn
char get_left(char dir) {
    if (dir == 'N') return 'W';
    if (dir == 'W') return 'S';
    if (dir == 'S') return 'E';
    if (dir == 'E') return 'N';
    return dir;
}

// Returns the direction resulting from a 90-degree right turn
char get_right(char dir) {
    if (dir == 'N') return 'E';
    if (dir == 'E') return 'S';
    if (dir == 'S') return 'W';
    if (dir == 'W') return 'N';
    return dir;
}

// Generates a random starting direction for newly spawned entities
char get_random_dir() {
    int r = rand() % 4;
    if (r == 0) return 'N';
    if (r == 1) return 'S';
    if (r == 2) return 'E';
    return 'W';
}

// Handles user input mapping and applies player movement if the path is clear
void process_player(Object& player, int key, Board* b) {
    char intent_dir = player.state;

    // Map WASD keys to cardinal directions, and spacebar to pause
    if (key == 'w' || key == 'W') intent_dir = 'N';
    else if (key == 's' || key == 'S') intent_dir = 'S';
    else if (key == 'a' || key == 'A') intent_dir = 'W';
    else if (key == 'd' || key == 'D') intent_dir = 'E';
    else if (key == ' ') intent_dir = 'P';

    int next_r = player.r;
    int next_c = player.c;

    // Check for wall collisions before finalizing the next coordinates
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

// Handles automated star movement including random turns and wall bouncing
void process_star(Object& star, Board* b) {
    char intent_dir = star.state;
    
    // Add a random chance for the star to turn left or right
    int r = rand() % 10;
    if (r == 0) intent_dir = get_left(star.state);
    else if (r == 1) intent_dir = get_right(star.state);

    char final_state = intent_dir;
    int next_r = star.r;
    int next_c = star.c;

    int dr = 0, dc = 0;
    get_dr_dc(intent_dir, dr, dc);
    
    // Bounce backwards if hitting a wall, handling double-blocked scenarios
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

// Handles the active tracking logic for hunters chasing the player
void process_hunter(Object& hunter, Object& player, Board* b) {
    // Hunters only update their tracking direction 50% of the time
    if (rand() % 2 == 0) {
        int dc = player.c - hunter.c;
        int dr = player.r - hunter.r;

        // Prioritize moving along the axis with the greater distance to the player
        if (abs(dc) >= abs(dr)) {
            if (dc < 0) hunter.state = 'W';
            else if (dc > 0) hunter.state = 'E';
        } else {
            if (dr < 0) hunter.state = 'N';
            else if (dr > 0) hunter.state = 'S';
        }
    }

    char final_state = hunter.state;
    int next_r = hunter.r;
    int next_c = hunter.c;

    int dr = 0, dc = 0;
    get_dr_dc(hunter.state, dr, dc);
    
    // Hunters still respect wall boundaries and will bounce like stars if trapped
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

// Determines if two objects currently share the exact same grid coordinates
bool check_collision(Object p, Object e) {
    return (p.r == e.r && p.c == e.c);
}

// Simulates a single stage, returning true if the player reached the goal safely
bool play_stage(StageNode* stage, int& stage_score) {
    Board* b = load_board(stage->board_file);
    if (!b) {
        return false;
    }

    Object player = {'P', b->start.r, b->start.c, 'P'};
    
    // Calculate total entities based on the script multipliers
    int num_stars = b->num_Zs * stage->num_ships;
    int num_hunters = b->num_Zs * stage->num_hunters;

    Object* stars = new Object[num_stars];
    Object* hunters = new Object[num_hunters];
    
    int s_idx = 0;
    int h_idx = 0;
    
    // Populate the arrays with the correct number of entities at each spawn location
    for (int i = 0; i < b->num_Zs; i++) {
        for (int j = 0; j < stage->num_ships; j++) {
            stars[s_idx++] = {'*', b->spawns[i].r, b->spawns[i].c, get_random_dir()};
        }
        for (int j = 0; j < stage->num_hunters; j++) {
            hunters[h_idx++] = {'K', b->spawns[i].r, b->spawns[i].c, get_random_dir()};
        }
    }

    // Output starting metadata before switching the terminal context
    cout << "Player start: (" << b->start.r << "," << b->start.c << ")\n";
    cout << "Spawn spots :";
    for (int i = 0; i < b->num_Zs; i++) {
        cout << " (" << b->spawns[i].r << "," << b->spawns[i].c << ")";
    }
    cout << "\n";

    startCurses();

    bool game_over = false;
    bool won = false;
    int steps = 0;

    // Active frame loop for the current stage
    while (!game_over) {
        // Render the static environment
        for (int r = 0; r < b->rows; r++) {
            for (int c = 0; c < b->cols; c++) {
                drawChar(b->grid[r][c], r, c);
            }
        }
        drawChar('X', b->goal.r, b->goal.c);
        
        // Render the movable entities
        for (int i = 0; i < num_stars; i++) {
            drawChar('*', stars[i].r, stars[i].c);
        }
        for (int i = 0; i < num_hunters; i++) {
            drawChar('K', hunters[i].r, hunters[i].c);
        }
        drawChar('P', player.r, player.c);

        refreshWindow();

        // Check if the player has navigated to the exit marker
        if (player.r == b->goal.r && player.c == b->goal.c) {
            won = true;
            game_over = true;
            break;
        }

        // Check if the player was caught by any hazards
        for (int i = 0; i < num_stars; i++) {
            if (check_collision(player, stars[i])) { game_over = true; break; }
        }
        for (int i = 0; i < num_hunters; i++) {
            if (check_collision(player, hunters[i])) { game_over = true; break; }
        }
        if (game_over) break;

        // Process incoming commands
        int key = inputChar();
        if (key == 'q' || key == 'Q') {
            break;
        }

        // Apply logic updates for the next frame
        process_player(player, key, b);

        for (int i = 0; i < num_stars; i++) {
            process_star(stars[i], b);
        }
        for (int i = 0; i < num_hunters; i++) {
            process_hunter(hunters[i], player, b);
        }

        steps++;
        usleep(100000); 
    }

    // Delay briefly to let the user process the game over state
    sleep(1);
    endCurses();

    // Calculate stage points upon victory
    if (won) {
        stage_score = stage->points + (500 - steps);
    }

    // Free local dynamic allocations
    delete[] stars;
    delete[] hunters;
    free_board(b);

    return won;
}

int main() {
    srand(time(0)); 

    string script_file;
    cout << "Gamescript file: ";
    cin >> script_file;

    ifstream fin(script_file);
    if (!fin) {
        cout << "Error: Script file not found!\n";
        return 1;
    }

    StageNode* head = nullptr;
    string b_file, dummy1, dummy2;
    int ships, hunters, pts;

    // Parse the entire game script into memory
    while (fin >> b_file >> ships >> hunters >> dummy1 >> dummy2 >> pts) {
        append_stage(head, b_file, ships, hunters, pts);
    }

    StageNode* curr_stage = head;
    int total_score = 0;
    int attempts = 0;

    // Process each stage sequentially
    while (curr_stage != nullptr) {
        int stage_score = 0;
        bool won = play_stage(curr_stage, stage_score);

        if (won) {
            total_score += stage_score;
            cout << "You won, score = " << stage_score << "\n";
            
            sleep(1);
            
            // Advance to the next level upon success
            curr_stage = curr_stage->next;
            attempts = 0; 
        } else {
            cout << "You lost, they got you!\n";
            attempts++;
            
            // Terminate the run if the player fails the same stage twice
            if (attempts == 2) {
                cout << "Sorry, you haven't cleared all the stages.\n";
                break;
            }
            
            sleep(1);
        }
    }

    // Output final completion message if the entire list was traversed
    if (curr_stage == nullptr) {
        cout << "You cleared all the stages!\n";
    }
    
    cout << "total score = " << total_score << "\n";

    // Clean up the linked list structure before exiting
    while (head != nullptr) {
        StageNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}