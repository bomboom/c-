#ifndef WINVER // ָ��Ҫ������ƽ̨�� Windows Vista��
#define WINVER 0x0600 // ����ֵ����Ϊ��Ӧ��ֵ���������� Windows �������汾��
#endif

#ifndef _WIN32_WINNT // ָ��Ҫ������ƽ̨�� Windows Vista��
#define _WIN32_WINNT 0x0600 // ����ֵ����Ϊ��Ӧ��ֵ���������� Windows �������汾��
#endif  

#include<cstdlib>    //�ṩ��������ת������

#include"afxdb.h"
#include<odbcinst.h>  //ODBC

#include <string>
#include<iostream>
#include<sstream>
#include<tchar.h>
using namespace std;

#include "MYDatabase.h"
#include"bank.h"
#include"worker.h"
