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
	cout << "                                         1 ѧ�Ų���\n";
	cout << "                                         2 ��������\n";
	cout << "                                         0 �˳�\n                                           ->";
}
void showchangmenu() {
	cout << "                                         1 �޸�ѧ��\n"
		<< "                                         2 �޸�����\n"
		<< "                                         3 �޸��Ա�\n"
		<< "                                         4 �޸�ѧԺ\n"
		<< "                                         5 �޸İ༶\n"
		<< "                                         6 �޸�����\n"
		<< "                                         0 �˳�\n                                           ->";
}

void showdelemenu() {
	cout << "                                         1 ѧ�Ų�����ɾ��\n";
	cout << "                                         2 ���ֲ�����ɾ��\n";
	cout << "                                         0 �˳�\n                                           ->";
}

void countmenu() {
	cout << "                                         1 ͳ�ư༶����\n"
		<< "                                         2 ͳ��ѧԺ����\n"
		<< "                                         3 ͳ����������\n"
		<< "                                         4 ͳ��Ů������\n";
	cout << "                                         0 �˳�\n                                           ->";
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
		cout << "�ڴ����ʧ��" << endl;
		exit(1);
	}
	SL->pNext = NULL;
}

void Student::judgeSex(Student* &SL, Student*p) {				//����Ա��ʽ
		//int j = 1;
	string sex;
	while (1) {
		cout << "                                         �������Ա� -> ";
		cin >> sex;
		cout << "                                            ѧ�� " << p->stuNo << endl;
		while (1) {
			if (sex == "M" || sex == "m" || sex == "����" || sex == "��") {
				p->Sex = "M";
				return;
			}
			else if (sex == "F" || sex == "f" || sex == "Ů��" || sex == "Ů") {
				p->Sex = "F";
				return;

			}
			else {
				system("cls");
				cout << "                                            ѧ�� " << p->stuNo << endl;
				cout << "                                          ������M����������F����Ů��\n"
					<< " \n                                        ��ʽ�������������� -> ";
				break;
			}
		}
	}

}

void Student::AddStuInfo(Student* &SL) {
	int conti = 1;
	while (conti) {
		cout << "                                         ������ѧ����Ϣ" << endl;
		Student *p, *q = SL;
		while (q->pNext != NULL) {
			q = q->pNext;														//qָ��β���
		}
		p = new Student;														//pָ���½��
		cout << "                                         ������ѧ�� -> ";

		judgeNo(SL, p);															//����Ա������ʽ�Ƿ���ȷ

		cout << "\n                                         ���������� -> ";
		cin >> p->stuName;


		judgeSex(SL, p);
		system("cls");
		cout << "                                            ѧ�� " << p->stuNo << endl;
		cout << "                                            ���� " << p->stuName << endl;
		cout << "                                            �Ա� " << p->Sex << endl;

		cout << "                                         ������ѧԺ -> ";
		cin >> p->Aca;
		cout << "                                         ������༶ -> ";
		cin >> p->stuClass;
		cout << "                                         ���������� -> ";
		cin >> p->birth;

		p->pNext = NULL;
		q->pNext = p;

		cout << "                                         �������ӳ�Ա������1���˳�������0 -> ";
		cin >> conti;
		system("cls");
	}
}
void Student::ShowStuInfo(Student* &SL) {

	Student *p = SL->pNext;
	if (!p) {
		cout << "                                         ѧ��������Ϊ�գ�" << endl;
		return;
	}
	cout << endl << "ѧ��\t\t����\t\t�Ա�\tѧԺ\t\t\t�༶\t\t\t����" << endl;
	while (p) {
		cout << p->stuNo << "\t\t" << p->stuName << "\t\t" << p->Sex << "\t"
			<< p->Aca << "\t\t" << p->stuClass << "\t\t\t" << p->birth << endl;
		p = p->pNext;
	}
}

