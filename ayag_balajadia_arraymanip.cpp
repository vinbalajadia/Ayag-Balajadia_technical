#include <iostream>
#include <cctype>

using namespace std;

int array1[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

//vin
void menu();
void displayArray();
void insertArray(int array[], int& size, int position, int newElement);
void deleteArray(int array[], int& size, int position);

//ry
int flag, position, findElement, firstElement, secondElement;
void swapArray(int array1[]);
void reverseArray();
void findArray();
void arrayPresent(int &flag, int &position);


int main(){
  menu();

  return 0;
}

void menu(){  
  int c; //choices
  int position, newElement; //for position and new value
  int size = 20; //max size

  do{
    //
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

    if(isalpha(c)){ //to check if the input was an alphabet
      cout << "Please enter a number from (1-7)." << endl;
      continue;
    }
    if(cin.fail()){
      cout << "Please enter a number from (1-7)." << endl;
      cin.clear(); //clears the error
      cin.ignore(); //clears the error buffer
      continue; //to continue right at the beginning
    }

    switch(c){
    case 1:
      displayArray();
      break;
    case 2:
      cout << "Current Array:" << endl; //output of current array 
      displayArray();
      cout << "Enter the position to insert: ";
      cin >> position;
      cout << "Enter the new value to insert: ";
      cin >> newElement;
      insertArray(array1, size, position, newElement); //function for insertion
      cout << "\nUpdated Array:" << endl;
      displayArray(); //output of updated array after insertion
      break;

    case 3:
      displayArray(); //output of current array 
      cout << "Enter the index of the element that you want to delete: ";
      cin >> position;
      deleteArray(array1, size, position);
      displayArray(); //output of updated array
      break;
    case 4:
      swapArray(array1);
      break;
    case 5:
      reverseArray();
      break;
    case 6:
      findArray();
      break;
    case 7:
      exit(0);
    default:
      cout << "\nPlease enter a valid input. Returning to menu again." << endl;
      menu(); //return to menu
      break;
  }
  }while(c!=7);
}

void displayArray(){ 
  int i; //loop
  
  for(i = 0; i < 20; i++){
    cout << array1[i] << " "; 
  }
  cout << endl;
}

void insertArray(int array1[], int& size, int position, int newElement){
  int i; //loop
  
  if(position < 0 || position > size) {
    cout << "Invalid position." << endl;
  }
  for(int i = size; i > position; i--) {
    array1[i] = array1[i - 1]; // shift elements to the right
  }
  array1[position] = newElement; // insert the new element
  size++; // increase the size of array
  cout << "\nElement inserted successfully." << endl;
}

void deleteArray(int array1[], int&size, int position){
  int i; //loop

  for (i = position; i < size - 1; i++){
    array1[i] = array1[i+1];
      size--;
  }
  cout << "\nDeleted Succesfully." << endl;
}

void swapArray(int array1[]){
  //by position, it means how it is displayed, not index
  cout << "\nEnter the number position of the first element: ";
  cin >> firstElement;
  if (cin.fail() || firstElement <= 0 || firstElement >= 20){ //esnures that only integer is entered
    cout << "\nPlease enter a valid input." << endl;
    cin.clear();
    cin.ignore();
    menu();
  }
  cout << "\nEnter the number position of the second element: ";    
  cin >> secondElement;
  if (cin.fail() || secondElement <= 0 || secondElement >= 20){ //esnures that only integer is entered
    cout << "\nPlease enter a valid input." << endl;
    cin.clear();
    cin.ignore();
    menu();
  }

  if (firstElement <= 20 && firstElement > 0 && secondElement<= 20 && secondElement > 0){ //validation of input
    int temp; //temporary storage to store values
    temp = array1[firstElement - 1];
    array1[firstElement - 1] = array1[secondElement - 1];
    array1[secondElement - 1] = temp;
    cout << "Swapping successful. Displaying the updated array." << endl;
    displayArray(); // display changes
  } else {
    cout << "\nPlease enter valid inputs only. Returning to menu." << endl;
    menu();
  }
}//b

void reverseArray(){
  for(int i =19;i>=0;i--){  //utilizes a for loop counting the iteration down to 0
    cout << array1[i] << " ";

  }
}//b

void findArray(){
  cout << "\nEnter the value or element you want to find the position of: ";
  cin >> findElement;

  if (cin.fail() || findElement <= 0 || findElement >= 20){ //esnures that only integer is entered
    cout << "\nPlease enter a valid input." << endl;
    cin.clear();
    cin.ignore();
    menu();
  }
  position = 0;  //position is default to 0 so if the user uses the function again, the previous changes are reset
  flag = 0;      //same as here
  if (findElement < 20 && findElement > 0){
    arrayPresent(flag, position); //it calls a function which runs a code which checks if the entered element is present and after returns the value of position and flag
    cout << "The value of " << findElement << " is located at the number " << position << " position of the list." << endl;
     if(flag == 0){
        cout << "The entered input is not inside the array. Please try again." << endl;
        menu();
  }
  } else {
    cout << "\nPlease enter a valid input. Returning to menu." << endl;
    menu();
  }
}

void arrayPresent (int &flag, int &position){
    for (int i = 0; i<20;i++){
      if(findElement == array1[i]){
        position = i + 1;  //plus one so the user bases the position on what is displayed and not the index
        flag = 1;
        return;
      }
    } if (flag == 0){
      cout << "\nEntered element cannot be found in the array. Please try again." << endl;
      menu();
    }
}