#include "S_compare.h"
#include "S_person.h"
#include "S_sort.h"

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main_sort(void) 
{
	int intArr[] = { 1,2,345,5467,221,34,-2345,-34 };
	size_t intArrLen = sizeof(intArr) / sizeof(intArr[0]);

	const char* stringArr[] = { "banana","apple","microsoft","tecent","xiaomi","huawei" };
	size_t stringArrLen = sizeof(stringArr) / sizeof(char*);

	genericSort(intArr, intArrLen, sizeof(int), intCompare, NULL);
	genericSort(stringArr, stringArrLen, sizeof(char*), stringCompare, NULL);
	puts("intArr[] = ");
	for (size_t i = 0; i < intArrLen; i++)
	{
		printf("%d ",intArr[i]);
	}

	puts("\nstringArr[] = ");
	for (size_t i = 0; i < stringArrLen; i++)
	{
		printf("%s ",stringArr[i]);
	}
	
	Person personArr[] = {
		{"Frank",30},
		{"Alice",24},
		{"Rigon",23},
		{"Dave",54}
	};

	size_t personArrLen = sizeof(personArr) / sizeof(Person);

	CompareFunc compareFunctions[] = { compareByName,compareByAge };

	int compareChoice = 1;		//0 for name, 1 for age
	genericSort(personArr, personArrLen, sizeof(Person), compareFunctions[compareChoice], NULL);

	puts("\npersonArr[] = ");
	for (size_t i = 0; i < personArrLen; i++)
	{
		printf("%s, %d\n", personArr[i].name, personArr[i].age);
	}

	return EXIT_SUCCESS;
}