#ifndef HABIT_H
#define HABIT_H

typedef struct {
    char name[100];
    int streak;
    char complete;
} Habit;

void viewHabit(Habit *habits, int habitCount);
void addHabit(Habit **habits, int *habitCount, int *capacity);
void deleteHabit(Habit *habits, int *habitCount);
void toggleHabit(Habit *habits, int habitCount);

#endif
