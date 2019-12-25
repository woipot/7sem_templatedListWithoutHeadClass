#ifndef LIST_H
#define LIST_H

#include <QString>
#include <QTextStream>



template<typename T> class List
{
private:
    T myValue;             //Непосредственно число
    List *myNext;            //Указатель на следушию ячейку
public:

    List(T value)
    {
        myNext = nullptr;
        myValue = value;
    }

    ~List()
    {
        if(myNext!=0)
         delete myNext;
    }

    T getValue(){return myValue;}


    void pushBack(T value)
    {
        List<T> *arrant=this;        //создаем указатель на обьект типа list и присваеваем ему
                                 //адрес вызвавшего его обьекта.
        while(arrant->myNext!=nullptr)  //проверяем равен ли указатель на следуший  обьект NULL
        {
           arrant=arrant->myNext;//двигаемся по списку,присваивая
           //адресу указателя -адрес на указатель следушиго обьекта и снова проверяем условие цыкла...
           //до тех пор пока не будем у конечного элемента...
        }
        arrant->myNext = new List<T>(value);
       /*
         Аресом указателем(указываюшего на последний элемет)вызываем поле указываешее на
         следуший элемент, присваиваем адрес нового созданого конструктора обьекта
         в котором  myValue=value;  и указатель на следуший элемент myNext=0;
       */
    }//добавления элемента

    T pop_back()
    {
        List<T> * arrant=this;//На голову
         while(arrant->myNext != nullptr && arrant->myNext->myNext != nullptr)
        {
            arrant=arrant->myNext;
        }
        List<T> * carrant=arrant->myNext; //указателю адрес на последним элемент
        arrant->myNext=nullptr;              //нулим указатель
        T valueCopy = carrant->getValue();
        delete carrant;          //высвобождаем память занимаемуе последним элемент

        return valueCopy;
    }


    int lentgh()
    {
        int counter=0;
        for(List<T> * arrant=this;arrant!=nullptr;arrant=arrant->myNext)
            ++counter;

        return counter;
    }             //размер списка

    int find(T value)
    {
        int result = -1;
        int counter=-1;
        for(List<T> * arrant=this;arrant!=nullptr;arrant=arrant->myNext)
        {
            ++counter;
           if(arrant->getValue() == value){
               result = counter;
               break;
           }
        }
        return result;
    } // -1 if result is'nt exist

    List* getNext()
    {
        return myNext;
     }
};

#endif // LIST_H
