#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include<string>
#include "clsDate.h"

using namespace std;

class clsTicket
{
private:
    string _Prefix = "";
    short _Number = 0;
    string _TicketDateTime = "";
    short _ClientsBeforeMe = 0; 
    short _AverageServeTime = 0;



public:
    clsTicket(const string& Prefix,short Number,short ClientsBeforeMe,short AverageServeTime)
        : _Prefix(Prefix),_Number(Number),_ClientsBeforeMe(ClientsBeforeMe),
        _AverageServeTime(AverageServeTime),_TicketDateTime(clsDate::GetSystemDateTimeString())
    {
    }
    
    string FullNumber() const
    {
        ostringstream Stream;
        Stream << _Prefix << setw(3) << setfill('0') << _Number;
        return Stream.str();
    }  
    const string& TicketDateTime()const
    {
        return _TicketDateTime;
    }

    short ClientsBeforeMe() const
    {
        return _ClientsBeforeMe;
    }
    short ExpectedServeTime() const
    {
        return _AverageServeTime * _ClientsBeforeMe;
    }
    void Print() const
    {
        cout << "\n\t\t\t" << setw(30) << setfill('*') << "" << endl;
        cout << setfill(' ');
        cout << "\t\t\t" << setw(18) << left << "Ticket Number" << ": " << FullNumber() << endl;
        cout << "\t\t\t" << setw(18) << left << "Time" << ": " << TicketDateTime() << endl;
        cout << "\t\t\t" << setw(18) << left << "Clients Before Me" << ": " << ClientsBeforeMe() << endl;
        cout << "\t\t\t" << setw(18) << left << "Expected Time" << ": " << ExpectedServeTime() << " Minutes." << endl;
        cout << "\t\t\t" << setw(30) << setfill('*') << "" << endl;
    }
};