#include <iostream>

using namespace std;

const int max_no_of_blocks = 201;
long long array[max_no_of_blocks][max_no_of_blocks];

// Function to count the number of structures for given height and remaining blocks
long long count(int height, int left)
{

    // All the blocks have been used
    if (left == 0)
    {
        return 1;
    }

    // Not enough blocks to build a new stair
    if (left < height)
    {
        return 0;
    }

    // Check if already calculated
    if (array[height][left] != -1)
    {
        return array[height][left];
    }

    // Either build a new stair now or try the next height (height + 1)
    return array[height][left] = count(height + 1, left - height) + count(height + 1, left);
}
#include <fstream>
int main()
{

    int n;
    // cin >> n; // Input n
    // cout << count(1, n) - 1 << endl;

    // initialising array
    for (int i = 0; i < max_no_of_blocks; i++)
    {
        for (int j = 0; j < max_no_of_blocks; j++)
        {
            array[i][j] = -1;
        }
    }

    // Test Case 1
    n = 10;
    cout << "Test Case 1: " << n << " -> " << count(1, n) - 1 << endl;

    // Test Case 2
    n = 100;
    cout << "Test Case 2: " << n << " -> " << count(1, n) - 1 << endl;

    // Test Case 3
    n = 150;
    cout << "Test Case 3: " << n << " -> " << count(1, n) - 1 << endl;

    // Test Case 4
    n = 180;
    cout << "Test Case 4: " << n << " -> " << count(1, n) - 1 << endl;

    // Test Case 5
    n = 200;
    cout << "Test Case 5: " << n << " -> " << count(1, n) - 1 << endl;
    return 0;
}