#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include<windows.h>
#include<vector>
#include <fstream> 
#include <sstream>
using namespace std;

void showfindmenu() {
	cout << "                                         1 学号查找\n";
	cout << "                                         2 姓名查找\n";
	cout << "                                         0 退出\n                                           ->";
}
void showchangmenu() {
	cout << "                                         1 修改学号\n"
		<< "                                         2 修改名字\n"
		<< "                                         3 修改性别\n"
		<< "                                         4 修改学院\n"
		<< "                                         5 修改班级\n"
		<< "                                         6 修改生日\n"
		<< "                                         0 退出\n                                           ->";
}

void showdelemenu() {
	cout << "                                         1 学号查找再删除\n";
	cout << "                                         2 名字查找再删除\n";
	cout << "                                         0 退出\n                                           ->";
}

void countmenu() {
	cout << "                                         1 统计班级人数\n"
		<< "                                         2 统计学院人数\n"
		<< "                                         3 统计男生人数\n"
		<< "                                         4 统计女生人数\n";
	cout << "                                         0 退出\n                                           ->";
}


class Student {
private:
	string stuNo;
	string stuName;
	string Sex;
	string stuClass;
	string Aca;
	string birth;

	Student *pNext;

public:

	void InitStuList(Student* &SL);
	void AddStuInfo(Student* &SL);
	void ShowStuInfo(Student* &SL);
	void FindStuInfo(Student* &SL);
	void FindStuInNa(Student* &SL);
	void DeleStuInfoNo(Student*&SL);
	void DeleStuInfoNa(Student*&SL);
	void ChangStuInfo(Student*&SL);
	void judgeNo(Student*&SL, Student *p);
	void Dele(Student*&SL);
	void sortStuInfo(Student*&SL);
	void Find(Student*&SL);
	void readFromFile(Student*&SL);
	void saveInfo(Student*&SL);
	void CountInfo(Student*&SL);
	void judgeSex(Student*&SL, Student *p);

};

void Student::InitStuList(Student* &SL) {
	SL = new Student;
	if (!SL) {
		cout << "内存分配失败" << endl;
		exit(1);
	}
	SL->pNext = NULL;
}

void Student::judgeSex(Student* &SL, Student*p) {				//检测性别格式
		//int j = 1;
	string sex;
	while (1) {
		cout << "                                         请输入性别 -> ";
		cin >> sex;
		cout << "                                            学号 " << p->stuNo << endl;
		while (1) {
			if (sex == "M" || sex == "m" || sex == "男生" || sex == "男") {
				p->Sex = "M";
				return;
			}
			else if (sex == "F" || sex == "f" || sex == "女生" || sex == "女") {
				p->Sex = "F";
				return;

			}
			else {
				system("cls");
				cout << "                                            学号 " << p->stuNo << endl;
				cout << "                                          请输入M代表男生，F代表女生\n"
					<< " \n                                        格式错误，请重新输入 -> ";
				break;
			}
		}
	}

}

void Student::AddStuInfo(Student* &SL) {
	int conti = 1;
	while (conti) {
		cout << "                                         请输入学生信息" << endl;
		Student *p, *q = SL;
		while (q->pNext != NULL) {
			q = q->pNext;														//q指向尾结点
		}
		p = new Student;														//p指向新结点
		cout << "                                         请输入学号 -> ";

		judgeNo(SL, p);															//检测性别输入格式是否正确

		cout << "\n                                         请输入姓名 -> ";
		cin >> p->stuName;


		judgeSex(SL, p);
		system("cls");
		cout << "                                            学号 " << p->stuNo << endl;
		cout << "                                            姓名 " << p->stuName << endl;
		cout << "                                            性别 " << p->Sex << endl;

		cout << "                                         请输入学院 -> ";
		cin >> p->Aca;
		cout << "                                         请输入班级 -> ";
		cin >> p->stuClass;
		cout << "                                         请输入生日 -> ";
		cin >> p->birth;

		p->pNext = NULL;
		q->pNext = p;

		cout << "                                         继续增加成员请输入1，退出请输入0 -> ";
		cin >> conti;
		system("cls");
	}
}
void Student::ShowStuInfo(Student* &SL) {

	Student *p = SL->pNext;
	if (!p) {
		cout << "                                         学生单链表为空！" << endl;
		return;
	}
	cout << endl << "学号\t\t姓名\t\t性别\t学院\t\t\t班级\t\t\t生日" << endl;
	while (p) {
		cout << p->stuNo << "\t\t" << p->stuName << "\t\t" << p->Sex << "\t"
			<< p->Aca << "\t\t" << p->stuClass << "\t\t\t" << p->birth << endl;
		p = p->pNext;
	}
}

