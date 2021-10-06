#include <iostream>

using namespace std;

bool checkNegatives(int s_val, int m_val, int l_val, int xl_val){
    bool neg_check = false;
    if(s_val < 0 || m_val < 0 || l_val < 0 || xl_val < 0){
        cout << "Negative value input. Try again." << endl;
        neg_check = true;
    }
    return neg_check;
}

bool checkSizes(int s_size, int m_size, int l_size, int xl_size){
    bool illegal_entry = false;
    if(s_size > m_size || s_size > l_size || s_size > xl_size){illegal_entry = true;}
    if(m_size > l_size || m_size > xl_size){illegal_entry = true;}
    if(l_size > xl_size){illegal_entry = true;}

    if(illegal_entry == true){cout << "Illegal size entries. Box sizes must be in ascending order from small to xlarge. Try again." << endl;}
    return illegal_entry;
}

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


    while(parts_remain >= xl_size && xl_boxes > 0){
        parts_remain -= xl_size;
        full_xl++;
        xl_boxes--;
    }
    cout << "XL Box (" << xl_tot << " x " << xl_size << " max): " << full_xl << "\t--\tremaining parts: " << parts_remain << '\n';

    while(parts_remain >= l_size && l_boxes > 0){
        parts_remain -= l_size;
        full_l++;
        l_boxes--;
    }
    cout << "L Box (" << l_tot << " x " << l_size << " max): " << full_l << "\t--\tremaining parts: " << parts_remain << '\n';

    while(parts_remain >= m_size && m_boxes > 0){
        parts_remain -= m_size;
        full_m++;
        m_boxes--;
    }
    cout << "M Box (" << m_tot << " x " << m_size << " max): " << full_m << "\t--\tremaining parts: " << parts_remain << '\n';


    while(parts_remain >= s_size && s_boxes > 0){
        parts_remain -= s_size;
        full_s++;
        s_boxes--;
    }
    cout << "S Box (" << s_tot << " x " << s_size << " max): " << full_s << "\t--\tremaining parts: " << parts_remain << '\n';




    return parts_remain;
}


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


int main(){
    int remainder = getBoxNums();
    cout << "Parts remaining: " << remainder << '\n';
    return 0;


}
