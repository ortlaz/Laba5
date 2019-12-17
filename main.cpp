#include <iostream>
#include <windows.h>
#include <Hash_Table.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Hash_Table<string,string> HT;

     int var;

    while (var){
        system("cls");

        cout<<"1.������� ��������.\n2.����� �������.\n3.������ ��������.\n4.����� �������� �� �����.\n5.�������� �������� �� �����.\n0.�����\n";
        cout<<"�������� ��������:";
        cin>>var;

        switch(var){
            case 1:{
                string code,name;
                cout<<"������� ��� �������������:";
                cin>>code;
                cout<<"\n������� �������� ����:";
                cin>>name;
                cout<<endl;
                HT.push(name,code);
                system("pause");
                break;
            }
            case 2:{
                HT.output();

                /*
                cout<<"�������������:"<<endl;
                HT.reHash();
                HT.output();
                */

                system("pause");
                break;
            }
            case 3:{
                cout<<"\n������ ��������\n";
                HT.Indexes();
                cout<<endl;
                system("pause");
                break;
            }
            case 4:{
                HT.findEl();
                system("pause");
                break;
            }
            case 5:{
                string el;
                cout<<"������� �� ��������:";
                cin>>el;
                HT.del(el);
                system("pause");
                break;
            }
            case 0:{
                exit(0);
                system("pause");
                break;
            }
            default:{
                cout<<"�������� �������� �� ������!\n";
                system("pause");
                break;
            }
        }
    }

    return 0;
}
