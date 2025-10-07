/*
  Game: Tic-Tac-Toe (Player X vs. Computer O)

  How it works:
  - Board is 9 cells (3x3) stored in an int array: 0=empty, 1=Player(X), 2=CPU(O).
  - Player enters their name (char array) and plays by choosing squares 1..9.
  - After each move, we draw the board and check for a winner or draw.
  - CPU is simple: it picks the first available empty square.
I thought this will be cool to make and very engagaing, I have made this in Java before as well 
*/

#include <stdio.h>   

// Draw the current board
void draw(int b[]) {
    char c[9];  // holds characters to print for each cell
    
for (int i = 0; i < 9; i++) { //loop through the board
    c[i] = '1' + i;           
    if (b[i] == 1) c[i] = 'X';// If board has player mark show it
    else if (b[i] == 2) c[i] = 'O'; //show cpu mark
}
//print the board
    printf("\n %c | %c | %c\n---+---+---\n %c | %c | %c\n---+---+---\n %c | %c | %c\n\n",
           c[0],c[1],c[2], c[3],c[4],c[5], c[6],c[7],c[8]);
}

// this returns 0=game continues, 1=player(X) wins, 2=CPU(O) wins, 3=draw
int winner(int b[]) {
	// All 8 winning line triplets
    int w[8][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };
    for (int i = 0; i < 8; i++) { //now we check each winning line
        int a = w[i][0], c = w[i][1], d = w[i][2];//indices in this line
        if (b[a] && b[a]==b[c] && b[c]==b[d]) return b[a]; // 1 or 2
    }
    for (int i = 0; i < 9; i++) if (b[i]==0) return 0;      // still spaces then continue
    return 3; // no spaces and no line is draw
}

// cpu  play the first open cell 
void cpu_move(int b[]) {//i used array argument here
    for (int i = 0; i < 9; i++) {//loop thrugh and place 0 where finds empty spot
        if (b[i] == 0) { b[i] = 2; return; }
    }
}

int main(void) {
    char name[32];         // Character array for player's name 
    int board[9] = {0};    // Integer array for board cells (rubric)
    int state;             // Game state from winner()

    // Read player name (allows spaces)
    printf("Enter your name: ");
    if (!fgets(name, sizeof(name), stdin)) return 1;//read line
    for (int i = 0; name[i]; i++) if (name[i]=='\n') { name[i]='\0'; break; } //trailing the new line if there is

    printf("Hi %s! You are X. Choose squares 1-9.\n", name); //prints this and then shows board
    draw(board);

    // Game loop: alternate player and CPU until win/draw
    while ((state = winner(board)) == 0) {
        int m;
        // Player turn
        printf("Your move (1-9): ");
        if (scanf("%d", &m) != 1) return 1;    // simple input 
        if (m < 1 || m > 9 || board[m-1] != 0) {
            printf("Invalid move. Try again.\n");
            // clear remainder of the line
            int ch;
	for (int cnt = 0; cnt < 1024; cnt++) {   // hard cap prevents infinite loops
   		 ch = getchar();                      // read one char
   		 if (ch == '\n') break;               // stop when we hit newline
}	
continue;                                // retry

        }
        board[m-1] = 1;
        draw(board);
        if ((state = winner(board)) != 0) break; // Check if game ended after player's move

        // CPU turn
        cpu_move(board);
        draw(board);
    }

    // Result
    if (state == 1)      printf("Congrats %s, you win!\n", name);
   else if (state == 2) printf("Computer wins. GG!\n");
     else                 printf("It's a draw.\n");

    return 0;



}
