
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long long MOD = 1e9 + 7;
using Matrix = long long**;

Matrix createMatrix (int k)
{
    Matrix M = new long long*[k];
    for (int i = 0; i < k; i++)
    {
        M[i] = new long long[k];
        for (int j = 0; j <k; j++)
        {
            M[i][j] = 0;
        }
    }
    return M;
}

void deleteMatrix (Matrix M, int k)
{
    for (int i = 0; i < k; i++)
    {
        delete[] M[i];
    }
    delete[] M;
}

void matrixmultiply(Matrix A, Matrix B, Matrix C, int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            __int128 sum = 0;
            for (int p = 0; p < k; p++) {
                sum += (__int128)A[i][p] * B[p][j];
            }
            C[i][j] = (long long)(sum % MOD);
        }
    }
}

void copyMatrix(Matrix source, Matrix dest, int k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            dest[i][j] = source[i][j];
        }
    }
}

Matrix matrixpower(Matrix A, int k, long long int d)
{
    long long int n = d;
    Matrix result = createMatrix(k);
    for (int i = 0; i < k;i++)
    {
        result[i][i] = 1;
    }
    //Making it an identity matrix to make the final multiplications easier
    Matrix base = createMatrix(k); // Base for squaring 
    copyMatrix(A, base, k);

    Matrix temp = createMatrix(k);
    while (n > 0)
    {
        if (n%2 == 1)
        {
            matrixmultiply(result, base, temp, k);
            copyMatrix(temp, result, k);
        }
        matrixmultiply(base, base, temp,k);
        copyMatrix(temp, base, k);

        n = n / 2;
    }
    deleteMatrix(base, k);
    deleteMatrix(temp, k);

    return result;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    long long int n, k, d;
    cin >> n >> k >> d;
    // cout << n << k << d << "\n";

    Matrix A = createMatrix(k);
    for (int i = 0; i < k; i++)
    {
        A[i] = new long long int[k];
    }

    //Initializing base vector N(0), N(1)....N(k)
    long long int base[40] = {0};
    base[0] = n;
    // for (int i = 1; i < k; i++)
    // {
    //     base[i] = 0;
    //     for (int j = 0; j < i; j++)
    //     {
    //         base[i] = (base[i] + ((long long)(i - j) * base[j]) % MOD) % MOD;
    //     }
    //     // cout << base[i] << " ";
    // }
    // cout <<'\n';

    if (d < k)
    {
        long long int sum_d = 0;
        for (int i = 0; i < d; i++)
        {
            sum_d = (sum_d + base[i]) % MOD;
        }
        cout << (sum_d) % MOD;
        deleteMatrix(A, k);

        return 0;
    }
    //Initialization of matrix A
    for (int i = 0; i <k; i++)
    {
        A[0][i] = i + 1;
    }
    for (int i = 1; i < k; i++)
    {
        A[i][i-1] = 1;
    }

    Matrix result_final = matrixpower(A, k, d);
    // for (int i = 0; i <k; i++)
    // {
    //     for (int j = 0; j < k; j++)
    //     {
    //         cout << result_final[i][j] << " ";
    //     }
    //     cout <<"\n";
    // }

    long long int fin[40] = {0};


    for (int i = 0; i < k; i++)
    {
        __int128 sum = 0;
        for (int j = 0; j < k; j++) {
            sum += (__int128)result_final[i][j] * base[j];
        }
        fin[i] = (long long)(sum % MOD);
    }

    long long total = 0;
    for (int i = 0; i < k; i++)
    {
        total = (total + fin[i])% MOD;
    }
    cout << (total) % MOD;
    

    deleteMatrix(A, k);
    deleteMatrix(result_final, k);

    return 0;
}
