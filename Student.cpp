#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string.h>

class Student
{
	char* name;//����
	char* major;//רҵ
	short int age;//����
	int ID;//ѧ��
	float gpa;//�ɼ�
public:
	Student(char*name,char*major,short int age, int ID);
	char* Getname();
	int GetID();
	short int Getage();
	~Student();
protected:
	void Changegpa(float GPA);//ӵ��Ȩ�޵��˲����޸�
	float Getgpa();//�ض�Ȩ�޵��˲��ܲ鿴
};

Student::Student(char*name,char*major,short int age,int ID)
{
	gpa = 0;
	if (!name)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	if (!major)
	{
		this->major = new char[strlen(major) + 1];
		strcpy(this->major, major);
	}
	this->age = age;
	this->ID = ID;
}

void Student::Changegpa(float GPA)
{
	this->gpa = GPA;
}

char* Student::Getname()
{
	return name;
}

short int Student::Getage()
{
	return age;
}

int Student::GetID()
{
	return ID;
}

float Student::Getgpa()
{
	return gpa;
}
Student::~Student()
{
	delete[]name;
}

