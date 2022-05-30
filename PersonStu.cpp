#include "PersonStu.h"

void PersonStu::xuan(LessonStu a)
{
	Time t = a.time;
	int w = t.weekday, o = t.order;
	schedule[w][o] = a;
	schedule[w][o].done = 1;
}

void PersonStu::tui(int week, int order)
{
	schedule[week][order].done = 0;
}

int PersonStu::lookscore(int w, int o)
{
	return schedule[w][o].score;
}

void PersonStu::lookschedule()
{
	for (int i = 0;i <= 6; i++) {
		for (int j = 0; j <= 4; j++) {
			if(schedule[i][j].done)schedule[i][j].print(i,j);
		}
	}
}
