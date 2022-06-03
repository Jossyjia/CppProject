#include "PersonStu.h"

PersonStu& PersonStu::operator=(PersonStu& s)
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
		for (int j = 1; j <= 5; j++) {
			if(schedule[i][j].done)
				schedule[i][j].print(i,j);
		}
	}
}
