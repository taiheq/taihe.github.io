#include <iostream>
#include<string>
using namespace std;
class Caidan
{
private:
    string Caiming;
    int Jiage;
public:
    static int Jilu;
    Caidan(string cm,int gz=0)
    {
        Caiming=cm;
        Jiage=gz;
        Jilu++;
    }
    Caidan(const Caidan &n)
    {
        Caiming="[Jia]"+n.Caiming;
        Jiage=n.Jiage;
        Jilu++;
    }
    void Showjilu(int j)
    {
        cout<<"\nNo."<<j<<" "<<Caiming<<" &"<<Jiage;
    }
    void Gaijiage(int qian)
    {
        Jiage+=qian;
    }

};

int Caidan::Jilu=0;
void ShowAll(Caidan* dcd[])
{
    for(int j=0; j<Caidan::Jilu; j++)
        dcd[j]->Showjilu(j);
    cout<<"\n---END----\n";
}

void Gaijiage(Caidan* dcd,int qian)
{
    dcd->Gaijiage(qian);
}

int main()
{
    Caidan* Xiaofeijilu[100] = { new Caidan("JiTui",4), new Caidan("YaTui",4),
                new Caidan("MiFan",1), new Caidan("QingCai",1)
    };
    while (1)
    {
        int i,rmb;
        cout << "\n 1-Gai Jia Ge \n 2-Jia Cai \n 3-Cha Xun \n Others-Tui chu" << endl;
        cin>>i;
        if (i == 1)
        {
            ShowAll(Xiaofeijilu);
            int sj;
            cout << "\n> Gai Na Ge Jilu      Jia duo shao?";
            cin >> sj >> rmb; //(4)从键盘输入列表序号，
            Gaijiage(Xiaofeijilu[sj],rmb);//(4)调用Gaijiage函数修改消费记录
        }
        else if (i == 2)
        {
            int n, m;
            cout << "\n> Jia Na Ge";
            cin >> n;//(5)从键盘输入列表序号，保存在n
            m = Caidan::Jilu;//(5)记录总数保存在m
            Xiaofeijilu[m] = new Caidan(*Xiaofeijilu[n]);	//(5)将n对象的属性Copy到序号为m的新建对象
        }
        else if (i == 3)
            ShowAll(Xiaofeijilu);
        else break;
    }
    return 0;
}
