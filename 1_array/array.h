/* ADT of array data structure */

#ifndef ARRAY_H
#define ARRAY_H

// Global configurations
#include "../aes-config.h"

// System Libraries
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

// Class declaration
class array
{
public:
    lint linear_search(vector<lint> &vect, lint key);
    lint linear_search_improved(vector<lint> &vect, lint key);
    lint binary_search_recursive(vector<lint> &vect, lint key, lint left, lint right);
    lint binary_search_iterative(vector<lint> &vect, lint key, lint left, lint right);
    void insertion_sort_iterative(vector<lint> &vect);
    void insertion_sort_recursive(vector<lint> &vect, lint size);
    void display_array(vector<lint> &vect);
    lint binary_search_util(vector<lint> &vect,lint key,lint low,lint high);
    void binary_insertion_sort(vector<lint> &vect);
    void bubble_sort_iterative(vector<lint> &vect);
    void bubble_sort_recursive(vector<lint> &vect, lint size);
    lint lomuto_qs_partition(vector<lint> &vect, lint low, lint high);
    void quick_sort(vector<lint> &vect, lint low, lint high);
    lint hoare_qs_partition(vector<lint> &vect, lint low, lint high);
    lint random_partition(vector<lint> vect, lint low, lint high);
    void randomized_quick_sort(vector<lint> &vect, lint low, lint high);
    void merge(vector<lint> &vect, lint low, lint mid, lint high);
    void merge_sort(vector<lint> &vect, lint low, lint high);
    void selection_sort_iterative(vector<lint> &vect);
    void bucket_sort(vector<float> &vect, lint buck);
    lint ss_min_index(vector<lint> &vect, lint start, lint end);
    void selection_sort_recursive(vector<lint> &vect, lint size, lint index = 0);
    void count_sort(vector<lint> &vect);
    lint rs_get_max(vector<lint> &vect);
    void rs_count_sort(vector<lint> &vect, lint exp);
    void radix_sort(vector<lint> &vect);
};

#endif