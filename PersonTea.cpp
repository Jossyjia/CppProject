#include "PersonTea.h"

void PersonTea::lookschedule()
{
	for (int i = 0; i <= 6; i++) {
		for (int j = 1; j <= 5; j++) {
			if (schedule[i][j].done)
				schedule[i][j].print(i, j);
		}
	}
}
