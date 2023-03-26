#pragma once
#ifndef _DLL_H_
#define _DLL_H_

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>
#include <direct.h>
#include <cstring>
#include <cstdlib>
#include <chrono>

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

using namespace std;


class Taskas {
public:
    double x;
    double y;
};

extern "C"
DLL_API string ribojimas(string, string[], string[]);

extern "C"
DLL_API void nested_folders();

extern "C"
DLL_API double tschirnhausen(double, double);

extern "C"
DLL_API void writeToFile(double, double, int, double);

extern "C"
DLL_API void calculateTschirnhausen(double, double, double, double);

extern "C"
DLL_API void merge(double);

extern "C"
DLL_API void delete_root();

#endif
