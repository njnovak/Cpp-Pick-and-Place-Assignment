#include <iostream>
#include <vector>
#include <string>


using namespace std;

void getInputs(){
  list box_nums<int>;
  list box_sizes<int>;
  int part_nums;
  cout << "Please enter the number of boxes, as numbers spearated by spaces. \n Format: S/M/L/XL: " << endl;
  cin >> box_nums;
  checkNegative(box_nums, "first, box number");
  cout << "Please enter the amount of parts each box can hold, as numbers spearated by spaces. \n Format: S/M/L/XL: " << endl;
  cin >> box_sizes;
  checkNegative(box_nums, "second, box size");
  cout << "Please enter the number of parts, as a positive number: " << endl;
  cin >> part_nums;
  
}

void checkNegative(list num_list<int>, string var_name){ //pass by reference here
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
