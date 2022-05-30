#include "PersonTea.h"

void PersonTea::lookschedule()
{
	for (int i = 0; i <= 6; i++) {
		for (int j = 0; j <= 4; j++) {
			if (schedule[i][j].done)schedule[i][j].print(i, j);
		}
	}
}
