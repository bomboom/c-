#ifndef WINVER // 指定要求的最低平台是 Windows Vista。
#define WINVER 0x0600 // 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif

#ifndef _WIN32_WINNT // 指定要求的最低平台是 Windows Vista。
#define _WIN32_WINNT 0x0600 // 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif  

#include<cstdlib>    //提供数据类型转换函数

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
