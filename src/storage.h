#ifndef STORAGE_H
#define STORAGE_H

#include "habit.h"

void loadHabit(Habit **habits, int *habitCount, int *capacity);
void saveHabit(Habit *habits, int habitCount);

#endif
