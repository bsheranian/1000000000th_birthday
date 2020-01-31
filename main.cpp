#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

const long day = 86400;
const long year = 31536000;
const long leap_year = 31622400;

class Date {
private:

    long second;
    long minute;
    long hour;
    long day;
    long month;
    long year;
    
public:
    
    Date(int _second, int _minute, int _hour, int _day, int _month, int _year) {
        second = _second;
        minute = _minute;
        hour = _hour;
        day = _day;
        month = _month;
        year = _year;
    }
    
    void update() {
        long scale;
        if (second >= 60) {
            scale = second / 60;
            second %= 60;
            minute += scale;
        }
        if (minute >= 60) {
            scale = minute / 60;
            minute %= 60;
            hour += scale;
        }
        if (hour >= 24) {
            scale = hour / 24;
            hour %= 24;
            day += scale;
        }
        
        //while loop for months
        
        
        
        while (day > 31 || (day > 30 && month % 2 == 0 && month != 8) || (day > 28 && month ==2)) {
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                day -= 31;
                month++;
            }
            else if (month == 2) {
                if (year % 4 == 0) {
                    day -= 29;
                    month++;
                }
                else {
                    day -= 28;
                    month++;
                }
            }
            else {
                day -= 30;
                month++;
            }
            if (month == 13) {
                year++;
                month = 1;
            }
        }
    }
    
    
    void addSeconds(long time) {
        second += time;
        update();
    }
    
    string toString() {
        string month_string;
        string day_string;
        
        switch (month) {
            case 1: month_string = "January"; break;
            case 2: month_string = "February"; break;
            case 3: month_string = "March"; break;
            case 4: month_string = "April"; break;
            case 5: month_string = "May"; break;
            case 6: month_string = "June"; break;
            case 7: month_string = "July"; break;
            case 8: month_string = "August"; break;
            case 9: month_string = "September"; break;
            case 10: month_string = "October"; break;
            case 11: month_string = "November"; break;
            case 12: month_string = "December"; break;
        }
        
        if (day == 1) {
            day_string = "1st";
        }
        else if (day == 2) {
            day_string = "2nd";
        }
        else if (day == 3) {
            day_string = "3rd";
        }
        else {
            day_string  = to_string(day) + "th";
        }
        
        stringstream ss;
        
        ss << setfill('0') << month_string << " " << day_string << ", " << setw(4) << year << " at " << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
        
        return ss.str();
    }
    
};





int main () {
    
    unsigned long billion = 1000000000;
    
    string bdayString;
    
    int start_second;
    int start_minute;
    int start_hour;
    int start_day;
    int start_month;
    int start_year;
    
    cout << "\n   ********************************************************************\n\n";
    cout << "\tLET'S FIND OUT WHEN YOUR ONE BILLION SECOND BIRTHDAY IS!!!\n";
    cout << "\n   ********************************************************************\n\n";
    
    bool validString =  false;
    while (validString == false) {
        cout << "1.) WHEN IS YOUR BIRTHDAY? (MM/DD/YYYY)\n\n";
        
        getline(cin, bdayString);
        
        char c;
        stringstream(bdayString) >> start_month >> c >> start_day >> c >> start_year;
        
        if (start_month > 0 && start_month < 13 && start_year >= 0 && (start_day < 28 || start_month != 2 || start_year % 4 == 0) && (start_day < 31 || start_month == 1 || start_month == 3 || start_month == 5 || start_month == 7 || start_month == 8 || start_month == 10 || start_month == 12) && start_day < 32 && start_day > 0) {
            validString = true;
            break;
        }
        else {
            cout << "\n**** SORRY, THIS IS NOT A VALID DATE ****\n\n";
        }
    }
    
    cout << "\n\n2.) WHAT TIME WERE YOU BORN? (HH:MM:SS) [if you don't know put 12:00:00]\n\n";
    
    getline(cin, bdayString);
    char c;
    stringstream(bdayString) >> start_hour >> c >> start_minute >> c >> start_second;
    
    
    Date* myDate = new Date(start_second, start_minute, start_hour, start_day, start_month, start_year);
    
    
    myDate->addSeconds(billion);
    
    cout << "\n   ************************************************************************\n\n";
    cout << "     You will turn ONE BILLION seconds on " << myDate->toString() << " !!!\n";
    cout << "\n   ************************************************************************\n\n";
    
    
    delete myDate;
    
}
