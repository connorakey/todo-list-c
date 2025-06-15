
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *description;
  int priority;
} Task;

int main() {
  Task tasks[1000];
  char buffer[1024];
  int taskCount = 0;
  do {
    printf("------ Todo List Application ------\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Remove Task\n");
    printf("4. Exit\n");
    printf("Please select an option (1-4): ");

    int choice = 0;
    if (scanf("%d", &choice) != 1) {
      printf("\nInvalid input. Please enter a number between 1 and 4.\n");
      while (getchar() != '\n'); // Clear the input buffer
      continue;
    }
    getchar();

    switch (choice) {
    case 1:
      printf("\nDescription of the task: ");
      if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("\nError reading input.\n");
        break;
      }
      tasks[taskCount].description = malloc(strlen(buffer) + 1);
      if (tasks[taskCount].description == NULL) {
        printf("\nMemory allocation failed.\n");
        return 1;
      }
      strcpy(tasks[taskCount].description, buffer);
      printf("\nPriority of the task (1-1000): ");
      int bufferPriority;
      if (scanf("%d", &bufferPriority) != 1) {
        printf("\nInvalid input. Please enter a number between 1 and 1000.\n");
        free(tasks[taskCount].description);
        while (getchar() != '\n'); // Clear the input buffer
        break;
      }
      if (bufferPriority < 1 || bufferPriority > 1000) {
        printf(
            "\nInvalid priority. Please enter a number between 1 and 1000.\n");
        free(tasks[taskCount].description);
        return 1;
      } else {
        tasks[taskCount].priority = bufferPriority;
        taskCount++;
        printf("\nTask added successfully.\n");
      }
      break;
    case 2:
      printf("\nYour tasks:\n");
      for (int i = 0; i < taskCount; i++) {
        printf("Task %d: %sPriority: %d\n", i + 1, tasks[i].description,
               tasks[i].priority);
      }
      break;
    case 3:
      int taskNumber = 0;
      printf("\nEnter the task number to remove: \n");
      for (int i = 0; i < taskCount; i++) {
        printf("Task %d: %s", i + 1, tasks[i].description);
      }
      if (scanf("%d", &taskNumber) != 1) {
        printf("\nInvalid input. Please enter a valid task number.\n");
        while (getchar() != '\n');
        break;
      }
      if (taskNumber < 1 || taskNumber > taskCount) {
        printf("\nInvalid task number.\n");
      } else {
        free(tasks[taskNumber - 1].description);
        for (int i = taskNumber - 1; i < taskCount - 1; i++) {
          tasks[i] = tasks[i + 1];
        }
        taskCount--;
        printf("\nTask removed successfully.\n");
      }
      break;

    case 4:
      printf("\nExiting the application.\n");
      for (int i = 0; i < taskCount; i++) {
        free(tasks[i].description);
      }
      return 0;
      break;
      printf("\nYour choice of %d is not valid. Please select a number between "
             "1 and 4.\n",
             choice);
      break;
    }
  } while (taskCount < 1000);

  return 0;
}
