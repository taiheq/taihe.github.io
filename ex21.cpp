// ex21.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Lizi{
private:
	float zhongliang; //���Ӷ��ٽ�
	float danjia; //һ�����Ǯ
	int goumairiqi; //�������
public:
	Lizi(float x,float y,int z)   //���캯���Ĳ�����
	{// (2) �������private�����ԣ����ݳ�Ա����ֵ
		zhongliang=x,
			danjia=y,
			goumairiqi=z;
	}
	float Zongjia() // ������ι�����ܼ�
	{
		return zhongliang*danjia;
	}
	int Goumairi() // ���ع�������
	{
		return goumairiqi;
	}
};

int main()
{
	float zl,dj;
	int z,rq,i;//(3) �Ӽ�������Ҫ����������˵����������z
	cout<<"�������˵�����";
	cin>>z;
	Lizi *l[200]; //������������飬����������ˮ��
	for (int i=0;i<z;i++){//(4) ѭ�����ɼ����������������ۡ��������ڣ���������
		cin>>zl>>dj>>rq;
		l[i]=new Lizi(zl,dj,rq);
	}
	float j=0;
	int zuihou=0,g=0;
	//g=l[1]->Goumairi();
	for(i=0;i<z;i++){//(5) ѭ��z�Σ��ۼ��ܼۣ������ڱ���j���ҵ������ʱ�䣬���浽����zuihou
		j+=l[i]->Zongjia();
		if(zuihou<l[i]->Goumairi())
			zuihou=l[i]->Goumairi();
	}
	cout<<"Hua le "<<j<<" yuan qian."<<endl; //�ܹ����˶���Ǯ
	cout<<"zui hou gou mai ri qi = "<<zuihou<<endl; //���������
	system("pause");
	return 0;
}

