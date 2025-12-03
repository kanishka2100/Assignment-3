# 🎮 Fruit Catcher (Console Game in C)

Fruit Catcher is a lightweight console-based arcade game developed in C.  
Your objective is simple: move the basket left or right to catch falling fruits before they hit the ground.  
With minimal controls and clean logic, this project is ideal for beginners learning C programming.

---

## 🚀 Features
- 3-lane movement system  
- Real-time keyboard controls using **arrow keys**  
- Animated falling fruit  
- Score tracking  
- Miss counter (3 misses = Game Over)  
- Persistent high score stored in `score.txt`  
- Smooth console rendering  
- Beginner-friendly and easily extendable  

---

## 🕹️ Controls

| Key              | Action             |
|------------------|--------------------|
| **← Left Arrow** | Move basket left   |
| **→ Right Arrow**| Move basket right  |
| **Q**            | Quit the game      |
| **R**            | Restart after Game Over |

---

## 📘 How the Game Works

- A fruit (`F`) randomly appears in one of three lanes.  
- Each frame, the fruit drops down one step.  
- When it reaches the last row:  
  - If the basket (`[ ]`) is in the same lane → **Caught (Score +1)**  
  - Otherwise → **Miss (Miss +1)**  
- After **3 misses**, the game ends.  
- If the score is greater than the saved high score, the high score is updated.

---

## 📦 File Structure

```
Fruit-Catcher/
│
├── fruitcatcher.c    # Main game source code
├── score.txt          # High score storage (auto-created)
└── README.md          # Project documentation
```

---

## ⚙️ Build & Run Instructions

### Requirements
- GCC (MinGW recommended for Windows)
- Windows Command Prompt or PowerShell

### Compile the Game
```bash
gcc fruitcatcher.c -o fruitcatcher
```

### Run the Game
```bash
fruitcatcher
```

---

## 🧱 Concepts Demonstrated

This project uses only basic C programming concepts:

- `while` loops  
- `if/else` conditions  
- `rand()` for random lane selection  
- Console control using `system("cls")`  
- Delay using `Sleep()`  
- Real-time input using `_kbhit()` and `_getch()`  
- File handling (`fopen`, `fprintf`, `fscanf`)  
- ASCII-based UI rendering  

---

## 📄 Purpose of This Project
This game serves as a simple demonstration of:

- Console game development in C  
- Basic animation and movement  
- Real-time user interaction  
- Score and state management  
- File handling for persistent data  

It is suitable as:
- A mini project  
- An academic assignment  
- A beginner C programming reference  

---

## 📜 License
This project is free to use and modify for learning and educational purposes.

