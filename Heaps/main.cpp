/* 
 * File:   main.cpp
 * Author: David Gonzales
 *
 * Created on June 20, 2019, 8:52 PM
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_VAL = 100;
const int NUM_ELEM = 15;

int find_median(priority_queue<int, vector<int>, greater<int>>& h_high, priority_queue<int>& h_low, int num);
template<typename T> void print_queue(T& q);
void addNumber(priority_queue<int, vector<int>, greater<int>>& h_high, priority_queue<int>& h_low, int num);

int main() {
    int current_median;
    priority_queue<int> lo; // Bottom half of numbers - max-heap (default) 
    priority_queue<int, vector<int>, greater<int> > hi; // Top half of numbers - min-heap 
    srand(time(0)); // Seed for random number generator
    for (int i = 0; i < NUM_ELEM; i++) {
        int n = rand() % MAX_VAL;
        current_median = find_median(hi, lo, n);
        cout <<  "Inserted " << n << " Median " << current_median << endl << endl;
    }
    
    return 0;
}

template<typename T>
void print_queue(T& q) {
    T q_copy(q);
    while(!q_copy.empty()) {
        std::cout << q_copy.top() << " ";
        q_copy.pop();
    }
    std::cout << '\n';
}
 
/**
 * 
 * @param h_high passes in the min heap
 * @param h_low passes in the max heap
 * @param num, the new number that is being inserted into the heap/list
 * @return the median 
 */
int find_median(priority_queue<int, vector<int>, greater<int>>& h_high, priority_queue<int>& h_low, int num) {
 // Your code here...
    
    addNumber(h_high, h_low, num);
    int median;
    
    
    // if the size of the minHeap(h_high) > the size of maxHeap(h_low), then  
    //  the median would be the top of the minHeap
    if(h_high.size()>h_low.size()){
        return h_high.top();
    }
    
    // if the size of the maxHeap(h_low) > the size of minHeap(h_high), then the median 
    // would be the top of the maxHeap 
    else if(h_low.size()>h_high.size()){
        return h_low.top();
    }
    
    // if minHeap and Maxheap are the same size then the median would be the
    // two tops added together and divided by two
    else if(h_low.size()==h_high.size()){
        median = (h_low.top() + h_high.top())/2; 
    }
    
   return median; 
}


// Function to help determine which heap to add the new number to. 
void addNumber(priority_queue<int, vector<int>, greater<int>>& h_high, priority_queue<int>& h_low, int num){
    

    
    // if the number to add is greater than the top of the minheap, 
    // or if it is the first number being added, add to the min heap
    if(h_high.size()==0 || h_high.top() < num){
        h_high.push(num);
    }else{
        
        // add it to the maxheap if the number being added is less than the top 
        // of the minheap
        h_low.push(num);
    }
    
    // Rebalance the heaps if one heap starts to become bigger than the other by 
    // more than two numbers
    int low = h_low.size();
    int high = h_high.size();
    
    if(low-high > 1){
        h_high.push(h_low.top());
        h_low.pop();
    }
    if(high-low >1){
        h_low.push(h_high.top());
        h_high.pop();
    }

    
    
}

