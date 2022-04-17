

#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please
#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here

// checks if the schedule is currently valid
bool isValid(DailySchedule& sched,const AvailabilityMatrix& avail, int d, int m);

// is the recursive function we'll call in schedule
bool traversal(DailySchedule& sched,const AvailabilityMatrix& avail, int n, int d, int k, int m, int daily);

// Add your implementation of schedule() and other helper functions here

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    // Add your code below

    int m = maxShifts;
    int daily = dailyNeed;
    int n = avail.size();
    int k = avail[0].size();

    std::vector<Worker_T> workers;
    workers.clear();

    std::vector<std::vector<Worker_T> > vec(n, std::vector<Worker_T> (daily, -1));
    
    bool something = false;
    something = traversal(vec, avail, 0, 0, k, m, daily);
    sched = vec;
    if (something) {return something;}
    return false;


}

bool traversal(DailySchedule& sched,const AvailabilityMatrix& avail, int n, int d, int k, int m, int daily)
{
    if (n == sched.size()-1 && d == sched[0].size())
    {
        return true;
    }
    if (d == sched[0].size())
    {
        n++;
        d = 0;
    }
    if (sched[n][d] != -1)
    {
        return traversal(sched, avail, n, d+1, k, m, daily);
    }
    for (int i = 0; i < k; i++)
    {
        sched[n][d] = i;
        daily = avail.size();
        if (isValid(sched, avail, daily, m))
        {
            bool finished = traversal(sched, avail, n, d+1, k, m, daily);
            if (finished)
            {
                return finished;
            }

        }
    }
    sched[n][d] = -1;
    return false;
}

bool isValid(DailySchedule& sched,const AvailabilityMatrix& avail, int d, int m)
{
    // workers scheduled not same as needed
    if (sched[0].size() != d) {return false;}

    int workers[avail[0].size()];

    for (int i = 0; i < sched.size();i++)
    {
        for (int j = 0; j < sched[0].size(); j++)
        {
            if (sched[i][j] > -1 && sched[i][j] < avail[0].size())
            {
                workers[j]++;
                // more than max shifts
                if (workers[j] > m) {return false;}
                // scheduled but not available
                if (avail[i][sched[i][j]] == 0) {return false;}
            }
            //std::cout << "is this ever called" << endl;
        }
    }
    return true;
}


// if row and column == to final
    // return true
// if column reaches final
    // change row ++
    // set col to 0
// if value is already set
    // iterate to next recursive call
// for loop
    // set value
    //if valid
        // recurse to next col
        // return true if recursive calls are valid
// backtrace and set value to -1
// return false