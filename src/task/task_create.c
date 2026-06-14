/*
** FREE PROJECT, 2026
** PROPHECY
** File description:
** Create a task from parameters
*/
#include "prophecy.h"

inline prTask prTask_create(
    prHandler handler,
    prTaskData data,
    tick delay,
    tick interval
)
{
    return (prTask){
        .id = 0,
        .handler = handler,
        .data = data,
        .target = delay,
        .interval = interval,
    };
}
