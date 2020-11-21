#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"
#include "system.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// TODO: Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() { return processes_; }

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() { 
    System::kernel = LinuxParser::Kernel();
    return System::kernel;
}

// TODO: Return the system's memory utilization
float System::MemoryUtilization() {
    System::memory = LinuxParser::MemoryUtilization();
    return System::memory;
}

// TODO: Return the operating system name
std::string System::OperatingSystem() {
    System::os = LinuxParser::OperatingSystem();
    return System::os;
}

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() {
    System::running_processes = LinuxParser::RunningProcesses();
    return running_processes;
}

// TODO: Return the total number of processes on the system
int System::TotalProcesses() {
    System::total_processes = LinuxParser::TotalProcesses();
    return System::total_processes;
}

// TODO: Return the number of seconds since the system started running
long int System::UpTime() { return 0; }