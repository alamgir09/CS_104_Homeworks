#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
#include <ctime>
#include <cstdlib>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
        // Add your code here
        int size = k.size();
        unsigned long long w[5] = {0,0,0,0,0};
        int wIndex = 4;
        // only 1-6 will be utilized
        HASH_INDEX_T a[7] = {0,0,0,0,0,0,0};
        int aIndex = 1;

        while (size > 0)
        {
            if (size >= 6)
            {
                for (int i = size-6; i < size;i++)
                {
                    a[aIndex++] = letterDigitToNumber(k[i]);
                }
                w[wIndex--] = ((((((a[1])*36 + a[2])*36 + a[3])*36 + a[4])*36 + a[5])*36 + a[6]);
                aIndex = 1;
                for (int i = 0; i < 7; i++)
                {
                    a[i] = 0;
                }
                size = size-6;
            }else if (size < 6){
               aIndex = 7 - size;
               for (int i = 0; i < size;i++)
                {
                    a[aIndex++] = letterDigitToNumber(k[i]);
                }
                unsigned long long aX = a[7-size];

                if (size == 1){w[wIndex--] = aX;break;}

                for (int i = 8 - size; i < 7; i++)
                {
                    aX = aX*36 + a[i];
                }
                w[wIndex--] = aX;
                aIndex = 1;
                
                for (int i = 0; i < 7; i++)
                {
                    a[i] = 0;
                }
                size = 0;
            }
        }
        return ((rValues[0]*w[0])+(rValues[1]*w[1])+(rValues[2]*w[2])+(rValues[3]*w[3])+(rValues[4]*w[4]));
    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        // Add code here or delete this helper function if you do not want it
        // make sure to convert to lower case before mapping
        // 3 cases
        // if number
        if ((int)letter > 47 && (int)letter < 58)
        {
            int converted = (int)letter - 22;
            return converted;
        }
        // if lowercase
        else if ((int)letter > 96 && (int)letter < 122)
        {
            int converted = (int)letter - 97;
            return converted;
        }
        // if uppercase
        else if ((int)letter > 64 && (int)letter < 91)
        {
            int converted = (int)letter - 65;
            return converted;
        }
        return 0;
    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif
