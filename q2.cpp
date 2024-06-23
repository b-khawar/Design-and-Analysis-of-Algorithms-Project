// #include <iostream>
// using namespace std;

// int sumOfArray(int *arr, int n)
// {
//     int sum = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         sum += arr[i];
//     }
//     return sum;
// }

// int getPrevBomb(bool *bomb_arr, int n, int index)
// {
//     int val = 0;
//     for (int i = 0; i < index; ++i)
//     {
//         if (bomb_arr[i] == 1)
//         {
//             val = i;
//         }
//     }
//     return val;
// }

// int getNextBomb(bool *bomb_arr, int n, int index)
// {
//     int val = n;
//     for (int i = index + 1; i < n; ++i)
//     {
//         if (bomb_arr[i] == 1)
//         {
//             val = i;
//             break;
//         }
//     }
//     return val;
// }

// int calculateStrategicValue(int depotValues[], int n, int attacks)
// {

//     bool bombed_indexes[n] = {0};
//     int total_strategic_value = 0;

//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = i + 1; j < n; ++j)
//         {
//             int strategic_value = depotValues[i] * depotValues[j];
//             total_strategic_value += strategic_value;
//         }
//     }

//     cout << "Total SV: " << total_strategic_value << endl;

//     if (attacks == 0)
//     {
//         return total_strategic_value;
//     }

//     int strategic_values[n];

//     // Calculate strategic values for each depot
//     for (int i = 0; i < n; ++i)
//     {
//         strategic_values[i] = 0;
//         for (int j = i + 1; j < n; ++j)
//         {
//             strategic_values[i] += depotValues[i] * depotValues[j];
//         }
//     }

//     // Output the strategic values
//     cout << "Depot Values: ";
//     for (int i = 0; i < n; ++i)
//     {
//         cout << depotValues[i] << " ";
//     }
//     cout << endl;
//     cout << "Strategic Values: ";
//     for (int i = 0; i < n; ++i)
//     {
//         cout << strategic_values[i] << " ";
//     }
//     cout << endl
//          << endl;

//     int temp_arr[n];

//     int min_arr[n];
//     int min = total_strategic_value;
//     int min_arr_bomb_index = -1;

//     cout << "ARRAYS:\n";
//     for (int h = 0; h < attacks; ++h)
//     {
//         for (int i = n - 1; i > 0; --i)
//         {

//             for (int j = 0; j < n; ++j)
//             {
//                 temp_arr[j] = strategic_values[j];
//             }

//             for (int j = i - 1; j >= getPrevBomb(bombed_indexes, n, j); --j)
//             {
//                 for (int k = i; k < getNextBomb(bombed_indexes, n, j); ++k)
//                 {
//                     temp_arr[j] -= (depotValues[j] * depotValues[k]);
//                 }
//             }
//             if (sumOfArray(temp_arr, n) < min)
//             {
//                 min_arr_bomb_index = i;
//                 min = sumOfArray(temp_arr, n);
//                 for (int j = 0; j < n; ++j)
//                 {
//                     min_arr[j] = temp_arr[j];
//                 }
//             }
//             for (int j = 0; j < n; ++j)
//             {
//                 cout << temp_arr[j] << "  ";
//             }
//             cout << "         " << sumOfArray(temp_arr, n);
//             cout << endl;
//         }
//         cout << endl;
//         bombed_indexes[min_arr_bomb_index] = 1;
//         for (int j = 0; j < n; ++j)
//         {
//             cout << min_arr[j] << "  ";
//         }
//         cout << endl;
//         cout << "MIN = " << min << endl;
//         for (int j = 0; j < n; ++j)
//         {
//             cout << bombed_indexes[j] << "  ";
//         }
//         cout << endl
//              << endl;

//         for (int j = 0; j < n; ++j)
//         {
//             strategic_values[j] = min_arr[j];
//         }

//         cout << "-----------------------\n";
//     }
//     return total_strategic_value;
// }

// int main()
// {
//     int arr[] = {3, 4, 5, 1, 2, 5, 3};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     calculateStrategicValue(arr, n, 3);
// }

#include <iostream>
#include <fstream>
using namespace std;

int sumOfArray(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

int getPrevBomb(bool *bomb_arr, int n, int index)
{
    int val = 0;
    for (int i = 0; i < index; ++i)
    {
        if (bomb_arr[i] == 1)
        {
            val = i;
        }
    }
    return val;
}

int getNextBomb(bool *bomb_arr, int n, int index)
{
    int val = n;
    for (int i = index + 1; i < n; ++i)
    {
        if (bomb_arr[i] == 1)
        {
            val = i;
            break;
        }
    }
    return val;
}

int calculateStrategicValue(int depotValues[], int n, int attacks, int mincost, bool bombed_indexes[], int strategic_values[])
{
    if (attacks == 0)
        return mincost;

    int temp_arr[n];

    int min_arr[n];
    int min = mincost;
    int min_arr_bomb_index = -1;

    // cout << "ARRAYS:\n";
    // for (int h = 0; h < attacks; ++h)
    //{
    for (int i = n - 1; i > 0; --i)
    {

        for (int j = 0; j < n; ++j)
        {
            temp_arr[j] = strategic_values[j];
        }

        for (int j = i - 1; j >= getPrevBomb(bombed_indexes, n, j); --j)
        {
            for (int k = i; k < getNextBomb(bombed_indexes, n, j); ++k)
            {
                temp_arr[j] -= (depotValues[j] * depotValues[k]);
            }
        }
        if (sumOfArray(temp_arr, n) < min)
        {
            min_arr_bomb_index = i;
            min = sumOfArray(temp_arr, n);
            for (int j = 0; j < n; ++j)
            {
                min_arr[j] = temp_arr[j];
            }
        }
        // for (int j = 0; j < n; ++j)
        // {
        //     cout << temp_arr[j] << "  ";
        // }
        // cout << "         " << sumOfArray(temp_arr, n);
        // cout << endl;
    }
    // cout << endl;
    bombed_indexes[min_arr_bomb_index] = 1;
    // for (int j = 0; j < n; ++j)
    // {
    //     cout << min_arr[j] << "  ";
    // }
    // cout << endl;
    // cout << "MIN = " << min << endl;
    // for (int j = 0; j < n; ++j)
    // {
    //     cout << bombed_indexes[j] << "  ";
    // }
    // cout << endl
    //      << endl;

    for (int j = 0; j < n; ++j)
    {
        strategic_values[j] = min_arr[j];
    }
    // cout << "-----------------------\n";

    return calculateStrategicValue(depotValues, n, attacks - 1, min, bombed_indexes, strategic_values);

    //}
    // return total_strategic_value;
}

int solve(int *depotValues, int n, int m)
{
    cout << "ARRAY: ";
    for (int i = 0; i < n; ++i)
    {
        cout << depotValues[i] << "  ";
    }
    cout << endl;

    bool bombed_indexes[n] = {0};
    int total_strategic_value = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int strategic_value = depotValues[i] * depotValues[j];
            total_strategic_value += strategic_value;
        }
    }

    // cout << "Total SV: " << total_strategic_value << endl;

    if (m == 0)
    {
        return total_strategic_value;
    }

    int strategic_values[n];

    // Calculate strategic values for each depot
    for (int i = 0; i < n; ++i)
    {
        strategic_values[i] = 0;
        for (int j = i + 1; j < n; ++j)
        {
            strategic_values[i] += depotValues[i] * depotValues[j];
        }
    }

    // Output the strategic values
    // cout << "Depot Values: ";
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << depotValues[i] << " ";
    // }
    // cout << endl;
    // cout << "Strategic Values: ";
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << strategic_values[i] << " ";
    // }
    // cout << endl
    //      << endl;

    return calculateStrategicValue(depotValues, n, m, total_strategic_value, bombed_indexes, strategic_values);
}

int main()
{
    ifstream myFile("q2_data.txt");

    int n, m;
    myFile >> n >> m;

    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        myFile >> arr[i];
    }

    int min = solve(arr, n, m);
    cout << "Min: " << min << endl;

    return 0;
}
