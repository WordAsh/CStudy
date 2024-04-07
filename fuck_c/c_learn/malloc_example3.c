#include <stdio.h>
#include <errno.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Employee {
	char* name;
	int* task_list;
	int task_count;
}Employee;


Employee* create_employee(const char* name, int task_count);
void free_employee(Employee* employee);

int main_malloc3(void)
{
	Employee* employee = create_employee("Developer", 5);

	if (employee == NULL) return EXIT_FAILURE;

	employee->task_list[0] = 101;

	printf("Assigned task for %s: %d\n",employee->name,employee->task_list[0]);

	free_employee(employee);

	return EXIT_SUCCESS;
}

Employee* create_employee(const char* name, int task_count) {
	Employee* employee = (Employee*)malloc(sizeof(Employee));

	if (employee == NULL) {
		perror("Failed to allocate memory for employee.");
		return NULL;
	}

	employee->name = (char*)malloc(strlen(name) + 1);
	if (employee->name == NULL) {
		perror("Failed to allocate memory for employee name.");
		free(employee);
		return NULL;
	}

	strcpy_s(employee->name, strlen(name) + 1, name);
	employee->task_count = task_count;
	employee->task_list = (int*)calloc(task_count, sizeof(int));
	if (employee->task_list == NULL) {
		perror("Failed to allocate memory for employee task list.");
		free(employee->name);
		free(employee);
		return NULL;
	}

	return employee;
}


void free_employee(Employee* employee) {
	if (employee != NULL) {
		free(employee->task_list);
		free(employee->name);
		free(employee);
	}
}