// ex4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
class Caidan
{
private:
	string Caiming;
	int Jiage;
public:
	static int Jilu;	//�����¼����
	Caidan(string cm, int gz = 0)
	{
		Caiming = cm;
		Jiage = gz;
		Jilu++;
	}
	Caidan(const Caidan &n)//(1) Copy���캯��
	{ Caiming = "[Jia]" + n.Caiming;
		Jiage = n.Jiage;
		Jilu++;
	}
		void Showjilu(int j)
	{
		cout << "\n No." << j << " " << Caiming<< " $" << Jiage;
	}
	void Gaijiage(int qian)
	{
		Jiage += qian;
	}
};
int Caidan::Jilu = 0; //(2)��̬���ݳ�Ա��ʼ��
void ShowAll(Caidan* dcd[])
{
	for (int j = 0; j < Caidan::Jilu; j++)
		dcd[j]->Showjilu(j);
	cout << "\n----END-----\n";
}
void Gaijiage(Caidan dcd,int qian) //(3)�������ݶ���
{
	dcd.Gaijiage(qian);
}
int main()
{
	Caidan* Xiaofeijilu[100] = { new Caidan("JiTui",4), new Caidan("YaTui",4),
							new Caidan("MiFan",1), new Caidan("QingCai",1) };
	while (1)
	{
		int i, rmb;
		cout << "\n 1-Gai Jia ge \n 2-Jia cai \n 3-Cha Xun\n Others-Tui chu\n>";
		cin >> i;
		if (i == 1)
		{
			ShowAll(Xiaofeijilu);
			int sj;
			cout << "\n> Gai Na Ge Jilu      Jia duo shao?";
			cin >> sj >> rmb; //(4)�Ӽ��������б���ţ�
			Gaijiage(Xiaofeijilu[sj],rmb);//(4)����Gaijiage�����޸����Ѽ�¼
		}
		else if (i == 2)
		{
			int n, m;
			cout << "\n> Jia Na Ge";
			cin >> n;//(5)�Ӽ��������б���ţ�������n
			m = Caidan::Jilu;//(5)��¼����������m
			Xiaofeijilu[m] = Xiaofeijilu[n];	//(5)��n���������Copy�����Ϊm���½�����
		}
		else if (i == 3)
			ShowAll(Xiaofeijilu);
		else break;
	}
	return 0;
}

