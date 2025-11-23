#include <iostream>

using namespace std;

int main(void)
{
    int n, m; 
    cin >> n >> m;
    int flag = 1;
    int matrix[n][m];
    int prefix[n][m];
    int sumarray[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] > 0){flag = 0;}
            prefix[i][j] = 0;
        }
        sumarray[i] = 0;
    }

    //To handle the negative case
    if (flag)
    {
        cout << "NO";
        return 0;
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0)
            {
                prefix[i][j] = matrix[i][j];
            }
            else
            {
                prefix[i][j] = prefix[i][j-1] + matrix[i][j];
            }
            // cout << prefix[i][j] << " ";
        }
        // cout << " \n";
    }

    long long int ans = 0;
    long long int submatrix_sum_max = -10000000;
    long long int sum = 0;
    int r1, r2, c1, c2;
    for (int i = 0; i < m; i++)
    {

        for (int j = i; j < m; j++)
        {
            submatrix_sum_max = -10000000;
            long long int row_sum = 0;
            int temp_r1 = 0, temp_r2 = 0;
            int startRow = 0;
            //For finding the maximum submatrix sum between column i and j, iterating over k
            for (int k = 0; k < n; k++)
            {
                if (i == 0) row_sum = prefix[k][j];
                else row_sum = prefix[k][j] - prefix[k][i-1];
                if (k == 0) 
                {
                    sumarray[k] = row_sum;
                    submatrix_sum_max = sumarray[k];
                    temp_r1 = startRow;
                    temp_r2 = k;
                    continue;
                }
                if (sumarray[k-1] > 0)
                {
                    sumarray[k] = sumarray[k-1] + row_sum;
                }
                else
                {
                    sumarray[k] = row_sum;
                    startRow = k;
                }
                if (sumarray[k] > submatrix_sum_max)
                {
                    submatrix_sum_max = sumarray[k];
                    temp_r1 = startRow;
                    temp_r2 = k;
                }
                // cout <<"("<< submatrix_sum_max << " " << k << ") ";
            }
            // cout << "\n";
            if (submatrix_sum_max > sum)
            {
                sum = submatrix_sum_max;
                c1 = i;
                c2 = j;
                r1 = temp_r1;
                r2 = temp_r2;
            }
            // cout << sum << " ";

        }
    }
    cout <<"YES" << "\n" << sum << "\n";
    cout << r1 + 1 << " " << c1 + 1 << " ";
    cout << r2 + 1 << " " << c2 + 1 << "\n";
    return 0;
}