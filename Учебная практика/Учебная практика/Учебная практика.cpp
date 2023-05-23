#include<iostream>
#include<algorithm>
#include<vector>

unsigned int lenLongestFibSubseq(const std::vector<int>& arr)
{

    const int n = (int)arr.size();

    uint8_t** len = new uint8_t * [n]; // создаем матрицу смежности графа, где len[

    for (size_t i = 0; i < n; i++)
    {
        len[i] = new uint8_t[n];
        for (size_t j = i; j < n; j++)
        {
            len[i][j] = 2;
        }
    }

    // [less number index][greater number index] -> sequence length
    int ans{};

    for (int secondPos = n - 2; secondPos >= 1; secondPos--)
    {
        int thirdPos = secondPos + 1;
        for (int firstPos = 0; firstPos < secondPos; firstPos++)
        {
            while (thirdPos < n && arr[firstPos] + arr[secondPos] > arr[thirdPos])
            {
                thirdPos++;
            }
            if (thirdPos < n && arr[firstPos] + arr[secondPos] == arr[thirdPos])
            {
                len[firstPos][secondPos] = len[secondPos][thirdPos] + 1;
                ans = std::max(ans, (int)len[firstPos][secondPos]);
            }
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        delete[] len[i];
    }
    delete[] len;

    return ans;
}

int main()
{
    setlocale(LC_ALL, "ru");


    std::vector<int> V = { 12,13,15,18,26,31,34,35,37,39,41,42,45,47,49,50,52,56,57,60,61,63,69,72,78,81,83,91,97,102,107,110,113,117,126,128,140,143,153,162,171,176,179,195,209,223,234,250,264,281,286,289,312,321,337,363,377,403,426,452,465,507,516,546,586,653,690,733,751,754,819,837,883,949,1056,1116,1185,1216,1219,1326,1353,1429,1535,1709,1806,1967,1973,2145,2190,2312,2922,3183,3192,3471,3543,3741,4728,5150,5165,5616,5733,6053,7650,8333,8357,9087,9276,13483,13522,14703,15009,21816,21879,23790,24285,35299,35401,38493,39294,63579 };
    //for (size_t i = 1; i < 9; i++)
    //{
    //    V.push_back(i);
    //    std::cout << "v[" << i << "] : " << i << std::endl;
    //}
    for (size_t i = 0; i < 10000; i++)
    {
        std::cout << "Самая длинная последовательность, подобная Фибоначчи: " << lenLongestFibSubseq(V);
    }

    return 0;
}