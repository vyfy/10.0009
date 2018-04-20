#pragma once
#include "stdafx.h"
class CCStudent
{

	
	bool gender;
	int *ArrMarks;
	
public:
	string FirstName;
	string LastName;
	int group;
	int QuantityMarks;
	void construct(string data); //"Сборка" студента по строке информации о нём.
	CCStudent(string data);
	int GetGroup() 
	{ 
		return group;
	}
	int GetMark(); 
	CCStudent();
	~CCStudent();
};

