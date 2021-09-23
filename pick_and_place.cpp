#include <iostream>
#include <vector>
#include <string>


using namespace std;

void getInputs(){
  int box_nums[];
  int box_sizes[];
  int part_nums;
  cout << "Please enter the number of boxes, as numbers spearated by spaces. \n Format: S/M/L/XL: " << endl;
  cin >> box_nums;
  checkNegative(box_nums, "first, box number");
  // Get the number of boxes and check them for illegal entries.
  
  cout << "Please enter the amount of parts each box can hold, as numbers spearated by spaces. \n Format: S/M/L/XL: " << endl;
  cin >> box_sizes;
  checkNegative(box_nums, "second, box size");
  // Get the capacity of the boxes and check them for illegal entries.
  
  cout << "Please enter the number of parts, as a positive number: " << endl;
  cin >> part_nums;
  // Get the number of parts and check for illegal entries.
  
}

void checkNegative(int num_list[], string var_name){ //pass by reference here
  for(int i=0; i<num_list.size(); i++){
    for(int j=0; j<i.size(); j++){
      if(i[j] == '-'){ //Change to accept list data structure
        cout << "Negative number detected in the " << var_name << " input. Please re-enter inputs with positive numbers." << endl;
        getInputs();
    }
    }
  }
}

void checkSizes(){
  
}

int main(){
  getInputs();
  
  
  return 0;
}
