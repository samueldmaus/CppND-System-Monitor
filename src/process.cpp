#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() {
    return pid_;
}

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() {
    vector<string> cpu_util = LinuxParser::CpuUtilization(pid_);
    float total_time = std::stof(cpu_util[0]) + std::stof(cpu_util[1]);
    total_time += std::stof(cpu_util[2]) + std::stof(cpu_util[3]);
    long up_time = LinuxParser::UpTime();
    int seconds = up_time - (std::stoi(cpu_util[4]) / sysconf(_SC_CLK_TCK));
    Process::cpu_usage_ = (total_time / sysconf(_SC_CLK_TCK)) / seconds;
    return cpu_usage_ * 100;
}

// TODO: Return the command that generated this process
string Process::Command() {
    return LinuxParser::Command(pid_);
}

// TODO: Return this process's memory utilization
string Process::Ram() {
    string ram_kb = LinuxParser::Ram(pid_);
    Process::ram_mb_ = std::stoi(ram_kb)/1000;
    return to_string(Process::ram_mb_);
}

// TODO: Return the user (name) that generated this process
string Process::User() {
    Process::user_name = LinuxParser::User(pid_);
    return Process::user_name;
}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() {
    return LinuxParser::UpTime(pid_);
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
    // logic for sorting by ram
    /*
    int ram_a = this->ram_mb;
    int ram_b = a.ram_mb;
    return ram_a > ram_b;
    */
   return cpu_usage_ > a.cpu_usage_;
}