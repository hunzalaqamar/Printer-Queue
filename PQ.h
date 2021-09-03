//this is the header file which includes all the class and function declarations


#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Time
{
private:
	int hours;
	
	int minutes;

	int seconds;
public:
	Time();

	void setHours(int);

	void setMinutes(int);

	void setSeconds(int);

	int getHours();

	int getMinutes();

	int getSeconds();
};

class Node
{
private:
	Time submissionTime, startTime, endTime;

	int numberOfPages;

	string taskName,dataSize,status;

	Node* next;
public:
	Node();

	void setSubTime(int, int,int);

	void setStartTime(int, int,int);

	void setEndTime(int, int,int);

	void setDataSize(string);

	void setNumberOfPages(int);

	void setNext(Node*);

	void setTaskName(string);

	void calculateEndTime(int&,int&,int&);

	void deleteData();

	void setStatus(string);

	Time getSubTime();

	Time getStartTime();

	Time getEndTime();

	string getDataSize();

	int getNumberOfPages();

	Node* getNext();

	string getTaskName();

	string getStatus();
};

class PrinterQueue
{
private:
	Node* front, * rear;
public:
	PrinterQueue();

	void addPrintingTask();

	void displayTasks();

	void deleteTask();

	void setNewTimes();

	void menu();

	void getSystemTime(int&,int&,int&);

	void processJobs();

	void executeProgram();
};