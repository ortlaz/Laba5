#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <iostream>
#include <string>
#include <ctype.h>

//#define SIZE 57

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

   int capasity = 3;
   int Size = 0;

   Univer<tKey,tValue> **table;

   //хеш функция
    int hashFunc(tKey str){

    //сумма чисел в коде специальности
    int asc = 0;
    int elem =0;
    for (int i=0; i<str.length();i++){

        if(isdigit(str[i])){
            elem = str[i];
            asc += elem;
        }
    }
    return asc % capasity;
   }

public:

    //иницилизация
    Hash_Table(){

       table = new Univer<tKey,tValue>*[capasity]; //выделение памяти

        for (int i=0; i<capasity; i++){
            table[i] = NULL;
        }
    }

    //удаление
    ~Hash_Table(){

        for(int i=0;i<capasity;i++){
            delete [] table[i];
        }
        delete [] table;
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

    //рехеширование
    void reHash();

};

//ВСТАВКА
template<typename tKey, typename tValue>
void Hash_Table<tKey,tValue>::push(tValue name, tKey code){

    //проверка на необходимость рехеширования
    if(Size && double(Size)/capasity > 0.75){
        cout<<"Требуется рехеширование!"<<endl;
        this->reHash();
    }

    //получение хеш кода
    int index = hashFunc(code);

    //создание нового элемента
    Univer<tKey,tValue>* univ = new Univer<tKey,tValue>(name, code);

    Size ++;
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

    for(int i=0;i<capasity;i++){
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

    Univer<tValue, tKey>*pt, *pt1 = nullptr;
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
        Size--;
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
        Size--;
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
        Size--;
    }
}

//вывод списка индексов
template<typename tKey, typename tValue>
void Hash_Table<tKey,tValue>::Indexes(){

     Univer<tKey,tValue>* ptr;

    for(int i=0;i<capasity;i++){
        if(table[i]){
            ptr=table[i];

            while(ptr){
                cout<<hashFunc(ptr->code)<<" ";
                ptr=ptr->next;
            }
        }
    }
}

//рехеширование
template<typename tKey, typename tValue>
void Hash_Table<tKey,tValue>::reHash(){

     //создание новой таблицы с capasity*2
     Univer<tKey,tValue> **new_table;    //новая таблица

     new_table = new Univer<tKey,tValue>*[capasity*2]; //выделение памяти

     //иницилизация
     for (int i=0; i<capasity*2; i++){
        new_table[i] = NULL;
     }

     int index = 0;
     tKey code;
     tValue name;

    capasity *=2; //новая ёмкость

    //перестановка элементов из старой таблицы в новую. применяя хеш функцию с новым capasity
    for (int i=0; i<capasity/2; i++){

        while(table[i]){

            name = table[i]->name;
            code = table[i]->code;

            index = hashFunc(code); //хеш функция

            //создание нового элемента
            Univer<tKey,tValue>* univ = new Univer<tKey,tValue>(name, code);

            //элемент хеш-таблицы
            Univer<tKey,tValue>* place = new_table[index];

            if(!place){
                new_table[index] = univ;
                new_table[index]->next = nullptr;
                Size ++;
            } else{
                    while(place->next){
                        place=place->next;
                    }
                    place->next = univ;
            }

            table[i]= table[i]->next;
        }
    }

    //удаление старой таблицы
    Univer<tKey,tValue> **temp = nullptr;

    temp = table;
    table = new_table;

   for(int i=0; i<capasity/2; i++){
        delete [] temp[i];
   }
   delete [] temp;

}

#endif // HASH_TABLE_H
