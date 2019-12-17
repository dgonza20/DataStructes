/* 
 * File:   main.cpp
 * Author: degme
 * Assignment 1 ECGR 3180
 * In this assignment the Karatsuba multiplication algorithm will be implemented
 * for any pair of multiples. 
 * Created on May 30, 2019, 10:07 AM
 */

#include<iostream>
#include<cmath>
#include<string>

using namespace std;


/* 
 * Returns the bigger number of digits of the two numbers
 */
int bigger(int one, int two){
    if(one >= two)
        return one;
    else
        return two; 
}

/*
 * Implementation of the Karatsuba algorithm, creates three recursion calls,
 * returning the result of the three recursion calls or returns the multiplication
 * if one number is a single digit
 */
int karatsuba(int num1, int num2){
    int power;
  
    
   // Gets how many digits each integer has
   int sizeNum1 = log10(num1) + 1;
   int sizeNum2 = log10(num2) + 1;
   
   
   
   // Getting the number of digits of the bigger size of the two integers passed in
   int n = bigger(sizeNum1,sizeNum2);
   
   
   // Getting (n/2)
   if(n%2==0){
       n =n/2;
   }
   else{
       n = (n/2) + 1;
   }
   
   
   // Getting 10^n
   power = pow(10,n);
   
   
   // Splits the two integers into two halves
   int a = num1/power;
   int b = num1-(a * power);
   int c = num2/power;
   int d = num2-(c*power);
   
   

   // Base case, one number is a single digit
   if((sizeNum1 < 10)||(sizeNum2 < 10)){
       return num1 * num2;
   }
   // Recursion calls for the karatsuba algorithm
   else{
       int ac = karatsuba(a,c);
       int bd = karatsuba(b,d);
       int x = karatsuba((a+b),(c+d));
       return bd + ((x-bd-ac) * pow(10,n)) + (ac * pow(10, n *2));
   } 
   
}


int main() {
    
    cout << "7*6 = " << karatsuba(7, 6) << endl; // 42
    cout << "15*15 = " << karatsuba(15, 15) << endl; // 225
    cout << "6*13 = " << karatsuba(6, 13) << endl; // 78
    cout << "51*49 = " << karatsuba(51, 49) << endl; // 2499
    cout << "111*111 = " << karatsuba(111, 111) << endl; // 12321
    cout << "5678*1234 = " << karatsuba(5678, 1234) << endl; // 7006652
    cout << "12345678*1 = " << karatsuba(12345678, 1) << endl; // 12345678
    cout << "12345678*0 = " << karatsuba(12345678, 0) << endl; // 0
    
    
    
    return 0;
}

