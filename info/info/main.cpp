#include "Information.h"
#include<conio.h>
using namespace std;

void showmenu() {
	cout << "          ************************************************************************************\n";
	cout << "          ************************************************************************************\n";
	cout << "                                                                                    \n";
	cout << "          *******                       欢迎使用th学生信息管理系统                     *******\n";
	cout << "                                                                                    \n";
	cout << "          ************************************************************************************\n";
	cout << "          ************************************************************************************\n";
	cout << "          *******                             1 增加信息                               *******\n";
	cout << "          *******                             2 删除信息                               *******\n";
	cout << "          *******                             3 修改信息                               *******\n";
	cout << "          *******                             4 显示信息                               *******\n";
	cout << "          *******                             5 查找信息                               *******\n";
	cout << "          *******                             6 信息排序                               *******\n";
	cout << "          *******                             7 统计信息                               *******\n";
	cout << "          *******                             8 保存信息                               *******\n";
	cout << "          *******                             0 退出系统                               *******\n";
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
		cout << "                                         输入账号 -> ";
		cin >> idno ;
		cout << "\n                                         输入密码 -> ";

		char ch;
		while ((ch = _getch()) != 13)
		{
			if (ch == 8) {
				password = password.substr(0, password.length() - 1);
				putchar('\b'); // 回退一格
				putchar(' '); // 输出一个空格将原来的*隐藏
				putchar('\b'); // 再回退一格等待输入
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
					cout << "                                              保存成功\n" ;
					Sleep(1000);
					break;

				case '0':
					if (!save) {
						cout << "                                            数据未保存\n"
							 <<"                                             保存请输入1，退出输入0 -> ";
						char ifsave;
						cin >> ifsave;
						switch(ifsave) {
						case '1':
							p->saveInfo(SL);

						case '0':
							exit(1);

						default:
							system("cls");
							cout << "乱！\n输!\n入!\n是!\n想!\n干!\n嘛!\n你乱输入了几个就要等几秒再进入系统！！";
							Sleep(500);
							break;
						}
					}
					exit(1);

				default:
					system("cls");
					cout << "乱！\n输!\n入!\n是!\n想!\n干!\n嘛!\n你乱输入了几个就要等几秒再进入系统！！";
					Sleep(500);
					break;
				}
			}
			
		}
		cout << "                                         账号或密码错误,请重新输入\n";
	}
	return 0;
}
