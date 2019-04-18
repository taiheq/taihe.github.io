// ex5_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
class vipcustomer {
private:

public:
	string vip_name;
	int vip_num;
	vipcustomer();
	vipcustomer(int vip_num1, string vip_name1);
	int getnumber();
	string getname();
	void show();
	
};

vipcustomer::vipcustomer() {
	vip_num = 0;
	vip_name = "";
}

vipcustomer::vipcustomer(int vip_num1, string vip_name1) {
	vip_num = vip_num1;
	vip_name = vip_name1;
}

int vipcustomer::getnumber() {
	return vip_num;
}

string vipcustomer::getname() {
	return vip_name;
}

void vipcustomer::show() {
	cout << "��Ա�ţ� "<<vip_num << "��Ա���� " << vip_name << endl;
}

class product {
private:

public:
	string product_name, product_num;
	double product_price;
	product();
	product(string pd_num, string pd_name, double pd_price);
	void show();
	string getproduct_num();
	string getproduct_name();
	double getproduct_price();
	void chang(int pri);
};

product::product() {
	product_num = "";
	product_name = "";
	product_price = 0;
}

product::product(string pd_num, string pd_name, double pd_price) {
	product_num = pd_num;
	product_name = pd_name;
	product_price = pd_price;
}

void product::show() {
	cout <<"��Ʒ�ţ� " << product_num <<"��Ʒ���֣� "<< product_name<<"��Ʒ���ۣ� " << product_price << endl;
}

string product::getproduct_num() {
	return product_num;
}

string product::getproduct_name() {
	return product_name;
}

double product::getproduct_price() {
	return product_price;
}

void product::chang(int pri){
	product_price = pri;
}

class bill {
private:
public:
	string product_name[10000] , product_number[10000];
	int precode=0;
	string vip_name;
	int bill_number, data, amount[10000], vip_num;
	double price[10000], total[10000],all=0;
	bill();
	bill(vipcustomer &v);
	void show();
	void vip_show();
	void bill_product(product &pr,int a);
	void get_data(int d);
	int isvip;
};

void bill::bill_product(product & pr,int a) {
	product_number[precode] = pr.product_num;
	product_name[precode] = pr.product_name;
	price[precode] = pr.product_price;
	amount[precode] = a;
	total[precode] = price[precode] * amount[precode];
	all += total[precode];
	precode++;
}

void bill::get_data(int d){
	data = d;
}

bill::bill(){
	isvip = 0;
}

bill::bill(vipcustomer &v) {
	vip_num = v.vip_num;
	vip_name = v.vip_name;
	isvip = 1;
}
void bill::vip_show(){
	cout << "��Ա�� " << vip_num << "  ��Ա�� " << vip_name;
	for (int i = 0; i < precode; i++) {
		cout << " ��Ʒ����" << product_name[i]  << "  ���� " << price[i] << "  ���� " << amount[i] << "  С�� " << total[i] <<endl<<"                             ";
	}
	cout <<"  �ܼ� " << all << "  ���� " << data << endl<<endl;
}

void bill::show() {
	for (int j = 0; j < precode; j++) {
		cout << "  ���� " << price[j] << " ���� " << amount[j] << " �ܼ� " << total[j] <<","<< data << endl;
	}
}


