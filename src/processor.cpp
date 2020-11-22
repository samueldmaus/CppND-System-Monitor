#include <unistd.h>
#include "processor.h"
#include "linux_parser.h"


// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
    float cpu_util;
    cpu_util = (float) (LinuxParser::ActiveJiffies()/sysconf(_SC_CLK_TCK))/LinuxParser::UpTime();
    return cpu_util;
}