void Student::FindStuInfo(Student *& SL) {
	Student *p = SL->pNext;
	if (!p) {
		cout << "                                         学生单链表为空！" << endl;
		return;
	}
	string x;
	cout << "                                         请输入你要查找的学号 ->  ";
	cin >> x;
	while (p) {
		if (p->stuNo == x) {
			cout << "                                         学号：   " << p->stuNo << endl
				<< "                                         姓名：   " << p->stuName << endl
				<< "                                         性别：   " << p->Sex << endl
				<< "                                         学院：   " << p->Aca << endl
				<< "                                         班别：   " << p->stuClass << endl
				<< "                                         生日：   " << p->birth << endl;
		}
		p = p->pNext;
	}
	system("pause");
}
void Student::FindStuInNa(Student *& SL) {
	string name;
	cout << "                                         输入要查找的姓名 ->";
	cin >> name;
	Student *p = SL->pNext;
	int a[50];
	int i = -1, j = 0;
	if (!p) {
		cout << "                                         学生单链表为空！" << endl;
		return;
	}
	while (p) {
		if (p->stuName == name) {
			i++;
			cout << "                                           >  " << i + 1 << endl
				<< "                                         学号：   " << p->stuNo << endl
				<< "                                         姓名：   " << p->stuName << endl
				<< "                                         性别：   " << p->Sex << endl << endl;
			a[i] = j;
		}
		j++;
		p = p->pNext;
	}
	if (i == -1) {
		cout << "                                         查无此人\n";
		return;
	}
	int showno;
	cout << "                                         想显示的学生的序号 ->";
	cin >> showno;
	p = SL;
	for (j = 0; j <= a[showno]; j++) {
		p = p->pNext;
	}
	cout << "                                         学号：   " << p->stuNo << endl
		<< "                                         姓名：   " << p->stuName << endl
		<< "                                         性别：   " << p->Sex << endl
		<< "                                         学院：   " << p->Aca << endl
		<< "                                         班别：   " << p->stuClass << endl
		<< "                                         生日：   " << p->birth << endl;
}
void Student::DeleStuInfoNo(Student *& SL) {
	string deleno;
	cout << "                                         删除的学号->";
	cin >> deleno;
	Student *q = SL, *p = SL->pNext;
	if (!p) {
		cout << "                                         学生单链表为空！" << endl;
		return;
	}
	while (p) {
		if (p->stuNo == deleno) {
			cout << "                                         学号：   " << p->stuNo << endl
				<< "                                         姓名：   " << p->stuName << endl
				<< "                                         性别：   " << p->Sex << endl
				<< "                                         学院：   " << p->Aca << endl
				<< "                                         班别：   " << p->stuClass << endl
				<< "                                         生日：   " << p->birth << endl;
			int x = 1;
			while (x) {
				cout << "                                         1确认删除，0退出 ->   ";
				cin >> x;
				switch (x) {
				case 1:
					q->pNext = p->pNext;
					delete p;
					return;
				case 0:
					return;
				default:
					cout << "                                         输入非法,请重试!\n";
					break;
				}
			}
		}
		q = q->pNext;
		p = p->pNext;
	}
	if (q->pNext == NULL) {
		cout << "                                         无此人\n";
		return;
	}
}

