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

        cout<<"1.Вставка элемента.\n2.Вывод таблицы.\n3.Список индексов.\n4.Поиск элемента по ключу.\n5.Удаление элемента по ключу.\n0.Выход\n";
        cout<<"Выберите действие:";
        cin>>var;

        switch(var){
            case 1:{
                string code,name;
                cout<<"Введите код специальности:";
                cin>>code;
                cout<<"\nВведите название ВУЗа:";
                cin>>name;
                cout<<endl;
                HT.push(name,code);
                system("pause");
                break;
            }
            case 2:{
                HT.output();

                /*
                cout<<"РЕХЕШИРОВАНИЕ:"<<endl;
                HT.reHash();
                HT.output();
                */

                system("pause");
                break;
            }
            case 3:{
                cout<<"\nСписок индексов\n";
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
                cout<<"Элемент на удаление:";
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
                cout<<"Выберите операцию из списка!\n";
                system("pause");
                break;
            }
        }
    }

    return 0;
}
