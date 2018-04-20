#include "stdafx.h"
#include "CStudent.h"


CCStudent::CCStudent(string data)
{
	construct(data);
}


CCStudent::CCStudent()
{
	FirstName = "void";
	LastName = "void";
	group = -1;
	gender = 1;
}


CCStudent::~CCStudent()
{
}


void CCStudent::construct(string data)
{
	stringstream ss(data);
	string stemp;
	ss >> FirstName;
	ss >> LastName;
	ss >> stemp;
	group = stoi(stemp);
	ss >> stemp;
	if (stemp == "f")
		gender = 1;
	else
		gender = 0;
	int i = 0;
	int pos = ss.tellg();
	while (!ss.eof())
	{
		ss >> stemp;
		i++;
	}
	ss.seekg(pos);
	QuantityMarks = i;
	ArrMarks = new int[QuantityMarks];
	for (int j = 0; j != i; j++)
		ss >> ArrMarks[j];
}

int CCStudent::GetMark()
{
	int mark = 0;
	for (int i = 0; i <QuantityMarks; i++)
	{
			mark =mark+ ArrMarks[i];
	}
	return mark;// Сумма оценок у одного студента.
}