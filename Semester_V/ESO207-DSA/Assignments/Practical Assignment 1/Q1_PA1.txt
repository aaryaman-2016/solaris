#include <iostream>

using namespace std;


struct Pair
{
    long long int g;
    long long int count;
};

long long get_gcd(long long a, long long b)
{
    if(b == 0) return a;
    else{return get_gcd(b, a % b);}
}


int main(void)
{
    int t; 
    cin >> t;
    for (int x = 0; x < t; x++)
    {    
        long long int n;
        long long int k;
        cin >> n >> k;
        long long arr[n];
        // cout << (get_gcd(18, 15));

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Pair prev[n], curr[n];
        long long int prevsize, currsize;
        prevsize = 0;

        long long int ans = 0; 

        //Loop to maintain the gcds
        for (int i = 0; i < n; i++)
        {
            currsize = 0; 

            curr[currsize].g = arr[i];
            curr[currsize].count = 1;
            currsize++;

            for(int j = 0; j < prevsize; j++)
            {
                long long int newg = get_gcd(prev[j].g, arr[i]);

                if ((currsize > 0) && (newg == curr[currsize-1].g))
                {
                    curr[currsize - 1].count += prev[j].count;
                }

                else
                {
                    curr[currsize].g = newg;
                    curr[currsize].count = prev[j].count;
                    currsize++;
                }
            }

            //Count additions to our answer here by checking for g = k in our current list
            for (int j = 0; j < currsize; j++)
            {
                if(curr[j].g == k)
                {
                    ans += curr[j].count;
                }
            }

            //make the current list as the previous list for the next iteration
            for (int j = 0; j < currsize; j++)
            {
                prev[j] = curr[j];
            }
            prevsize = currsize;
        }

        cout << ans <<"\n";
    }
    return 0;
}