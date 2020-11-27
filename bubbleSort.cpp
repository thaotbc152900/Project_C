#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <math.h>
using namespace std;
// void readfile(){
//     ifstream file;
// 			file.open("mang1.txt");
// 			file >> n;
// 			cout<<endl;
// 			for(int i = 0; i < n; i++){
// 				file >> *(p + i);
// 			}
// 			file.close();
// 			cout<<"n= "<<n;
// 			output(p,n);
// 			break;
// }

int input_array(int *p, int n){
    int choose;
    cout<<"Chon phuong thuc nhap mang\n";
    cout<<" ____________________________________________\n";
    cout<<"|            1.Nhap du lieu ban phim         |\n";
    cout<<"|____________________________________________|\n";
    cout<<" ____________________________________________\n";
    cout<<"|             2.Tao mang ngau nhien          |\n";
    cout<<"|____________________________________________|\n";
    cout << "Nhap su lua chon: ";
    cin >> choose;
    switch (choose)
    {
    case 1: 
        cout << "nhap so phan tu cua mang: ";
			cin >> n;
			for(int i = 0; i < n; i++){
				cout << "nhap phan tu thu " << i + 1<<": ";
				cin >> *(p + i); 
			}
            for(int i = 0 ; i < n ; i++){
                cout<<setw(5)<<*(p+i);
            }
            cout<< endl;
			break;
    case 2:
			srand(time(0));
			cout << "nhap so phan tu mang: ";
			cin >> n;
			for(int i = 0; i < n; i++){
				*(p + i) = rand() % 45 + 5;
			}
            for(int i = 0 ; i < n ; i++){
                cout<<setw(5)<<*(p+i);
            }
            cout<< endl;
			break;
    }
    return n;
}
void output(int *p, int n){
	for(int k =0; k<n;k++){
        cout<<setw(5)<<*(p+k);
    } 
    cout<<endl;
}
void bubbleSort(int *p, int n){
    for(int i = 0; i< n-1; i++){
        for(int j = 0; j<n-1-i; j++){
            if (*(p+j) > *(p+j+1)){
            	int temp = *(p+j);
            	*(p+j)= *(p+j+1);
            	*(p+j+1)=temp;
			}
            cout<<"Mang sau moi buoc sap xep: ";
            output(p,n);
        }     
    }
    
}
void selectSort(int *p, int n){
    for (int i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        int min_idx = i;  
        for (int j = i+1; j < n; j++)  
        if (*(p + j) < *(p + min_idx))  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        int temp = *(p+min_idx);
        *(p+min_idx)= *(p+i);
        *(p+i)=temp; 
		cout<<"Mang sau moi buoc sap xep: "; 
        output(p,n);
    }  
}
void insertSort(int *p, int n){
	for (int i = 1; i < n; i++) 
    {  
        int key = *(p+i);  
        int j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && *(p+j) > key) 
        {  
           *(p+j + 1) = *(p+j);  
            j = j - 1;  
        }  
        *(p+j+1) = key;  
        cout<<"Mang sau moi buoc sap xep: "; 
        output(p,n);
    }  
}
int main(){
    int n;
    int *array = new int [n];
    int select;
    cout << " -----------------------------------------------TRANG CHU-------------------------------------------- \n";
    cout << "|                                      ___________________________                                   |\n";
    cout << "|                                     |       1. Bubble Sort      |                                  |\n";
    cout << "|                                     |___________________________|                                  |\n";
    cout << "|                                      ___________________________                                   |\n";
    cout << "|                                     |     2. Selection Sort     |                                  |\n";
    cout << "|                                     |___________________________|                                  |\n";
    cout << "|                                      ___________________________                                   |\n";
    cout << "|                                     |     3. Insertion Sort     |                                  |\n";
    cout << "|                                     |___________________________|                                  |\n";
    cout << " ---------------------------------------------------------------------------------------------------- \n";

    cout << "\n";
    cout << "\n";
    cout << "Moi ban nhap lua chon : \n >";
    cin >> select;
    switch (select)
    {
    case 1:
        n=input_array(array,n);
        cout << "Sap sep noi bot: \n";
        bubbleSort(array, n); 
        output(array,n);
        break;
    case 2:
        n=input_array(array,n);
        cout << "Sap sep chon: \n";
        selectSort(array,n); 
        break;
    case 3:
        n=input_array(array,n);
        cout << "Sap sep noi bot: \n";
        insertSort(array, n); 
        
        break;
    default:
        break;
    }
}
      
