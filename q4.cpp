#include <iostream>
#include <fstream>
using namespace std;

int maxOfArray(int *arr, int s) // Returns maximum value in an array (...O(s)...)
{
    int max = arr[0];
    for (int i = 1; i < s; ++i)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int caclulateMaxPower(int **arr, int m, int n)
{
    if (m == 1)
    {
        return maxOfArray(arr[0], n); //(...O(n)...)
    }
    else if (m >= 2)
    {
        int dp[m][n] = {0};

        // Initializing dp table
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dp[i][j] = arr[i][j];
            }
        }

        int *maxArray = new int[n]; // Array to store maximum values in each column

        // Populating the maxArray
        for (int j = 0; j < n; ++j)
        {
            int max = arr[0][j];
            for (int i = 1; i < m; ++i)
            {
                if (arr[i][j] > max)
                    max = arr[i][j];
            }
            maxArray[j] = max;
        }

        int *count = new int[n]; // Count of occurances of maximum element in a single column
        for (int i = 0; i < n; ++i)
            count[i] = 0;

        // Populating the count array
        for (int j = 0; j < n; ++j)
        {
            for (int i = 0; i < m; ++i)
            {
                if (arr[i][j] == maxArray[j])
                    count[j]++;
            }
        }

        int *secondMaxArray = new int[n]; // Array to store maximum values in each column

        // Populating the secondMaxArray
        for (int j = 0; j < n; ++j)
        {
            int secondMaxValue = -100000;
            for (int i = 0; i < m; ++i)
            {
                if (count[j] > 1)
                {
                    secondMaxValue = maxArray[j];
                    break;
                }
                // cout << arr[i][j] << "  " << maxArray[j] << endl;
                if (arr[i][j] != maxArray[j] && arr[i][j] > secondMaxValue)
                    secondMaxValue = arr[i][j];
            }
            secondMaxArray[j] = secondMaxValue;
        }

        for (int j = n - 2; j >= 0; --j)
        {
            for (int i = 0; i < m; ++i)
            {
                if (dp[i][j + 1] == maxArray[j + 1])
                {
                    if (dp[i][j] + secondMaxArray[j + 1] > maxArray[j + 1])
                    {
                        dp[i][j] = dp[i][j] + secondMaxArray[j + 1];
                    }
                    else
                    {
                        dp[i][j] = maxArray[j + 1];
                    }
                }
                else
                {
                    if (dp[i][j] + maxArray[j + 1] > dp[i][j + 1])
                    {
                        dp[i][j] = dp[i][j] + maxArray[j + 1];
                    }
                    else
                    {
                        dp[i][j] = dp[i][j + 1];
                    }
                }

                // Update max & secondmax
                if (dp[i][j] >= maxArray[j])
                {
                    if (maxArray[j] > secondMaxArray[j])
                    {
                        secondMaxArray[j] = maxArray[j];
                    }
                    maxArray[j] = dp[i][j];
                }
                else if (dp[i][j] >= secondMaxArray[j])
                {
                    secondMaxArray[j] = dp[i][j];
                }
            }
        }

        int max = dp[0][0];
        for (int i = 1; i < m; ++i)
        {
            if (dp[i][0] > max)
                max = dp[i][0];
        }

        return max;
    }
    return -1;
}

int main()
{
    int m, n;
    ifstream myFile("q4_data.txt");
    myFile >> m >> n;

    int **arr = new int *[m];
    for (int i = 0; i < m; ++i)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; ++j)
        {
            myFile >> arr[i][j];
        }
    }

    cout << "MAX POWER: " << caclulateMaxPower(arr, m, n) << endl;
}