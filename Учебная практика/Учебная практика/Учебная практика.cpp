#include<iostream>
#include<algorithm>
#include<vector>

unsigned int lenLongestFibSubseq(const std::vector<int>&arr)
{
    const int n = (int)arr.size();
    
    uint8_t * *len = new uint8_t * [n]; // создаем матрицу смежности графа, где len[позиция первого слагаемого][позиция второго] = длина последовательности                                       
    
    for (size_t i = 0; i < n; i++)
    {
        len[i] = new uint8_t[n];
        for (size_t j = i; j < n; j++)
        {
           len[i][j] = 2;
        }
   	}
   
    int max{};
    
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
     	        max = std::max(max, (int)len[firstPos][secondPos]);
     	    }
    	}
    }
    
     for (size_t i = 0; i < n; i++)
         delete[] len[i];
   	 delete[] len;
   
    return max;
}

int main()
{
    setlocale(LC_ALL, "ru");

    std::vector<int> V;
    
    std::cout << "Исходный массив: arr = [";
    for (size_t i = 1; i < 9; i++)
    {
        V.push_back(i);        
        if (i < 8)
            std::cout << " " << i << ", ";
        else
            std::cout << " " << i << ']';
    }
    std::cout << std::endl;

    std::cout << "Самая длинная последовательность, подобная Фибоначчи: " << lenLongestFibSubseq(V);

    return 0;
}