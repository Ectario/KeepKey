#pragma once //to be included only once in a single compilation.
#include <string>
#include <fstream>

using namespace std;

class LogManager
{
public:
	~LogManager();
	void save(string s);
	void init(string path); //path of where we gonna put the logs
private:
	ofstream file;
	string path;
	string content;
};

