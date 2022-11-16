#include <iostream>
using namespace std;
class Student {
public:
    void SetSID(int a);
    int GetSID();
private:
    int SID;
};

void Student::SetSID(int a) {
    SID = a;
};
int Student::GetSID() {
    return SID;
};

int* BinarySearch(Student* ptr, int arr_size, int key) {
    
    static int val[2];
    // ...
    int low = 0, high = arr_size - 1, count = 0;
        while (low <= high) {
            count++;
            int mid = ((low + high) / 2);
            
            if (ptr[mid].GetSID() == key) {
                val[0] = mid;
                val[1] = count;
                break;
            }
            else if (key < ptr[mid].GetSID()) {
                high = mid - 1;
            }
            else if (key > ptr[mid].GetSID()){
                low = mid + 1;
            } else {
                val[0] = -1;
            }
        }
    return val;
}

int CheckOrder(Student* ptr, int arr_size) {

    int i;
        for (i = 0; i < arr_size - 1; i++)
        {
            Student close = ptr[i];
            Student far = ptr[i + 1];

            if (close.GetSID() > far.GetSID())
            {
                return 0;
            }
        }
        return 1;
}

int main()
{
    Student x[7];
    int temp, key, mode, *value;
    cin >> mode >> key;
    for (int i = 0; i < 7; i++) {
        
        cin >> temp;
        x[i].SetSID(temp);
    }
    switch (mode) {
    
    case 1: // check correction of the CheckOrder function
        
        cout << CheckOrder(x, 7) << endl;
        break;
    case 2: // check correction of the returned index of the search
        if (CheckOrder(x, 7)) {
            value = BinarySearch(x, 7, key);
            cout << value[0] << endl;
        }
        else {
            cout << -2 << endl;
        }
        break;
    case 3: // check correction of the number of search iterations
        if (CheckOrder(x, 7)) {
            value = BinarySearch(x, 7, key);
            cout << value[1] << endl;
        }
        else {
            cout << -2 << endl;
        }
        break;
    }
    return 0;
}
