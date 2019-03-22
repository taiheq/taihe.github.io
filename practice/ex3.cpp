// ex3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <ctime>
using namespace std;
class Tushuguan
{
private:
	time_t jieshijian;    //借出时间
public:
	const double jieduojiu;   //可以借多久
	const int xszheng;   //谁借的
	const int shuhao;    //书号
	Tushuguan(int x,int y,int z) : jieduojiu(x),xszheng(y),shuhao(z)
	{
		jieshijian = time(0);
	}
	~Tushuguan()      //析构函数, 显示书已经归还
	{
		cout << "1";
		cout << " ***" << xszheng << " huan le " << shuhao << ". Jie chu shi jian=" << Jieleduojiu() << endl;
	}
	double Jieleduojiu()
	{
		cout << "2";
		return difftime(time(0), jieshijian);
	} //借了多久=当前时间-借出时间
	int Daoqi()
	{
		cout << "3";
		int t = jieduojiu - Jieleduojiu();
		if (t < 0) { cout << "***Guoqi***"; t = 0; }
		return t;
	}
};
int main()
{
	Tushuguan* jilu[100];
	int jl = 0;
	while (1) {
		int i, jq, xsz, sh ;
		cout << "\n 1-Jieshu\n 2-Huan shu\n 3-cha xun\n Qita-tui chu\n";
		cin >> i;
		if (i == 1) {
			cout << "\n  Jieduojiu Xueshengzheng Shuhao:";
			//cin >> jq >> xsz >> sh;//   (4) 从键盘读入借书时长存入jq、读入学号存入xsz、读入书号存入sh;
			jilu[jl] = new Tushuguan(12, 23, 34);   //(4) 用new新建一个对象，返回地址存入数组jilu
			jl++;//   (4) 记录数自增1
		}
		else if (i == 2) {
			delete [] jilu[jl];	//删除jilu所指向的对象
			jl--;				//   (5) 记录数自减1
		}
		else if (i == 3) {
			for (int j = 0; j < jl; j++)
				cout << j << ": XSZ " << jilu[j]->xszheng << "| ISBN" << jilu[j]->shuhao <<
				"| GuiHuan" << jilu[j]->jieduojiu << "| Daoqi" << jilu[j]->Daoqi() << endl;
		}
		else break;
	}
	system("pause");
	return 0;
}