int main(){
	vipcustomer *person[10000];
	product *products[10000];
	bill *bills[10000];
	int vip_recode = 0 , pd_recode =0 , bill_recode = 0;
	products[pd_recode] = new product("001", "yashua", 5);
	person[vip_recode] = new vipcustomer(10000, "xiaoli");
	vip_recode++;
	pd_recode++;
	int  vip_num, fp, fpr, isvip[10000], data;	//fpѰ�ҵ��ı��
	string vip_name, product_name, product_num, product_number[10000];
	double product_price;
	while (1) {
		int i;
		cout << "______________________ \n                       *\n"
			 << "|   1-����vip��Ա      *\n|   2-ɾ��vip��Ա      *\n|   3-��ʾ����vip��Ա  *\n|   4-������Ʒ         *\n|   5-ɾ����Ʒ         *\n|   6-��ʾ������Ʒ     *\n"
			 <<"|   7-���Ķ���         *\n|   8-����˵�         *\n|   9-ɾ������         *\n|   10-��ʾ���г�Ա    *\n|   11-�������˵�����  *\n|   Other-Quit         *\n"
			 <<"_______________________*\n>";
		cin >> i;
		if (i == 1) {
			cout << "�������Ա�ţ� ";
			cin >> vip_num ;
			cout << "�������Ա���֣� ";
			cin >> vip_name;
			person[vip_recode] = new vipcustomer(vip_num, vip_name);
			vip_recode++;
		}
		else if (i == 2) {
			for (int a = 0; a < vip_recode; a++) {
				cout << a << ".";
				person[a]->show();
			}
			int dp;
			cout << "����������ɾ�������";
			cin >> dp;
			delete person[dp];
			for (int k = dp; k < vip_recode; k++)
				person[k] = person[k + 1];
			vip_recode--;
		}
		else if (i == 3) {
			for (int a = 0; a < vip_recode; a++)
				person[a]->show();
		}
		else if (i == 4) {
			cout << "��������Ʒ�ţ� ";
			cin >> product_num  ;
			cout << "��������Ʒ���֣� ";
			cin >> product_name;
			cout << "��������Ʒ���ۣ� ";
			cin >> product_price;
			products[pd_recode] = new product(product_num, product_name, product_price);
			pd_recode++;
		}
		else if (i == 5) {
			for (int b = 0; b < pd_recode; b++) {
				cout << b << ".";
				products[b]->show();
			}
			int dpr;
			cout << "����������ɾ�������";
			cin >> dpr;
			delete products[dpr];
			for (int k = dpr; k < vip_recode; k++)
				products[k] = products[k + 1];
			pd_recode--;
		}
		else if (i == 6) {
			for (int b = 0; b < pd_recode; b++)
				products[b]->show();
		}
		else if (i == 7) {
			for (int b = 0; b < vip_recode; b++) {
				cout << "b";
				products[b]->show();
			}
			int chang, price;
			cout << "����������ĵ����" << endl;
			cin >> chang ;
			cout << "��������ĺ�ĵ���" << endl;
			cin >> price;
			products[chang]->chang(price);
		}
		else if (i == 8) {
			int judge = 1;
			int judge1 = 1;
			cout << "�ǻ�Ա������1������������0";
			cin >> judge1;
			while (judge1) {
				cout << "�����Ա�ţ�" << endl;
				int vipnumber;
				cout << "�������Ա�ţ�";
				cin >> vipnumber;
				for (int b = 0; b < vip_recode; b++) {
					if (vipnumber == person[b]->vip_num) {
						vipnumber = person[b]->vip_num;
						isvip[bill_recode] = 1;
						bills[bill_recode] = new bill(*person[b]);
						judge1 = 0;
						break;
					}
					if (b == vip_recode - 1) {
						cout << "û�������Ա" << endl;
						isvip[bill_recode] = 0;
						bills[bill_recode] = new bill();
						cout << "��������������1���޻�Ա������0" << endl;
						cin >> judge1;
						break;
					}
				}
			}
			string s;
			int  amount,sz = 0;
			while (judge) {
				cout << "��Ʒ���:" ;
				cin >> s;
				for (int c = 0; c < pd_recode; c++) {
					if (s == products[c]->product_num) {
						cout << "����������:";
						cin >> amount;
						product_number[sz] = products[c]->product_num;
						sz++;
						bills[bill_recode]->bill_product(*products[c], amount);
						fpr = c;	
						break;
					}
					if (c == pd_recode - 1) {
						cout << "û�������Ʒ" << endl;
						break;
					}
				}
				cout << "����������Ʒ������1,����������0" << endl;
				cin >> judge;
			}
			cout << "����������:";
			cin >> data;
			bills[bill_recode]->get_data(data);
			bill_recode++;
		}
		else if (i == 9) {
			for (int d = 0; d < bill_recode; d++) {
				if (isvip[d] == 1) {
					cout << d << ".";
					bills[d]->vip_show();
				}
				else {
					cout << d << ".";
					bills[d]->show();
				}
			}
			int del;
			cout << "����������ɾ�������: ";
			cin >> del;
			delete bills[del];
			for (int k = del; k < bill_recode-1; k++) {
				cout << "1";
				bills[k] = bills[k + 1];
				cout << "2";
				if(bills[k + 1]->isvip=0)
				bills[k]->isvip = 0;
			}
			bill_recode--;
		}
		else if (i == 10) {
			for (int d = 0; d < bill_recode; d++) {
				if (isvip[d] == 1) {
					cout << d << ".";
					bills[d]->vip_show();
				}
				else {
					cout << d << ".";
					bills[d]->show();
				}
			}
		}
		else if (i == 11) {
			bill *bill1[10000];
			bill *t;
			for (int i = 0; i < bill_recode; i++) {
				bill1[i] = bills[i];
			}
			int r;
			for (int j = 0; j < bill_recode; j++) {
				for (int k = j+1; k < bill_recode; k++) {
					if (bills[j] < bills[k]) {
						t = bills[j];
						bills[j] = bills[k];
						bills[k] = t;
					}

				}

			}
			cout << "�����";
			for (int d = 0; d < bill_recode; d++) {
				if (bill1[d]->isvip == 1) {
					cout << d << ".";
					bill1[d]->vip_show();
				}
				else {
					cout << d << ".";
					bill1[d]->show();
				}
			}
		}
		else break;
	}
	return 0;
}


