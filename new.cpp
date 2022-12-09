#include <bits/stdc++.h>
int no_of_integers;
using namespace std;
int insert(int x, int array[], int position) {
    int temp;
    for (int k = position-1; k < 50; k++) {
        temp = array[49];

        

}}
int main() {
    int i;
/*    for (i = 0;i <5;i++) {
  
        cout << "hello world" << endl;
        cout << i<<endl;


}
   cout << i<<endl;*/
   int array[50];
   
   cout <<"Enter the number of elements in the array: ";
   cin >> no_of_integers;
   for (i = 0; i < no_of_integers; i++) {
        cout << "Enter the element no " << i+1;
        cin >> array[i];


}
    for (i = no_of_integers; i < 50; i++) {
        array[i] = -1;}
    for (int j = 0; j < 50; j++) {
        cout << array[j] << endl;}
}
