#include<vector>
#include<iostream>
#include<chrono>
#include<cstdlib>


void new_algorithm(std::vector<int>& V, size_t &arr_accesses)
{
    size_t num_min_el{};                    // номер минимального элемента
    size_t min_el_buffer = V[0];            // значение минимального элемента
    size_t num_max_el{};                    // номер максимального элемента
    size_t max_el_buffer = V[0];            // значение максимального элемента
    

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
        arr_accesses++;
    }

    if (num_min_el > num_max_el)
        std::swap(num_min_el, num_max_el);

    for (size_t i = num_min_el + 1; i < num_max_el + 1; i++) //сортировка между минимальной и максимальной позициями
    {
        int x = V[i];
        size_t j = i;

        for (; j > num_min_el && V[j - 1] > x; j--)
        {
            V[j] = V[j - 1];
            arr_accesses++;
        }
        V[j] = x;
        arr_accesses++;
    }

    for (size_t i = num_max_el + 1; i < V.size(); i++) //сортировка с начала до максимальной позиции
    {
        int x = V[i];
        size_t j = i;

        for (; j > 0 && V[j - 1] > x; j--)
        {
            V[j] = V[j - 1];
            arr_accesses++;
        }
        V[j] = x;
        arr_accesses++;
    }
}

void InsertionSort(std::vector<int>& values, size_t &arr_accesses)
{
    for (size_t i = 1; i < values.size(); ++i)                  //n
    {
        int x = values[i];                                      //n-1
        size_t j = i;                                           //n-1
        while (j > 0 && values[j - 1] > x)
        {
            values[j] = values[j - 1];
            --j;
            arr_accesses++;
        }
        values[j] = x;
        arr_accesses++;
    }
}


int main()
{
    double all_time_for_first{};
    double all_time{};

    size_t all_arr_accesses_for_first{};
    size_t all_arr_accesses{};
    size_t n = 10000;

    size_t range = 10000;
    size_t iter = 10;

    for (size_t j = 0; j < n; j++)
    {
        std::vector<int> V;
        size_t arr_accesses{};


        for (size_t i = 0; i < iter; i++)
        {
            V.push_back(rand() % range);
        }

        auto start = std::chrono::high_resolution_clock::now();

        //InsertionSort_part(V, arr_accesses);
        InsertionSort(V, arr_accesses);

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        all_time_for_first += duration.count();
        all_arr_accesses_for_first += arr_accesses;
    }
    all_arr_accesses_for_first /= n;
    std::cout << "////////////////////////////////////" << std::endl;
    std::cout << "all_arr_accesses = " << all_arr_accesses_for_first << std::endl;
    std::cout << "all_time = " << all_time_for_first / n << std::endl;

    //srand(1);

    for (size_t j = 0; j < n; j++)
    {
        std::vector<int> V;
        size_t arr_accesses{};

        srand(time(NULL));

        for (size_t i = 0; i < iter; i++)
        {
            V.push_back(rand() % range);
        }

        auto start = std::chrono::high_resolution_clock::now();
        
        //InsertionSort_part(V, arr_accesses);
        InsertionSort(V, arr_accesses);

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        //std::cout << "Duration: " << duration.count() << std::endl << std::endl;
        all_time += duration.count();
        all_arr_accesses += arr_accesses;
        srand(1);
    }
    std::cout << "////////////////////////////////////" << std::endl;
    all_arr_accesses /= n;
    std::cout << "all_arr_accesses = " << all_arr_accesses << std::endl;
    std::cout << "all_time = " << all_time / n << std::endl;
    std::cout << "all_all_arr_accesses = " << (all_arr_accesses + all_arr_accesses_for_first) / 2 << std::endl;
    std::cout << "all_all_time = " << (all_time + all_time_for_first)/ (n * 2) << std::endl;

}