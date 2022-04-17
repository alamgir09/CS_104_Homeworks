// For debugging
#include <iostream>
// For std::remove
#include <vector>
#include <algorithm> 
#include <map>
#include <set>
#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
void traversal(std::vector<char> floatVec, const std::set<std::string>& dict, std::set<std::string> &generated, long unsigned int index, std::string combination, std::string& letters, long unsigned int& dashes);
long unsigned int dashesPresent(std::string& combination);

// use backtracking, and check cases as you go through problem
// similar to n-queens problem, he went over a similar problem in lecture, all possible word combinations

// Create helper function that checks if floating letters exist in combination of word


// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    std::set<std::string> generated; // will contain all possible combinations
    std::string combination = in;
    std::string letters = "abcdefghijklmnopqrstuvwxyz";
    // to allow us to delete letters from string and use find function, we must import floating into a vector of chars
    std::vector<char> floatVec;
    //std::multiset<char> floatSet;
    /* the multiset version
    for (long unsigned int i = 0; i < floating.size();i++)
    {
        floatSet.insert(floating[i]);
    }
    */
    ///*
    for (long unsigned int i = 0; i < floating.size(); i++)
    {
        floatVec.push_back(floating[i]);
    }
    //*/
    long unsigned int index = 0;
    long unsigned int dashes = dashesPresent(combination);
    if (combination.empty()) return generated;
    traversal(floatVec, dict, generated, index, combination, letters, dashes);
    return generated;
}

// Define any helper functions here

// counts number of dashes/empty spots left
long unsigned int dashesPresent(std::string& combination)
{
    long unsigned int dashes = 0;
    for (long unsigned int i = 0; i < combination.size(); i++)
    {
        if (combination[i] == '-')
        {
            dashes++;
        }
    }
    return dashes;
}


// does the recursion for me, generating combinations
void traversal(std::vector<char> floatVec, const std::set<std::string>& dict, std::set<std::string> &generated, long unsigned int index, std::string combination, std::string& letters, long unsigned int& dashes)
{
    dashes = dashesPresent(combination);
    // quick check if this position can even be modified, if not then go to next index
    if (combination[index] != '-')
    {
        //index++;
        traversal(floatVec, dict, generated, index+1, combination, letters, dashes);
        return;
    }
    // BC
    // if index has reached that of the answer
    else if (dashes == 0)
    {
        // is the word in the dictionary? add to combinations set
        if (dict.find(combination) != dict.end())
        {
            generated.insert(combination);
        }
        return;
    // check if this position of the word should even be changed
    }
    // only use hints, since number hints equals the blank spaces left
    else if (dashes == floatVec.size())
    {
        // only go through characters left in floating
        ///*
        for (long unsigned int i = 0; i < floatVec.size(); i++)
        {
            char character = floatVec[i];
            combination[index] = character;
            std::vector<char>::iterator it = floatVec.begin() + i;
            floatVec.erase(it);
            traversal(floatVec, dict, generated, index+1, combination, letters, dashes);
            floatVec.insert(floatVec.begin() + i, character);
        }
        //*/
        /* the multiset version
        bool erased = false;
        for (std::multiset<char>::iterator it = floatVec.begin(); it != floatVec.end(); ++it)
        {
            char character = *it;
            combination[index] = character;
            if (it != floatVec.end())
            {
                floatVec.erase(it);
                erased = true;
            }
            traversal(floatVec, dict, generated, index+1, combination, letters, dashes);
            if (erased) floatVec.insert(it, character);
            erased = false;
        }
        */
        return;
    }
    // go through all characters since more blank spaces than hintsUsed
    
    else if (dashes > floatVec.size())
    {
        ///*
        for (long unsigned int i = 0; i < 26; i++)
        {
            std::vector<char> temp = floatVec;
            //char character = letters[i];
            combination[index] = letters[i];
            // remove this character from floating, if it exists in floating
            if (temp.size() != 0)
            {
                std::vector<char>::iterator it = std::find(temp.begin(), temp.end(), letters[i]);
                if (it != temp.end())
                {
                    temp.erase(it);
                }
            }
            traversal(temp, dict, generated, index+1, combination, letters, dashes);
            
        }
        //*/
        // multiset version
        /*

        for (long unsigned int i = 0; i < 26; i++)
        {
            combination[index] = letters[i];
            std::multiset<char> temp = floatVec;
            // remove this character from floating, if it exists in floating
            if (temp.size() != 0)
            {
                std::multiset<char>::iterator it = temp.find(letters[i]);
                if (it != temp.end())
                {
                    temp.erase(it);
                }
            }
            traversal(temp, dict, generated, index+1, combination, letters, dashes);
        }
        */
        return;
    }
}
// -- ab
// dashes < floatVec
// try floating characters, dashes < floatVec, use only floatVec











/*
    else if (dashes > floatVec.size())
    {
        for (long unsigned int i = 0; i < floatVec.size(); i++)
        {
            //std::vector<char> temp = floatVec;
            char character = floatVec[i];
            combination[index] = character;
            std::vector<char>::iterator it = floatVec.begin() + i;
            floatVec.erase(it);
            traversal(floatVec, dict, generated, index+1, combination, letters);
            floatVec.insert(floatVec.begin() + i, character);
        }
        for (long unsigned int i = 0; i < 26; i++)
        {
            //std::vector<char> temp = floatVec;
            combination[index] = letters[i];
            if (std::find(floatVec.begin(), floatVec.end(), letters[i]) == floatVec.end())
            {
                traversal(floatVec, dict, generated, index+1, combination, letters);
            }
        }
        return;
    }
    */