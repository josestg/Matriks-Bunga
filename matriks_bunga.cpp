
/*
* Membuat implementasi Matriks flower dengan 
* dynamic typing (seperti python) 
*/

#include<iostream>
using namespace std;


/*
* VERSI A
*
* @param M : Matriks berukuran mxn
* @param k : skala baris memekar 
* @param l : skala kolom memekar 
*/
template<typename T, size_t row, size_t col>
T** flower(T (&M)[row][col], int k,int l){

    int k_row = row*k; // memperbesar ukuran baris menjadi k*m
    int k_col = col*l; // // memperbesar ukuran baris menjadi k*n

    // Membuat matriks baru R berukuran km*kn
    T **R = new T*[k_row];
    for(int i=0;i<k_row;i++){
        R[i] = new T[k_col];
    }

    // Memekarkan Matriks
    for(int i=0; i< row; i++){
        for(int j=0; j<col; j++){
            // Memekarkan setiap matrik i,j ke i+k dan j+k
            for(int x=i*k; x<(i+1)*k;x++){
                for(int y=j*l;y<(j+1)*l;y++){
                    R[x][y] = M[i][j];
                }
            }

        }
    }

    return R;
}

/*
* VERSI B
*
* @param M : Matriks berukuran mxn
* @param k : skala baris memekar 
* @param l : skala kolom memekar 
* @param R : Matriks Bunga hasil, R pass by reference 
*/
template<typename T, size_t row, size_t col, size_t k_row, size_t l_col>
void flower(T (&M)[row][col], int k,int l,T (&R)[k_row][l_col]){

    for(int i=0; i< row; i++){
        for(int j=0; j<col; j++){
            // Memekarkan setiap matrik i,j ke i+k dan j+k
            for(int x=i*k; x<(i+1)*k;x++){
                for(int y=j*l;y<(j+1)*l;y++){
                    R[x][y] = M[i][j];
                }
            }

        }
    }
}

int main(){

    int M[2][2] = {1,2,3,4};
    char A[3][2] = {'a','b','c','d','e','f'};

    // char R[6][6];
    // flower(A,2,3,R);
    auto **R = flower(A,2,3);
    for(int i = 0; i<6;i++){
        for(int j=0;j<9;j++){
            cout<<R[i][j]<<" ";
        }
        cout<<endl;
    }

}

