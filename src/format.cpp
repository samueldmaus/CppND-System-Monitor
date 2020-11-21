#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function

string Format::ElapsedTime(long seconds) {
    string time;
    int hrs, mins, secs;
    hrs = seconds/3600;
    mins = (seconds % 3600) / 60;
    secs = (seconds % 3600 % 60);
    time = Format::HelperTime(hrs) + ":" + Format::HelperTime(mins) + ":" + Format::HelperTime(secs);
    return time;
}

string Format::HelperTime (int n) {
    string helper_time;
    if(n < 10) {
        helper_time = "0" + std::to_string(n);
    } else {
        helper_time = std::to_string(n);
    }
    return helper_time;
}

