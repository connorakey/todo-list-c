#ifndef CONFIG_H
#define CONFIG_H

#define MAX_TASKS 1000
#define BUFFER_SIZE 2056

typedef struct {
    char *description;
    int   priority;
} Task;

#endif