void Student::DeleStuInfoNa(Student *& SL) {
	string delena;
	cout << "                                       请输入想要删除人名字 -> ";
	cin >> delena;
	Student *q = SL, *p = SL->pNext;
	int i = -1, j = 0, a[50];
	if (!p) {
		cout << "                                         学生单链表为空！" << endl;
		return;
	}
	while (p) {
		if (p->stuName == delena) {
			i++;
			cout << "                                           >  " << i + 1 << endl
				<< "                                          学号：   " << p->stuNo << endl
				<< "                                           姓名：   " << p->stuName << endl
				<< "                                           性别：   " << p->Sex << endl
				<< "                                           学院：   " << p->Aca << endl
				<< "                                           班级：   " << p->stuClass << endl
				<< "                                           学号：   " << p->birth << endl << endl;

			a[i] = j;
		}
		j++;
		p = p->pNext;
	}
	if (i == -1) {
		cout << "                                         查无此人\n";
		return;
	}
	int choose;
	cout << "                                           输入你想删除的序号 -> ";
	cin >> choose;
	p = SL;
	for (j = 0; j <= a[choose - 1]; j++) {
		p = p->pNext;
	}
	for (j = 0; j < a[choose - 1]; j++) {
		q = q->pNext;
	}
	int x = 1;
	while (x) {
		cout << "                                           1确认删除，0退出 -> ";
		cin >> x;
		switch (x) {
		case 1:
			q->pNext = p->pNext;
			delete p;
			cout << "                                           删除完成";
			Sleep(1000);
			return;

		case 0:
			return;

		default:
			cout << "                                 输入非法,请重试!\n";
			break;
		}
	}

}
void Student::ChangStuInfo(Student *& SL) {
	string id;
	cout << "                                         输入要修改人的学号->";
	cin >> id;
	Student *p = SL->pNext;
	if (!p) {
		cout << "                                         学生单链表为空！" << endl;
		return;
	}
	while (p) {
		if (p->stuNo == id) {
			cout << "                                         学号：" << p->stuNo << endl
				<< "\n                                         姓名：" << p->stuName
				<< "\n                                         性别：" << p->Sex
				<< "\n                                         学院：" << p->Aca
				<< "\n                                         班别：" << p->stuClass
				<< "\n                                         生日：" << p->birth << endl << endl << endl;
			break;
		}
		p = p->pNext;
	}
	if (p == NULL) {
		cout << "								输入错误，1秒后回到主菜单";
		Sleep(1000);
		return;
	}

	int x = 1;
	showchangmenu();
	while (x) {
		cin >> x;
		switch (x) {
		case 1:
			cout << "                             修改为 -> ";
			judgeNo(SL, p);								//检查学号
			cout << "                            修改成功";
			Sleep(1000);
			return;

		case 2:
			cout << "                                修改为 -> ";
			cin >> p->stuName;
			cout << "                            修改成功";
			Sleep(1000);
			return;

		case 3:
			judgeNo(SL, p);
			return;

		case 4:
			cout << "                               修改为 -> ";
			cin >> p->Aca;
			cout << "                            修改成功";
			Sleep(1000);
			return;

		case 5:
			cout << "                               修改为 -> ";
			cin >> p->stuClass;
			cout << "                            修改成功";
			Sleep(1000);
			return;

		case 6:
			cout << "                               修改为 -> ";
			cin >> p->birth;
			cout << "                            修改成功";
			Sleep(1000);
			return;

		case 0:
			return;

		default:
			cout << "                                         输入非法,请重试!\n";
			break;
		}
	}
	system("pause");
}

void Student::judgeNo(Student*&SL, Student *p) {					//检测学号是否重复
	int j = 1;
	string x;
	while (j) {
		cin >> x;
		Student *q = SL->pNext;
		if (!q) {
			p->stuNo = x;
			break;
		}
		while (q != NULL) {
			if (x == q->stuNo) {
				system("cls");
				cout << "                                         已有这个学号\n"
					<< "                                          学号：   " << q->stuNo
					<< "\n                                         姓名：" << q->stuName
					<< " \n                                        请重新输入 -> ";
				j = 1;
				break;
			}
			else {
				j = 0;
			}
			q = q->pNext;
		}

	}
	p->stuNo = x;
	system("cls");
	cout << "                                         学号：         " << p->stuNo;
}

