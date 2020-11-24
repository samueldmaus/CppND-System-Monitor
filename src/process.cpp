#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"
#include "system.h"

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
    return cpu_usage_;
}

// TODO: Return the command that generated this process
string Process::Command() {
    Process::command_line = LinuxParser::Command(pid_);
    if(Process::command_line.length() > 40) {
        return Process::command_line.substr(0,40).append("...");
    } else {
        return Process::command_line;
    }
    return string{};
}

// TODO: Return this process's memory utilization
std::string Process::Ram() {
    int int_ram_kb;
    std::string ram_kb = LinuxParser::Ram(pid_);
    if (ram_kb != "") {
        int_ram_kb = (std::stoi(ram_kb))/1000;
    }
    Process::ram_mb_ = to_string(int_ram_kb);
    return Process::ram_mb_;
}

// TODO: Return the user (name) that generated this process
string Process::User() {
    Process::user_name = LinuxParser::User(pid_);
    return Process::user_name;
}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() {
    Process::up_time = LinuxParser::UpTime(pid_);
    long int total_time = LinuxParser::UpTime();
    return total_time - Process::up_time;
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
   return a.cpu_usage_ < cpu_usage_;
}