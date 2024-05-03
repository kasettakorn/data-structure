#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,5,4,6,7,8,10,9,2,3};
    int arr2d[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; //Must be identify size of multi dimensional arrray
    
    string arr_string[2][100] = {{"ABC", "EFGH"}, {"IJKL", "MNOPQRSTUVWXYZ"}};

    cout << arr2d[0][0] << endl;
    
    // cout << sizeof(arr_string)/sizeof(arr_string[0]) << endl;

    for(int i=0; i<2; i++) {
        for (int j = 0; j < 2; j++)
        {
            cout << arr_string[i][j] << " ";
        }
        cout << endl;
        
    }

    return 0;
}