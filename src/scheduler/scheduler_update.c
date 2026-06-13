/*
** FREE PROJECT, 2026
** PROPHECY
** File description:
** Update the scheduler
*/
#include "prophecy.h"
#include <stddef.h>
#include "../minheap/minheap.h"

size_t prScheduler_tick(prScheduler *sch, void *context)
{
    size_t done = 0;
    prTask ctask;

    sch->tick++;
    while (sch->count > 0 && sch->tasks[0].target <= sch->tick) {
        ctask = sch->tasks[0];
        prMinHeap_remove(sch, 0);
        ctask.handler(context, ctask.data);
        done++;
        if (ctask.interval > 0) {
            ctask.target = ctask.interval;
            prScheduler_addTask(sch, ctask);
        }
    }
    return done;
}
