#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "habit.h"
#include "storage.h"

void loadHabit(Habit **habits, int *habitCount, int *capacity) {
    FILE *file = fopen("habits1.txt", "r");
    if (!file) return;

    char line[200];

    while (fgets(line, sizeof(line), file)) {

        if (*habitCount == *capacity) {
            *capacity *= 2;

            Habit *temp = realloc(*habits, (*capacity) * sizeof(Habit));
            if (!temp) return;

            *habits = temp;
        }

        char *name = strtok(line, "|");
        char *streakText = strtok(NULL, "|");
        char *completeText = strtok(NULL, "\n");

        if (!name || !streakText || !completeText) continue;

        strcpy((*habits)[*habitCount].name, name);
        (*habits)[*habitCount].streak = atoi(streakText);
        (*habits)[*habitCount].complete = atoi(completeText);

        (*habitCount)++;
    }

    fclose(file);
}

void saveHabit(Habit *habits, int habitCount) {
    FILE *file = fopen("habits1.txt", "w");
    if (!file) return;

    for (int i = 0; i < habitCount; i++) {
        fprintf(file, "%s|%d|%d\n",
                habits[i].name,
                habits[i].streak,
                habits[i].complete);
    }

    fclose(file);
}