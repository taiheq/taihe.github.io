#include "Information.h"
#include<conio.h>
using namespace std;

void showmenu() {
	cout << "          ************************************************************************************\n";
	cout << "          ************************************************************************************\n";
	cout << "                                                                                    \n";
	cout << "          *******                       ��ӭʹ��thѧ����Ϣ����ϵͳ                     *******\n";
	cout << "                                                                                    \n";
	cout << "          ************************************************************************************\n";
	cout << "          ************************************************************************************\n";
	cout << "          *******                             1 ������Ϣ                               *******\n";
	cout << "          *******                             2 ɾ����Ϣ                               *******\n";
	cout << "          *******                             3 �޸���Ϣ                               *******\n";
	cout << "          *******                             4 ��ʾ��Ϣ                               *******\n";
	cout << "          *******                             5 ������Ϣ                               *******\n";
	cout << "          *******                             6 ��Ϣ����                               *******\n";
	cout << "          *******                             7 ͳ����Ϣ                               *******\n";
	cout << "          *******                             8 ������Ϣ                               *******\n";
	cout << "          *******                             0 �˳�ϵͳ                               *******\n";
	cout << "          ************************************************************************************\n";
}

int main() {

	Student *SL;
	Student *p = new Student;
	p->InitStuList(SL);
	p->readFromFile(SL);

	
	int save = 1;
	while (1) {
		string idno, password;
		cout << "                                         �����˺� -> ";
		cin >> idno ;
		cout << "\n                                         �������� -> ";

		char ch;
		while ((ch = _getch()) != 13)
		{
			if (ch == 8) {
				password = password.substr(0, password.length() - 1);
				putchar('\b'); // ����һ��
				putchar(' '); // ���һ���ո�ԭ����*����
				putchar('\b'); // �ٻ���һ��ȴ�����
				continue;
			}
			password += ch;
			cout << "*";
		}
		system("cls");
		if (idno== "190" && password == "111") {
			while (1) {
				system("cls");
				showmenu();
				char choose;
				cout << "\n                                         >>>> ";
				cin >> choose;
				system("cls");
				switch (choose) {
				case '1':
					p->AddStuInfo(SL);
					save = 0;
					break;

				case '2':
					showdelemenu();
					p->Dele(SL);
					save = 0;
					break;

				case '3':
					p->ChangStuInfo(SL);
					save = 0;
					break;

				case '4':
					p->ShowStuInfo(SL);
					system("pause");
					break;

				case '5':
					
					p->Find(SL);
					break;

				case '6':
					p->sortStuInfo(SL);
					p->ShowStuInfo(SL);
					system("pause");
					save = 0;
					break;

				case '7':
					p->CountInfo(SL);
					system("pause");
					break;

				case '8':
					p->saveInfo(SL);
					cout << "                                              ����ɹ�\n" ;
					Sleep(1000);
					break;

				case '0':
					if (!save) {
						cout << "                                            ����δ����\n"
							 <<"                                             ����������1���˳�����0 -> ";
						char ifsave;
						cin >> ifsave;
						switch(ifsave) {
						case '1':
							p->saveInfo(SL);

						case '0':
							exit(1);

						default:
							system("cls");
							cout << "�ң�\n��!\n��!\n��!\n��!\n��!\n��!\n���������˼�����Ҫ�ȼ����ٽ���ϵͳ����";
							Sleep(500);
							break;
						}
					}
					exit(1);

				default:
					system("cls");
					cout << "�ң�\n��!\n��!\n��!\n��!\n��!\n��!\n���������˼�����Ҫ�ȼ����ٽ���ϵͳ����";
					Sleep(500);
					break;
				}
			}
			
		}
		cout << "                                         �˺Ż��������,����������\n";
	}
	return 0;
}
