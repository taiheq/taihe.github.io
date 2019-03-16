// ex21.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Lizi{
private:
	float zhongliang; //栗子多少斤
	float danjia; //一斤多少钱
	int goumairiqi; //哪天买的
public:
	Lizi(float x,float y,int z)   //构造函数的参数表
	{// (2) 在这里对private的属性（数据成员）赋值
		zhongliang=x,
			danjia=y,
			goumairiqi=z;
	}
	float Zongjia() // 计算这次购买的总价
	{
		return zhongliang*danjia;
	}
	int Goumairi() // 返回购买日期
	{
		return goumairiqi;
	}
};

int main()
{
	float zl,dj;
	int z,rq,i;//(3) 从键盘输入要保存多少张账单，存入变量z
	cout<<"请输入账单总数";
	cin>>z;
	Lizi *l[200]; //创建了类的数组，用来保存流水帐
	for (int i=0;i<z;i++){//(4) 循环中由键盘输入重量、单价、购买日期，存入数组
		cin>>zl>>dj>>rq;
		l[i]=new Lizi(zl,dj,rq);
	}
	float j=0;
	int zuihou=0,g=0;
	//g=l[1]->Goumairi();
	for(i=0;i<z;i++){//(5) 循环z次：累加总价，保存在变量j；找到最后购买时间，保存到变量zuihou
		j+=l[i]->Zongjia();
		if(zuihou<l[i]->Goumairi())
			zuihou=l[i]->Goumairi();
	}
	cout<<"Hua le "<<j<<" yuan qian."<<endl; //总共花了多少钱
	cout<<"zui hou gou mai ri qi = "<<zuihou<<endl; //最后购买日期
	system("pause");
	return 0;
}

