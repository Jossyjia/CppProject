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

PersonTea& PersonTea::operator=(PersonTea& s)
{
	for (int i = 0; i <= 6; i++) {
		for (int j = 1; j <= 5; j++) {
			this->schedule[i][j] = s.schedule[i][j];
			this->schedule[i][j].done = s.schedule[i][j].done;
		}
	}
	return *this;
	// TODO: 在此处插入 return 语句
}
