#include <iostream>
#include <windows.h>
#include <Hash_Table.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Hash_Table<string,string> HT;
    HT.push("МИРЭА","001");
    HT.push("МИРЭА_2","102");
    HT.push("МИТХТ","111");
    HT.push("МИТХТ","210");

    HT.output();
    HT.findEl();

    cout<<"\nСписок индексов\n";
    HT.Indexes();
    cout<<endl;

    string el;
    cout<<"Элемент на удаление:";
    cin>>el;
    HT.del(el);
    HT.output();


    return 0;
}
