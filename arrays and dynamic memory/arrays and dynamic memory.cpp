// arrays and dynamic memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <string>
#include <fstream>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::directory_iterator;
using namespace std;

/// <summary>
/// this function takes an array of ints and prints each element
/// </summary>
/// <param name="array_print"></param> pointer to array
/// <param name="number_elements"></param> number of elements in array
void PrintIntArray(int * array_print, int number_elements) {

    for (int i = 0; i < number_elements; i++) {

        std::cout << std::to_string(array_print[i]);
    }
}


void PrintStringArray(string* array_print, int number_elements) {

    for (int i = 0; i < number_elements; i++) {

        std::cout << array_print[i];
    }
}

//takes an int and retuns an array of that length
//returned array is populated by sequential numbers
int* Return_Array(int array_length) {

    int *my_array;
    my_array = new int[array_length];

    for (int i = 0; i < array_length; i++) {
        my_array[i] = i;
    }

    return my_array;
    //I assume my_array gets deleted after function completes?


}

//reads file row by row and puts row in array and returns array
string* ReturnArrayFromFile(string file_path, int number_rows) {
    string *my_array = new string [number_rows];
    string temp_txt;
    int row_number = 0;

    ifstream MyReadFile(file_path);
    while (getline(MyReadFile, temp_txt)) {
        //issue here
        my_array[row_number] = temp_txt;

        row_number += 1;
    } 
    
    
    
    return my_array;
       
}

//gets number of lines in file
int GetNumLines(string file_path) {

    int number_of_lines = 0;
    std::string line;
    std::ifstream myfile(file_path);

    while (std::getline(myfile, line))
        ++number_of_lines;

    return number_of_lines;
}


/// <summary>
/// takes and string array and returns array with one extra elements
/// </summary>
/// <param name="arr"></param>
/// <param name="number_elements"></param>
/// <returns>array with one extra element</returns>
string* resize(string* arr, int number_elements)
{
    //create new empty array with extra element
    string* resize_arr = new string[number_elements + 1];

    //add elements of existing array to extended array
    for (int i = 0; i < number_elements; i++) {
        resize_arr[i] = arr[i];
    }

    return resize_arr;
}

int main()
{
    //questions how to resize arrays
    // issue with C6835
     
    //create basic array
    int basic_array_length = 5;
    int basic_array[5] = { 1,3,5,8,3 };

    //create dynamic array
    string *dynamic_array;
    string file_path = "arraydata\\arraydata.txt";
    int dynamic_array_length = GetNumLines(file_path);
    dynamic_array = new string[dynamic_array_length];
    dynamic_array = ReturnArrayFromFile(file_path, dynamic_array_length);

    //extend dynamic array by 1 element and add extra element
    dynamic_array = resize(dynamic_array, dynamic_array_length);
    dynamic_array_length++;
    dynamic_array[dynamic_array_length - 1] = " percy";


   
    //print out basic array
    //PrintIntArray(basic_array, (sizeof(basic_array) / sizeof(*basic_array)));

    //print out dynamic array
    PrintStringArray(dynamic_array, dynamic_array_length);


    delete[] dynamic_array;
}
