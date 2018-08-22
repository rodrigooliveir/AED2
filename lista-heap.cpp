#include <stdlib.h>
#include <iostream>
#define TAM 50

using namespace std;

int tamHeap;

void heapSort(int lista[TAM], int n);

void imprime_vetor(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    //int lista[TAM]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
    int lista[TAM]={50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,};
    imprime_vetor(lista, TAM);
    heapSort(lista, TAM);
    cout << endl;
    imprime_vetor(lista, TAM);
    return 0;
}

void heapify(int arr[], int i)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int m = i;
    int temp;
    if (l < tamHeap && arr[l] > arr[m])
        m = l;
    if (r < tamHeap && arr[r] > arr[m])
        m = r;
    if (m != i)
    {
        temp=arr[i];
        arr[i]=arr[m];
        arr[m]=temp;
        heapify(arr, m);
    }
}

void constHeap(int arr[], int n)
{
    tamHeap=n;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr,i);
}

void heapSort(int arr[], int n)
{
    int temp;
    constHeap(arr, n);
    for (int i=n-1; i>=0; i--)
    {
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        tamHeap--;
        heapify(arr,0);
    }
}
