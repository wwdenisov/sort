#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
/*
int *myMarge(int *first, int *second, int sizeF, int sizeS){
    int *actual;
    actual = new int [sizeF+sizeS];
    int kolF = 0;
    int kilS = 0;
    for(int i = 0; i < sizeF+sizeS; i++){
                //если мы уже полностью использовали вектора а,
                //то нам осталось дописать элементы вектора b
         if(kol1==sizeF){
            actual[i] = second[kol2];
            kol2++;
            continue;
         }
                //наоборот
         if(kol2==sizeS){
            actual[i] = first[kol1];
            kol1++;
            continue;
         }
                //так как наши вектора еще не полностью
                //использованы, то нужно сравнить какое
                //значение ставить на следующее место
         if(first[kol1]<=second[kol2]){
            actual[i] = first[kol1];
            kol1++;
         }
         else{
            actual[i] = second[kol2];
            kol2++;
         }
     }
     return actual;
}
*/
vector <int> merge(vector <int> a, vector <int> b)
//функция сливает два вектора
{
    vector<int> c(a.size()+b.size());//результирующий вектор
    //количество использованных вершин
    int kol1 = 0;//в векторе а
    int kol2 = 0;//в векторе b
    //заполним массив c
    for(int i = 0; i < c.size(); i++)
    {
        //если мы уже полностью использовали вектора а,
        //то нам осталось дописать элементы вектора b
        if(kol1==a.size())
        {
            c[i] = b[kol2];
            kol2++;
            continue;
        }
        //наоборот
        if(kol2==b.size())
        {
            c[i] = a[kol1];
            kol1++;
            continue;
        }
        //так как наши вектора еще не полностью
        //использованы, то нужно сравнить какое
        //значение ставить на следующее место
        if(a[kol1]<=b[kol2])
        {
            c[i] = a[kol1];
            kol1++;
        }
        else
        {
            c[i] = b[kol2];
            kol2++;
        }
    }
    return c;
}

int *myMerge_sort(int *notSort, int size){

}

//функция сортирует вектор
vector<int> merge_sort(vector <int> a)
{
    //если размер вектора меньше 1,
    //то он отсортирован
    if(a.size()<=1)
        return a;
    vector<int> b,c;
    b.assign(a.begin(), a.end()-(a.size()/2));
    c.assign(a.end()-(a.size()/2), a.end());
    return merge(merge_sort(b),merge_sort(c));
}
int main()
{

    vector<int> a;
    for(int i = 0; i < 10; i++)
    {
        a.push_back(rand()%10);
    }
    for(int i = 0;i < a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout << endl;
    a = merge_sort(a);
    for(int i = 0;i < a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

