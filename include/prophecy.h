/*
** FREE PROJECT, 2026
** PROPHECY
** File description:
** Definitions of structs and methods for prophecy lib
*/
#ifndef PROPHECY_H
    #define PROPHECY_H
    #include <stdint.h>
    #include <stddef.h>

typedef void (*prHandler)(void *, void *);
typedef uint64_t tick;

/*
** This task scheduler will implemente a min - heap binary tree,
** in order to optimize ressources and checking.
** https://www.geeksforgeeks.org/c/c-program-to-implement-min-heap/
*/

///////////////////////////////////////////////////////////////////////////////
/**
 * @struct prophecy_task_s
 *
 * @brief  task definition
 */
///////////////////////////////////////////////////////////////////////////////
typedef struct prophecy_task_s {

    size_t     id;        //!< The id of the tasks
    prHandler  handler;   //!< The handler (callback)
    void      *data;      //!< The data (payload) to give to the handler
    tick       interval;  //!< The interval (0 if ponctual, > 0 else)
    tick       target;     //!< The tick remainings.

} prTask;
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/**
 * @struct prophecy_scheduler_s
 *
 * @brief  scheduler definition
 */
///////////////////////////////////////////////////////////////////////////////
typedef struct prophecy_scheduler_s {

    prTask  *tasks;  //!< The raw array of tasks
    size_t   size;   //!< The size of tasks raw array
    size_t   count;  //!< The number of tasks pushed
    tick     tick;   //!< The current tick (please tick scheduler at each loop)

} prScheduler;
///////////////////////////////////////////////////////////////////////////////

// TODO: Documention
prScheduler *prScheduler_create(size_t size);
void prScheduler_destroy(prScheduler *sch);
int prScheduler_init(prScheduler *sch, size_t size);
void prScheduler_clear(prScheduler *sch);

#endif /* PROPHECY_H */
