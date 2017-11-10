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

void sdvig(double *array, int size, int sdv){
    double *array_left=new double[size-sdv];
    double *array_right=new double[sdv];
    for(unsigned int i=0; i<size; ++i){
        if(i<size-sdv){
            array_left[i]=array[i];
        }
        else{
            array_right[i+sdv-size]=array[i];
        }
    }
    for(unsigned int i=0; i<(size-sdv)/2; ++i){
        swap(array_left[i], array_left[size-sdv-1-i]);
    }
    for(unsigned int i=0; i<sdv/2; ++i){
        swap(array_right[i], array_right[sdv-1-i]);
    }
    for(unsigned int i=0; i<size; ++i){
        if(i<size-sdv){
            array[i]=array_left[i];
        }
        else{
            array[i]=array_right[i+sdv-size];
        }
    }
    for(unsigned int i=0; i<size/2; ++i){
        swap(array[i], array[size-1-i]);
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
        int sdv;
        string s1;
        getline(cin, s1);
        istringstream stream1(s1);
        if(!(stream1>>sdv)||(sdv<0)){
            cout<<"An error has occured while reading input data."<<endl;
            return -2;
        }
        sdvig(array, size, sdv);
        for(unsigned int i=0; i<size; ++i){
            cout<<array[i]<<" ";
        }
    }
    delete[]array;
    return 0;
}
