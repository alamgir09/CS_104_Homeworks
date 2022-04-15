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
void traversal(std::vector<char> floatVec, const std::set<std::string>& dict, std::set<std::string> &generated, long unsigned int index, std::string combination, std::string& letters);
// int inWord(std::string& combination, const std::string& floating);
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
    for (long unsigned int i = 0; i < floating.size(); i++)
    {
        floatVec.push_back(floating[i]);
    }
    long unsigned int index = 0;
    if (combination.empty()) return generated;
    traversal(floatVec, dict, generated, index, combination, letters);
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
void traversal(std::vector<char> floatVec, const std::set<std::string>& dict, std::set<std::string> &generated, long unsigned int index, std::string combination, std::string& letters)
{
    long unsigned int dashes = dashesPresent(combination);
    // quick check if this position can even be modified, if not then go to next index
    if (combination[index] != '-')
    {
        index++;
        traversal(floatVec, dict, generated, index, combination, letters);
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
            //std::cout << "the word generated " << combination << std::endl;
        }
        return;
    // check if this position of the word should even be changed
    }
    // only use hints, since number hints equals the blank spaces left
    else if (dashes == floatVec.size())
    {
        // only go through characters left in floating
        for (long unsigned int i = 0; i < floatVec.size(); i++)
        {
            std::vector<char> temp = floatVec;
            combination[index] = floatVec[i];
            if (temp.size() != 0)
            {
                std::vector<char>::iterator it = temp.begin() + i;
                if (it != temp.end())
                {
                    temp.erase(it);
                }
            }
            traversal(temp, dict, generated, index+1, combination, letters);
        }
        return;
    }
    // go through all characters since more blank spaces than hintsUsed
    /*
    else if (dashes > floatVec.size())
    {
        for (long unsigned int i = 0; i < 26; i++)
        {
            std::vector<char> temp = floatVec;
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
            traversal(temp, dict, generated, index+1, combination, letters);
        }
        return;
    }
    */
   
    else if (dashes > floatVec.size())
    {
        for (long unsigned int i = 0; i < floatVec.size(); i++)
        {
            std::vector<char> temp = floatVec;
            combination[index] = floatVec[i];
            std::vector<char>::iterator it = temp.begin() + i;
            temp.erase(it);
            traversal(temp, dict, generated, index+1, combination, letters);
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

}
// -- ab
// dashes < floatVec
// try floating characters, dashes < floatVec, use only floatVec