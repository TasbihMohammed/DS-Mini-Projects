#include <iostream>
#include "clsQueueLine.h"
using namespace std;

int main()
{
    clsQueueLine Queue("A", 5);

    Queue.CreateTickets(3);

    cout << "\nQueue Information:\n";
    Queue.PrintInfo();

    cout << "\nAll Tickets:\n";
    Queue.PrintAllTickets();

    cout << "\nTickets (Left To Right):\n";
    Queue.PrintTicketsLineLTR();

    cout << "\nTickets (Right To Left):\n";
    Queue.PrintTicketsLineRTL();

    cout << "\nServing Next Client...\n";
    Queue.ServeNextClient();

    cout << "\nQueue Information After Serving:\n";
    Queue.PrintInfo();

    cout << "\nAll Tickets After Serving:\n";
    Queue.PrintAllTickets();

    return 0;
}