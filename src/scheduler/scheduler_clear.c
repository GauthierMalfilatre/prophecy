/*
** FREE PROJECT, 2026
** PROPHECY
** File description:
** Clear a scheduler
*/
#include "prophecy.h"
#include <stdlib.h>

void prScheduler_clear(prScheduler *sch)
{
    if (!sch) {
        return;
    }
    if (sch->tasks) {
        free(sch->tasks);
    }
    sch->count = 0;
    sch->size = 0;
    sch->tick = 0;
}
