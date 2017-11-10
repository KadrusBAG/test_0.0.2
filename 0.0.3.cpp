#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool input(float ** & matrix, unsigned int & rows, unsigned int & columns){
    string RoCo;
    getline(cin, RoCo);
    istringstream RC(RoCo);
    char znak;
    if((RC>>rows)&&(RC>>znak)&&(znak==',')&&(RC>>columns)){
        matrix=new float *[rows];
        for(unsigned int i=0; i<rows; ++i){
            matrix[i]=new float[columns];
            string stroka;
            getline(cin, stroka);
            istringstream stream(stroka);
            for(unsigned int j=0; j<columns; ++j){ 
                if(!(stream>>matrix[i][j])){
                    return false; 
                }
            }
        }
    }
    else{
        return false;
    }
    return true;
}

void sdvig(float *array, int size, int sdv){
    float *array_left=new float[size-sdv];
    float *array_right=new float[sdv];
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
    float **matrix;
    unsigned int rows, columns;
    if(!(input(matrix, rows, columns))){
        cout<<"An error has occured while reading input data"<<endl;
        return -1;
    }
    int sdv;
    string s;
    getline(cin, s);
    istringstream stream(s);
    if(!(stream>>sdv)||(sdv<0)){
        cout<<"An error has occured while reading input data."<<endl;
        return -2;
    }
    unsigned int size=2*rows+2*columns-4;
    float *line=new float[size];
    unsigned int el=0;
    for(unsigned int j=0; j<columns-1; ++j){
        line[el]=matrix[0][j];
        el++;
    }
    for(unsigned int i=0; i<rows-1; ++i){
        line[el]=matrix[i][columns-1];
        el++;
    }
    for(unsigned int j=columns-1; j>0; --j){
        line[el]=matrix[rows-1][j];
        el++;
    }
    for(unsigned int i=rows-1; i>0; --i){
        line[el]=matrix[i][0];
        el++;
    }
    sdvig(line, size, sdv);
    el=0;
    for(unsigned int j=0; j<columns-1; ++j){
        matrix[0][j]=line[el];
        el++;
    }
    for(unsigned int i=0; i<rows-1; ++i){
        matrix[i][columns-1]=line[el];
        el++;
    }
    for(unsigned int j=columns-1; j>0; --j){
        matrix[rows-1][j]=line[el];
        el++;
    }
    for(unsigned int i=rows-1; i>0; --i){
        matrix[i][0]=line[el];
        el++;
    }
    delete[]line;
    for(unsigned int i=0; i<rows; ++i){
        for(unsigned int j=0; j<columns; ++j){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    for(unsigned int i=0; i<rows; ++i){
        delete[]matrix[i];
    }
    delete[]matrix;
}
