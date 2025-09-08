#include <iostream>
#include <limits>
#include <string>

int findMax(int* int_array, int arr_size) {
    int max_element = INT_MIN;

    for (unsigned int i = 0; i < arr_size; ++i) {
        if (int_array[i] > max_element) {
            max_element = int_array[i];
        }
    }

    return max_element;
}

float findMax(float* float_array, int arr_size) {
    float max_element = std::numeric_limits<float>::min();

    for (unsigned int i = 0; i < arr_size; ++i) {
        if (float_array[i] > max_element) {
            max_element = float_array[i];
        }
    }

    return max_element;
}

std::string findMax(std::string* string_array, int arr_size) {
    std::string max_string = std::string("");

    for (unsigned int i = 0; i < arr_size; ++i) {
        if (string_array[i].size() > max_string.size()) {
            max_string = string_array[i];
        }
    }
    return max_string;
}