//this the PQ.cpp file which includes all the class and function definations
#define _CRT_SECURE_NO_WARNINGS

#include "PQ.h"

Time::Time()
{
	hours = 0;

	minutes = 0;

	seconds = 0;
}
void Time::setHours(int nHours)
{
	if (nHours >= 00 && nHours <= 12)
	{
		hours = nHours;
	}
	else
	{
		hours = 0;
	}
}
void Time::setMinutes(int nMinutes)
{
	if (nMinutes >=00 && nMinutes < 60)
	{
		minutes = nMinutes;

	}
	else
	{
		minutes = 0;
	}
}
void Time::setSeconds(int nSec)
{
	if (nSec >= 00 && nSec < 60)
	{
		seconds = nSec;
	}
	else
	{
		seconds = 0;
	}
}
int Time::getHours()
{
	return hours;
}
int Time::getMinutes()
{
	return minutes;
}
int Time::getSeconds()
{
	return seconds;
}



Node::Node()
{
	dataSize = "";

	status = "";
	
	numberOfPages = 0;

	next = NULL;
}
void Node::setDataSize(string nData)
{
	dataSize = nData;
}
void Node::setNumberOfPages(int nNOP)
{
	numberOfPages = nNOP;
}
void Node::setNext(Node* nNext)
{
	next = nNext;
}
void Node::setSubTime(int nHours, int nMinutes,int nSeconds)
{
	submissionTime.setHours(nHours);

	submissionTime.setMinutes(nMinutes);

	submissionTime.setSeconds(nSeconds);
}
void Node::setStartTime(int nHours, int nMinutes,int nSeconds)
{
	startTime.setHours(nHours);

	startTime.setMinutes(nMinutes);

	startTime.setSeconds(nSeconds);
}
void Node::setEndTime(int nHours, int nMinutes,int nSeconds)
{
	endTime.setHours(nHours);

	endTime.setMinutes(nMinutes);

	endTime.setSeconds(nSeconds);
}
void Node::setTaskName(string nTaskName)
{
	taskName = nTaskName;
}
void Node::calculateEndTime(int& nHours, int& nMinutes, int& nSeconds)
{
	int count = 0, tsecs = 0, val2 = 0;

	float tnop = 0.0, val = 0.0;

	tnop = numberOfPages;

	if (tnop <= 5)
	{
		tnop = tnop * 10;

		nSeconds = nSeconds + tnop;

		if (nSeconds == 60)
		{
			nSeconds = 0;

			nMinutes++;

			if (nMinutes == 60)
			{
				nMinutes = 0;

				nHours++;
			}

			if (nHours > 12)
			{
				nHours = nHours - 12;
			}
		}
		else if (nSeconds > 60)
		{
			nSeconds = nSeconds - 60;

			nMinutes++;

			if (nMinutes == 60)
			{
				nMinutes = 0;

				nHours++;
			}

			if (nHours > 12)
			{
				nHours = nHours - 12;
			}
		}
	}
	else
	{
		tnop = tnop * 10;

		tnop = tnop / 60;

		val = tnop;

		val2 = tnop;

		val -= val2;

		val = val * 100;

		nMinutes = nMinutes + tnop;

		nSeconds += val;

		if (nSeconds < 60)
		{
			if (nMinutes >= 60)
			{
				nHours++;

				nMinutes = nMinutes - 60;

				if (nHours > 12)
				{
					nHours = nHours - 12;
				}
			}
		}

		else if (nSeconds == 60)
		{
			nSeconds = 0;

			nMinutes++;

			if (nMinutes == 60)
			{
				nMinutes = 0;

				nHours++;
			}

			if (nHours > 12)
			{
				nHours = nHours - 12;
			}
		}
		else if (nSeconds > 60)
		{
			nSeconds = nSeconds - 60;

			nMinutes++;

			if (nMinutes == 60)
			{
				nMinutes = 0;

				nHours++;
			}

			if (nHours > 12)
			{
				nHours = nHours - 12;
			}
		}
	}
}
void Node::setStatus(string nS)
{
	status = nS;
}
Time Node::getSubTime()
{
	return submissionTime;
}
Time Node::getStartTime()
{
	return startTime;
}
Time Node::getEndTime()
{
	return endTime;
}
string Node::getDataSize()
{
	return dataSize;
}
int Node::getNumberOfPages()
{
	return numberOfPages;
}
Node* Node::getNext()
{
	return next;
}
string Node::getTaskName()
{
	return taskName;
}
string Node::getStatus()
{
	return status;
}
void Node::deleteData()
{
	submissionTime.setHours(0);
	submissionTime.setMinutes(0);
	submissionTime.setSeconds(0);
	startTime.setHours(0);
	startTime.setMinutes(0);
	startTime.setSeconds(0);
	endTime.setHours(0);
	endTime.setMinutes(0);
	endTime.setSeconds(0);
	numberOfPages = 0;
	taskName = " ";
	dataSize = " ";
	status = " ";
	next = NULL;
}


