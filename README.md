# ❌⭕ Tic-Tac-Toe in C (Player vs Computer) 🎮

A tiny terminal Tic-Tac-Toe you can compile and play in seconds.  
You are **X**, the computer is **O**. First to 3-in-a-row wins!

---

## ✨ Features

- 3×3 board stored as an `int` array (`0` empty, `1` X, `2` O)
- Player name captured with a `char` array (spaces supported)
- Clear ASCII board after every move
- Simple CPU: picks the **first open** cell
- Input validation and clean prompts
- Single C file, no external dependencies

---

## 🧰 Requirements

- C11-compatible compiler (GCC or Clang)
- Any terminal (Linux/macOS/WSL/Windows)

---
##Sample session

Enter your name: Heer
Hi Heer! You are X. Choose squares 1-9.

 1 | 2 | 3
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9

Your move (1-9): 5

 1 | 2 | 3
---+---+---
 4 | X | 6
---+---+---
 7 | 8 | 9

 1 | 2 | O
---+---+---
 4 | X | 6
---+---+---
 7 | 8 | 9

Your move (1-9): 1
...
Congrats Heer, you win!


### Linux / macOS / WSL
```bash
gcc -std=c11 -Wall -Wextra -O2 tictactoe.c -o ttt
./ttt
