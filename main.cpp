#include <iostream>
#include <iomanip>
#include <fstream>
#include "matrix.h"
using namespace std;

matrix readNewMatrix(char* filename)
{
        int dim_m = -1;
        int dim_n = -1;

        ifstream matrixInput(filename);

        if(matrixInput.is_open())
        {
            matrixInput >> dim_m;
            matrixInput >> dim_n;

            matrix myNewMatrix(dim_m,dim_n);

            int* tmpInput = new int[dim_m*dim_n];
            for(int i=0;i<(dim_m*dim_n);i++)
            {
                matrixInput >> tmpInput[i];
            }
            myNewMatrix.set(tmpInput);
            delete[] tmpInput;

            return myNewMatrix;
        }
        else
        {
            cout << "Inputstream konnte nicht geöffnet werden" << endl;
            matrix error(0,0);
            return error;
        }

}


int main(int argc, char *argv[])
{
    if ( argc == 3 )
    {
        cout << "Die Dateien " << argv[1] << " und " << argv[2] << "werden eingelesen" << endl;

        char* filename1 = argv[1];
        char* filename2 = argv[2];

        matrix myMatrix1 = readNewMatrix(filename1);
        matrix myMatrix2 = readNewMatrix(filename2);

        myMatrix1.out;
        myMatrix2.out;



    }
    matrix test(3,2);
    test.out();
}
