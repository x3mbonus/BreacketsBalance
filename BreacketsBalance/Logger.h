#pragma once
#include <string>
#include <fstream>

using std::string;
using std::ofstream;

class Logger
{
private:
	ofstream * _logFile;
public:
	//Todo: LogType LogType;
	void Write(const string & message = "") const;
	void WriteLine(const string & message = "") const;
	const Logger & operator<<(const string & message) const;
	const Logger & operator<<(const int & message) const;
	Logger(const string & logFileName);
	~Logger(void);
};

