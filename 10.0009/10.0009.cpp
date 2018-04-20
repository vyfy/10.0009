// 10.0009.cpp: определ€ет точку входа дл€ консольного приложени€.
//10.9.	ƒл€ каждой группы составить список студентов с успеваемостью выше средней на курсе.

#include "stdafx.h"
#include "CStudent.h" //ќбъ€вление класса обработки информации о студентах




int main()
{
	vector<CCStudent> all;
	ifstream filein("input.txt");
	string stemp;
	CCStudent temp;
	int j=0;
	while (!filein.eof()) //—оздание вектора студентов, т.к. количество студентов неизвестно.
	{
		getline(filein, stemp);
		temp.construct(stemp);
		all.insert(all.end(), temp);
		j++;
	}
	

	float MidAllMark = 0;// —редн€€ оценка у студента за все предметы.
	int GroupCount = 1; int a;
	vector<CCStudent>::iterator i;
	for (i = all.begin(); i != all.end(); ++i) 
	{
		a = temp.group;
				MidAllMark=MidAllMark+(i->GetMark());
				if(a>GroupCount)
				{
					GroupCount = a;
				}
	}
	MidAllMark = (MidAllMark / (j*(temp.QuantityMarks)));

	for (int ii = 1; ii != GroupCount + 1; ii++) 
	{
		int lp;lp = 0;
		cout << "\n In " <<ii << " group:" << endl;
		for (i = all.begin(); i != all.end(); i++)
		{
			
			float MidStMark = (i->GetMark()) / (temp.QuantityMarks);

			if (i->GetGroup() == ii)
			{
					if (MidStMark > MidAllMark) 
					{
						cout << "Student " << (i->FirstName) << " " << (i->LastName) << " has better marks then other students" << endl;
						lp++;
					}
			}
			
		}
		if (lp == 0) cout << "There are no excelent students in this group" << endl;
	}
	return 0;
}

