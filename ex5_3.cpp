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
	cout << vip_num << vip_name << endl;
}

class product {
private:

public:
	string product_name;
	double product_price;
	int product_num;
	product();
	product(int pd_num, string pd_name, double pd_price);
	void show();
	int getproduct_num();
	string getproduct_name();
	double getproduct_price();
};

product::product() {
	product_num = 0;
	product_name = "";
	product_price = 0;
}

product::product(int pd_num, string pd_name, double pd_price) {
	product_num = pd_num;
	product_name = pd_name;
	product_price = pd_price;
}

void product::show() {
	cout << product_num << product_name << product_price << endl;
}

int product::getproduct_num() {
	return product_num;
}

string product::getproduct_name() {
	return product_name;
}

double product::getproduct_price() {
	return product_price;
}

class bill {
private:
	//static int billcount;
public:
	string product_name[10000];
	int product_number[10000],precode=0;
	string vip_name;
	int bill_number, data, amount[10000], vip_num;
	double price[10000], total[10000],all=0;
	bill();
	bill(vipcustomer &v);
	void show();
	void vip_show();
	void bill_product(product &pr,int a);
	void get_data(int d);
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

}

bill::bill(vipcustomer &v) {
	vip_num = v.vip_num;
	vip_name = v.vip_name; 
}
void bill::vip_show(){
	cout << "会员号 " << vip_num << "  会员名 " << vip_name;
	for (int i = 0; i < precode; i++) {
		cout << " 商品名：" << product_name[i]  << "  单价 " << price[i] << "  数量 " << amount[i] << "  小计 " << total[i] <<endl<<"                             ";
	}
	cout <<"  总价 " << all << "  日期 " << data << endl<<endl;
}

void bill::show() {
	for (int j = 0; j < precode; j++) {
		cout << "  单价 " << price[j] << " 总价 " << amount[j] << " 总价 " << total[j] << endl;
	}
}


int main(){
	vipcustomer *person[10000];
	product *products[10000];
	bill *bills[10000];
	int vip_recode = 0 , pd_recode =0 , bill_recode = 0;
	products[pd_recode] = new product(001, "yashua", 5);
	person[vip_recode] = new vipcustomer(10000, "xiaoli");
	vip_recode++;
	pd_recode++;
	int product_num, vip_num,fp, fpr,product_number[10000],isvip[10000],data;	//dp:person中想delete的编号   dpr：products中delete的编号  fp寻找到的编号
	string vip_name, product_name;
	double product_price;
	while (1) {
		int i;
		cout << "\n 1-Add vipcustomer\n 2-Reduse vipcustomer\n 3-Add product\n 4-Reduse product\n ";
		cout << "5-Query\n 6-Query\n 7-Add bill\n 8-Reduse bill\n 9-Query\n Other-Quit\n>";
		cin >> i;
		if (i == 1) {
			cin >> vip_num >> vip_name;
			person[vip_recode] = new vipcustomer(vip_num, vip_name);
			vip_recode++;
		}
		else if (i == 2) {
			for (int a = 0; a < vip_recode; a++) {
				cout << a << ".";
				person[a]->show();
			}
			int dp;
			cout << "请输入你想删除的序号";
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
			cin >> product_num >> product_name >> product_price;
			products[pd_recode] = new product(product_num, product_name, product_price);
			pd_recode++;
		}
		else if (i == 5) {
			for (int b = 0; b < vip_recode; b++) {
				cout << b << ".";
				products[b]->show();
			}
			int dpr;
			cout << "请输入你想删除的序号";
			cin >> dpr;
			delete products[dpr];
			for (int k = dpr; k < vip_recode; k++)
				products[k] = products[k + 1];
			pd_recode--;
		}
		else if (i == 6) {
			for (int b = 0; b < vip_recode; b++)
				products[b]->show();
		}
		else if (i == 7) {
			int judge = 1;
			int judge1 = 1;
			while (judge1) {
				cout << "is vip?if yes, input vip number" << endl;
				int vipnumber;
				cout << "请输入会员号";
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
						cout << "没有这个会员" << endl;
						isvip[bill_recode] = 0;
						bills[bill_recode] = new bill();
						cout << "重新输入请输入1，无会员请输入0" << endl;
						cin >> judge1;
						break;
					}
				}
			}
			int s, amount,sz = 0;
			while (judge) {
				cout << "商品序号:" ;
				cin >> s;
				for (int c = 0; c < pd_recode; c++) {
					if (s == products[c]->product_num) {
						cout << "请输入数量:";
						cin >> amount;
						product_number[sz] = products[c]->product_num;
						sz++;
						bills[bill_recode]->bill_product(*products[c], amount);
						fpr = c;	
						break;
					}
					if (s == pd_recode - 1) {
						cout << "没有这个商品" << endl;
						break;
					}
				}
				cout << "继续输入商品请输入1,否则请输入0" << endl;
				cin >> judge;
			}
			cout << "请输入日期:";
			cin >> data;
			bills[bill_recode]->get_data(data);
			bill_recode++;
		}
		else if (i == 8) {
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
			cout << "请输入你想删除的序号";
			cin >> del;
			delete person[del];
			for (int k = del; k < vip_recode; k++)
				bills[k] = bills[k + 1];
			bill_recode--;
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
		}
		else break;
	}
	return 0;
}


