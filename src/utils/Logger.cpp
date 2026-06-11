#include "../../include/utils/Logger.h"
#include <fstream>

Logger::Logger() {
}

void Logger::writeLog(const string& message) {
    logs.push_back(message);
}

void Logger::exportLog(const string& path) {
    ofstream file(path);

    if (!file.is_open()) {
        return;
    }

    for (const auto& log : logs) {
        file << log << endl;
    }

    file.close();
}

vector<string>& Logger::getLogs() {
    return logs;
}