void Student::FindStuInfo(Student *& SL) {
	Student *p = SL->pNext;
	if (!p) {
		cout << "                                         ѧ��������Ϊ�գ�" << endl;
		return;
	}
	string x;
	cout << "                                         ��������Ҫ���ҵ�ѧ�� ->  ";
	cin >> x;
	while (p) {
		if (p->stuNo == x) {
			cout << "                                         ѧ�ţ�   " << p->stuNo << endl
				<< "                                         ������   " << p->stuName << endl
				<< "                                         �Ա�   " << p->Sex << endl
				<< "                                         ѧԺ��   " << p->Aca << endl
				<< "                                         ���   " << p->stuClass << endl
				<< "                                         ���գ�   " << p->birth << endl;
		}
		p = p->pNext;
	}
	system("pause");
}
void Student::FindStuInNa(Student *& SL) {
	string name;
	cout << "                                         ����Ҫ���ҵ����� ->";
	cin >> name;
	Student *p = SL->pNext;
	int a[50];
	int i = -1, j = 0;
	if (!p) {
		cout << "                                         ѧ��������Ϊ�գ�" << endl;
		return;
	}
	while (p) {
		if (p->stuName == name) {
			i++;
			cout << "                                           >  " << i + 1 << endl
				<< "                                         ѧ�ţ�   " << p->stuNo << endl
				<< "                                         ������   " << p->stuName << endl
				<< "                                         �Ա�   " << p->Sex << endl << endl;
			a[i] = j;
		}
		j++;
		p = p->pNext;
	}
	if (i == -1) {
		cout << "                                         ���޴���\n";
		return;
	}
	int showno;
	cout << "                                         ����ʾ��ѧ������� ->";
	cin >> showno;
	p = SL;
	for (j = 0; j <= a[showno]; j++) {
		p = p->pNext;
	}
	cout << "                                         ѧ�ţ�   " << p->stuNo << endl
		<< "                                         ������   " << p->stuName << endl
		<< "                                         �Ա�   " << p->Sex << endl
		<< "                                         ѧԺ��   " << p->Aca << endl
		<< "                                         ���   " << p->stuClass << endl
		<< "                                         ���գ�   " << p->birth << endl;
}
void Student::DeleStuInfoNo(Student *& SL) {
	string deleno;
	cout << "                                         ɾ����ѧ��->";
	cin >> deleno;
	Student *q = SL, *p = SL->pNext;
	if (!p) {
		cout << "                                         ѧ��������Ϊ�գ�" << endl;
		return;
	}
	while (p) {
		if (p->stuNo == deleno) {
			cout << "                                         ѧ�ţ�   " << p->stuNo << endl
				<< "                                         ������   " << p->stuName << endl
				<< "                                         �Ա�   " << p->Sex << endl
				<< "                                         ѧԺ��   " << p->Aca << endl
				<< "                                         ���   " << p->stuClass << endl
				<< "                                         ���գ�   " << p->birth << endl;
			int x = 1;
			while (x) {
				cout << "                                         1ȷ��ɾ����0�˳� ->   ";
				cin >> x;
				switch (x) {
				case 1:
					q->pNext = p->pNext;
					delete p;
					return;
				case 0:
					return;
				default:
					cout << "                                         ����Ƿ�,������!\n";
					break;
				}
			}
		}
		q = q->pNext;
		p = p->pNext;
	}
	if (q->pNext == NULL) {
		cout << "                                         �޴���\n";
		return;
	}
}

