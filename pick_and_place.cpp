#include <iostream>
#include <vector>
#include <string>


using namespace std;

void getInputs(){
  string box_nums;
  string box_sizes;
  cout << "Please enter the number of boxes, as numbers spearated by spaces. \n Format: S/M/L/XL: " << endl;
  cin >> box_nums;
  checknegative(box_nums, "first, box number");
  cout << "Please enter the amount of parts each box can hold, as numbers spearated by spaces. \n Format: S/M/L/XL: " << endl;
  cin >> box_sizes;
  checkNegative(box_nums, "second, box size");
}

void checkNegative(string num_string, string var_name){ //pass by reference here
  for(int i=0; i<num_string.size(); i++){
    if(box_nums[i] == '-'){
      cout << "Negative number detected in the " << var_name << " input. Please re-enter inputs with positive numbers." << endl;
      getInputs();
    }
  }
}

int main(){
  getInputs();
  
  
  return 0;
}
