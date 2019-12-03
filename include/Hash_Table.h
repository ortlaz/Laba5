#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <iostream>
#include <string>
#include <ctype.h>

#define SIZE 28

using namespace std;

template<typename tKey, typename tValue>
class Hash_Table{

    template<typename Key, typename Value>
     struct Univer{

        Univer(Value n= 0, Key c=0,Univer* nxt=nullptr):name(n),code(c),next(nxt){}

        Univer *next;
        Value name;
        Key code;
   };

   Univer<tKey,tValue> *table[SIZE];

   //хеш функция
    int hashFunc(tKey str){

    //сумма чисел в коде специальности
    int asc = 0;

    for (int i=0; i<str.length();i++){
        if(isdigit(str[i])){
            asc +=str[i];
        }
    }
    return asc % SIZE;
   }

 /*  Univer* head;
   Univer* tail;
 */

public:

    //иницилизация
    Hash_Table(){

        for (int i=0; i<SIZE; i++){
            table[i] = NULL;
        }
    }

    //удаление
    ~Hash_Table(){
        for(int i=0;i<SIZE;i++){
            delete table[i];
        }
    }

    //вставка
    void push(tValue name, tKey code);

    //поиск по коду специализации
    void findEl();

    //удаляет по ключу
    void del(tKey elem);

    //вывод
    void output();

    //вывод индексов
    void Indexes();

};

//ВСТАВКА
template<typename tKey, typename tValue>
void Hash_Table<tKey,tValue>::push(tValue name, tKey code){

    //получение хеш кода
    int index = hashFunc(code);

    //создание нового элемента
    Univer<tKey,tValue>* univ = new Univer<tKey,tValue>(name, code);

    //элемент хеш-таблицы
    Univer<tKey,tValue>* place = table[index];

    if(!place){
        table[index] = univ;
        table[index]->next = nullptr;
        return;
    }

    while(place->next){
        place=place->next;
    }
    place->next = univ;
}

//ВЫВОД
template<typename tKey, typename tValue>
void Hash_Table<tKey,tValue>::output(){
    Univer<tKey,tValue>* ptr;

    for(int i=0;i<SIZE;i++){
        if(table[i]){
            ptr=table[i];
            cout<<"Element "<<i<<" "<<endl;

            while(ptr){
                cout<<" "<<ptr->code<<":"<<ptr->name<<endl;
                ptr=ptr->next;
            }
        }
    }
}

//ПОИСК по ключу
template<typename tKey, typename tValue>
void Hash_Table<tKey,tValue>::findEl(){

    Univer<tKey,tValue>* ptr;
    string num;

    cout<<"\nВведите код специальности:\n";
    cin>>num;

    int index = hashFunc(num);
    ptr=table[index]; //указатель на текущий элемент

    if(ptr){
        while(ptr && (ptr->code != num) ){

            ptr=ptr->next;
        }

        if(ptr){
          cout<<"ВУЗ:"<<ptr->name<<endl;
        } else{
            cout<<"Element not found\n";
            return;
        }
    } else{
        cout<<"Element not found\n";
        return;
    }
}

//УДАЛЕНИЕ
template<typename tKey, typename tValue>
void Hash_Table<tKey,tValue>::del(tKey elem){

    Univer<tValue, tKey>*pt, *pt1 = nullptr, *pt2 = nullptr;
    int index = hashFunc(elem);

    pt=table[index];
    pt1=pt;

    while(pt->code!=elem && pt){
        pt=pt->next;
    }

    //элемент в начале
    if(pt && pt1==pt){

        pt1=pt->next;

        delete pt;

        table[index] = pt1;
        return;

    }

    //элемент не найден
    if(!pt){
        cout<<"Error\n";
        return;
    }

    //элемент в конце
    if(!pt->next){

        Univer<tValue,tKey>* temp2 = pt1;

        //поиск указателя на предыдущий элемент
        while(temp2 -> next && temp2->next !=pt){
            temp2=temp2->next;
        }

        table[index] = pt1; //указатель на предыдущий элемент

        free(pt);

        table[index]->next =0;

    }

    //элемент в середине
    else{

        Univer<tValue,tKey>* temp1 = table[index];

        while(temp1 -> next && temp1->next != pt){
            temp1=temp1->next;
        }
         pt1=temp1;
         pt1->next = pt->next;

        delete pt;
    }
}

//вывод списка индексов
template<typename tKey, typename tValue>
void Hash_Table<tKey,tValue>::Indexes(){

     Univer<tKey,tValue>* ptr;

    for(int i=0;i<SIZE;i++){
        if(table[i]){
            ptr=table[i];

            while(ptr){
                cout<<hashFunc(ptr->code)<<" ";
                ptr=ptr->next;
            }
        }
    }
}

#endif // HASH_TABLE_H
