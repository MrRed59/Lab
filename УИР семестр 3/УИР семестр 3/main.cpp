#include<vector>
#include<iostream>
#include<chrono>
#include<cstdlib>


void InsertionSort_part(std::vector<int>& V)
{
    size_t num_min_el{};
    size_t min_el_buffer = V[0];
    size_t num_max_el{};
    size_t max_el_buffer = V[0];

    for (size_t i = 1; i < V.size(); i++) // поиск максимального и минимального значений, а так же их номер
    {
        if (V[i] < min_el_buffer)
        {
            min_el_buffer = V[i];
            num_min_el = i;
        }
        else if (V[i] > max_el_buffer)
        {
            max_el_buffer = V[i];
            num_max_el = i;
        }
    }

    if (num_min_el > num_max_el)
        std::swap(num_min_el, num_max_el);



    for (size_t i = num_min_el + 1; i < num_max_el + 1; i++) //сортировка между минимальным и максимальным позициями
    {
        int x = V[i];
        size_t j = i;

        for (; j > num_min_el && V[j - 1] > x; j--)
        {
            V[j] = V[j - 1];
        }
        V[j] = x;
    }    

    if (num_min_el)
    {
        size_t i = num_min_el + 1;

        do
        {
            i--;
            int x = V[i];
            size_t j = i;

            for (; j < num_max_el && V[j + 1] < x; j++)
            {
                V[j] = V[j + 1];
            }
            V[j] = x;            
        } while (i > 0);
    }    


    for (size_t i = num_max_el; i < V.size(); i++) //сортировка с начала до максимальной позиции
    {
        int x = V[i];
        size_t j = i;

        for (; j > 0 && V[j - 1] > x; j--)
        {
            V[j] = V[j - 1];
        }
        V[j] = x;
    }
}

void InsertionSort(std::vector<int>& values)
{
    for (size_t i = 1; i < values.size(); ++i)
    {
        int x = values[i];
        size_t j = i;
        while (j > 0 && values[j - 1] > x)
        {
            values[j] = values[j - 1];
            --j;
        }
        values[j] = x;
    }
}


int main()
{
    std::vector<int> V = { 1, 7, 8, 0, 1, 4, 4, 4, 4, 7, 8, 2, 7, 1, 1 ,9, 3, 7, 5, 8};

    //srand(time(NULL));

    /*for (size_t i = 0; i < 20; i++)
    {
        V.push_back(rand() % 10);
    }*/

    for (size_t i = 0; i < V.size(); i++)
        std::cout << "V" << i << " = " << V[i] << std::endl;

    std::cout << std::endl << std::endl;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    InsertionSort_part(V);

    //InsertionSort(V);

    auto end = std::chrono::high_resolution_clock::now();
    
    for (size_t i = 0; i < V.size(); i++)
        std::cout << "V" << i << " = " << V[i] << std::endl;

    std::chrono::duration<double> duration = end - start;
    std::cout << "Duration: " << duration.count() << std::endl << std::endl;
}