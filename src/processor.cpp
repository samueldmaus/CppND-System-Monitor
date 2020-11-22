#include <unistd.h>
#include "processor.h"
#include "linux_parser.h"


// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
    Processor::cpu_usage_1 = (float) (LinuxParser::ActiveJiffies()/sysconf(_SC_CLK_TCK))/LinuxParser::UpTime();
    return Processor::cpu_usage_1;
}