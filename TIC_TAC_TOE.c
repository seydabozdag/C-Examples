#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE];

void initialize_board() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void display_board() {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

bool check_winner(char player) {

    for(int i = 0; i < SIZE; i++) {

        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;

        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;

    }

    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
        
    return false;
}

bool check_draw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    int row, col;
    char current_player = 'X';
    bool game_over = false;

    initialize_board();

    while(!game_over) {
        printf("Player %c's turn\n", current_player);
        display_board();

        printf("Enter row and column (0-2): ");
        scanf("%d %d", &row, &col);

        if(board[row][col] == ' ') {
            board[row][col] = current_player;

            if(check_winner(current_player)) {
                printf("Player %c wins!\n", current_player);
                game_over = true;
            } else if(check_draw()) {  
                printf("It's a draw!\n");
                game_over = true;
            }

            if(current_player == 'X')
                current_player = 'O';
            else
                current_player = 'X';
        } else {
            printf("That cell is already taken. Try again.\n");
        }
    }

    display_board();
    return 0;
}
