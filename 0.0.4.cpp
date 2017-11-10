#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool create(int ** & matrix, int & rows, int & columns){
    string RoCo;
    getline(cin, RoCo);
    istringstream RC(RoCo);
    char znak;
    if((RC>>rows)&&(RC>>znak)&&(znak==',')&&(RC>>columns)){
        matrix=new int *[rows];
        for(int i=0; i<rows; ++i){
            matrix[i]=new int[columns];
            for(int j=0; j<columns; ++j){
                matrix[i][j]=0;
            }
        }
    }
    else{
        return false;
    }
    return true;
}

void ulitka(int ** matrix, int rows, int columns){
    int i, j, k=1,  c=0, b;
	b=rows*columns;
    while(k<=rows*columns){
		for(j=c; j<columns-c; ++j){
			if(k>b){
				break;
			}
			matrix[c][j]=k++;
		}
		for(i=c+1; i<rows-c; ++i){
			if (k>b){
				break;
			}
			matrix[i][columns-c-1]=k++;
		}
		for(j=columns-c-2; j>=c; --j){
			if(k>b){
				break;
			}
			matrix[rows-c-1][j]=k++;
		}
		j++;
		for(i=rows-c-2; i>c; --i){
			if(k>b){
				break;
			}
			matrix[i][c]=k++;
		}
		c++;
	}
}

int main(){
    int **matrix, rows, columns;
    if(!(create(matrix, rows, columns))){
        cout<<"ERROR"<<endl;
        return -1;
    }
    ulitka(matrix, rows, columns);
    for(int i=0; i<rows; ++i){
        for(int j=0; j<columns; ++j){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<rows; ++i){
        delete[]matrix[i];
    }
    delete[]matrix;
    return 0;
}
