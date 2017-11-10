#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool create(float ** & matrix, unsigned int & rows, unsigned int & columns){
    string RoCo;
    getline(cin, RoCo);
    istringstream RC(RoCo);
    char znak;
    if((RC>>rows)&&(RC>>znak)&&(znak==',')&&(RC>>columns)){
        matrix=new float *[rows];
        for(unsigned int i=0; i<rows; ++i){
            matrix[i]=new float[columns];
        }
    }
    else{
        return false;
    }
    return true;
}

void ulitka(float ** & matrix, int rows, int columns){
    int j,i;
	int t=1;
	i=1;
	int v=0;
	int l=1,c=0,d=0;
	int f1, f2;
	f1=rows; f2=columns;
	while (t<=rows*columns){
	    for (j=v;j<f2;++j){          //заполняем справа на лево
			matrix[i][j]=t;
			++t;
		}
		v=j;
		for (i=1;i<f1;++i){          //заполняем с верху вниз
			matrix[i][j]=t;
			++t;
		}
		l=i;
		for (j=v;j>=c;--j){         //заполняем с лева на право
            matrix[i][j]=t;
			++t;
		}
        for (i=l;i>d;--i){          //заполняем с низу верх
              matrix[i][j]=t;
			++t;
		}
		--f1;
		--f2;               //уменьшаем параметры матрицы(что бы числа шли внутрь а не заполнялись поверх тех которы уже заполнены)
		++v;
		++l;
		++c;
		++d;
	}
}

int main(){
    float **matrix; unsigned int rows, columns;
    if(!(create(matrix, rows, columns))){
        cout<<"ERROR"<<endl;
        return -1;
    }
    ulitka(matrix, rows, columns);
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
