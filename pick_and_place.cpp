/**
 * @file RWA01.cpp
 * @author Nicholas Novak (nnovak@umd.edu)
 * @brief This program will simulate the packaging of boxes by an industrial robot.
 * @version 0.4
 * @date 2021-10-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

/**
 * @brief This function checks inputs to ensure that they are positive numbers.
 * 
 * @param s_val the small box value
 * @param m_val the medium box value
 * @param l_val the large box value
 * @param xl_val the xlarge box value
 * @return true returned if there is a negative value
 * @return false returned as default or if no negative values are found
 */

bool checkNegatives(int s_val, int m_val, int l_val, int xl_val){
    bool neg_check = false;

    // Detection for all inputs
    if(s_val < 0 || m_val < 0 || l_val < 0 || xl_val < 0){
        cout << "Negative value input. Try again." << endl;
        neg_check = true;
    }
    
    return neg_check;
}

/**
 * @brief This function checks for illegal inputs. In this case, an illegal input would be if a box can hold more parts than its larger counterpart.
 * i.e. if a small could hold 20 parts and a large could hold 5.
 * 
 * @param s_size the size of the small box
 * @param m_size the size of the medium box
 * @param l_size the size of the large box
 * @param xl_size the size of the xlarge box
 * @return true returned if an illegal entry is detected
 * @return false returned by default or if no illegal entries are detected
 */

bool checkSizes(int s_size, int m_size, int l_size, int xl_size){
    bool illegal_entry = false;

    // Check all sizes for illegal entries.
    if(s_size > m_size || s_size > l_size || s_size > xl_size){illegal_entry = true;}
    if(m_size > l_size || m_size > xl_size){illegal_entry = true;}
    if(l_size > xl_size){illegal_entry = true;}

    if(illegal_entry == true){cout << "Illegal size entries. Box sizes must be in ascending order from small to xlarge. Try again." << endl;}
    return illegal_entry;
}

/**
 * @brief This function performs the calculations needed to represent the boxes being filled.
 * The total sum is decremented as each box is filled.
 * 
 * @param s_boxes the amount of small boxes
 * @param m_boxes the amount of medium boxes
 * @param l_boxes the amount of large boxes
 * @param xl_boxes the amount of xlarge boxes
 * @param s_size  the size of small boxes
 * @param m_size the size of medium boxes
 * @param l_size the size of large boxes
 * @param xl_size the size of xlarge boxes
 * @param total_vals the total amount of parts to be packaged
 * @return int the remaining parts are returned
 */

int fillBoxes(int s_boxes, int m_boxes, int l_boxes, int xl_boxes, int s_size, int m_size, int l_size, int xl_size, int total_vals){
    int parts_remain{total_vals};
    int full_s{0};
    int full_m{0};
    int full_l{0};
    int full_xl{0};

    int s_tot = s_boxes;
    int m_tot = m_boxes;
    int l_tot = l_boxes;
    int xl_tot = xl_boxes;


    cout << "Boxes that can be built with " << total_vals << " parts:" << '\n';
    cout << string(20, '-') << '\n';

    // Fill xlarge boxes first.
    while(parts_remain >= xl_size && xl_boxes > 0){
        parts_remain -= xl_size;
        full_xl++;
        xl_boxes--;
    }
    cout << "XL Box (" << xl_tot << " x " << xl_size << " max): " << full_xl << "\t--\tremaining parts: " << parts_remain << '\n';

    // Fill large boxes second.
    while(parts_remain >= l_size && l_boxes > 0){
        parts_remain -= l_size;
        full_l++;
        l_boxes--;
    }
    cout << "L Box (" << l_tot << " x " << l_size << " max): " << full_l << "\t--\tremaining parts: " << parts_remain << '\n';

    // Fill medium boxes third.
    while(parts_remain >= m_size && m_boxes > 0){
        parts_remain -= m_size;
        full_m++;
        m_boxes--;
    }
    cout << "M Box (" << m_tot << " x " << m_size << " max): " << full_m << "\t--\tremaining parts: " << parts_remain << '\n';

    // Fill small boxes last.
    while(parts_remain >= s_size && s_boxes > 0){
        parts_remain -= s_size;
        full_s++;
        s_boxes--;
    }
    cout << "S Box (" << s_tot << " x " << s_size << " max): " << full_s << "\t--\tremaining parts: " << parts_remain << '\n';

    return parts_remain;
}

/**
 * @brief Obtain the parts to be packed, box numbers, and box sizes from the user.
 * Call checkNegative and checkSizes to check the inputs.
 * Call fillBoxes to begin the filling process.
 * 
 * @return int return the remaining parts for printing in the main statement.
 */

int getBoxNums(){
    int total_parts;

    int s_box;
    int m_box;
    int l_box;
    int xl_box;

    int s_size;
    int m_size;
    int l_size;
    int xl_size;

    cout << string(20,'-') << '\n';
    cout << "How many parts in total?\t";
    cin >> total_parts;
    if(total_parts < 0){
        cout << "Negative number entered." << endl;
        getBoxNums();
    }



    cout << string(20, '-') << endl;
    cout << "How many boxes for S/M/L/XL?\t";
    scanf ("%d %d %d %d", &s_box, &m_box, &l_box, &xl_box);
    if(checkNegatives(s_box,m_box,l_box,xl_box)){getBoxNums();}

    cout << string(20, '-') << endl;
    cout << "How many parts per box for S/M/L/XL?\t";
    scanf ("%d %d %d %d", &s_size, &m_size, &l_size, &xl_size);
    if(checkNegatives(s_size,m_size,l_size,xl_size)){getBoxNums();}
    if(checkSizes(s_size, m_size, l_size, xl_size)){getBoxNums();}

    int parts_left = fillBoxes(s_box, m_box, l_box, xl_box, s_size, m_size, l_size, xl_size, total_parts);

    return parts_left;
}

/**
 * @brief Call getBoxNums to begin the program. Print out the parts remaining at the end.
 * 
 * @return int 0
 */

int main(){
    int remainder = getBoxNums();
    cout << "Parts remaining: " << remainder << '\n';
    return 0;


}
