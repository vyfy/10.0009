// 10.0009.cpp: ���������� ����� ����� ��� ����������� ����������.
//10.9.	��� ������ ������ ��������� ������ ��������� � ������������� ���� ������� �� �����.

#include "stdafx.h"
#include "CStudent.h" //���������� ������ ��������� ���������� � ���������




int main()
{
	vector<CCStudent> all;
	ifstream filein("input.txt");
	string stemp;
	CCStudent temp;
	int j=0;
	while (!filein.eof()) //�������� ������� ���������, �.�. ���������� ��������� ����������.
	{
		getline(filein, stemp);
		temp.construct(stemp);
		all.insert(all.end(), temp);
		j++;
	}
	

	float MidAllMark = 0;// ������� ������ � �������� �� ��� ��������.
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

