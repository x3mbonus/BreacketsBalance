#include <iostream>
#include <string>
#include <fstream>
#include "Logger.h"

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios_base;
using std::to_string;

void countBreackets(char * str, int & countOpened, int & countClosed);

int main (int argc, char ** args)
{
	setlocale(LC_ALL, "rus"); 
	string standartPath = "d:\\temp\\";
	string standartName = standartPath + "111.txt";
	string logFileName = standartPath+"log.txt";
	cout << "Enter the filepath (- = \""<< standartName <<"\"): ";
	string fullFileName;
	getline(cin, fullFileName);
	if (!fullFileName.empty())
	{
		if (fullFileName == "-")
		{
			fullFileName = standartName;
		}

		ifstream file(fullFileName, ios_base::in);
		Logger logger(logFileName);
		if (!file)
		{
			logger << "Sorry. Error opening file!";
		}
		else
		{
			logger << "File content:\r\n";
			const int len = 100;
			
			int countOpened = 0, countClosed = 0;
			
			
			
			while (!file.eof())
			{
				char * buffer = new char[len];
				file.get(buffer, len);
				logger << buffer;
				countBreackets(buffer, countOpened, countClosed);
				delete [] buffer; 
			}
			file.close();
			logger.WriteLine();
			logger << "Count opened: " << countOpened << "\r\n" <<
				"Count closed: " << countClosed << "\r\n";
		}

	}
	system("pause >> void");
}

void showLog(const string & message, const ofstream & log)
{
	cout << message;
}

void countBreackets(char * str, int & countOpened, int & countClosed)
{
	const char opened = '{', closed = '}';
	
	int i = 0;
	char c;
	do
	{
		c = str[i++];
		if (c == opened)
		{
			countOpened ++;
		}
		else if (c == closed)
		{
			countClosed ++;
		}
	}
	while (c != '\0');
}