#pragma once

#if BuildDLL
#define MyMath_API __declspec(dllexport)

#else
#define MyMath_API __declspec(dllimport)

#endif

int MyMath_API Add(int a, int b);