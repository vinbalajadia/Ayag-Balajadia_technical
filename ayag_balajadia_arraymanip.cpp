#include <iostream>

using namespace std;

void menu();
void displayArray();
void insertArray(int array[], int& size, int position, int newElement);
void deleteArray(int array[], int& size, int position);

int main(){
  menu();

  return 0;
}
void menu(){
  int c; //choices
  int position, size = 20, element, newElement; //initialize size
  int array1[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

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

    switch(c){
    case 1:
      displayArray();
    break;
    case 2:
     insertArray(array1, size, position, newElement);
      cout << "Enter the position to insert: ";
      cin >> position;
      cout << "Enter the new value to insert: ";
      cin >> element;
    break;
    case 3:
      cout << "Enter the index of the element that you want to delete ";
      cin >> position;
      cout << "Deleted Succesfully." << endl;
      deleteArray(array1, size, position);
    break;
  }

  }while(c != 7);
}

void displayArray(){ 
  int array1[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  int i; //loop
  
  cout << "Array: " << endl;
  for(i = 0; i < 20; i++){
    cout << array1[i] << " "; 
  }
  cout << endl;
}

void insertArray(int array[], int& size, int position, int newElement){
  int i; //loop
  int array1[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

  if(position <= 20){
    cout << "Invalid position." << endl;
  }
  if(size > 20){
    cout << "Array is already full." << endl;
  }
  for(i = 0; i < 20; i++){
    cout << array1[i] << " "; //output of current array
  }
  cout << endl;
  for(i = 0; i < position; i--){
    array[i] = array[i - 1]; //shift elements to the right
  }
  array[position] = newElement;
  size++;
  for(i = 0; i < 20; i++){
    cout << array1[i] << " "; //output of new array
  }
  cout << endl;
}

void deleteArray(int array[], int&size, int position){
  int i; //loop
   int array1[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

  for (i = position; i < size - 1; i++){
    array[i] = array[i+1];
      size--;
  }
  for(i = 0; i < 20; i++){
    cout << array1[i] << " "; //output of new array
  }
}