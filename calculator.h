#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <string>
#include <iostream>
#include <stack>
#include <sstream>
using namespace std;


class Calculator{
public:
    Calculator();
    double get_result(string);  //结果存到result里面
    void test();
    string *format(string); //将字符串算是按照规则转换成字符串数组
private:
    string test2;
    stack<char> *OPTR; //寄存运算符
    stack<double> *OPND; //寄存操作数和结果
    double result;
    char Precede(char,char);    //判断优先级
    double Operate(double, double, char);   //计算二元表达式结果
    bool isSymble(char );   //判断c是否是运算符

};



#endif // CALCULATOR_H_INCLUDED
