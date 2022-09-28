﻿#include <iostream>
#include <fstream>


int* create_array (int arr_size)
{
    return new int [arr_size]();
}

int main()
{
    setlocale(LC_ALL, "Russian");


    int arr_size = 0;
    int arr_size_second = 0;
    int* file_in_array = 0;
    int* file_in_array_second = 0;

    

    std::ifstream fin ("in.txt");
    std::ofstream fout("out.txt");

    fin >> arr_size;
    file_in_array = create_array(arr_size);


    if (fin.is_open())
    {

        for (int i = 0; i < arr_size; ++i)
        {
            fin >> file_in_array[i];
        }
    }
    else
        std::cout << "\nНе удалось открыть файл \"in.txt\"!";


    fin >> arr_size_second;
    file_in_array_second = create_array(arr_size_second);

    if (fin.is_open())
    {
        for (int i = 0; i < arr_size_second; ++i)
        {
            fin >> file_in_array_second[i];
        }
    }
    else
        std::cout << "\nНе удалось открыть файл \"in.txt\"!";

    

    if (fout.is_open())
    {
        fout << arr_size_second << std::endl;
        fout << file_in_array_second[arr_size_second - 1] << " ";

        for (int i = 0; i < arr_size_second - 1; ++i)
        {
            fout << file_in_array_second[i] << " ";
        }
        fout << std::endl;
    }
    else
        std::cout << "\nНе удалось открыть файл \"out.txt\" ";

    if (fout.is_open())
    {
        fout << arr_size << std::endl;
        //fout << file_in_array[arr_size - 1] << " ";

        for (int i = 1; i < arr_size ; ++i)
        {
            fout << file_in_array[i] << " ";
        }
        fout << file_in_array[0];
    }
    else
        std::cout << "\nНе удалось открыть файл \"out.txt\" ";
    


    fin.close();
    fout.close();

    delete[] file_in_array;
    file_in_array = nullptr;
    delete[] file_in_array_second;
    file_in_array_second = nullptr;

    return 0;
}