#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

Task tasks[MAX_TASKS];
char buffer[BUFFER_SIZE];
int  taskCount = 0;

void createTask(char *description, int priority);

void viewTasks();

void removeTask(int index);

int main() {
    while (1) {
        printf("\n------ Todo List Application ------\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Remove Task\n");
        printf("4. Exit\n");
        printf("Please select an option (1-4): ");

        int choice = 0;
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
            printf("Invalid choice. Please try again.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        getchar();

        switch (choice) {
            case 1:
                if (taskCount >= MAX_TASKS) {
                    printf("Maximum number of tasks reached.\n");
                    break;
                }

                printf("\nDescription of the task: ");
                if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                    printf("Error reading input.\n");
                    break;
                }

                printf("Priority of the task (1-1000): ");
                int bufferPriority;
                if (scanf("%d", &bufferPriority) != 1 || bufferPriority < 1 ||
                    bufferPriority > 1000) {
                    printf("Invalid priority. Please enter a number between 1 and 1000.\n");
                    while (getchar() != '\n')
                        ;
                    break;
                }
                getchar();

                createTask(buffer, bufferPriority);
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                if (taskCount == 0) {
                    printf("No tasks to remove.\n");
                    break;
                }
                viewTasks();
                printf("Enter task number to remove (1-%d): ", taskCount);
                int index;
                if (scanf("%d", &index) != 1 || index < 1 || index > taskCount) {
                    printf("Invalid task number.\n");
                    while (getchar() != '\n')
                        ;
                    break;
                }
                getchar();  // consume newline
                removeTask(index - 1);
                break;

            case 4:
                printf("Exiting...\n");
                for (int i = 0; i < taskCount; i++) {
                    free(tasks[i].description);
                }
                exit(0);
        }
    }
}

void createTask(char *description, int priority) {
    description[strcspn(description, "\n")] = 0;  // remove newline
    tasks[taskCount].description            = malloc(strlen(description) + 1);
    if (tasks[taskCount].description == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(tasks[taskCount].description, description);
    tasks[taskCount].priority = priority;
    taskCount++;
    printf("Task added successfully!\n");
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s (Priority: %d)\n", i + 1, tasks[i].description, tasks[i].priority);
    }
}

void removeTask(int index) {
    free(tasks[index].description);
    for (int i = index; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    printf("Task removed successfully.\n");
}
