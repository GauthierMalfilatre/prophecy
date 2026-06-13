/*
** FREE PROJECT, 2026
** PROPHECY
** File description:
** Minheap utils
*/
#ifndef PROPHECY_MINHEAP_H
    #define PROPHECY_MINHEAP_H
    #include "prophecy.h"

void prMinHeap_add(prScheduler *sch, size_t idx);
void prMinHeap_remove(prScheduler *sch, size_t idx);
void prMinHeap_swap(prTask *task1, prTask *task2);

#endif /* PROPHECY_MINHEAP_H */
