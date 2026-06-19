#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "habit.h"
#include "storage.h"

extern int getIntInput();

void viewHabit(Habit *habits, int habitCount) {
    for (int i = 0; i < habitCount; i++) {
        printf("%d. %s | Streak: %d | Status: %s\n",
               i + 1,
               habits[i].name,
               habits[i].streak,
               habits[i].complete ? "Complete" : "Not Complete");
    }
}

void addHabit(Habit **habits, int *habitCount, int *capacity) {

    if (*habitCount == *capacity) {
        *capacity *= 2;

        Habit *temp = realloc(*habits, (*capacity) * sizeof(Habit));
        if (!temp) return;

        *habits = temp;
    }

    char newHabit[100];

    printf("Enter new habit: ");
    fgets(newHabit, sizeof(newHabit), stdin);
    newHabit[strcspn(newHabit, "\n")] = '\0';

    strcpy((*habits)[*habitCount].name, newHabit);
    (*habits)[*habitCount].streak = 0;
    (*habits)[*habitCount].complete = 0;

    (*habitCount)++;
}

void deleteHabit(Habit *habits, int *habitCount) {

    if (*habitCount == 0) return;

    for (int i = 0; i < *habitCount; i++) {
        printf("%d. %s\n", i + 1, habits[i].name);
    }

    printf("Which habit to delete: ");
    int index = getIntInput() - 1;

    if (index < 0 || index >= *habitCount) {
        printf("Invalid index\n");
        return;
    }

    for (int i = index; i < *habitCount - 1; i++) {
        habits[i] = habits[i + 1];
    }

    (*habitCount)--;
}

void toggleHabit(Habit *habits, int habitCount) {

    if (habitCount == 0) return;

    printf("Pick habit to toggle:\n");
    for (int i = 0; i < habitCount; i++) {
        printf("%d. %s\n", i + 1, habits[i].name);
    }

    int index = getIntInput() - 1;

    if (index < 0 || index >= habitCount) {
        printf("Invalid index\n");
        return;
    }

    habits[index].complete = !habits[index].complete;

    if (habits[index].complete) {
        habits[index].streak++;
    }
}
