#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "habit.h"
#include "storage.h"

#define INITIAL_CAPACITY 2

int getIntInput() {
    char input[100];
    char *end;

    while (1) {
        printf("Enter your choice: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Input error\n");
            continue;
        }

        long value = strtol(input, &end, 10);

        if (end == input) {
            printf("Invalid input (numbers only)\n");
            continue;
        }

        if (*end != '\n' && *end != '\0') {
            printf("Invalid input (extra characters)\n");
            continue;
        }

        return (int)value;
    }
}

int main() {

    int capacity = INITIAL_CAPACITY;
    int habitCount = 0;

    Habit *habits = malloc(capacity * sizeof(Habit));
    if (!habits) return 1;

    loadHabit(&habits, &habitCount, &capacity);

    int menu = 0;

    while (menu != 5) {

        printf("\n--- HABIT TRACKER ---\n");
        printf("1. View\n2. Add\n3. Delete\n4. Toggle\n5. Exit\n");

        menu = getIntInput();

        if (menu == 1) {
            viewHabit(habits, habitCount);
        }
        else if (menu == 2) {
            addHabit(&habits, &habitCount, &capacity);
            saveHabit(habits, habitCount);
        }
        else if (menu == 3) {
            deleteHabit(habits, &habitCount);
            saveHabit(habits, habitCount);
        }
        else if (menu == 4) {
            toggleHabit(habits, habitCount);
            saveHabit(habits, habitCount);
        }
    }

    saveHabit(habits, habitCount);
    free(habits);

    return 0;
}