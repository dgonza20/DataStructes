/* 
 * File:   main.cpp
 * Author: David Gonzales
 *
 * Created on June 13, 2019, 3:19 PM
 */

/* Test cases - 1) Random array mixed positive and negative numbers 
 * 2) Sorted array 
 * 3) Reverse sorted array 
 * 4) Custom input 
 */ 
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <algorithm>

using namespace std;

const int NUM_ELEM = 15;
const int MAX_VAL = 100;

int countInv(vector<int> &in_vec, vector<int> &out_vec, int begin, int end);
int mergesortCount(vector<int> &in_vec, vector<int> &out_vec, int begin, int midpoint, int end);

int main(int argc, char **argv)
{
    vector<int> my_vec;
    vector<int>::iterator it;
    srand(time(0)); // Seed for random number generator
    assert(argc == 2);
    switch(atoi(argv[1])) {
        case 1:
                // Input vector of positive and negative random ints
                for (int i = 0; i < NUM_ELEM; i++)
                    my_vec.push_back(rand() % MAX_VAL - (MAX_VAL/2));
                break;
        case 2:
                // Input vector of sorted ints
                for (int i = 0; i < NUM_ELEM; ++i)
                    my_vec.push_back(i);
                break;
        case 3: 
                // Input vector of reverse sorted ints
                for (int i = 0; i < NUM_ELEM; ++i)
                    my_vec.push_back(NUM_ELEM-i);
                break;
        case 4:
                // Custom input
                my_vec.push_back(4);
                my_vec.push_back(5);
                my_vec.push_back(6);
                my_vec.push_back(1);
                my_vec.push_back(2);
                my_vec.push_back(3);
                break;
        default: 
                cout << "Invalid input" << endl;
                return -1;
        
    }
    
    // Print vector
    for (it = my_vec.begin(); it !=  my_vec.end(); ++it)
        cout << *it << " ";
    cout << endl << endl;
    
    vector<int> sort_vec(my_vec);
    cout << "Number of inversions " << countInv(my_vec, sort_vec, 0, my_vec.size()) << endl;
    
    // Sorted array
    for (it = sort_vec.begin(); it != sort_vec.end(); ++it)
        cout << *it << " ";
    cout << endl;
}


int countInv(vector<int> &in_vec, vector<int> &out_vec, int begin, int end) {
    // Your code goes here
    
    // Base case, if the vector is only 1 element long no inversions happen
    if(end - begin < 2){
        return 0;
    }
    else{

        int midpoint = (begin + end) / 2;
    
        int count = 0;
        
        // recursively call the countInv for the first half and the second half of the vector
         countInv(in_vec, out_vec, begin, midpoint);
         countInv(in_vec, out_vec, midpoint, end);
        
        // Merge sort, and count the number of inversions 
        count += mergesortCount(in_vec, out_vec, begin, midpoint, end); 

        return count;
    }
}

/*
 * This function takes in a left and right sorted vector and merges them, while 
 * taking count of any inversion that may be in these two sorted halves of the vector
 * @param in_vec: is the two halves of the sorted vectors
 * @param out_vec: would be the merge of the two sorted vector halves
 * @return count: number of inversion found while doing a merge sort
 */

int mergesortCount(vector<int> &in_vec, vector<int> &out_vec, int begin, int midpoint, int end){
    
    int count = 0;

    
    // Assign starting points for the left and right side of the vector
    int first1 = begin;      // First index of the left half of the vector
    int first2 = midpoint;   // First index of the right half of the vector
    int index = begin;      // Starting index for the merged vector
    
    // While the left side has not reached its end, and while the right side
    // has not reached its end
    while((first1 < midpoint) && (first2 < end)){
        
        // If the value in the left side of the vector at index i is less or equal
        // to the value in the right side of the vector at index j. No inversion
        if(out_vec[first1] <= out_vec[first2]){
            
            // Place that value into the merge vector
            in_vec[index] = out_vec[first1]; 
            
            // Advance the left index
            first1++;    
        }
        else{
            
            // The value in the right side of the vector is greater than the value in the
            // left side of the vector = inversions. Place that value into the merge vector
            in_vec[index] = out_vec[first2];
           
            // Advance the right index
            first2++;
            
            // The number of inversion is the same as the number of elments still 
            // left in the first half of the vector
            count += midpoint -first1;
            
        }
        // Advance the index in the merge vector
        index++;
    }

    
    // Copy any remaining elements from the left side of the vector to the merge vector
    while(first1 < midpoint){
        in_vec[index] = out_vec[first1];
        index++;
        first1++;
    }
    
    // Copy the elements of the in_vec to the out_vec 
    copy(in_vec.begin()+begin, in_vec.begin() + end, out_vec.begin() + begin);


    return count;
}
