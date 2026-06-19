# Habit Tracker in C (CLI Project)

A command-line Habit Tracker written in C to practice low-level programming concepts such as pointers, dynamic memory allocation, structs, file I/O, and safe input handling.

---

## Features

- Add new habits dynamically
- Delete existing habits
- Toggle completion status
- Track simple streak values
- Persistent storage using file I/O (save/load from file)
- Dynamic memory allocation using malloc and realloc
- Safe integer input parsing using strtol
- Input validation to prevent crashes or invalid data

---

## Technical Concepts Used

- C structs for data modeling
- Pointers and pointer manipulation
- Dynamic memory management (malloc, realloc, free)
- File handling (fopen, fgets, fprintf)
- String parsing (strtok)
- Safe input handling using strtol
- CLI-based menu system design

---

## How It Works

1. On startup, the program loads saved habits from habits1.txt
2. The user interacts through a menu system:
   - View habits
   - Add habits
   - Delete habits
   - Toggle completion status
3. Data is stored in a dynamically resizable array
4. All changes are saved back to the file
5. Memory is freed before program exit

---

## Build & Run

Compile:

```bash
gcc src/*.c -o habit-tracker


```

Run:
```bash


./habit-tracker


```
## File Structure

```
habit-tracker-c/
├── src/
│   ├── main.c
│   ├── habit.c
│   ├── habit.h
│   ├── storage.c
│   ├── storage.h
│   ├── data/
│   │   └── habits1.txt
├── README.md
└── Makefile
```


