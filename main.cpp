#include <iostream>
#include <windows.h>
#include <Hash_Table.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Hash_Table<string,string> HT;
    HT.push("�����","001");
    HT.push("�����_2","102");
    HT.push("�����","111");
    HT.push("�����","210");

    HT.output();
    HT.findEl();

    cout<<"\n������ ��������\n";
    HT.Indexes();
    cout<<endl;

    string el;
    cout<<"������� �� ��������:";
    cin>>el;
    HT.del(el);
    HT.output();


    return 0;
}
