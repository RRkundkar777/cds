/* Array algorithms */

#ifndef ARRAY_ALG_H
#define ARRAY_ALG_H

// Array ADT
#include "array.h"

// Linear search algorithm
lint array::linear_search(vector<lint> &vect, lint key)
{
    vector<lint>::iterator it;
    for (it = vect.begin(); it != vect.end(); it++)
    {
        if (*it == key)
            return (it - vect.begin());
    }
    return INT_MIN;
}

// Improved linear search algorithm
lint array::linear_search_improved(vector<lint> &vect, lint key)
{
    vector<lint>::iterator left, right;
    left = vect.begin();
    right = vect.end();

    for (; left <= right;)
    {
        if (*left == key)
            return (left - vect.begin());
        else if (*right == key)
            return (right - vect.begin());
        left++;
        right--;
    }
    return INT_MIN;
}

// Recursive Binary search algorithm
lint array::binary_search_recursive(vector<lint> &vect, lint key, lint left, lint right)
{
    if (right >= left)
    {
        lint mid = left + (right - left) / 2;

        if (vect[mid] == key)
            return mid;

        if (vect[mid] > key)
            return binary_search_recursive(vect, key, left, mid - 1);

        return binary_search_recursive(vect, key, mid + 1, right);
    }
    return INT_MIN;
}

// Iterative binary search algorithm
lint array::binary_search_iterative(vector<lint> &vect, lint key, lint left, lint right)
{
    // While array still has atleast one element
    while (left <= right)
    {
        lint mid = left + (right - left) / 2;

        // Check if x is present at mid
        if (vect[mid] == key)
            return mid;

        // If x greater, ignore left half
        if (vect[mid] < key)
            left = mid + 1;

        // If x is smaller, ignore right half
        else
            right = mid - 1;
    }

    // if we reach here, then element was not present
    return INT_MIN;
}

// Iterative insertion sort algorithm
void array::insertion_sort_iterative(vector<lint> &vect)
{
    // Key and iterators
    lint iter, key, it;
    // Iterate the complete array
    for (iter = 1; iter < vect.size(); iter++)
    {
        key = vect[iter];
        it = iter - 1;

        // find the right space to insert current key
        while (it >= 0 && vect[it] > key)
        {
            vect[it + 1] = vect[it];
            it = it - 1;
        }
        // Insert the key into its rightful position
        vect[it + 1] = key;
    }
}

// Recursive insertion sort
void array::insertion_sort_recursive(vector<lint> &vect, lint size)
{
    // If array contains only one element
    if (size <= 1)
    {
        return;
    }

    // Sort first n-1 elements
    insertion_sort_recursive(vect, size - 1);

    // Insert last element at its correct position in sorted array.
    lint key = vect[size - 1];
    int it = size - 2;

    // find the right space to insert current key
    while (it >= 0 && vect[it] > key)
    {
        vect[it + 1] = vect[it];
        it--;
    }
    vect[it + 1] = key;
}

// Utility for binary_insertion_sort
lint array::binary_search_util(vector<lint> &vect,lint key,lint low,lint high)
{
    if(high <= low)
        return (key > vect[low])? low + 1: low;
    lint mid = (low + high)/2;

    if(key == vect[mid])
        return mid + 1;

    if(key > vect[mid])
        return binary_search_util(vect,key,mid+1,high);

    return binary_search_util(vect,key,low,mid-1);
}

// Binary insertion sort
void array::binary_insertion_sort(vector<lint> &vect)
{
    // Key and iterators
    lint iter, key, it;
    // Iterate the complete array
    for (iter = 1; iter < vect.size(); iter++)
    {
        key = vect[iter];
        it = iter - 1;

        lint location = binary_search_util(vect,key,0,it);

        // find the right space to insert current key
        while (it >= location)
        {
            vect[it + 1] = vect[it];
            it = it - 1;
        }
        // Insert the key into its rightful position
        vect[it + 1] = key;
    }
}

