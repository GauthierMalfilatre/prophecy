/*
** FREE PROJECT, 2026
** PROPHECY
** File description:
** Swap two minheap tasks.
*/
#include "minheap.h"

void prMinHeap_swap(prTask *task1, prTask *task2)
{
    prTask tmp = *task1;

    *task1 = *task2;
    *task2 = tmp;
}
