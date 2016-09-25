//
//  main.cpp
//  Front-N_C++
//
//  Created by chenyufeng on 9/25/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * 找出数组中第N大的数
 */

int Partition(vector<int> &vec, int left, int right);
void FindN(vector<int> &vec, int left, int right ,int N);

int main(int argc, const char * argv[])
{
    int arr[] = {20,8,9,0,1,6};
    int N = 6;
    vector<int> vectorArr(arr,arr + sizeof(arr)/sizeof(int));

    FindN(vectorArr, 0, 5, N);

    return 0;
}

void FindN(vector<int> &vec, int left, int right ,int N)
{
    int index = Partition(vec, left, right);
    if (left == right)
    {
        cout << vec[left] << endl;
        return;
    }

    // 确定下标为index的数字是第几大,注意下标index与N大之间的关系
    int th = right - index + 1;

    if (th == N)
    {
        // 找到该值
        cout << vec[index] << endl;
        return;
    }
    else if (th < N)
    {
        // 左边找
        FindN(vec, left, index - 1, N - th);
    }
    else if (th > N)
    {
        // 右边找
        FindN(vec, index + 1, right, N);
    }
}

int Partition(vector<int> &vec, int left, int right)
{
    int i = left, j = right, x = vec[i];
    while (i < j)
    {
        while (i < j && x <= vec[j])
        {
            j--;
        }
        if (i < j)
        {
            vec[i++] = vec[j];
        }

        while (i < j && x > vec[i])
        {
            i++;
        }
        if (i < j)
        {
            vec[j--] = vec[i];
        }
    }

    vec[i] = x;

    return i;
}














