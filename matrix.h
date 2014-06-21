#ifndef MATRIX_H
#define MATRIX_H
using namespace std;

class matrix
{
    private:
        int** pmatrix;
        int m;
        int n;

    public:
        matrix(int,int);
        ~matrix();

        void set(int* a);
        void out();

};

matrix::matrix(int m,int n)
{
    if(m>0 && n>0)
    {
        this->m=m;
        this->n=n;
        this->pmatrix = new int* [m];

        for (int i=0;i<m;i++)
        {
            this->pmatrix[i]=new int[n];
        }

        for(int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                this->pmatrix[i][j]=0;
            }
        }
    }
    else
    {
        this->m=0;
        this->n=0;
        this->pmatrix=0;
    }
}
matrix::~matrix()
 {
    for(int i=0;i < this->m;i++) delete[] pmatrix[i];
    delete[] pmatrix;
 }

void matrix::set(int* insertArray)
{
    if(insertArray)
    {
        int y = 0;
        for(int i=0;i < this->m;i++)
        {
            for(int j=0;j < this->n;j++)
            {
                this->pmatrix[i][j] = insertArray[y];
                y++;
            }
        }

    }
    else cout << "Es wurde nichts in die Matrix eingetragen!" << endl;
}

void matrix::out()
 {
    for(int i=0;i < this->m;i++)
    {
        for(int j=0;j < this->n;j++)
        {
            cout << left << setw(6) << this->pmatrix[i][j];
        }
        cout << endl;
    }
 }
#endif // MATRIX_H
