#include <iostream>
#include <fstream>
using namespace std;

int calculateMNPNOfSigleValue(int i)
{
    if (i > 0)
    {
        return 0;
    }
    else
    {
        return i;
    }
}
int calculateMNPN(int start, int end, int *arr) // Calculates the MNPN of array
{
    // cout << "SUB_ARRAY: ";
    // for (int i = start; i <= end; ++i)
    // {
    //     cout << arr[i] << "  ";
    // }
    // cout << endl;

    int max = arr[start];
    for (int i = start + 1; i <= end; ++i)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    bool *newArr = new bool[max + 1];

    for (int i = 0; i <= max; ++i)
    {
        newArr[i] = 0;
    }

    for (int i = start; i <= end; ++i)
    {
        newArr[arr[i]] = 1;
    }

    for (int i = 0; i <= max; ++i)
    {
        if (newArr[i] == 0)
        {
            // cout << "MNPN: " << i << endl;
            return i;
        }
    }
}

/*int *createSubArray(int start, int end, int *arr)
{
    int *newArr = new int[end - start + 1];

    int count = 0;
    for (int i = start; i <= end; ++i)
    {
        newArr[count] = arr[i];
        count++;
    }

    return newArr;
}*/

int **createDP(int size, int *arr)
{
    int max = arr[0];
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int **dpTable = new int *[max + 10];
    for (int i = 0; i < max + 10; i++)
    {
        dpTable[i] = new int[max + 1];
    }

    for (int i = 0; i <= max; ++i)
    {
        dpTable[0][i] = -1;
    }

    for (int i = 0; i < size; ++i) // Set first row of dp to the values that occured
    {
        dpTable[0][arr[i]] = arr[i];
    }

    for (int i = 0; i <= max; ++i)
    {
        dpTable[1][i] = 0;
    }

    for (int i = 0; i < size; ++i) // Set second row to occurence of values
    {
        dpTable[1][arr[i]]++;
        dpTable[dpTable[1][arr[i]] + 1][arr[i]] = i;
    }

    // for (int i = 0; i < max + 10; ++i)
    // {
    //     for (int j = 0; j < max + 1; ++j)
    //         cout << dpTable[i][j] << "  ";
    //     cout << endl;
    //     // cout << "A\n";
    // }
    // cout << endl;

    return dpTable;
}

bool checkMNPNInDP(int **dp, int mnpn, int start, int end)
{
    if (dp[1][mnpn] == 1)
    {
        if (dp[2][mnpn] >= start && dp[2][mnpn] <= end)
        {
            return 1;
        }
    }
    else if (dp[1][mnpn] > 1)
    {
        int *indexes = new int[dp[1][mnpn]];
        for (int i = 0; i < dp[1][mnpn]; ++i)
        {
            indexes[i] = dp[i + 2][mnpn];
        }

        for (int i = 0; i < dp[1][mnpn]; ++i)
        {
            if (indexes[i] >= start && indexes[i] <= end)
            {
                return 1;
            }
        }
    }
    return 0;
}

void calculateSegments(int size, int *arr)
{
    int mnpnOfArray = calculateMNPN(0, size - 1, arr);

    int min = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    if (min > mnpnOfArray && size > 2)
    {
        cout << "Start            End\n";
        cout << "1                1" << endl;
        cout << "2                " << size << endl;
        return;
    }

    int **dp = createDP(size, arr);

    int mnpnArray[size];
    int start = 0;
    mnpnArray[0] = 0;
    for (int i = 1; i < size; ++i)
    {
        mnpnArray[i] = calculateMNPNOfSigleValue(arr[i]);
        // if (dp[1][mnpnArray[i - 1]] == 1)
        // {
        //     if (dp[2][mnpnArray[i - 1]] >= start && dp[2][mnpnArray[i - 1]] <= i)
        //     {
        //         mnpnArray[i]++;
        //     }
        // }
        if (checkMNPNInDP(dp, mnpnArray[i], start, i) == 0 && mnpnArray[i - 1] != mnpnOfArray)
        {
            mnpnArray[i] = mnpnArray[i - 1];
        }
        while (checkMNPNInDP(dp, mnpnArray[i], start, i))
        {
            mnpnArray[i]++;
            if (mnpnArray[i] == mnpnOfArray)
            {
                start = i + 1;
                break;
            }
        }
    }

    int sub_arrays = 0;
    for (int i = 0; i < size; ++i)
    {
        if (mnpnArray[i] == mnpnOfArray)
        {
            sub_arrays++;
        }
    }

    start = 0;
    int passed = 0;
    if (sub_arrays > 1)
        cout << "Start            End\n";
    for (int i = 0; i < size; ++i)
    {
        if (mnpnArray[i] == mnpnOfArray && passed < sub_arrays - 1)
        {
            passed++;
            cout << start + 1 << "                " << i + 1 << endl;
            start = i + 1;
        }
    }
    if (sub_arrays > 1)
        cout << start + 1 << "                " << size << endl;
    else
    {
        cout << -1 << endl;
        cout << "No Segments Exist\n\n";
    }
}

int main()
{
    ifstream myFile("q3_data.txt");

    int num;
    myFile >> num;

    int *arr = new int[num];
    for (int i = 0; i < num; ++i)
    {
        myFile >> arr[i];
    }

    calculateSegments(num, arr);

    // int arr[] = {1, 7};
    // cout << calculateMNPN(0, 1, arr) << endl;

    return 0;
}