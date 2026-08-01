#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "clsString.h"

using namespace std;

class clsDate
{
private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;

public:

    // ---------------- Constructors ----------------

    clsDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        _Day = now->tm_mday;
        _Month = now->tm_mon + 1;
        _Year = now->tm_year + 1900;
    }

    clsDate(string sDate)
    {
        vector<string> dateParts = clsString::Split(sDate, "/");
        _Day = stoi(dateParts[0]);
        _Month = stoi(dateParts[1]);
        _Year = stoi(dateParts[2]);
    }

    clsDate(short Day, short Month, short Year)
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    clsDate(short DateOrderInYear, short Year)
    {
        clsDate date = GetDateFromDayOrderInYear(DateOrderInYear, Year);
        _Day = date.Day;
        _Month = date.Month;
        _Year = date.Year;
    }

    // ---------------- Properties ----------------

    void SetDay(short Day) { _Day = Day; }
    short GetDay() { return _Day; }
    __declspec(property(get = GetDay, put = SetDay)) short Day;

    void SetMonth(short Month) { _Month = Month; }
    short GetMonth() { return _Month; }
    __declspec(property(get = GetMonth, put = SetMonth)) short Month;

    void SetYear(short Year) { _Year = Year; }
    short GetYear() { return _Year; }
    __declspec(property(get = GetYear, put = SetYear)) short Year;

    // ---------------- Display ----------------

    void Print()
    {
        cout << DateToString() << endl;
    }

    static string DateToString(clsDate Date)
    {
        return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }

    string DateToString()
    {
        return DateToString(*this);
    }

    // ---------------- System Date ----------------

    static clsDate GetSystemDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        short Day = now->tm_mday;
        short Month = now->tm_mon + 1;
        short Year = now->tm_year + 1900;

        return clsDate(Day, Month, Year);
    }

    // ---------------- Validation ----------------

    static bool IsValidDate(clsDate Date)
    {
        if (Date.Day < 1 || Date.Month < 1 || Date.Month > 12)
            return false;

        return Date.Day <= NumberOfDaysInAMonth(Date.Month, Date.Year);
    }

    bool IsValid()
    {
        return IsValidDate(*this);
    }

    // ---------------- Leap Year / Day-Time Counting ----------------

    static bool isLeapYear(short Year)
    {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    bool isLeapYear()
    {
        return isLeapYear(_Year);
    }

    static short NumberOfDaysInAYear(short Year)
    {
        return isLeapYear(Year) ? 366 : 365;
    }

    short NumberOfDaysInAYear()
    {
        return NumberOfDaysInAYear(_Year);
    }

    static short NumberOfHoursInAYear(short Year)
    {
        return NumberOfDaysInAYear(Year) * 24;
    }

    short NumberOfHoursInAYear()
    {
        return NumberOfHoursInAYear(_Year);
    }

    static int NumberOfMinutesInAYear(short Year)
    {
        return NumberOfHoursInAYear(Year) * 60;
    }

    int NumberOfMinutesInAYear()
    {
        return NumberOfMinutesInAYear(_Year);
    }

    static int NumberOfSecondsInAYear(short Year)
    {
        return NumberOfMinutesInAYear(Year) * 60;
    }

    int NumberOfSecondsInAYear()
    {
        return NumberOfSecondsInAYear(_Year);
    }

    static short NumberOfDaysInAMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12)
            return 0;

        short daysPerMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : daysPerMonth[Month - 1];
    }

    short NumberOfDaysInAMonth()
    {
        return NumberOfDaysInAMonth(_Month, _Year);
    }

    static short NumberOfHoursInAMonth(short Month, short Year)
    {
        return NumberOfDaysInAMonth(Month, Year) * 24;
    }

    short NumberOfHoursInAMonth()
    {
        return NumberOfHoursInAMonth(_Month, _Year);
    }

    static int NumberOfMinutesInAMonth(short Month, short Year)
    {
        return NumberOfHoursInAMonth(Month, Year) * 60;
    }

    int NumberOfMinutesInAMonth()
    {
        return NumberOfMinutesInAMonth(_Month, _Year);
    }

    static int NumberOfSecondsInAMonth(short Month, short Year)
    {
        return NumberOfMinutesInAMonth(Month, Year) * 60;
    }

    int NumberOfSecondsInAMonth()
    {
        return NumberOfSecondsInAMonth(_Month, _Year);
    }

    // ---------------- Day of Week ----------------

    static short DayOfWeekOrder(short Day, short Month, short Year)
    {
        short a = (14 - Month) / 12;
        short y = Year - a;
        short m = Month + (12 * a) - 2;

        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    short DayOfWeekOrder()
    {
        return DayOfWeekOrder(_Day, _Month, _Year);
    }

    static string DayShortName(short DayOfWeekOrder)
    {
        string dayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
        return dayNames[DayOfWeekOrder];
    }

    static string DayShortName(short Day, short Month, short Year)
    {
        return DayShortName(DayOfWeekOrder(Day, Month, Year));
    }

    string DayShortName()
    {
        return DayShortName(_Day, _Month, _Year);
    }

    static string MonthShortName(short MonthNumber)
    {
        string months[12] = { "Jan","Feb","Mar","Apr","May","Jun",
                               "Jul","Aug","Sep","Oct","Nov","Dec" };
        return months[MonthNumber - 1];
    }

    string MonthShortName()
    {
        return MonthShortName(_Month);
    }

    // ---------------- Calendar Printing ----------------

    static void PrintMonthCalendar(short Month, short Year)
    {
        int startColumn = DayOfWeekOrder(1, Month, Year);
        int daysInMonth = NumberOfDaysInAMonth(Month, Year);

        printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        int column = 0;
        for (; column < startColumn; column++)
            printf("     ");

        for (int day = 1; day <= daysInMonth; day++)
        {
            printf("%5d", day);

            if (++column == 7)
            {
                column = 0;
                printf("\n");
            }
        }

        printf("\n  _________________________________\n");
    }

    void PrintMonthCalendar()
    {
        PrintMonthCalendar(_Month, _Year);
    }

    static void PrintYearCalendar(int Year)
    {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", Year);
        printf("  _________________________________\n");

        for (int month = 1; month <= 12; month++)
            PrintMonthCalendar(month, Year);
    }

    void PrintYearCalendar()
    {
        PrintYearCalendar(_Year);
    }

    // ---------------- Day Counting Within a Year ----------------

    static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
    {
        short totalDays = 0;
        for (short month = 1; month < Month; month++)
            totalDays += NumberOfDaysInAMonth(month, Year);

        return totalDays + Day;
    }

    short DaysFromTheBeginingOfTheYear()
    {
        return DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
    }

    static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
    {
        clsDate date;
        short remainingDays = DateOrderInYear;

        date.Year = Year;
        date.Month = 1;

        while (true)
        {
            short daysInMonth = NumberOfDaysInAMonth(date.Month, Year);

            if (remainingDays > daysInMonth)
            {
                remainingDays -= daysInMonth;
                date.Month++;
            }
            else
            {
                date.Day = remainingDays;
                break;
            }
        }

        return date;
    }

    void AddDays(short Days)
    {
        short remainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
        _Month = 1;

        while (true)
        {
            short daysInMonth = NumberOfDaysInAMonth(_Month, _Year);

            if (remainingDays > daysInMonth)
            {
                remainingDays -= daysInMonth;
                _Month++;

                if (_Month > 12)
                {
                    _Month = 1;
                    _Year++;
                }
            }
            else
            {
                _Day = remainingDays;
                break;
            }
        }
    }

    // ---------------- Comparison ----------------

    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        if (Date1.Year != Date2.Year)
            return Date1.Year < Date2.Year;

        if (Date1.Month != Date2.Month)
            return Date1.Month < Date2.Month;

        return Date1.Day < Date2.Day;
    }

    bool IsDateBeforeDate2(clsDate Date2)
    {
        return IsDate1BeforeDate2(*this, Date2);
    }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day;
    }

    bool IsDateEqualDate2(clsDate Date2)
    {
        return IsDate1EqualDate2(*this, Date2);
    }

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
    }

    bool IsDateAfterDate2(clsDate Date2)
    {
        return IsDate1AfterDate2(*this, Date2);
    }

    enum enDateCompare { Before = -1, Equal = 0, After = 1 };

    static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
            return enDateCompare::Before;

        if (IsDate1EqualDate2(Date1, Date2))
            return enDateCompare::Equal;

        return enDateCompare::After;
    }

    enDateCompare CompareDates(clsDate Date2)
    {
        return CompareDates(*this, Date2);
    }

    // ---------------- Single Day Step ----------------

    static bool IsLastDayInMonth(clsDate Date)
    {
        return Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year);
    }

    bool IsLastDayInMonth()
    {
        return IsLastDayInMonth(*this);
    }

    static bool IsLastMonthInYear(short Month)
    {
        return Month == 12;
    }

    static clsDate AddOneDay(clsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date.Month))
            {
                Date.Month = 1;
                Date.Day = 1;
                Date.Year++;
            }
            else
            {
                Date.Month++;
                Date.Day = 1;
            }
        }
        else
        {
            Date.Day++;
        }

        return Date;
    }

    void AddOneDay()
    {
        *this = AddOneDay(*this);
    }

    static clsDate DecreaseDateByOneDay(clsDate Date)
    {
        if (Date.Day == 1)
        {
            if (Date.Month == 1)
            {
                Date.Month = 12;
                Date.Day = 31;
                Date.Year--;
            }
            else
            {
                Date.Month--;
                Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
            }
        }
        else
        {
            Date.Day--;
        }

        return Date;
    }

    void DecreaseDateByOneDay()
    {
        *this = DecreaseDateByOneDay(*this);
    }

    static void SwapDates(clsDate& Date1, clsDate& Date2)
    {
        clsDate temp = Date1;
        Date1 = Date2;
        Date2 = temp;
    }

    static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        int days = 0;
        int sign = 1;

        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            SwapDates(Date1, Date2);
            sign = -1;
        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            days++;
            Date1 = AddOneDay(Date1);
        }

        if (IncludeEndDay)
            days++;

        return days * sign;
    }

    int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
    {
        return GetDifferenceInDays(*this, Date2, IncludeEndDay);
    }

    static short CalculateMyAgeInDays(clsDate DateOfBirth)
    {
        return (short)GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
    }

    // ---------------- Increase By Period ----------------

    static clsDate IncreaseDateByOneWeek(clsDate& Date)
    {
        for (int i = 1; i <= 7; i++)
            Date = AddOneDay(Date);

        return Date;
    }

    void IncreaseDateByOneWeek()
    {
        IncreaseDateByOneWeek(*this);
    }

    clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date)
    {
        for (short i = 1; i <= Weeks; i++)
            Date = IncreaseDateByOneWeek(Date);

        return Date;
    }

    void IncreaseDateByXWeeks(short Weeks)
    {
        IncreaseDateByXWeeks(Weeks, *this);
    }

    clsDate IncreaseDateByOneMonth(clsDate& Date)
    {
        if (Date.Month == 12)
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Month++;
        }

        short daysInNewMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (Date.Day > daysInNewMonth)
            Date.Day = daysInNewMonth;

        return Date;
    }

    void IncreaseDateByOneMonth()
    {
        IncreaseDateByOneMonth(*this);
    }

    clsDate IncreaseDateByXDays(short Days, clsDate& Date)
    {
        for (short i = 1; i <= Days; i++)
            Date = AddOneDay(Date);

        return Date;
    }

    void IncreaseDateByXDays(short Days)
    {
        IncreaseDateByXDays(Days, *this);
    }

    clsDate IncreaseDateByXMonths(short Months, clsDate& Date)
    {
        for (short i = 1; i <= Months; i++)
            Date = IncreaseDateByOneMonth(Date);

        return Date;
    }

    void IncreaseDateByXMonths(short Months)
    {
        IncreaseDateByXMonths(Months, *this);
    }

    static clsDate IncreaseDateByOneYear(clsDate& Date)
    {
        Date.Year++;
        return Date;
    }

    void IncreaseDateByOneYear()
    {
        IncreaseDateByOneYear(*this);
    }

    clsDate IncreaseDateByXYears(short Years, clsDate& Date)
    {
        Date.Year += Years;
        return Date;
    }

    void IncreaseDateByXYears(short Years)
    {
        IncreaseDateByXYears(Years, *this);
    }

    clsDate IncreaseDateByOneDecade(clsDate& Date)
    {
        Date.Year += 10;
        return Date;
    }

    void IncreaseDateByOneDecade()
    {
        IncreaseDateByOneDecade(*this);
    }

    clsDate IncreaseDateByXDecades(short Decades, clsDate& Date)
    {
        Date.Year += Decades * 10;
        return Date;
    }

    void IncreaseDateByXDecades(short Decades)
    {
        IncreaseDateByXDecades(Decades, *this);
    }

    clsDate IncreaseDateByOneCentury(clsDate& Date)
    {
        Date.Year += 100;
        return Date;
    }

    void IncreaseDateByOneCentury()
    {
        IncreaseDateByOneCentury(*this);
    }

    clsDate IncreaseDateByOneMillennium(clsDate& Date)
    {
        Date.Year += 1000;
        return Date;
    }

    clsDate IncreaseDateByOneMillennium()
    {
        return IncreaseDateByOneMillennium(*this);
    }

    // ---------------- Decrease By Period ----------------

    static clsDate DecreaseDateByOneWeek(clsDate& Date)
    {
        for (int i = 1; i <= 7; i++)
            Date = DecreaseDateByOneDay(Date);

        return Date;
    }

    void DecreaseDateByOneWeek()
    {
        DecreaseDateByOneWeek(*this);
    }

    static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date)
    {
        for (short i = 1; i <= Weeks; i++)
            Date = DecreaseDateByOneWeek(Date);

        return Date;
    }

    void DecreaseDateByXWeeks(short Weeks)
    {
        DecreaseDateByXWeeks(Weeks, *this);
    }

    static clsDate DecreaseDateByOneMonth(clsDate& Date)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
        }

        short daysInNewMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (Date.Day > daysInNewMonth)
            Date.Day = daysInNewMonth;

        return Date;
    }

    void DecreaseDateByOneMonth()
    {
        DecreaseDateByOneMonth(*this);
    }

    static clsDate DecreaseDateByXDays(short Days, clsDate& Date)
    {
        for (short i = 1; i <= Days; i++)
            Date = DecreaseDateByOneDay(Date);

        return Date;
    }

    void DecreaseDateByXDays(short Days)
    {
        DecreaseDateByXDays(Days, *this);
    }

    static clsDate DecreaseDateByXMonths(short Months, clsDate& Date)
    {
        for (short i = 1; i <= Months; i++)
            Date = DecreaseDateByOneMonth(Date);

        return Date;
    }

    void DecreaseDateByXMonths(short Months)
    {
        DecreaseDateByXMonths(Months, *this);
    }

    static clsDate DecreaseDateByOneYear(clsDate& Date)
    {
        Date.Year--;
        return Date;
    }

    void DecreaseDateByOneYear()
    {
        DecreaseDateByOneYear(*this);
    }

    static clsDate DecreaseDateByXYears(short Years, clsDate& Date)
    {
        Date.Year -= Years;
        return Date;
    }

    void DecreaseDateByXYears(short Years)
    {
        DecreaseDateByXYears(Years, *this);
    }

    static clsDate DecreaseDateByOneDecade(clsDate& Date)
    {
        Date.Year -= 10;
        return Date;
    }

    void DecreaseDateByOneDecade()
    {
        DecreaseDateByOneDecade(*this);
    }

    static clsDate DecreaseDateByXDecades(short Decades, clsDate& Date)
    {
        Date.Year -= Decades * 10;
        return Date;
    }

    void DecreaseDateByXDecades(short Decades)
    {
        DecreaseDateByXDecades(Decades, *this);
    }

    static clsDate DecreaseDateByOneCentury(clsDate& Date)
    {
        Date.Year -= 100;
        return Date;
    }

    void DecreaseDateByOneCentury()
    {
        DecreaseDateByOneCentury(*this);
    }

    static clsDate DecreaseDateByOneMillennium(clsDate& Date)
    {
        Date.Year -= 1000;
        return Date;
    }

    void DecreaseDateByOneMillennium()
    {
        DecreaseDateByOneMillennium(*this);
    }

    // ---------------- Week / Business Day Helpers ----------------

    static bool IsEndOfWeek(clsDate Date)
    {
        return DayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6;
    }

    bool IsEndOfWeek()
    {
        return IsEndOfWeek(*this);
    }

    static bool IsWeekEnd(clsDate Date)
    {
        short dayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
        return dayIndex == 5 || dayIndex == 6;
    }

    bool IsWeekEnd()
    {
        return IsWeekEnd(*this);
    }

    static bool IsBusinessDay(clsDate Date)
    {
        return !IsWeekEnd(Date);
    }

    bool IsBusinessDay()
    {
        return IsBusinessDay(*this);
    }

    static short DaysUntilTheEndOfWeek(clsDate Date)
    {
        return 6 - DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
    }

    short DaysUntilTheEndOfWeek()
    {
        return DaysUntilTheEndOfWeek(*this);
    }

    static short DaysUntilTheEndOfMonth(clsDate Date)
    {
        clsDate endOfMonth(NumberOfDaysInAMonth(Date.Month, Date.Year), Date.Month, Date.Year);
        return GetDifferenceInDays(Date, endOfMonth, true);
    }

    short DaysUntilTheEndOfMonth()
    {
        return DaysUntilTheEndOfMonth(*this);
    }

    static short DaysUntilTheEndOfYear(clsDate Date)
    {
        clsDate endOfYear(31, 12, Date.Year);
        return GetDifferenceInDays(Date, endOfYear, true);
    }

    short DaysUntilTheEndOfYear()
    {
        return DaysUntilTheEndOfYear(*this);
    }

    static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
    {
        short days = 0;
        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                days++;

            DateFrom = AddOneDay(DateFrom);
        }

        return days;
    }

    static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
    {
        return CalculateBusinessDays(DateFrom, DateTo);
    }

    static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
    {
        short weekendCounter = 0;

        for (short i = 1; i <= VacationDays; i++)
        {
            if (IsWeekEnd(DateFrom))
                weekendCounter++;

            DateFrom = AddOneDay(DateFrom);
        }

        for (short i = 1; i <= weekendCounter; i++)
            DateFrom = AddOneDay(DateFrom);

        return DateFrom;
    }

    static string GetSystemDateTimeString()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        short Day, Month, Year, Hour, Minute, Second;

        Year = now->tm_year + 1900;
        Month = now->tm_mon + 1;
        Day = now->tm_mday;
        Hour = now->tm_hour;
        Minute = now->tm_min;
        Second = now->tm_sec;

        return(to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - "
            + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second));
    }
};

