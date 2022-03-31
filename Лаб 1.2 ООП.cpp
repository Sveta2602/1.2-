//////////////////////////////////////////////////////////////////////////////
// KvadratMatriza.h
// заголовний файл – визначення класу
#pragma once

#include <iostream>
#include <iomanip>
using namespace std;


class KvadratMatriza
{
private:
    int n;
    int** arr;

public:
    
    void Masiv0();
    void Masiv(int n);
    
    int Get_n() const { return n; }
    void Get_Arr()const { arr[n]; }
    bool Set_n(int);
    bool Set_Arr();
    bool Init(int n,int arr);
    int sum() ;                  //сума елем головнои диагонали
    int sumVerx();
    int sumNiz();
    void Read();                                //Create,Input     //вводимо з клавыатури/
    void Display();                         //Print
        void Del();  
};

#include <iostream>
using namespace std;

void KvadratMatriza::Masiv(int n) //конструктор видилення пам"яти масиву
{
    
    arr = new int* [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    
}
void KvadratMatriza::Masiv0() //конструктор без параметрів
{
    n = 1;
    arr = new int* [n];
    for (int i = 0; i < n; i++)
        arr[i] = 0;
}


bool KvadratMatriza::Set_n(int value)
{
    if (value > 0)
    {
        n = value;
        return true;
    }
    else
    {
        n = 0;
        return false;
    }
}
bool KvadratMatriza::Set_Arr()
{
    int i = 0, j = 0;
    if (i > n || j > n)
        if (i < 0 || j < 0)
            return false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j];
        }
        return true;
    }
    return 0;

}
bool KvadratMatriza::Init(int n,int arr)   // встановлює коректнисть параметрив до умов
{


    Set_n(n);

    return Set_Arr();
}



void KvadratMatriza::Read()  
{
    
    
    cout << " порядок матрици ="; cin >> n;  // задаємо значення порядку матрици
    do
                                                      //  заповнюємо масив елементами
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++) {

                cout << "arr[" << i << "][" << j << "] = ";

                cin >> arr[i][j];
            }
            cout << endl;
        }
            
         while (!Init(n,**arr));

}

void KvadratMatriza::Display()
{
    for (int i = 0; i < n; i++)                     ////виводимо на консоль матрицю
    {
        for (int j = 0; j < n; j++)
        
            cout <<  setw(4) << arr[i][j];
            cout << endl;
    }
    cout << endl;
}

int KvadratMatriza::sum()   //находимо суму елементив головнои диагонали
{
    int s = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(j==i)
            s += arr[i][j];
    return s;
}
int KvadratMatriza::sumVerx()   //знаходимо суму елементив над головною диагоналлю
{
    int s = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i < j)
                s += arr[i][j];
    return s;
}
int KvadratMatriza::sumNiz()
{                                                 //знаходимо суму елементив пид головною диагоналлю
    int s = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i > j)
            s += arr[i][j];
    return s;
}
        
void KvadratMatriza::Del()                    //видаляємо пам"ять надану для масиву
{
    for (int i = 0; i < n; i++)
        delete[] arr[i];

    delete[] arr;
}


#include <iostream>

using namespace std;

int main()
{
    
    setlocale(LC_ALL, "ru");
    
    KvadratMatriza a;
    
   
    a.Masiv(7);
    a.Read();
    a.Display();
    
   
    cout << "сума елементив гол.диагонали матрици a = " << a.sum() << endl;
    
    cout << "сума елементив над головною диагоналю матрици а = " << a.sumVerx() << endl;
    cout << "сума елементив пид головною диагоналю матрици а = " << a.sumNiz() << endl;

    a.Del();
    return 0;
}