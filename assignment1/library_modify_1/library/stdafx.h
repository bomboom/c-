#ifndef WINVER 
#define WINVER 0x0600
#endif                               //���ƽ̨Windows Vista��ʹ���������汾
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif


#include<cstdlib>


#include"afxdb.h"
#include<odbcinst.h>                  //���ݿ����

#include<iostream>
#include<sstream>
#include<tchar.h>
#include<string>
using namespace std;

#include"student.h"
#include"admin.h"