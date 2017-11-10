#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool read(double *array, int size){
    string stroka;
    getline(cin, stroka);
    istringstream stream(stroka);
    for(unsigned int i=0; i<size; ++i){
        if(!(stream>>array[i])){
            cout<<"An error has occured while reading input data."<<endl;
            return false;
        }
    }
    if(!(stream.eof())){
        cout<<"An error has occured while reading input data."<<endl;
        return false;
    }
}

void reverse(double *array, int size){
    for(unsigned int i=0; i<size/2; ++i){
        swap(array[i], array[size-i-1]);
    }
}

int main(){
    int size;
    string s;
    getline(cin, s);
    istringstream stream(s);
    if(!(stream>>size)||(size<0)){
        cout<<"An error has occured while reading input data."<<endl;
        return -1;
    }
    double *array=new double[size];
    if(read(array, size)){
        reverse(array, size);
        for(unsigned int i=0; i<size; ++i){
            cout<<array[i]<<" ";
        }
    }
    delete[]array;
    return 0;
}
