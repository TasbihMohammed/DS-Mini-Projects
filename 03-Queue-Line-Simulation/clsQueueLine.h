#pragma once
#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<queue>
#include<stack>
#include"clsTicket.h"
using namespace std;

class clsQueueLine
{
private:
    string _Prefix="";
    short _AverageServeTime=0;
    short _TotalTickets=0;

    queue<clsTicket> _Queue;
public:
    clsQueueLine(const string& Prefix, short AverageServeTime) :_Prefix(Prefix) ,
        _AverageServeTime(AverageServeTime)
    {
    }

    void IssueTicket()
    {
        _TotalTickets++;
        clsTicket Ticket(_Prefix,_TotalTickets,_Queue.size(),_AverageServeTime);
        _Queue.push(Ticket);
    }	
    void CreateTickets(short NumberOfTickets)
    {
        for (int i = 1;i <= NumberOfTickets; i++)
        {
            IssueTicket();
        }
    }

    string WhoIsNext() const
    {
        if (_Queue.empty())
            return "No Clients Left :-)";

        return _Queue.front().FullNumber() ;
    }
    bool ServeNextClient()
    {
        if (_Queue.empty())
            return false;

            _Queue.pop();
            return true;
    }
    short WaitingClients() const
    {
        return _Queue.size();
    }
    short ServedClients() const
    {
        return _TotalTickets - WaitingClients();
    }

    void PrintInfo() const
    {
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t\tQueue Info";
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t    Prefix   = " << _Prefix;
        cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
        cout << "\n\t\t\t    Served Clients  = " << ServedClients();
        cout << "\n\t\t\t    Waiting Clients  = " << WaitingClients(); ;
        cout << "\n\t\t\t _________________________\n";
        cout << "\n";
    }
    void PrintTicketsLineRTL()
    {
        if (_Queue.empty())
        {
            cout << "\n\t\tTickets: No Tickets.";
            return;
        }
        else
            cout << "\n\t\tTickets: ";

        queue <clsTicket> TempQueueLine = _Queue;

        while (!TempQueueLine.empty())
        {
            clsTicket Ticket = TempQueueLine.front();
            cout << " " << Ticket.FullNumber() << " <-- ";
            TempQueueLine.pop();
        }
        cout << "\n";
    }
    void PrintTicketsLineLTR()
    {
        if (_Queue.empty())
        {
            cout << "\n\t\tTickets: No Tickets.";
            return;
        }
        else
            cout << "\n\t\tTickets: ";

        queue <clsTicket> TempQueue = _Queue;
        stack <clsTicket> TempStack;

        while (!TempQueue.empty())
        {
            TempStack.push(TempQueue.front());
            TempQueue.pop();
        }

        while (!TempStack.empty())
        {
            clsTicket Ticket = TempStack.top();
            cout << " " << Ticket.FullNumber() << " --> ";
            TempStack.pop();
        }
        cout << "\n";
    }
    void PrintAllTickets()
    {

        cout << "\n\n\t\t\t       ---Tickets---";

        if (_Queue.empty())
        {
            cout << "\n\n\t\t\t     ---No Tickets---\n";
            return;
        }

        queue <clsTicket> TempQueue = _Queue;

        while (!TempQueue.empty())
        {
            TempQueue.front().Print();
            TempQueue.pop();
        }

    }
};

