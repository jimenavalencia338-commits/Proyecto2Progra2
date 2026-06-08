#include "../../include/utils/ReportGenerator.h"
#include "../../include/utils/Logger.h"

#include <fstream>

ReportGenerator::ReportGenerator() {
}

void ReportGenerator::generateReport(
        World& world,
        Logger& logger,
        const string& path) {

    ofstream file(path);

    if (!file.is_open()) {
        return;
    }

    file << "Adventure Simulation Report" << endl;
    file << "===========================" << endl;

    for (const auto& log : logger.getLogs()) {
        file << log << endl;
    }

    file.close();
}