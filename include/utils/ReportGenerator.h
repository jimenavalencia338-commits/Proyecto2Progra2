#pragma once

#include <string>

using namespace std;

class World;
class Logger;

class ReportGenerator {
public:
    ReportGenerator();

    void generateReport(
        World& world,
        Logger& logger,
        const string& path
    );
};