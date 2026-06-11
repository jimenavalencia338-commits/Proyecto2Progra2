#pragma once

#include <string>
#include <vector>

using namespace std;

class Logger {
private:
    vector<string> logs;

public:
    Logger();

    void writeLog(const string& message);
    void exportLog(const string& path);

    vector<string>& getLogs();
};

