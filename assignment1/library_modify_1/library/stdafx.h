#ifndef WINVER 
#define WINVER 0x0600
#endif                               //最低平台Windows Vista，使用于其他版本
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif


#include<cstdlib>


#include"afxdb.h"
#include<odbcinst.h>                  //数据库相关

#include<iostream>
#include<sstream>
#include<tchar.h>
#include<string>
using namespace std;

#include"student.h"
#include"admin.h"