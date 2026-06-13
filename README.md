# Prophecy

Prophecy is a lightweight, efficient task scheduler library for C applications. It implements a **min-heap binary tree** to manage task priorities, ensuring optimal resource usage and fast task lookups.

## Features

- **Efficient Scheduling**: Uses a min-heap to keep the next upcoming task at the top.
- **One-time & Periodic Tasks**: Support for both punctual and recurring tasks.
- **Payload Support**: Attach custom data context to each task.
- **Lightweight**: Zero-dependency library, easy to integrate.
- **Multiple Build Systems**: Support for both CMake and Makefile.

## Installation

### Using CMake

```bash
mkdir build
cd build
cmake ..
make
```

### Using Makefile

```bash
make
```

This will generate `libprophecy.a`.

## Quick Start

Here is a simple example of how to use Prophecy:

```c
#include "prophecy.h"
#include <stdio.h>
#include <unistd.h>

// Your task handler
static void my_handler(void *context, void *data)
{
    printf("Task executed with data: %ld\n", (long int)data);
}

int main(void)
{
    // Create a scheduler with a capacity of 512 tasks
    prScheduler *sch = prScheduler_create(512);

    // Add a periodic task (runs in 2 ticks, then every 5 ticks)
    prScheduler_addTask(sch, prTask_create(&my_handler, (void *)1, 2, 5));

    // Add a punctual task (runs once in 10 ticks)
    prScheduler_addTask(sch, prTask_create(&my_handler, (void *)3, 10, 0));

    // Main loop
    while (1) {
        sleep(1); // Simulate time passing
        prScheduler_tick(sch, NULL);
    }

    prScheduler_destroy(sch);
    return 0;
}
```

## API Overview

### Scheduler Management
- `prScheduler_create(size_t size)`: Allocate and initialize a new scheduler.
- `prScheduler_destroy(prScheduler *sch)`: Free the scheduler and its resources.
- `prScheduler_tick(prScheduler *sch, void *context)`: Advance the scheduler by one tick and execute ready tasks.

### Task Management
- `prTask_create(prHandler handler, void *data, tick delay, tick interval)`: Build a task structure.
- `prScheduler_addTask(prScheduler *sch, prTask task)`: Register a task in the scheduler.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
