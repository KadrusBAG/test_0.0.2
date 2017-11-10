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
    for(unsigned int i=0; i<rows-1; ++j){
        line[el]=matrix[i][columns-1];
        el++;
    }
    for(unsigned int j=columns-1; j>0; --j){
        line[el]=matrix[rows-1][j];
        el++;
    }
    for(unsigned int i=rows-1; i>0; --j){
        line[el]=matrix[i][0];
        el++;
    }