void Student::Dele(Student *& SL) {
	int choose;
	cin >> choose;
	system("cls");
	switch (choose) {	
	case 1:
		DeleStuInfoNo(SL);
		break;
	case 2:
		DeleStuInfoNa(SL);
		break;
	case 0:
		break;
	default:
		cout << "                                         输入非法,请重试!\n";
		break;
	}

}

template<class T>
T swap(T b, T a) {
	T temp; temp = a; a = b; b = temp;
}

void Student::sortStuInfo(Student *& SL) {
	Student *p = SL->pNext, *q;//= p->pNext;
	if (!p) {
		cout << "                                         学生单链表为空！" << endl;
		return;
	}
	while (p) {
		q = p->pNext;
		while (q) {
			long a = atol(p->stuNo.c_str());//
			long b = atol(q->stuNo.c_str());
			if (a > b) {
				swap(p->stuNo, q->stuNo);
				swap(p->stuName, q->stuName);
			}
			q = q->pNext;
		}
		p = p->pNext;

	}
	cout << "                                        按学号升序排列后：\n";
}

void Student::Find(Student *& SL) {
	int choose;
	showfindmenu();
	cin >> choose;
	system("cls");
	switch (choose) {
	case 1:
		FindStuInfo(SL);
		break;
	case 2:
		FindStuInNa(SL);
		break;
	case 0:
		break;
	default:
		cout << "                                         输入非法,请重试!\n";
		break;
	}
}

void Student::readFromFile(Student *& SL) {
	Student *p, *q = SL;
	ifstream fin(".\\data.txt", ios::in);
	int len = 0;
	if (!fin) {
		cout << "wrong";
		fin.close();
		return;
	}

	while (!fin.eof()) {
		p = new Student;
		fin >> p->stuNo >> p->stuName >> p->Sex >> p->Aca >> p->stuClass >> p->birth;

		q->pNext = p;
		q = q->pNext;
		len++;
	}

	fin.close();
	q = SL;
	for (int i = 1; i < len; i++) {
		q = q->pNext;
	}
	q->pNext = NULL;
	cout << "                                        ***文件读取成功***\n";
	Sleep(1000);
	system("cls");
	return;
}

void Student::saveInfo(Student *& SL) {
	Student *p = SL->pNext;
	if (!p) {
		cout << "                                         学生单链表为空！" << endl;
		return;
	}
	ofstream fout(".\\data.txt", ios::out);
	if (!fout) {

		cout << "                                         文件打开失败，原因未知";
		return;
	}
	while (p) {
		fout << p->stuNo << "\t\t" << p->stuName << "\t\t" << p->Sex << "\t"
			<< p->Aca << "\t\t\t\t" << p->stuClass << "\t\t\t" << p->birth << endl;
		p = p->pNext;
	}
	fout.close();
}

void Student::CountInfo(Student *& SL) {
	countmenu();
	Student *p = SL->pNext;
	int count = 0;
	string countStr;
	char choose;
	cin >> choose;
	switch (choose) {
	case '1':
		cout << "                                         输入班级号 -> ";
		cin >> countStr;
		while (p) {
			if (p->stuClass == countStr) {
				count++;
			}
			p = p->pNext;
		}
		cout << "                                         班级总人数人数： " << count << endl;
		return;

	case '2':
		cout << "                                         输入学院 -> ";
		cin >> countStr;
		while (p) {
			if (p->Aca == countStr) {
				count++;
			}
			p = p->pNext;
		}
		cout << "                                         学院总人数： " << count << endl;
		return;


	case '3':
		while (p) {
			if (p->Sex == "M") {
				count++;
			}
			p = p->pNext;
		}
		cout << "                                         男生人数： " << count << endl;
		return;

	case '4':
		countStr = "F";
		while (p) {
			if (p->Sex == countStr) {
				count++;
			}
			p = p->pNext;
		}
		cout << "                                         女生人数： " << count << endl;
		return;
	}
}

