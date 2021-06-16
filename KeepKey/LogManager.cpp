#include "LogManager.h"

LogManager::~LogManager() {};

void LogManager::save(string s)
{
    content += s;
    file.open(this->path);
    file << content;
    file.close();
}

void LogManager::init(string path)
{
    this->path = path + "keyLog.txt";
}