void Student::DeleStuInfoNa(Student *& SL) {
	string delena;
	cout << "                                       ��������Ҫɾ�������� -> ";
	cin >> delena;
	Student *q = SL, *p = SL->pNext;
	int i = -1, j = 0, a[50];
	if (!p) {
		cout << "                                         ѧ��������Ϊ�գ�" << endl;
		return;
	}
	while (p) {
		if (p->stuName == delena) {
			i++;
			cout << "                                           >  " << i + 1 << endl
				<< "                                          ѧ�ţ�   " << p->stuNo << endl
				<< "                                           ������   " << p->stuName << endl
				<< "                                           �Ա�   " << p->Sex << endl
				<< "                                           ѧԺ��   " << p->Aca << endl
				<< "                                           �༶��   " << p->stuClass << endl
				<< "                                           ѧ�ţ�   " << p->birth << endl << endl;

			a[i] = j;
		}
		j++;
		p = p->pNext;
	}
	if (i == -1) {
		cout << "                                         ���޴���\n";
		return;
	}
	int choose;
	cout << "                                           ��������ɾ������� -> ";
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
		cout << "                                           1ȷ��ɾ����0�˳� -> ";
		cin >> x;
		switch (x) {
		case 1:
			q->pNext = p->pNext;
			delete p;
			cout << "                                           ɾ�����";
			Sleep(1000);
			return;

		case 0:
			return;

		default:
			cout << "                                 ����Ƿ�,������!\n";
			break;
		}
	}

}
void Student::ChangStuInfo(Student *& SL) {
	string id;
	cout << "                                         ����Ҫ�޸��˵�ѧ��->";
	cin >> id;
	Student *p = SL->pNext;
	if (!p) {
		cout << "                                         ѧ��������Ϊ�գ�" << endl;
		return;
	}
	while (p) {
		if (p->stuNo == id) {
			cout << "                                         ѧ�ţ�" << p->stuNo << endl
				<< "\n                                         ������" << p->stuName
				<< "\n                                         �Ա�" << p->Sex
				<< "\n                                         ѧԺ��" << p->Aca
				<< "\n                                         ���" << p->stuClass
				<< "\n                                         ���գ�" << p->birth << endl << endl << endl;
			break;
		}
		p = p->pNext;
	}
	if (p == NULL) {
		cout << "								�������1���ص����˵�";
		Sleep(1000);
		return;
	}

	int x = 1;
	showchangmenu();
	while (x) {
		cin >> x;
		switch (x) {
		case 1:
			cout << "                             �޸�Ϊ -> ";
			judgeNo(SL, p);								//���ѧ��
			cout << "                            �޸ĳɹ�";
			Sleep(1000);
			return;

		case 2:
			cout << "                                �޸�Ϊ -> ";
			cin >> p->stuName;
			cout << "                            �޸ĳɹ�";
			Sleep(1000);
			return;

		case 3:
			judgeNo(SL, p);
			return;

		case 4:
			cout << "                               �޸�Ϊ -> ";
			cin >> p->Aca;
			cout << "                            �޸ĳɹ�";
			Sleep(1000);
			return;

		case 5:
			cout << "                               �޸�Ϊ -> ";
			cin >> p->stuClass;
			cout << "                            �޸ĳɹ�";
			Sleep(1000);
			return;

		case 6:
			cout << "                               �޸�Ϊ -> ";
			cin >> p->birth;
			cout << "                            �޸ĳɹ�";
			Sleep(1000);
			return;

		case 0:
			return;

		default:
			cout << "                                         ����Ƿ�,������!\n";
			break;
		}
	}
	system("pause");
}

void Student::judgeNo(Student*&SL, Student *p) {					//���ѧ���Ƿ��ظ�
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
				cout << "                                         �������ѧ��\n"
					<< "                                          ѧ�ţ�   " << q->stuNo
					<< "\n                                         ������" << q->stuName
					<< " \n                                        ���������� -> ";
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
	cout << "                                         ѧ�ţ�         " << p->stuNo;
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
		cout << "                                         ����Ƿ�,������!\n";
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
		cout << "                                         ѧ��������Ϊ�գ�" << endl;
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
	cout << "                                        ��ѧ���������к�\n";
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
		cout << "                                         ����Ƿ�,������!\n";
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
	cout << "                                        ***�ļ���ȡ�ɹ�***\n";
	Sleep(1000);
	system("cls");
	return;
}

void Student::saveInfo(Student *& SL) {
	Student *p = SL->pNext;
	if (!p) {
		cout << "                                         ѧ��������Ϊ�գ�" << endl;
		return;
	}
	ofstream fout(".\\data.txt", ios::out);
	if (!fout) {

		cout << "                                         �ļ���ʧ�ܣ�ԭ��δ֪";
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
		cout << "                                         ����༶�� -> ";
		cin >> countStr;
		while (p) {
			if (p->stuClass == countStr) {
				count++;
			}
			p = p->pNext;
		}
		cout << "                                         �༶������������ " << count << endl;
		return;

	case '2':
		cout << "                                         ����ѧԺ -> ";
		cin >> countStr;
		while (p) {
			if (p->Aca == countStr) {
				count++;
			}
			p = p->pNext;
		}
		cout << "                                         ѧԺ�������� " << count << endl;
		return;


	case '3':
		while (p) {
			if (p->Sex == "M") {
				count++;
			}
			p = p->pNext;
		}
		cout << "                                         ���������� " << count << endl;
		return;

	case '4':
		countStr = "F";
		while (p) {
			if (p->Sex == countStr) {
				count++;
			}
			p = p->pNext;
		}
		cout << "                                         Ů�������� " << count << endl;
		return;
	}
}

