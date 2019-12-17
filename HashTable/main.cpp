
/* 
 * File:   main.cpp
 * Author: David Gonzales
 *
 * Created on June 25, 2019, 4:31 PM
 */


#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
vector<vector<string>> findAnagrams(const vector<string>& dict);
int keyHelper(string word);

int main() 
{
   vector<string> word_list = {"debitcard", "elvis", "silent", "badcredit", "lives", "freedom",    "listen", "levis"};
  //vector<string> word_list = {};//"debitcard", "elvis", "silent", "badcredit", "lives", "freedom",    "listen", "levis"};
   vector<vector<string>> result = findAnagrams(word_list);
   for (auto anagrams: result) {
      for (auto words: anagrams)
         cout << words << " ";
         cout << endl;
    }
   return 0;
}


/**
 * This function passes in one of the words from the list and adds all the ASCII
 * values for that word and divides it by a prime number 
 * @param word, passes in one of the words from the list
 * @return keyVal, returns the key value that is associated with the word passed in
 */
int keyHelper(string word){
    
    int total = 0;
    int keyVal;
    
    // takes each letter of the word and combines the ASCII values of that word
    for(int j = 0 ; j < word.length(); j++){
        total += (int)word[j];
    }
    
    // divide the total by a prime number
    keyVal = total % 53;
    return keyVal;
}


vector<vector<string>> findAnagrams(const vector<string>& dict) {
    
    unordered_map<int, vector<string> > map;
    vector<vector<string>> ans;
    int bucket;
    
    // if the vector passed in is only one word of empty = no anagrams
    if(dict.size() < 1){
        return ans;
    }

   
    for(int i = 0 ; i < dict.size(); i++){
        
        // gets the key for each word in the list, one at a time
        bucket = keyHelper(dict.at(i));
        
        // stores that word into the map at its associated bucket
        map[bucket].push_back(dict[i]);
    }

    // puts the words in each bucket into a vector of its own
    for(auto it = map.begin() ; it != map.end(); it++){
        ans.push_back(it->second);
    }
    
    return ans;

}
