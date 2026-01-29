#include <bits/types/struct_sigstack.h>
#include <stdio.h>
#include <stdbool.h>

// Function declarations
void print_board(char board[3][3]);
bool check_win(char board[3][3], char player);
bool check_draw(char board[3][3]);
void player_move(char board[3][3], char player);

int main() {
  // Initialize game board with numbers 1-9
  char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
  };

  char current_player = 'X';
  bool game_won = false;
  bool game_draw = false;
  
  printf("Welcome to Tic-Tac-Toe!\n");
  printf("Player 1: X\nPlayer 2: O\n\n");

  // Main game loop
  while(!game_won && !game_draw) {
    print_board(board);
    printf("\nPlayer %c's turn\n", current_player);
    player_move(board, current_player);

    // Check if current player won
    game_won = check_win(board, current_player);
    if(game_won) {
      print_board(board);
      printf("\nPlayer %c wins!\n", current_player);
      break;
    }
    // Switch players
    current_player = (current_player == 'X') ? 'O' : 'X';
  }
  return 0;
}

// Print the game board
void print_board(char board[3][3]) {
  printf("\n");
  for(int i = 0; i < 3; i++) {
    printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
    if(i < 2) {
      printf("---|---|---\n");
    }
  }
  printf("\n");
}

// Handle player's move
void player_move(char board[3][3], char player) {
  int choice;
  bool valid_move = false;

  while(!valid_move) {
    printf("Enter your move (1-9): ");
    scanf("%d", &choice);

    // Check if choice is valid (1-9)
    if(choice < 1 || choice > 9) {
      printf("Invalid choice! Please enter a number between 1-9.\n");
      continue;
    }
    // Convert choice to row and column
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    // Check if the spot is already taken
    if(board[row][col] == 'X' || board[row][col] == 'O') {
      printf("That spot is already taken! Please choose another.\n");
    }
    else {
      board[row][col] = player;
      valid_move = true;
    }
  }
}

// Check if a player has won
bool check_win(char board[3][3], char player) {
  // Check columns
  for(int i = 0; i < 3; i++) {
    if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return true;
    }
  }
  // Check rows
  for(int i = 0; i < 3; i++) {
    if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
  }
  // Check diagonal (top-left to bottom-right)
  if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  // Check diagonal (top-right to bottom-left)
  if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }
  return false;
}

// Check if game is a draw
bool check_draw(char board[3][3]) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      // If any spot still has a number, game is not a draw
      if(board[i][j] != 'X' && board[i][j] != 'O') {
        return false;
      }
    }
  }
  return true; // All spots filled and no winner: draw
}
