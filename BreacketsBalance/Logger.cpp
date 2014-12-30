#include "Logger.h"
#include <iostream>
#include <string>

using std::cout;
using std::to_string;


void Logger::Write(const string & message) const
{
	cout << message;
	if (_logFile != nullptr &&
		_logFile->is_open())
	{
		(*_logFile) << message;
	}
}

void Logger::WriteLine(const string & message) const
{
	Write(message + "\r\n");
}

const Logger & Logger::operator<<(const string & message) const
{
	Write(message);
	return (*this);
}

const Logger & Logger::operator<<(const int & message) const
{
	Write(to_string(message));
	return (*this);
}

Logger::Logger(const string & logFileName)
{
	_logFile = new ofstream(logFileName);
}


Logger::~Logger(void)
{
	if (_logFile != nullptr)
	{
		_logFile->close();
		delete _logFile;
		_logFile = 0;
	}
}