PrinterQueue::PrinterQueue()
{
	front = NULL;

	rear = NULL;
}
void PrinterQueue::getSystemTime(int& hour, int& min, int& sec)
{
	// current date/time based on current system
	time_t now = time(0);

	// convert now to string form
	tm mytime = *localtime(&now);

	hour = mytime.tm_hour;
	
	min = mytime.tm_min;

	sec = mytime.tm_sec;
}
void PrinterQueue::executeProgram()
{
	int choice=0;

	while (true)
	{
		menu();

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			addPrintingTask();

			break;
		}
		case 2:
		{
			deleteTask();

			break;
		}
		case 3:
		{
			displayTasks();

			break;
		}
		case 4:
		{
			cout << "\nThe Program will now terminate"<<endl;

			system("Pause");

			exit(0);
		}
		default:
		{
			cout << "\nInvalid Choice Try Again"<<endl;

			system("Pause");
		}
		}
	}
}
void PrinterQueue::addPrintingTask()
{
	system("CLS");

	string tname, tDataSize;

	int tnop, thour = 0, tmins = 0, tsec = 0, ans = 0;

	cout << "\nEnter Task Name : ";
	
	cin.ignore();
	
	getline(cin, tname);

	cout << "\nEnter Number Of Pages To Print : ";

	cin >> tnop;

	cout << "\nEnter Data Size in string (mention KB,MB.etc also) : ";

	cin.ignore();

	getline(cin,tDataSize);

	cout << "\nEnter Submission Time in Hours,Minutes and seconds (Note:enter hours and minutes in 12 hour format first enter hours give a space and then enter minutes and then enter seconds and enter) : ";

	cin >> thour >> tmins >> tsec;

	if ((thour >=00 && thour <= 12) && (tmins >=00 && tmins < 60) && (tsec >=00 && tsec < 60))
	{
		cout << "\nValid Time Entered";
	}
	else
	{
		cout << "\nInvalid Time Entered Try Again";

		thour = 0;

		tmins = 0;

		tsec = 0;
		
		system("Pause");
	}

	cout << "\n\nDo You want to add a task containing following information above ? (Enter 1 for yes And 2 For no) : ";
	
	cin >> ans;

	if (ans == 1)
	{
		Node* temp = new Node();

		temp->setTaskName(tname);

		temp->setSubTime(thour, tmins,tsec);

		temp->setDataSize(tDataSize);

		temp->setNumberOfPages(tnop);

		temp->setNext(NULL);

		if (rear == NULL)
		{
			front = temp;

			rear = temp;

			temp->setStartTime(thour, tmins, tsec);

			temp->calculateEndTime(thour, tmins, tsec);

			temp->setEndTime(thour, tmins, tsec);

			temp->setStatus("Active");
		}
		else
		{
			thour = rear->getEndTime().getHours();

			tmins = rear->getEndTime().getMinutes();
			
			tsec = rear->getEndTime().getSeconds();

			rear->setNext(temp);

			rear = temp;

			temp->setStartTime(thour, tmins, tsec);

			temp->calculateEndTime(thour, tmins, tsec);

			temp->setEndTime(thour, tmins, tsec);

			temp->setStatus("Pending");
		}

	}
	else
	{
		cout << "\nData Not Saved"<<endl;

		system("Pause");
	}
}
void PrinterQueue::deleteTask()
{
	system("CLS");

	Node* temp=NULL;

	int choice = 0;

	temp = front;

	if (front != NULL)
	{
		cout << "\nDo you want to continue to delete the job present at top considering it is active ? (enter 1 for yes and 2 for no) ";

		cout << "\n\nTask Name : " << front->getTaskName();

		cout << "\n\nPages To Print : " << front->getNumberOfPages();

		cout << "\n\nStatus : " << front->getStatus();

		cout << "\n\nYour Choice : ";

		cin >> choice;

		if (choice == 1)
		{
			if (front == rear)
			{
				front->deleteData();

				front = NULL;

				rear = NULL;

				cout << "\nTask Deleted Successfully"<<endl;

				system("Pause");
			}
			else
			{
				front = front->getNext();

				front->setStatus("Active");

				temp->deleteData();

				cout << "\nTask Deleted Successfully"<<endl;

				system("Pause");

				setNewTimes();
			}
		}
		else
		{
			cout << "\nJob Not Deleted"<<endl;

			system("Pause");
		}
	}
	else
	{
		cout << "No Job Present Please Add one to use this feature"<<endl;

		system("Pause");
	}
}
void PrinterQueue::setNewTimes()
{
	Node* temp = NULL;

	bool flag = false;

	temp = front;

	if (front == NULL)
	{
		cout << "\n\nQueue is empty";

		system("Pause");
	}
	else if(front==rear)
	{
		int th, tm, ts;

		th = front->getSubTime().getHours();

		tm = front->getSubTime().getMinutes();

		ts = front->getSubTime().getSeconds();

		front->setStartTime(th, tm, ts);

		front->calculateEndTime(th, tm, ts);

		front->setEndTime(th, tm, ts);
	}
	else
	{
		while (temp != rear)
		{
			if (flag == false)
			{
				int th, tm, ts;

				th = temp->getSubTime().getHours();

				tm = temp->getSubTime().getMinutes();

				ts = temp->getSubTime().getSeconds();

				temp->setStartTime(th, tm, ts);

				temp->calculateEndTime(th, tm, ts);

				temp->setEndTime(th, tm, ts);

				flag = true;
			}
			else
			{
				int th, tm, ts;

				th = temp->getEndTime().getHours();

				tm = temp->getEndTime().getMinutes();

				ts = temp->getEndTime().getSeconds();

				temp = temp->getNext();

				temp->setStartTime(th, tm, ts);

				temp->calculateEndTime(th, tm, ts);

				temp->setEndTime(th, tm, ts);

			}
		}
	}
}
void PrinterQueue::processJobs()
{
	int th, tm, ts;
	
	getSystemTime(th, tm, ts);

	th = th - 12;

	Node* temp = NULL;

	temp = front;

	if (temp != NULL)
	{

		if ((temp->getEndTime().getHours() == th) && (temp->getEndTime().getMinutes() < tm))
		{
			front = front->getNext();

			front->setStatus("Active");

			temp->deleteData();
		}
		else if ((th > temp->getEndTime().getHours()) && (tm > temp->getEndTime().getMinutes()))
		{
			front = front->getNext();

			front->setStatus("Active");

			temp->deleteData();
		}
		else
		{
			return;
		}
	}
}
void PrinterQueue::displayTasks()
{
	system("CLS");

	Node* temp = new Node();

	temp = front;

	if (temp == NULL)
	{
		cout << "\nQueue is empty" << endl;
	}
	else
	{
		while (temp != NULL)
		{
			processJobs();
			cout << "\n--------------------------------------------------------------";
			cout << "\nTask Name : " << temp->getTaskName();
			cout << "\nNumber Of Pages To Print : " << temp->getNumberOfPages();
			cout << "\nData Size : " << temp->getDataSize();
			cout << "\nStatus Of Task : " << temp->getStatus();
			cout << "\nSubmission Time of Task : " << temp->getSubTime().getHours() << ":" << temp->getSubTime().getMinutes() << ":" << temp->getSubTime().getSeconds();
			cout << "\nStarting Time of Task : " << temp->getStartTime().getHours() << ":" << temp->getStartTime().getMinutes() << ":" << temp->getStartTime().getSeconds();
			cout << "\nEnding Time of Task : " << temp->getEndTime().getHours() << ":" << temp->getEndTime().getMinutes() << ":" << temp->getEndTime().getSeconds();
			cout << "\n--------------------------------------------------------------";
			temp = temp->getNext();
		}
	}
	system("Pause");
}
	
void PrinterQueue::menu()
{
		system("CLS");
		system("COLOR 0A");
		cout << "\n\n**************************************************************************************************";
		cout << "\n\n						Cloud Printing Service		            ";
		cout << "\n\n**************************************************************************************************";
		cout << "\n\n1:Add Printing Task ";
		cout << "\n\n2:Delete Printing Task ";
		cout << "\n\n3:See Printing Tasks ";
		cout << "\n\n4:Exit Program ";
		cout << "\n\nYour Choice : ";
}