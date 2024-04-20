#include <iostream>

using namespace std;

void menu();
void insertArray(int array[], int& size, int position, int n);
void deleteArray();

int main(){
  int array1 [20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  menu();
}
void menu(){
  int c; //choices

  do{
    cout << "---------------------------------------" << endl;
    cout << "|\t\t MENU                 |" << endl;
    cout << "---------------------------------------" << endl;
    cout << "| [1] Display Array Contents          |" << endl;
    cout << "| [2] Insert Element                  |" << endl;
    cout << "| [3] Delete Element                  |" << endl;
    cout << "| [4] Swap Element                    |" << endl;
    cout << "| [5] Reverse Element                 |" << endl;
    cout << "| [6] Find Element                    |" << endl;
    cout << "| [7] Exit Program                    |" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Enter your choice: ";
    cin >> c;
  }while(c != 7);
}

void insertArray(int array[], int& size, int position, int n){

}

void deleteArray(){

}