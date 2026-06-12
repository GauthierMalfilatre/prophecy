/*
** FREE PROJECT, 2026
** PROPHECY
** File description:
** add a task to the scheduler
*/
#include "prophecy.h"
#include <stddef.h>
#include <stdlib.h>

static int __prScheduler_ensureCapacity(prScheduler *sch)
{
    prTask *old = sch->tasks;
    size_t newSize = (sch->size == 0) ? 16 : sch->size * 2;

    sch->tasks = reallocarray(sch->tasks, newSize, sizeof(prTask));
    if (!sch->tasks) {
        sch->tasks = old;
        return -1;
    }
    sch->size = newSize;
    return 0;
}

static void __prScheduler_swapTasks(prTask *task1, prTask *task2)
{
    prTask tmp = *task1;

    *task1 = *task2;
    *task2 = tmp;
}

/*
** To know parent      : (i - 1) / 2 (>> 1)
** To know left child  : (2 * i) + 1 (<< 1)
** To know right child : (2 * i) + 2 (<< 1)
*/
// DEBUG: Bubble up
static void __prScheduler_buildMinHeap(prScheduler *sch, size_t idx)
{
    while (idx > 0 && sch->tasks[(idx - 1) >> 1].target > sch->tasks[idx].target) {
        __prScheduler_swapTasks(&sch->tasks[idx],  &sch->tasks[(idx - 1) >> 1]);
        idx = (idx - 1) >> 1;
    }
}

size_t prScheduler_addTask(prScheduler *sch, prTask task)
{
    static size_t _id = 1;

    if (sch->count >= sch->size) {
        if (__prScheduler_ensureCapacity(sch) == -1) {
            return 0;
        }
    }
    sch->tasks[sch->count] = task; 
    sch->tasks[sch->count].id = _id;
    sch->tasks[sch->count].target = sch->tick + task.target;
    __prScheduler_buildMinHeap(sch, sch->count);
    ++sch->count;
    return _id++;
}