// Advanced bubble sort
void array::bubble_sort_iterative(vector<lint> &vect)
{
    lint size = vect.size();
    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if(vect[j] > vect[j+1])
            {
                swap(vect[j],vect[j+1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}

// Recursive bubble sort
void array::bubble_sort_recursive(vector<lint> &vect, lint size)
{
    if(size == 1)
        return;

    for (int i = 0; i < size - 1; i++)
    {
        if(vect[i] > vect[i+1])
            swap(vect[i],vect[i+1]);
    }

    bubble_sort_recursive(vect,size - 1);
}

// Quick sort partition using Lomuto scheme
lint array::lomuto_qs_partition(vector<lint> &vect, lint low, lint high)
{
    lint pivot = vect[high];
    lint small_index = (low - 1);

    for (int i = low; i < high; i++)
    {
        if(vect[i] < pivot)
        {
            small_index++;
            swap(vect[i],vect[small_index]);
        }
    }
    swap(vect[small_index+1],vect[high]);
    return small_index + 1;
}

// Simple quick sort algorithm
void array::quick_sort(vector<lint> &vect, lint low, lint high)
{
    if(low < high)
    {
        lint part_index = lomuto_qs_partition(vect,low,high);    
        quick_sort(vect,low,part_index - 1);
        quick_sort(vect,part_index + 1,high);
    }
}

// Quick sort partition using Hoare scheme
lint array::hoare_qs_partition(vector<lint> &vect, lint low, lint high)
{
    lint pivot = vect[low];
    lint i = low - 1, j = high + 1;
    while(true)
    {
        do
        {
            i++;
        }while(vect[i] < pivot);

        do
        {
            j--;
        }while(vect[j] > pivot);

        if(i >= j)
            return j;

        swap(vect[i],vect[j]);
    }
}

// Random quicksort partition
lint array::random_partition(vector<lint> vect, lint low, lint high)
{
    // Generate a random number in between low .. high
    srand(time(NULL));
    lint random = low + rand() % (high - low);
 
    swap(vect[random], vect[low]);
 
    return hoare_qs_partition(vect, low, high);
}

// Hoare quick sort algorithm
void array::randomized_quick_sort(vector<lint> &vect, lint low, lint high)
{
    if(low < high)
    {
        lint part_index = random_partition(vect,low,high);    
        quick_sort(vect,low,part_index);
        quick_sort(vect,part_index + 1,high);
    }
}

// Merge utility for mergesort
void array::merge(vector<lint> &vect, lint low, lint mid, lint high)
{
    lint size_1 = mid - low + 1;
    lint size_2 = high - mid;

    lint *left = new lint[size_1];
    lint *right = new lint[size_2];

    for (lint i = 0; i < size_1; i++)
    {
        left[i] = vect[low + i];
    }

    for (lint i = 0; i < size_2; i++)
    {
        right[i] = vect[mid + 1 + i];
    }

    lint left_index = 0, right_index = 0, merge_index = low;

    while(left_index < size_1 && right_index < size_2)
    {
        if(left[left_index] <= right[right_index])
        {
            vect[merge_index] = left[left_index];
            left_index++; 
        }
        else
        {
            vect[merge_index] = right[right_index];
            right_index++;
        }
        merge_index++;
    }

    while(left_index < size_1)
    {
        vect[merge_index] = left[left_index];
        left_index++;
        merge_index++;
    }

    while(right_index < size_2)
    {
        vect[merge_index] = right[right_index];
        right_index++;
        merge_index++;   
    }
}

// Merge sort
void array::merge_sort(vector<lint> &vect, lint low, lint high)
{
    if(low >= high)
        return;

    lint mid = low + (high - low)/2;

    merge_sort(vect,low,mid);
    merge_sort(vect,mid+1,high);
    merge(vect,low,mid,high);
}

// Iterative selection sort
void array::selection_sort_iterative(vector<lint> &vect)
{
    lint size = vect.size();
    lint min_index;
    for (lint i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (lint j = i+1; j < size; i++)
        {
            if(vect[j] < vect[min_index])
                min_index = j;
        }
        swap(vect[i],vect[min_index]);
    }
}

// Utility for recursive selection sort
lint array::ss_min_index(vector<lint> &vect, lint start, lint end)
{
    if(start == end)
        return start;

    lint rem_index = ss_min_index(vect,start + 1,end);

    return (vect[rem_index] > vect[start]) ? start : rem_index;
}

void array::selection_sort_recursive(vector<lint> &vect, lint size, lint index)
{
    if(index == size)
        return;

    lint i = ss_min_index(vect,index,size);

    if(i != index)
        swap(vect[i],vect[index]);

    selection_sort_recursive(vect,size,index + 1);
}

// Count sort algorithm
void array::count_sort(vector<lint> &vect)
{
    lint max = *max_element(vect.begin(),vect.end());
    lint min = *min_element(vect.begin(),vect.end());
    lint range = max - min + 1;

    vector<lint> count(range);
    vector<lint> output(vect.size());

    for (int i = 0; i < vect.size(); i++)
    {
        count[vect[i] - min]++;    
    }

    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i-1];
    }

    for (int i = vect.size() - 1; i >= 0; i--)
    {
        output[count[vect[i] - min] - 1] = vect[i];
        count[vect[i] - min]--;
    }

    for (int i = 0; i < vect.size(); i++)
    {
        vect[i] = output[i];
    }
}

// Utility to get max element for radix sort
lint array::rs_get_max(vector<lint> &vect)
{
    lint max = vect[0];
    for (int i = 0; i < vect.size(); i++)
    {
        if(vect[i] > max)
            max = vect[i];
    }
    return max;
}

// Utility count sort for radix sort
void array::rs_count_sort(vector<lint> &vect, lint exp)
{
    lint size = vect.size();
    vector<lint> output(size);
    vector<lint> count(10);
    lint i;

    for (i = 0; i < size; i++)
        count[(vect[i] / exp) % 10]++;
  
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
  
    for (i = size - 1; i >= 0; i--) {
        output[count[(vect[i] / exp) % 10] - 1] = vect[i];
        count[(vect[i] / exp) % 10]--;
    }
  
    for (i = 0; i < size; i++)
        vect[i] = output[i];
}

// Radix sort
void array::radix_sort(vector<lint> &vect)
{
    lint max_val = rs_get_max(vect);

    for (int exp = 1; max_val/exp > 0; exp *= 10)
    {
        rs_count_sort(vect,exp);
    }
}

// Bucket sort for floating nums < 1
void array::bucket_sort(vector<float> &vect, lint buck)
{
    vector<float> buckets[buck];

    for (int i = 0; i < buck; i++)
    {
        lint buck_index = buck * vect[i];
        buckets[buck_index].push_back(vect[i]);
    }

    for (int i = 0; i < buck; i++)
    {
        sort(buckets[i].begin(),buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < buck; ++i)
    {
        for(int j = 0; j < buckets[i].size() ; j++)
        {
            vect[index++] = buckets[i][j];
        }
    }
}

#endif