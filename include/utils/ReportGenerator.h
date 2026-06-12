#pragma once

#include "world/World.h"
#include "utils/Logger.h"

#include <string>

using namespace std;



class ReportGenerator {
public:
    ReportGenerator();

    void generateReport(
        World& world,
        Logger& logger,
        const string& path
    );
};