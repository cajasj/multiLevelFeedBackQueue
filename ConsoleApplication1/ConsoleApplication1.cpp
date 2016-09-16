
#include "stdafx.h"
#include <time.h>  
#include <iostream>
#include <deque>
using namespace std;


class process {
public:
	std::deque<int> deque;
	std::deque<int> timeClass;


};
void createProcess(process &q1, process &q2, process &q3, int i,int &step);
void reduce(process &q1, process &q2, process &q3, int &idUsed, int &step);
int _tmain(int argc, _TCHAR* argv[])
{

	process q1;
	process q2;
	process q3;
	
	int random = rand() % 17 + 1;
	int i = 0;
	int step = 1;
	for (i = 0; i < 24; i++) {
		createProcess(q1, q2, q3, i,step);
		
	}

	int idUsed = i;
	i = 0;
	int x = 0;
	int y = 0;
	while (y < 60) {
		reduce(q1, q2, q3, idUsed,step);
		y++;
	}
	return 0;
}

void createProcess(process &q1, process &q2, process &q3, int i, int &step) {
	int random = rand() % 18 + 1;
	if (random < 7) {
		q1.deque.push_back(i);
		q1.timeClass.push_back(random);
		cout << "step " << step << " ID " << q1.deque.back() << " with remaining time of " <<  q1.timeClass.back() << " moved to q1" << endl;
		step++;
	}
	else if (random < 12) {
		q2.deque.push_back(i);
		q2.timeClass.push_back(random);
		cout << "step " << step << " ID " << q2.deque.back() << " with remaining time of " << q2.timeClass.back() << " moved to q2" << endl;
		step++;
	}
	else {
		q3.deque.push_back(i);
		q3.timeClass.push_back(random);
		q3.deque.front();
		cout << "step " << step << " ID " << q3.deque.back() << " with remaining time of " << q3.timeClass.back() << " moved to q3" << endl;
		step++;
	}

}
void reduce(process &q1, process &q2, process &q3, int &idUsed, int &step) {
	if (!q1.timeClass.empty()) {
		if (q1.timeClass.front() < 7 && q1.timeClass.front() > 0) {

			q1.timeClass.front() -= 3;
			if (q1.timeClass.front() <= 0) {
				step++;
				cout << "step " << step << " ID " << q1.deque.front() << " has been remove from queue 1" << endl;
				idUsed++;
				q1.deque.pop_front();
				q1.timeClass.pop_front();
				createProcess(q1, q2, q3, idUsed, step);


			}
		}
	}
	if (!q2.timeClass.empty()) {
		if (q2.timeClass.front() < 12 && q2.timeClass.front() >= 7) {
			q2.timeClass.front() -= 2;
			if (q2.timeClass.front() <= 6) {
				step++;
				cout << "step " << step << " ID " << q2.deque.front() << " with remaining time of " << q2.timeClass.front() << " moved to q1 " << endl;
				q1.timeClass.push_back(q2.timeClass.front());
				q1.deque.push_back(q2.deque.front());

				q2.deque.pop_front();
				q2.timeClass.pop_front();

			}
		}
	}
	if (!q3.timeClass.empty()) {
		if (q3.timeClass.front() < 18 && q3.timeClass.front() >= 12) {
			q3.timeClass.front() -= 1;
			if (q3.timeClass.front() <= 11) {
				step++;
				cout << "step " << step << " ID " << q3.deque.front() << " with remaining time of " << q3.timeClass.front() << " moved to q2" << endl;
				q2.timeClass.push_back(q3.timeClass.front());
				q2.deque.push_back(q3.deque.front());
				q3.deque.pop_front();
				q3.timeClass.pop_front();
			}
		}

	}
}
