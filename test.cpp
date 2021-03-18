#define _CRT_SECURE_NO_WARNINGS 1

#include"Myarr.h"



int main()
{
	SeqList S;
	Myarr::CreateArr(S, 5);
	Myarr::ArrEmpty(S);
	SeqElemtype e = { 18, "lihua" };
	Myarr::InserElement(S, 1, e);
	Myarr::ElementPos(S, e);
	Myarr::DeleteElement(S, 1);
	Myarr::ArrEmpty(S);
	Myarr::DestroyList(S);
}